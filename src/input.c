#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "grafica.h"

extern int InputPosizione(char **disegno, size_t *riga, size_t *colonna, char *simbolo, bool x_o) {
    int posizione; // posizione del simbolo inserito

    char *input = calloc(100, sizeof(char));
    bool check = true;

    GoToXY(19, 29);
    printf("Inserisci un numero: ");
    scanf("%s", input);

    char *errore;

    posizione = strtoul(input, &errore, 10);

    if (input == errore)
        check = false;

    else if (posizione > 9)
        check = false;

    else if (posizione < 0)
        check = false;

    else if (posizione != 0) {
        // riga
        if (posizione >= 7 && posizione <= 9)
            *riga = 0;
        else if (posizione >= 4 && posizione <= 6)
            *riga = 1;
        else
            *riga = 2;

        // colonna
        if (posizione % 3 == 1)
            *colonna = 0;
        else if (posizione % 3 == 2)
            *colonna = 1;
        else
            *colonna = 2;

        // verifica simbolo
        if (disegno[*riga][*colonna] != ' ')
            check = false;
        else {
            // allocazione simbolo "X"
            if (x_o == false)
                *simbolo = 'X';
                // allocazione simbolo "O"
            else
                *simbolo = 'O';

            // posizionamento simbolo
            disegno[*riga][*colonna] = *simbolo;
        }
    }

    free(input);
    system("cls");

    if (check == false)
        return -1;

    return posizione;
}

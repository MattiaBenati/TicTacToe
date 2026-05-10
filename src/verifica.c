#include <stdio.h>
#include <windows.h>
#include "verifica.h"
#include "grafica.h"

// verifica della colonna
extern bool VerificaColonna(char **disegno, size_t colonna, char simbolo) {
    for (size_t r = 0; r < 3; ++r) {
        // disegno[riga][colonna]
        if (disegno[r][colonna] != simbolo)
            return false;
    }

    return true;
}

// verifica della riga
extern bool VerificaRiga(char **disegno, size_t riga, char simbolo) {
    for (size_t c = 0; c < 3; ++c) {
        // disegno[riga][colonna]
        if (disegno[riga][c] != simbolo)
            return false;
    }

    return true;
}

// verifica diagonale sinistra (da in alto a sinistra verso in basso a destra)
extern bool VerificaDiagonaleSx(char **disegno, char simbolo) {
    size_t row = 0;
    size_t col = 0;

    // [0][0]
    // [1][1]
    // [2][2]

    for (size_t r_c = 0; r_c < 3; ++r_c) {
        if (disegno[row][col] != simbolo)
            return false;

        row += 1;
        col += 1;
    }

    return true;
}

// verifica diagonale destra (da in alto a destra verso in basso a sinistra)
extern bool VerificaDiagonaleDx(char **disegno, char simbolo) {
    size_t row = 0;
    size_t col = 2;

    // [0][2]
    // [1][1]
    // [2][0]

    for (size_t r_c = 0; r_c < 3; ++r_c) {
        if (disegno[row][col] != simbolo)
            return false;

        row += 1;
        col -= 1;
    }

    return true;
}

// verifica uscita dal gioco
extern int VerificaUscita(size_t punteggio_x, size_t punteggio_o) {
    int check_exit = 0;

    BordiPannelloExit();
    StampaEsito(punteggio_x, punteggio_o);

    GoToXY(4, 12);
    printf("Sei sicuro di voler uscire dal gioco?");

    GoToXY(4, 14);
    printf("- Digita '1' se vuoi tornare al gioco");
    GoToXY(4, 15);
    printf("- Digita '0' se vuoi uscire dal gioco");

    char *input = calloc(100, sizeof(char));
    bool check = true;

    GoToXY(4, 17);
    printf("Inserisci il numero: ");
    scanf("%s", input);

    char *error;

    check_exit = strtoul(input, &error, 10);

    if (input == error)
        check = false;

    else if (check_exit != 0 && check_exit != 1)
        check = false;

    free(input);

    // errore di immissione
    if (check == false)
        return -1;

    // chiudi programma
    if (check_exit == 1)
        return false;

    // torna alla schermata principale
    return true;
}

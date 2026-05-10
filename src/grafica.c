#include <stdio.h>
#include <windows.h>
#include "grafica.h"

// posizione specifica nello schermo
extern void GoToXY(int x, int y) {
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

// stampa del pannello schermata home
extern void BordiPannelloGioco() {
    // prima riga
    GoToXY(1, 1);
    printf("%c", 201);

    for (size_t i = 0; i < X_GAME - 4; ++i)
        printf("%c", 205);

    GoToXY(X_GAME - 2, 1);
    printf("%c", 187);

    // righe centrali
    for (size_t i = 0; i < Y_GAME - 4; ++i) {
        // colonna sinistra
        GoToXY(1, i + 2);
        printf("%c", 186);

        // colonna destra
        GoToXY(X_GAME - 2, i + 2);
        printf("%c", 186);
    }

    // separatore
    GoToXY(3, 13);
    for (size_t i = 0; i < X_GAME - 6; ++i)
        printf("%c", 196);

    // ultima riga
    GoToXY(1, Y_GAME - 2);
    printf("%c", 200);

    for (size_t i = 0; i < X_GAME - 4; ++i)
        printf("%c", 205);

    GoToXY(X_GAME - 2, Y_GAME - 2);
    printf("%c", 188);
}

// stampa del pannello schermata exit
extern void BordiPannelloExit() {
    // prima riga
    GoToXY(1, 1);
    printf("%c", 201);

    for (size_t i = 0; i < X_EXIT - 4; ++i)
        printf("%c", 205);

    GoToXY(X_EXIT - 2, 1);
    printf("%c", 187);

    // righe centrali
    for (size_t i = 0; i < Y_EXIT - 4; ++i) {
        // colonna sinistra
        GoToXY(1, i + 2);
        printf("%c", 186);

        // colonna destra
        GoToXY(X_EXIT - 2, i + 2);
        printf("%c", 186);
    }

    // separatore
    GoToXY(3, 10);
    for (size_t i = 0; i < X_GAME - 6; ++i)
        printf("%c", 196);

    // ultima riga
    GoToXY(1, Y_EXIT - 2);
    printf("%c", 200);

    for (size_t i = 0; i < X_EXIT - 4; ++i)
        printf("%c", 205);

    GoToXY(X_EXIT - 2, Y_EXIT - 2);
    printf("%c", 188);
}

// stampa punti del giocatore "X" e giocatore "O"
extern void StampaPunteggio(size_t punti_x, size_t punti_o) {
    GoToXY(5, 3);
    printf("Giocatore 'X': { %lu }", punti_x);

    GoToXY(X_GAME - 25, 3);
    printf("Giocatore 'O': { %lu }", punti_o);
}

// stampa posizioni ancora disponibili del disegno
extern void StampaPosizioni(char **disegno) {
    int num = 55; // numero '7' in ASCII

    GoToXY(X_GAME / 2 - 10, 5);
    printf("Posizioni rimanenti:");

    for (size_t i = 0; i < 3; ++i) {
        GoToXY(X_GAME / 2 - 3, 7 + i);

        for (size_t j = 0; j < 3; ++j) {
            if (disegno[i][j] == ' ')
                printf("%c ", num);
            else
                printf("  ");

            num += 1;
        }

        num -= 6;
    }

    GoToXY(X_GAME / 2 - 9, 11);
    printf("('0' per uscire)");
}

// stampa del disegno
extern void StampaDisegno(char **disegno) {
    size_t row = 0;
    size_t col = 0;

    for (size_t r = 0; r < 9; ++r) {
        GoToXY(X_GAME / 2 - 9, 18 + r);

        for (size_t c = 0; c < 17; ++c) {
            // stampa "X" o "O"
            if (c % 6 == 2 && r % 3 == 1) {
                printf("%c", disegno[row][col]);
                col += 1;
            }

            // stampa colonne
            else if (c == 5 || c == 11)
                printf("|");

                // stampa righe
            else if (r == 2 || r == 5)
                printf("_");

                // stampa spazi
            else
                printf(" ");
        }

        if (r % 3 == 1) {
            col = 0;
            row += 1;
        }
    }
}

// stampa risultato vincitore
extern void StampaEsito(size_t punteggio_x, size_t punteggio_o) {
    GoToXY(4, 3);
    printf("Risultato:");

    if (punteggio_x != 1 && punteggio_o != 1) {
        GoToXY(4, 5);
        printf("- %lu vittorie di 'X'\n", punteggio_x);

        GoToXY(4, 6);
        printf("- %lu vittorie di 'O'\n", punteggio_o);
    } else if (punteggio_x == 1 && punteggio_o != 1) {
        GoToXY(4, 5);
        printf("- %lu vittoria di 'X'\n", punteggio_x);

        GoToXY(4, 6);
        printf("- %lu vittorie di 'O'\n", punteggio_o);
    } else if (punteggio_x != 1 && punteggio_o == 1) {
        GoToXY(4, 5);
        printf("- %lu vittorie di 'X'\n", punteggio_x);

        GoToXY(4, 6);
        printf("- %lu vittoria di 'O'\n", punteggio_o);
    } else if (punteggio_x == 1 && punteggio_o == 1) {
        GoToXY(4, 5);
        printf("- %lu vittoria di 'X'\n", punteggio_x);

        GoToXY(4, 6);
        printf("- %lu vittoria di 'O'\n", punteggio_o);
    }

    GoToXY(4, 8);

    // vincitore "X"
    if (punteggio_x > punteggio_o)
        printf("Il vincitore di questa partita e' 'X'!!");

        // vincitore "O"
    else if (punteggio_x < punteggio_o)
        printf("Il vincitore di questa partita e' 'O'!!");

        // pareggio
    else
        printf("Pareggio!!");
}

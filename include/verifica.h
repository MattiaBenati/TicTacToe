#ifndef VERIFICA_H
#define VERIFICA_H
#include <stdbool.h>

extern bool VerificaColonna(char **disegno, size_t colonna, char simbolo);

extern bool VerificaRiga(char **disegno, size_t riga, char simbolo);

extern bool VerificaDiagonaleSx(char **disegno, char simbolo);

extern bool VerificaDiagonaleDx(char **disegno, char simbolo);

extern int VerificaUscita(size_t punteggio_x, size_t punteggio_o);

#endif //VERIFICA_H

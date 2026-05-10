#include <stdlib.h>
#include "disegno.h"

// allocazione memoria per il disegno
extern char** AllocazioneMemoria()
{
    char** disegno = calloc(3, sizeof(char*));

    for (size_t i = 0; i < 3; ++i)
        disegno[i] = calloc(3, sizeof(char));

    return disegno;
}

// liberazione memoria per il disegno
extern void LiberazioneMemoria(char** disegno)
{
    for (size_t i = 0; i < 3; ++i)
        free(disegno[i]);

    free(disegno);
}

// inizializzazione disegno
extern void InizializzazioneDisegno(char** disegno)
{
    for (size_t r = 0; r < 3; ++r)
    {
        for (size_t c = 0; c < 3; ++c)
        {
            disegno[r][c] = ' ';
        }
    }
}
#ifndef GRAFICA_H
#define GRAFICA_H
#define X_GAME 62
#define Y_GAME 34
#define X_EXIT 62
#define Y_EXIT 21

extern void GoToXY(int x, int y);

extern void BordiPannelloGioco();

extern void BordiPannelloExit();

extern void StampaPunteggio(size_t punti_x, size_t punti_o);

extern void StampaPosizioni(char **disegno);

extern void StampaDisegno(char **disegno);

extern void StampaEsito(size_t punteggio_x, size_t punteggio_o);

#endif //GRAFICA_H

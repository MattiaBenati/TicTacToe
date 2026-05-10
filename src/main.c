#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "disegno.h"
#include "console.h"
#include "grafica.h"
#include "input.h"
#include "verifica.h"

int main(void)
{
	ImpostaTitoloFinestraConsole("TicTacToe");
	system("MODE 62, 34");	// DIMENSIONE pannello
	CentraEBloccaFinestraConsole();	// pannello CENTRALE e NON CLICCABILE

	char** disegno = AllocazioneMemoria();

	// variabili
	bool x_o = false;	// "X" = false, "O" = true
	bool vincitore = false;

	char simbolo;		// simbolo "X" o "O" inserito
	int posizione;		// posizione del simbolo inserito
	int verifica_uscita = false;

	size_t n = 0;

	size_t score_x = 0;	// punti del giocatore "X"
	size_t score_o = 0;	// punti del giocatore "O"

	size_t riga;		// riga analizzata
	size_t colonna;		// colonna analizzata

	// inizio del gioco
	while (true)
	{
		size_t n = 0;	// numero di simboli inseriti
		bool vincitore = false;

		InizializzazioneDisegno(disegno);	// inizializzazione array

		// inizio turno del gioco
		while (true)
		{
		reset_inizio:
			// dimensione pannello gioco
			system("MODE 62, 34");

			BordiPannelloGioco();
			StampaPunteggio(score_x, score_o);	// stampa punti dei giocatori
			StampaPosizioni(disegno);			// stampa posizioni rimanenti

			// stampa turno giocatore
			GoToXY(X_GAME / 2 - 10, 15);
			if (x_o == false)
				printf("E' il turno di 'X'");
			else
				printf("E' il turno di 'O'");

			// stampa disegno
			StampaDisegno(disegno);

			// input "posizione"
			posizione = InputPosizione(disegno, &riga, &colonna, &simbolo, x_o);

			if (posizione == -1)		// errore input
				goto reset_inizio;

			// verifica uscita dal gioco
			if (posizione == 0)
			{
			reset_uscita:
				system("cls");

				// dimensione pannello gioco
				system("MODE 62, 21");

				verifica_uscita = VerificaUscita(score_x, score_o);

				if (verifica_uscita == -1)
					goto reset_uscita;

				if (verifica_uscita == true)
					break;
				else
				{
					system("cls");
					continue;
				}
			}

			if (VerificaRiga(disegno, riga, simbolo) == true)
			{
				vincitore = true;
				break;
			}

			if (VerificaColonna(disegno, colonna, simbolo) == true)
			{
				vincitore = true;
				break;
			}

			if (VerificaDiagonaleSx(disegno, simbolo) == true)
			{
				vincitore = true;
				break;
			}

			if (VerificaDiagonaleDx(disegno, simbolo) == true)
			{
				vincitore = true;
				break;
			}

			// cambio turno giocatore
			if (x_o == false)
				x_o = true;
			else
				x_o = false;

			// pareggio
			if (n == 8)
				break;
			else
				n += 1;
		}

		if (verifica_uscita == true)
			break;

		// assegnazione punto giocatore
		if (vincitore == true && x_o == false)
			score_x += 1;
		else if (vincitore == true && x_o == true)
			score_o += 1;
	}

	// eliminazione memoria
	LiberazioneMemoria(disegno);

	return 0;
}
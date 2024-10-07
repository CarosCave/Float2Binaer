#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int true;
    int false;
} bool;


int main(void)
{
    char input[81];
    char inputCopy[81]; // Kopie des Eingabestrings
    char * ganzzahlteil = malloc(81);  // Speicherung des Ganzzahlteils
    char * dezimalzahlteil = malloc(81); // Speicherung des Dezimalzahlteils
    char * cVorzeichen = ""; // Vorzeichen
    char * delimiter1 = ","; // Trenner für die Ganzzahl und den Dezimalteil
    char * delimiter2 = "-"; // Trenner für das Vorzeichen
    bool vorzeichen; // Speichert das Vorzeichen
    char * bGanzzahlTeil = malloc(81);
    char * tbGanzzahlTeil = malloc(81);
    char * bDezimalzahlteil = malloc(81);
    char * tbDezimalzahlteil = malloc(81);
    char * tBinaerZahl = malloc(81); // 32 Bit, Speichert die Binärzahl zum arbeiten innerhalb des Programms
    char * binaerZahl = malloc(81); // 32 Bit, Speichert die Binärzahl inkl. Trennzeichen zur besseren Lesbarkeit
    int mantisse = 127;
    char * bMantisse = malloc(81); // 8 Bit

    int schleifendurchlauf = 0;
    int ergebnis = 0;
    int tempZahl = 0;
    int rest;
    int zweiteSchleife = 0;

    int iGanzzahlteil;
    int iDezimalzahlteil;


    printf("Float in Binaer Umrechner\n");
    printf("Float: ");


    scanf(" %s", input);

    strcpy(inputCopy, input); // Original-String kopieren für spätere Verarbeitung

    if (inputCopy[0] == '-') {
        vorzeichen.true = 1;
        vorzeichen.false = 0;
        cVorzeichen = "-";
        strtok(inputCopy, delimiter2); // Trenne am Vorzeichen
        strcpy(input, &inputCopy[1]);      // Setze den Input neu (ohne Vorzeichen)
    }
    else {
        vorzeichen.true = 0;
        vorzeichen.false = 1;
        cVorzeichen = "+";
    }

    if (vorzeichen.true) {
        tBinaerZahl[0] = 1;
    }
    else if (vorzeichen.false) {
        //tBinaerZahl[0] = 0;
    }

    ganzzahlteil = strtok(input, delimiter1);
    dezimalzahlteil = strtok(NULL, delimiter1);

    iGanzzahlteil = atoi(ganzzahlteil);
    iDezimalzahlteil = atoi(dezimalzahlteil);

    tempZahl = iGanzzahlteil;

    do {
        ergebnis = tempZahl / 2;
        rest = tempZahl % 2;
        printf("%i : 2 = %i R %i\n", tempZahl, ergebnis, rest);
        fflush(stdout); // Puffer leeren
        tempZahl = ergebnis;
        tbGanzzahlTeil[schleifendurchlauf] = rest + '0';
        schleifendurchlauf++;
    } while (ergebnis != 0);
    tbGanzzahlTeil[schleifendurchlauf] = 0;

    mantisse += schleifendurchlauf - 1;

    // Binärzahl umkehren
    for (int i = 0; i < schleifendurchlauf; i++) {
        bGanzzahlTeil[i] = tbGanzzahlTeil[schleifendurchlauf - 1 - i]; // Umgekehrt speichern
    }
    bGanzzahlTeil[schleifendurchlauf] = 0;
    printf("%i\n", schleifendurchlauf);

    tempZahl = iDezimalzahlteil;
    schleifendurchlauf = 0;
    do {
        ergebnis = tempZahl / 2;
        rest = tempZahl % 2;
        printf("%i : 2 = %i R %i\n", tempZahl, ergebnis, rest);
        fflush(stdout); // Puffer leeren
        tempZahl = ergebnis;
        tbDezimalzahlteil[schleifendurchlauf] = rest + '0';
        schleifendurchlauf++;
    } while (ergebnis != 0);
    tbDezimalzahlteil[schleifendurchlauf] = 0;

    printf("Vorzeichen: %i\n", vorzeichen.true);
    printf("Vorzeichen: %s\n", cVorzeichen);
    printf("Ganzzahlteil = %s\n", ganzzahlteil);
    printf("Dezimalzahlteil = %s\n", dezimalzahlteil);
    printf("%s,%s", bGanzzahlTeil, tbDezimalzahlteil);
    return 0;


}

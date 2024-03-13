/**********************************************************************\
* Kurzbeschreibung: Uebung: 22.2.1; Punkte: 0
*
* Datum:       Autor:           Grund der Aenderung:
* 20.05.2021   Denise Griebel   Neuerstellung
\**********************************************************************/
#include <stdio.h>
#include <math.h>

/*--- Funktionsdefinitionen ------------------------------------------*/
double streckeberechnen();

/*--- Funktionsdefinitionen ------------------------------------------*/
int main()
{
    char c;
    int eingabe_Test, xsta, ysta, xend, yend, ende = 1;
    double strecke = 0;

    printf("Strecken-Berechnung"
           "\n===================\n"
           "Bitte Startpunkt eingeben (x,y): ");
    //Erste Streckeneingabe + eingabe testen
    eingabe_Test = scanf("%d,%d", &xsta, &ysta);
    while(eingabe_Test != 2){
        while ((c = getchar()) != '\n' && c != EOF) { }
        printf("\nEingabe muss im Format \"(x,y)\" erfolgen.\n"
               "Versuchen Sie es nochmal.\n\n"
               "Erster Streckenpunkt (x,y): ");
        eingabe_Test = scanf("%d,%d", &xsta, &ysta);
    }
    //Streckenberechnung mit abbruchkriterium
    do{
        //Neuer Streckenpunkt
        printf("Neuer Streckenpunkt (x,y) [Abbruch mit x=-1]: ");
        eingabe_Test = scanf("%d,%d", &xend, &yend);
        while((eingabe_Test != 2 && xend != -1) || !eingabe_Test){
            while ((c = getchar()) != '\n' && c != EOF) { }
            printf("\nEingabe muss im Format \"(x,y)\" erfolgen.\n"
                   "Versuchen Sie es nochmal.\n\n"
                   "Neuer Streckenpunkt (x,y) [Abbruch mit x=-1]: ");
            eingabe_Test = scanf("%d,%d", &xend, &yend);
        }
        //Abbruchkriterium x = -1 uny y = NULL
        if(xend == -1 && eingabe_Test == 1){
            ende = 0;
        }else{
            //Strecke berechnen
            strecke += streckeberechnen(xsta, ysta, xend, yend );
            //Start Koordinaten mit End Koordinaten überschreiben und End Koordinaten auf 0 setzen
            xsta = xend; ysta = yend; xend = 0; yend = 0;
        }
    }while(ende);
    //Streckenausgabe wenn das Programm beenden soll
    printf("\n\n-> Die Streckenlaenge betraegt: %.2lf Einheiten\n", strecke);
    return 0;
}

//Streckenberechnung

double streckeberechnen(int xsta, int ysta, int xend, int yend )
{
    double result;
    int vectorX, vectorY;

    vectorX = xend - xsta;
    vectorY = yend - ysta;
    result = sqrt(vectorX*vectorX + vectorY*vectorY);
    return result;
}

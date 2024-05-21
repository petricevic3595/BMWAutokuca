#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "funkcije.h"

int brojAutomobila = 0;

int main() {
    Automobil* automobili = NULL;
    int sljedeciId = 0;
    int odabir;

    stvoriDatoteku();

    do {
        system("cls");
        printf("\nGlavni Izbornik\n");
        printf("1. Dodaj Automobil (Zahtjeva admin login)\n");
        printf("2. Prikazi Automobile\n");
        printf("3. Pretrazi i Izmijeni Automobil (Zahtjeva admin login)\n");
        printf("4. Izbrisi Automobil (Zahtjeva admin login)\n");
        printf("5. Sortiraj Automobile po Cijeni (Uzlazno)\n");
        printf("6. Sortiraj Automobile po Cijeni (Silazno)\n");
        printf("7. Sortiraj Automobile po Snazi (Uzlazno)\n");
        printf("8. Sortiraj Automobile po Snazi (Silazno)\n");
        printf("9. Spremi Automobile u Datoteku (Zahtjeva admin login)\n");
        printf("10. Izlaz\n");
        printf("Odaberite: ");

        // Input validation
        while (scanf("%d", &odabir) != 1 || odabir < 1 || odabir > 10) {
            printf("Neispravan unos! Molimo unesite broj izmedu 1 i 10: ");
            // Clear input buffer
            while (getchar() != '\n');
        }

        switch (odabir) {
        case 1:
            if (adminPrijava())
                dodajAutomobil(&automobili, &brojAutomobila, &sljedeciId);
            break;
        case 2:
            prikaziAutomobile(automobili, brojAutomobila);
            break;
        case 3:
            if (adminPrijava())
                pretraziIIzmijeniAutomobil(automobili, brojAutomobila);
            break;
        case 4:
            if (adminPrijava())
                izbrisiAutomobil(&automobili, &brojAutomobila);
            break;
        case 5:
            sortirajPoCijeniUzlazno(automobili, brojAutomobila);
            break;
        case 6:
            sortirajPoCijeniSilazno(automobili, brojAutomobila);
            break;
        case 7:
            sortirajPoSnaziUzlazno(automobili, brojAutomobila);
            break;
        case 8:
            sortirajPoSnaziSilazno(automobili, brojAutomobila);
            break;
        case 9:
            if (adminPrijava())
                spremiAutomobileUDatoteku(automobili, brojAutomobila);
            break;
        case 10:
            odabir = izlazIzPrograma(automobili);
            if (odabir == 0)
                return 0;
            break;
        default:
            printf("Nevazeci odabir! Molimo unesite broj izmedu 1 i 10.\n");
            break;
        }
        while (getchar() != '\n');
        system("pause");
    } while (odabir != 10);

    free(automobili);
    automobili = NULL;



    return 0;
}
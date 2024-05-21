#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funkcije.h"

void dodajAutomobil(Automobil** automobili, int* brojAutomobila, int* sljedeciId) {
    *automobili = realloc(*automobili, (*brojAutomobila + 1) * sizeof(Automobil));
    if (*automobili == NULL) {
        printf("Neuspjelo alociranje memorije.\n");
        return;
    }

    printf("Unesite informacije o automobilu:\n");

    printf("Model (maks. 30 znakova): ");
    if (scanf("%30s", (*automobili)[*brojAutomobila].model) != 1) {
        printf("Neispravan unos. Molimo unesite model ponovno.\n");
        // Clear input buffer
        while (getchar() != '\n');
        return; // Exit the function
    }

    printf("Ubrzanje: ");
    if (scanf("%f", &(*automobili)[*brojAutomobila].ubrzanje) != 1) {
        printf("Neispravan unos. Molimo unesite ubrzanje ponovno.\n");
        // Clear input buffer
        while (getchar() != '\n');
        return; // Exit the function
    }

    printf("Potrosnja: ");
    if (scanf("%f", &(*automobili)[*brojAutomobila].potrosnja) != 1) {
        printf("Neispravan unos. Molimo unesite potrosnju ponovno.\n");
        // Clear input buffer
        while (getchar() != '\n');
        return; // Exit the function
    }

    printf("Kilometraza (0 i vise): ");
    if (scanf("%d", &(*automobili)[*brojAutomobila].kilometraza) != 1 || (*automobili)[*brojAutomobila].kilometraza < 0) {
        printf("Neispravan unos. Molimo unesite kilometrazu ponovno.\n");
        // Clear input buffer
        while (getchar() != '\n');
        return; // Exit the function
    }

    printf("Snaga (mora biti veca od 0): ");
    if (scanf("%d", &(*automobili)[*brojAutomobila].snaga) != 1 || (*automobili)[*brojAutomobila].snaga <= 0) {
        printf("Neispravan unos. Molimo unesite snagu ponovno.\n");
        // Clear input buffer
        while (getchar() != '\n');
        return; // Exit the function
    }

    printf("Cijena (mora biti veca od 0): ");
    if (scanf("%d", &(*automobili)[*brojAutomobila].cijena) != 1 || (*automobili)[*brojAutomobila].cijena <= 0) {
        printf("Neispravan unos. Molimo unesite cijenu ponovno.\n");
        // Clear input buffer
        while (getchar() != '\n');
        return; // Exit the function
    }

    printf("Godiste (maks. 5 znakova): ");
    if (scanf("%5s", (*automobili)[*brojAutomobila].godiste) != 1) {
        printf("Neispravan unos. Molimo unesite godiste ponovno.\n");
        // Clear input buffer
        while (getchar() != '\n');
        return; // Exit the function
    }


    (*automobili)[*brojAutomobila].id = *sljedeciId;
    (*brojAutomobila)++;
    (*sljedeciId)++;
}

void prikaziAutomobile(Automobil* automobili, int brojAutomobila) {
    if (brojAutomobila == 0) {
        printf("Nema automobila za prikaz.\n");
        return;
    }

    printf("Automobili:\n");
    for (int i = 0; i < brojAutomobila; i++) {
        printf("ID: %d, Model: %s, Ubrzanje: %.2f, Potrosnja: %.2f, Kilometraza: %d, Snaga: %d, Cijena: %d, Godiste: %s\n",
            automobili[i].id, automobili[i].model, automobili[i].ubrzanje, automobili[i].potrosnja, automobili[i].kilometraza, automobili[i].snaga, automobili[i].cijena, automobili[i].godiste);
    }
}

void spremiAutomobileUDatoteku(Automobil* automobili, int brojAutomobila) {
    FILE* datoteka = fopen("auto.txt", "w");
    if (datoteka == NULL) {
        printf("Pogreska: Nije moguce otvoriti datoteku za pisanje.\n");
        return;
    }

    for (int i = 0; i < brojAutomobila; i++) {
        fprintf(datoteka, "%d %s %.2f %.2f %d %d %d %s\n", automobili[i].id, automobili[i].model, automobili[i].ubrzanje, automobili[i].potrosnja, automobili[i].kilometraza, automobili[i].snaga, automobili[i].cijena, automobili[i].godiste);
    }

    fclose(datoteka);
    printf("Automobili uspjesno spremljeni u datoteku.\n");
}

void stvoriDatoteku() {
    FILE* datoteka = fopen("auto.txt", "r");
    if (datoteka == NULL) {
        datoteka = fopen("auto.txt", "w");
        if (datoteka != NULL) {
            printf("Datoteka auto.txt stvorena.\n");
            fclose(datoteka);
        }
        else {
            printf("Pogreska: Nije moguce stvoriti datoteku.\n");
        }
    }
    else {
        printf("Datoteka auto.txt vec postoji.\n");
        fclose(datoteka);
    }
}

int adminPrijava() {
    char korisnickoIme[50];
    char lozinka[50];
    printf("Unesite admin korisnicko ime: ");
    scanf("%s", korisnickoIme);
    printf("Unesite admin lozinku: ");
    scanf("%s", lozinka);

    if (strcmp(korisnickoIme, "admin") == 0 && strcmp(lozinka, "adminpass") == 0) {
        printf("Prijava uspjesna.\n");
        return 1;
    }
    else {
        printf("Neispravni podaci za prijavu.\n");
        return 0;
    }
}

int izlazIzPrograma(Automobil* automobili) {
    static char potvrda[4];
    while (1) {
        printf("Zelite li zaista izaci iz programa?\n");
        printf("Upisite \"da\" ako zaista zelite izaci iz programa, inace upisite \"ne\"!\n");
        if (scanf("%3s", potvrda) == 1) {
            if (strcmp("da", potvrda) == 0) {
                free(automobili);
                automobili = NULL;
                return 0;
            }
            else if (strcmp("ne", potvrda) == 0) {
                return 1;
            }
            else {
                printf("Neispravan unos. Molimo upisite \"da\" ili \"ne\".\n");
                // Ocisti ulazni bafer
                while (getchar() != '\n');
            }
        }
        else {
            printf("Neispravan unos. Molimo upisite \"da\" ili \"ne\".\n");
            // Ocisti ulazni bafer
            while (getchar() != '\n');
        }
    }
    free(automobili);
    automobili = NULL;
}

void pretraziIIzmijeniAutomobil(Automobil* automobili, int brojAutomobila) {
    static int id;
    printf("Unesite ID automobila koji zelite urediti: ");
    scanf("%d", &id);

    int pronaden = 0;
    for (int i = 0; i < brojAutomobila; i++) {
        if (automobili[i].id == id) {
            pronaden = 1;
            printf("Automobil pronaden!\n");
            printf("Trenutne informacije:\n");
            printf("Model: %s, Ubrzanje: %.2f, Potrosnja: %.2f, Kilometraza: %d, Snaga: %d, Cijena: %d, Godiste: %s\n",
                automobili[i].model, automobili[i].ubrzanje, automobili[i].potrosnja, automobili[i].kilometraza, automobili[i].snaga, automobili[i].cijena, automobili[i].godiste);
            printf("Unesite nove informacije:\n");

            printf("Model (maks. 10 znakova): ");
            if (scanf("%10s", automobili[i].model) != 1) {
                printf("Neispravan unos. Molimo unesite model ponovno.\n");
                // Clear input buffer
                while (getchar() != '\n');
                return; // Exit the function
            }

            printf("Ubrzanje: ");
            if (scanf("%f", &automobili[i].ubrzanje) != 1) {
                printf("Neispravan unos. Molimo unesite ubrzanje ponovno.\n");
                // Clear input buffer
                while (getchar() != '\n');
                return; // Exit the function
            }

            printf("Potrosnja: ");
            if (scanf("%f", &automobili[i].potrosnja) != 1) {
                printf("Neispravan unos. Molimo unesite potrosnju ponovno.\n");
                // Clear input buffer
                while (getchar() != '\n');
                return; // Exit the function
            }

            printf("Kilometraza (0 i vise): ");
            if (scanf("%d", &automobili[i].kilometraza) != 1 || automobili[i].kilometraza < 0) {
                printf("Neispravan unos. Molimo unesite kilometrazu ponovno.\n");
                // Clear input buffer
                while (getchar() != '\n');
                return; // Exit the function
            }

            printf("Snaga (mora biti veca od 0): ");
            if (scanf("%d", &automobili[i].snaga) != 1 || automobili[i].snaga <= 0) {
                printf("Neispravan unos. Molimo unesite snagu ponovno.\n");
                // Clear input buffer
                while (getchar() != '\n');
                return; // Exit the function
            }

            printf("Cijena (mora biti veca od 0): ");
            if (scanf("%d", &automobili[i].cijena) != 1 || automobili[i].cijena <= 0) {
                printf("Neispravan unos. Molimo unesite cijenu ponovno.\n");
                // Clear input buffer
                while (getchar() != '\n');
                return; // Exit the function
            }

            printf("Godiste (maks. 5 znakova): ");
            if (scanf("%5s", automobili[i].godiste) != 1) {
                printf("Neispravan unos. Molimo unesite godiste ponovno.\n");
                // Clear input buffer
                while (getchar() != '\n');
                return; // Exit the function
            }

            printf("Informacije o automobilu su azurirane.\n");
            break;
        }
    }


    if (!pronaden) {
        printf("Automobil s ID-om %d nije pronaden.\n", id);
    }
}

void izbrisiAutomobil(Automobil** automobili, int* brojAutomobila) {
    int id;
    printf("Unesite ID automobila koji zelite izbrisati: ");
    scanf("%d", &id);

    int indeksZaBrisanje = -1;
    for (int i = 0; i < *brojAutomobila; i++) {
        if ((*automobili)[i].id == id) {
            indeksZaBrisanje = i;
            break;
        }
    }

    if (indeksZaBrisanje != -1) {
        char potvrda[3];
        printf("Jeste li sigurni da zelite izbrisati automobil? (d/n): ");
        scanf("%s", potvrda);
        if (strcmp(potvrda, "d") == 0 || strcmp(potvrda, "D") == 0) {
            for (int i = indeksZaBrisanje; i < (*brojAutomobila - 1); i++) {
                (*automobili)[i] = (*automobili)[i + 1];
            }
            (*brojAutomobila)--;
            printf("Automobil uspjesno izbrisan.\n");
        }
        else {
            printf("Automobil nije izbrisan.\n");
        }
    }
    else {
        printf("Automobil s ID-om %d nije pronaden.\n", id);
    }
}

void sortirajPoCijeniUzlazno(Automobil* automobili, int brojAutomobila) {
    for (int i = 0; i < brojAutomobila - 1; i++) {
        for (int j = 0; j < brojAutomobila - i - 1; j++) {
            if (automobili[j].cijena > automobili[j + 1].cijena) {
                Automobil temp = automobili[j];
                automobili[j] = automobili[j + 1];
                automobili[j + 1] = temp;
            }
        }
    }
    printf("Automobili sortirani po cijeni uzlazno:\n");
    prikaziAutomobile(automobili, brojAutomobila);
}

void sortirajPoCijeniSilazno(Automobil* automobili, int brojAutomobila) {
    for (int i = 0; i < brojAutomobila - 1; i++) {
        for (int j = 0; j < brojAutomobila - i - 1; j++) {
            if (automobili[j].cijena < automobili[j + 1].cijena) {
                Automobil temp = automobili[j];
                automobili[j] = automobili[j + 1];
                automobili[j + 1] = temp;
            }
        }
    }
    printf("Automobili sortirani po cijeni silazno:\n");
    prikaziAutomobile(automobili, brojAutomobila);
}

void sortirajPoSnaziUzlazno(Automobil* automobili, int brojAutomobila) {
    for (int i = 0; i < brojAutomobila - 1; i++) {
        for (int j = 0; j < brojAutomobila - i - 1; j++) {
            if (automobili[j].snaga > automobili[j + 1].snaga) {
                Automobil temp = automobili[j];
                automobili[j] = automobili[j + 1];
                automobili[j + 1] = temp;
            }
        }
    }
    printf("Automobili sortirani po snazi uzlazno:\n");
    prikaziAutomobile(automobili, brojAutomobila);
}

void sortirajPoSnaziSilazno(Automobil* automobili, int brojAutomobila) {
    for (int i = 0; i < brojAutomobila - 1; i++) {
        for (int j = 0; j < brojAutomobila - i - 1; j++) {
            if (automobili[j].snaga < automobili[j + 1].snaga) {
                Automobil temp = automobili[j];
                automobili[j] = automobili[j + 1];
                automobili[j + 1] = temp;
            }
        }
    }
    printf("Automobili sortirani po snazi silazno:\n");
    prikaziAutomobile(automobili, brojAutomobila);
}

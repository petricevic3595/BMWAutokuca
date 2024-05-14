#pragma once

typedef struct {
    int id;
    char model[11];
    float ubrzanje;
    float potrosnja;
    int kilometraza;
    int snaga;
    int cijena;
    char godiste[6];
} Automobil;

void dodajAutomobil(Automobil** automobili, int* brojAutomobila, int* sljedeciId);
void prikaziAutomobile(Automobil* automobili, int brojAutomobila);
void spremiAutomobileUDatoteku(Automobil* automobili, int brojAutomobila);
void stvoriDatoteku();
void pretraziIIzmijeniAutomobil(Automobil* automobili, int brojAutomobila);
void izbrisiAutomobil(Automobil** automobili, int* brojAutomobila);
void sortirajPoCijeniUzlazno(Automobil* automobili, int brojAutomobila);
void sortirajPoCijeniSilazno(Automobil* automobili, int brojAutomobila);
void sortirajPoSnaziUzlazno(Automobil* automobili, int brojAutomobila);
void sortirajPoSnaziSilazno(Automobil* automobili, int brojAutomobila);
int adminPrijava();
int izlazIzPrograma(Automobil* automobili);

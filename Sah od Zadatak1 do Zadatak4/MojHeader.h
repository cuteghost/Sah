#include <stdio.h>
#include <stdlib.h>

#define duzina 8
#define sirina duzina*2
#define crno_polje 178
#define bijelo_polje 177
#define crna_figura 219
#define bijela_figura 170
#define MAX_FIGURA 26
#include "figure.h"
#include "SlovaIBrojevi.h"
//ova enum je da lakse pratim sve mogucnosti

enum SPolje{
    BrojJedan,
    BrojDva,
    BrojTri,
    BrojCetiri,
    BrojPet,
    BrojSest,
    BrojSedam,
    BrojOsam,

    SlovoA,
    SlovoB,
    SlovoC,
    SlovoD,
    SlovoE,
    SlovoF,
    SlovoG,
    SlovoH,
};
enum Figura{
    None,

    BPiun,
    WPiun,

    BKralj,
    WKralj,

    BKraljica,
    WKraljica,

    BLovac,
    WLovac,

    BTop,
    WTop,

    BKonj,
    WKonj
};
enum Pozicija {
	PraznoCrno,
	PraznoBijelo,

	CrnoPoljeCrniLovac,
	CrnoPoljeBijeliLovac,
	BijeloPoljeCrniLovac,
	BijeloPoljeBijeliLovac,

	CrnoPoljeCrniKralj,
	CrnoPoljeBijeliKralj,
	BijeloPoljeCrnaKraljica,
	BijeloPoljeBijelaKraljica,

	CrnoPoljeCrniKonj,
	CrnoPoljeBijeliKonj,
	BijeloPoljeCrniKonj,
	BijeloPoljeBijeliKonj,

	BijeloPoljeBijeliTop,
	BijeloPoljeCrniTop,
	CrnoPoljeBijeliTop,
	CrnoPoljeCrniTop,

	CrnoPoljeCrniPiun,
	CrnoPoljeBijeliPiun,
	BijeloPoljeCrniPiun,
	BijeloPoljeBijeliPiun,


	BijeloPoljeBijeliKralj,
	BijeloPoljeCrniKralj,
	CrnoPoljeBijelaKraljica,
	CrnoPoljeCrnaKraljica,


};

const char* CharPozicija[]= {
	"PraznoCrno",
	"PraznoBijelo",

	"CrnoPoljeCrniLovac",
	"CrnoPoljeBijeliLovac",
	"BijeloPoljeCrniLovac",
	"BijeloPoljeBijeliLovac",

	"CrnoPoljeCrniKralj",
	"CrnoPoljeBijeliKralj",
	"BijeloPoljeCrnaKraljica",
	"BijeloPoljeBijelaKraljica",

	"BijeloPoljeCrniKonj",
	"CrnoPoljeBijeliKonj",
	"CrnoPoljeCrniKonj",
	"BijeloPoljeBijeliKonj",

	"BijeloPoljeBijeliTop",
	"BijeloPoljeCrniTop",
	"CrnoPoljeBijeliTop",
	"CrnoPoljeCrniTop",

	"CrnoPoljeCrniPiun",
	"CrnoPoljeBijeliPiun",
	"BijeloPoljeCrniPiun",
	"BijeloPoljeBijeliPiun",


	"BijeloPoljeBijeliKralj",
	"BijeloPoljeCrniKralj",
	"CrnoPoljeCrnaKraljica",
	"CrnoPoljeBijelaKraljica"
};

struct Polje {
	char polje[duzina][sirina];

};

struct Polje init_Spolje(struct Polje p, int tip_figure) {
    int i,j;

    for(int i = 0; i<duzina;i++)
    {
        for(int j = 0; j<sirina;j++)
        {
            p.polje[i][j] = SpecijalnaPolja[tip_figure][i][j];
        }
    }
    return p;
}
struct Polje init_polje(struct Polje p, int tip_figure) {
    int i,j;

    for(int i = 0; i<duzina;i++)
    {
        for(int j = 0; j<sirina;j++)
        {
            p.polje[i][j] = SahovskeFigure[tip_figure][i][j];
        }
    }
    return p;
}
void ispis_polja(struct Polje p)
{
    int i, j;
    for(i=0;i<duzina;i++)
    {
        for(j=0;j<sirina;j++)
        {
            printf("%c",p.polje[i][j]);

        }
        printf("\n");
    }
}






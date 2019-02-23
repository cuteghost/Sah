#include <stdio.h>
#include <stdlib.h>
#include "MojHeader.h"
enum Pozicija Pozicija2D[8][8];
enum Figura PolozajFigura[8][8];
struct Polje Ploca[9][9];//PROSIRENA MATRICA ZBOG SLOVA I BROJEVA
void initPozicija()
{
    int i,s;
    for(i = 0; i<8;i++)
    {
        if(i%2==0)
        {
            Pozicija2D[i][0] = Pozicija2D[i][2] = Pozicija2D[i][4] = Pozicija2D[i][6] = PraznoBijelo;
            Pozicija2D[i][1] = Pozicija2D[i][3] = Pozicija2D[i][5] = Pozicija2D[i][7] = PraznoCrno;
        }
        else{
            Pozicija2D[i][0] = Pozicija2D[i][2] = Pozicija2D[i][4] = Pozicija2D[i][6] = PraznoCrno;
            Pozicija2D[i][1] = Pozicija2D[i][3] = Pozicija2D[i][5] = Pozicija2D[i][7] = PraznoBijelo;
        }
    }

    for(i = 0;i<8;i++){
        for(s = 0;s<8;s++){
           PolozajFigura[i][s] = None;
        }
    }

    PolozajFigura[0][0] = PolozajFigura[0][7] = BTop;
    PolozajFigura[7][0] = PolozajFigura[7][7] = WTop;

    PolozajFigura[0][1] = PolozajFigura[0][6] = BKonj;
    PolozajFigura[7][1] = PolozajFigura[7][6] = WKonj;

    PolozajFigura[0][2] = PolozajFigura[0][5] = BLovac;
    PolozajFigura[7][2] = PolozajFigura[7][5] = WLovac;
    PolozajFigura[0][3] = BKraljica; PolozajFigura[7][3] = WKraljica;
    PolozajFigura[0][4] = BKralj; PolozajFigura[7][4] = WKralj;
    for(i = 0;i<8;i++){
        PolozajFigura[1][i] = BPiun;
        PolozajFigura[6][i] = WPiun;
    }
}
int meni(){
    int odabir = 1;
    do{
        printf("Unesite zeljenu figuru (1-26)\n");
        scanf("%d",&odabir);
        odabir--;
    }while(odabir<0 || odabir > 25);
    return odabir;

}
int Provjera(int redOd,int kolOd,int redDo, int kolDo){

    if((kolDo < 9 && kolDo >= 1)&&(redDo < 9 && redDo >= 1))
    {
        if(PolozajFigura[redOd-1][kolOd-1] == BPiun || PolozajFigura[redOd-1][kolOd-1] == WPiun)
            {
                if(((redOd-1+1)==redDo-1 && (kolOd-1)==(kolDo-1))||((redOd-1-1)==(redDo -1) && (kolOd-1)==(kolDo-1)))
                    return 1;
                else
                    return 0;
            }
        else if(PolozajFigura[redOd-1][kolOd-1] == BTop || PolozajFigura[redOd-1][kolOd-1] == WTop){

            if((redDo-1>redOd-1 && kolOd-1==kolDo-1)||(redDo-1<redOd-1 && kolOd-1==kolDo-1))
                return 1;
            else if((kolDo-1>kolOd-1 && redOd-1==redDo-1)||(kolDo-1<kolOd-1 && redOd-1==redDo-1))
                return 1;
            else
                return 0;
        }
        else if(PolozajFigura[redOd-1][kolOd-1] == BKralj || PolozajFigura[redOd-1][kolOd-1] == WKralj )
        {
            if((redOd-1+1)==redDo-1 && kolOd-1==kolDo-1)
                return 1;
            else if((redOd-1-1)==redDo-1 && kolOd-1==kolDo-1)
                return 1;
            else if((kolOd-1+1)==kolDo-1 && redOd-1==redDo-1)
                return 1;
            else if((kolOd-1-1)==kolDo-1 && redOd-1==redDo-1)
                return 1;
            else if((redOd-1+1)==redDo-1 && (kolOd-1+1)==kolDo-1)
                return 1;
            else if((redOd-1+1)==redDo-1 && (kolOd-1-1)==kolDo-1)
                return 1;
            else if((redOd-1-1)==redDo-1 && (kolOd-1-1)==kolDo-1)
                return 1;
            else if((redOd-1-1)==redDo-1 && (kolOd-1+1)==kolDo-1)
                return 1;
            else if((kolOd-1+1)==kolDo-1 && (redOd-1+1)==redDo-1)
                return 1;
            else if((kolOd-1+1)==kolDo-1 && (redOd-1-1)==redDo-1)
                return 1;
            else if((kolOd-1-1)==kolDo-1 && (redOd-1-1)==redDo-1)
                return 1;
            else if((kolOd-1-1)==kolDo-1 && (redOd-1+1)==redDo-1)
                return 1;
            else return 0;
        }
        else if(PolozajFigura[redOd-1][kolOd-1] == BLovac || PolozajFigura[redOd-1][kolOd-1] == WLovac)
            {
               int counter = 1;
               while(counter<9)
               {

                    if(((redOd-1+counter)==redDo-1 && (kolOd-1+counter)==kolDo-1))
                        return 1;
                    else if(((redOd-1+counter)==redDo-1 && (kolOd-1-counter)==kolDo-1))
                        return 1;
                    else if(((redOd-1-counter)==redDo-1 && (kolOd-1+counter)==kolDo-1))
                        return 1;
                    else if(((redOd-1-counter)==redDo-1 && (kolOd-1-counter)==kolDo-1))
                        return 1;
                    counter++;
               }
               return 0;
           }
           else if(PolozajFigura[redOd-1][kolOd-1] == BKraljica || PolozajFigura[redOd-1][kolOd-1] == WKraljica)
            {
               int counter = 1;
               while(counter<9)
               {

                    if(((redOd-1+counter)==redDo-1 && (kolOd-1+counter)==kolDo-1))
                        return 1;
                    else if(((redOd-1+counter)==redDo-1 && (kolOd-1-counter)==kolDo-1))
                        return 1;
                    else if(((redOd-1-counter)==redDo-1 && (kolOd-1+counter)==kolDo-1))
                        return 1;
                    else if(((redOd-1-counter)==redDo-1 && (kolOd-1-counter)==kolDo-1))
                        return 1;
                    counter++;
               }
               if((redDo-1>redOd-1 && kolOd-1==kolDo-1)||(redDo-1<redOd-1 && kolOd-1==kolDo-1))
                    return 1;
               else if((kolDo-1>kolOd-1 && redOd-1==redDo-1)||(kolDo-1<kolOd-1 && redOd-1==redDo-1))
                    return 1;
               return 0;
            }

           else if(PolozajFigura[redOd-1][kolOd-1] == BKonj || PolozajFigura[redOd-1][kolOd-1] == WKonj)
            {
                if((redOd-1+1)==redDo-1 && (kolOd-1+2)==kolDo-1)
                    return 1;
                else if((redOd-1+1)==redDo-1 && (kolOd-1-2)==kolDo-1)
                    return 1;
                else if((redOd-1-1)==redDo-1 && (kolOd-1+2)==kolDo-1)
                    return 1;
                else if((redOd-1-1)==redDo-1 && (kolOd-1-2)==kolDo-1)
                    return 1;
                else if((kolOd-1+1)==kolDo-1 && (redOd-1+2)==redDo-1)
                    return 1;
                else if((kolOd-1+1)==kolDo-1 && (redOd-1-2)==redDo-1)
                    return 1;
                else if((kolOd-1-1)==kolDo-1 && (redOd-1+2)==redDo-1)
                    return 1;
                else if((kolOd-1-1)==kolDo-1 && (redOd-1-2)==redDo-1)
                    return 1;
                else return 0;
            }
    }
}

void Zamjeni(int redOd,int kolOd,int redDo,int kolDo){
    if(PolozajFigura[redOd-1][kolOd-1] == None)
        return;
    //dodaj provjeru
    if(Provjera(redOd,kolOd,redDo,kolDo)==1){

    enum Pozicija poz = Pozicija2D[redOd-1][kolOd-1];//BijeloPolje ili CrnoPolje
    enum Figura f = PolozajFigura[redOd-1][kolOd-1];//TipFigure
    enum Pozicija newPolje;

    Ploca[redOd][kolOd] = init_polje(Ploca[redOd][kolOd], poz);
    if(Pozicija2D[redDo-1][kolDo-1]== PraznoBijelo){
        switch(f){
            case BTop:
                newPolje = BijeloPoljeCrniTop;
                break;
            case WTop:
                newPolje = BijeloPoljeBijeliTop;
                break;
            case WLovac:
                newPolje = BijeloPoljeBijeliLovac;
                break;
            case WKonj:
                newPolje = BijeloPoljeBijeliKonj;
                break;
            case WKralj:
                newPolje = BijeloPoljeBijeliKralj;
                break;
            case WKraljica:
                newPolje = BijeloPoljeBijelaKraljica;
                break;
            case WPiun:
                newPolje = BijeloPoljeBijeliPiun;
                break;
            case BKonj:
                newPolje = BijeloPoljeCrniKonj;
                break;
            case BLovac:
                newPolje = BijeloPoljeCrniLovac;
                break;
            case BKralj:
                newPolje = BijeloPoljeCrniKralj;
                break;
            case BKraljica:
                newPolje = BijeloPoljeCrnaKraljica;
                break;

            case BPiun:
                newPolje = BijeloPoljeCrniPiun;
                break;
        }
    }
    else if(Pozicija2D[redDo-1][kolDo-1] == PraznoCrno) {
 switch(f){
           case BTop:
                newPolje = CrnoPoljeCrniTop;
                break;
            case WTop:
                newPolje = CrnoPoljeBijeliTop;
                break;
            case WLovac:
                newPolje = CrnoPoljeBijeliLovac;
                break;
            case WKonj:
                newPolje = CrnoPoljeBijeliKonj;
                break;
            case WKralj:
                newPolje = CrnoPoljeBijeliKralj;
                break;
            case WKraljica:
                newPolje = CrnoPoljeBijelaKraljica;
                break;
            case WPiun:
                newPolje = CrnoPoljeBijeliPiun;
                break;
            case BKonj:
                newPolje = CrnoPoljeCrniKonj;
                break;
            case BLovac:
                newPolje = CrnoPoljeCrniLovac;
                break;
            case BKralj:
                newPolje = CrnoPoljeCrniKralj;
                break;
            case BKraljica:
                newPolje = CrnoPoljeCrnaKraljica;
                break;
            case BPiun:
                newPolje = CrnoPoljeCrniPiun;
                break;
        }
    }
    //Potrebno dodati jos par else if-ova u kojima bi se definisalo "jedenje figura"(opposite boje) i zabrana "jedenja figura"(same boje)

    Ploca[redOd][kolOd] = init_polje(Ploca[redOd][kolOd], poz);
    Ploca[redDo][kolDo] = init_polje(Ploca[redDo][kolDo], newPolje);
    PolozajFigura[redDo-1][kolDo-1] = PolozajFigura[redOd-1][kolOd-1];
    PolozajFigura[redOd-1][kolOd-1] = None;
    }
    else return;
}

int main()
{
    initPozicija();
	struct Polje p;
	int i, j, dalje, odabir;
	do{
        printf("Unos nove figure? 1 - DA | 0 - NE\n");
        scanf("%d", &dalje);
        if(dalje){
            odabir = meni();
            p = init_polje(p, odabir);
            ispis_polja(p);
        }
	}while(dalje != 0);

    init_ploca();

    ispis_plocu();

    int redOd,redDo,kolOd,kolDo;
    char temp;
    do{
        printf("Unesite red i kolonu OD (1-8 A-H): \r\n");
        scanf("%d %c",&redOd,&temp);
        kolOd = (int)(temp - 'A')+1;
        redOd = 9 - redOd;
        printf("Unesite red i kolonu DO (1-8 A-H): \r\n");
        scanf("%d %c",&redDo,&temp);
        kolDo =(int)(temp-'A')+1;
        redDo = 9-redDo;
        Zamjeni(redOd, kolOd,redDo,kolDo);
        ispis_plocu();
    }while(1);



	system("pause>0");
	return 0;
}
void init_ploca()
{
    int i, j;
    Ploca[0][0] = init_polje(Ploca[0][0],PraznoCrno);
	Ploca[0][1] = init_Spolje(Ploca[0][1],SlovoA);
	Ploca[0][2] = init_Spolje(Ploca[0][2],SlovoB);
	Ploca[0][3] = init_Spolje(Ploca[0][3],SlovoC);
	Ploca[0][4] = init_Spolje(Ploca[0][4],SlovoD);
	Ploca[0][5] = init_Spolje(Ploca[0][5],SlovoE);
	Ploca[0][6] = init_Spolje(Ploca[0][6],SlovoF);
	Ploca[0][7] = init_Spolje(Ploca[0][7],SlovoG);
	Ploca[0][8] = init_Spolje(Ploca[0][7],SlovoH);

	Ploca[1][1] = init_polje(Ploca[1][1],BijeloPoljeCrniTop);
	Ploca[1][2] = init_polje(Ploca[1][2],CrnoPoljeCrniKonj);
	Ploca[1][3] = init_polje(Ploca[1][3],BijeloPoljeCrniLovac);
	Ploca[1][4] = init_polje(Ploca[1][4],CrnoPoljeCrnaKraljica);
	Ploca[1][5] = init_polje(Ploca[1][5],BijeloPoljeCrniKralj);
	Ploca[1][6] = init_polje(Ploca[1][6],CrnoPoljeCrniLovac);
	Ploca[1][7] = init_polje(Ploca[1][7],BijeloPoljeCrniKonj);
	Ploca[1][8] = init_polje(Ploca[1][8],CrnoPoljeCrniTop);
    Ploca [1][0] = init_Spolje(Ploca[1][0],BrojOsam);
    Ploca [2][0] = init_Spolje(Ploca[2][0],BrojSedam);
    for(j = 1;j<9;j++){
        if(j%2==0)
            Ploca[2][j] = init_polje(Ploca[2][j],BijeloPoljeCrniPiun);
        else
            Ploca[2][j] = init_polje(Ploca[2][j],CrnoPoljeCrniPiun);
    }
    Ploca [3][0] = init_Spolje(Ploca[3][0],BrojSest);
    Ploca [4][0] = init_Spolje(Ploca[4][0],BrojPet);
    Ploca [5][0] = init_Spolje(Ploca[5][0],BrojCetiri);
    Ploca [6][0] = init_Spolje(Ploca[6][0],BrojTri);
    for(i = 3; i<8;i++)
    {
        for(j = 1; j<9;j++)
        {
            if(i%2!=0)
            {
                if(j%2==0)
                    Ploca[i][j] = init_polje(Ploca[i][j],PraznoCrno);
            else
                    Ploca[i][j] = init_polje(Ploca[1][j],PraznoBijelo);
            }
            else{
                if(j%2==0)
                    Ploca[i][j] = init_polje(Ploca[1][j],PraznoBijelo);
                else
                    Ploca[i][j] = init_polje(Ploca[i][j],PraznoCrno);
            }
        }

    }
    Ploca [7][0] = init_Spolje(Ploca[7][0],BrojDva);
    for(j = 1;j<9;j++){
        if(j%2==0)
            Ploca[7][j] = init_polje(Ploca[7][j],CrnoPoljeBijeliPiun);
        else
            Ploca[7][j] = init_polje(Ploca[7][j],BijeloPoljeBijeliPiun);

}
    Ploca[8][0] = init_Spolje(Ploca[8][0],BrojJedan);
    Ploca[8][1] = init_polje(Ploca[7][0],CrnoPoljeBijeliTop);
    Ploca[8][2] = init_polje(Ploca[7][1],BijeloPoljeBijeliKonj);
    Ploca[8][3] = init_polje(Ploca[7][2],CrnoPoljeBijeliLovac);
    Ploca[8][4] = init_polje(Ploca[7][3],BijeloPoljeBijelaKraljica);
    Ploca[8][5] = init_polje(Ploca[7][4],CrnoPoljeBijeliKralj);
    Ploca[8][6] = init_polje(Ploca[7][5],BijeloPoljeBijeliLovac);
    Ploca[8][7] = init_polje(Ploca[7][6],CrnoPoljeBijeliKonj);
    Ploca[8][8] = init_polje(Ploca[7][7],BijeloPoljeBijeliTop);

}
void ispis_plocu(){

    int i,j,k,n;
    for(i = 0; i< 9 ; i++)
    {
        for(j = 0; j<8; j++)
        {
            for(n=0;n<9;n++)
            {
                for(k=0;k<16;k++){
                   printf("%c",Ploca[i][n].polje[j][k]);
                }
            }
            printf("\n");
        }

    }

}


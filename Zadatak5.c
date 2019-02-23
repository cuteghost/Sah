#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = mkdir("Zadaca5Folder");
    n = chdir("Zadaca5Folder");
    FILE * file = fopen("1. Zadatak - Makroi.c","w");
    const char * tekstPrvogZadatka = {"#include <stdio.h>#include \"popravni.h\"int main(){    int x,y,i, maxi,fakt=1;printf(\"Unesite dva broja:\n\");scanf(\"%d%d\",&x,&y);maxi=MAX(x,y);printf(\"Maximalan je: %d\", maxi);for(i=1;i<=maxi;i++){fakt=fakt*i;}printf(\"\nFaktorijel je: %d\", fakt);printf(\"\nFaktorijel oktalno je %o,\n a heksadecimalno %x\",fakt,fakt);int aski;aski=fakt%128;printf(\"\n Rezultat je:%c\", aski);printf(\"\nIme datoteke u kojoj se radi je:\n %s,\n\n a trenutni datum i vrijeme su:\n %s  %s\",__FILE__,__DATE__,__TIME__);return 0;}"};
    fputs(tekstPrvogZadatka,file);
    fclose(file);
    file = fopen("2. Zadatak - Nizovi i Stringovi.c","w");
    const char * tekstDrugogZadatka = {"#include<stdio.h>#include]\"popravni.h\"intmain(){//aunsignedcharime[]=\"GoranMadzarevic\";inti,j,k;for(i=0;i<strlen(ime);i++){ime[i]=3*ime[i];printf(\"%c\",ime[i]);}printf(\"\n\n\n\");//bintsuma=0;for(i=0;i<strlen(ime);i++){printf(\"Ime[%d]je:%d\n\",i,ime[i]);suma+=ime[i];}printf(\"Sumaje:%d\n\",suma);//ccharstr[100];printf(\"\nUnesitestring:\");gets(str);intduzina=strlen(str)-1;charpom_str[duzina+1];pom_str[duzina]='\0';strncpy(pom_str,str,duzina);strrev(pom_str);strcat(str,pom_str);printf(\"\nPalindromje:%s\",str);//dpalindrom3(str);return0;}"};
    fputs(tekstDrugogZadatka,file);
    fclose(file);
    file = fopen("3. Zadatak - Matrice i Pokazivaci.c", "w");
    const char * tekstTrecegZadatka = {"#include<stdio.h>#include\"popravni.h\"#include<string.h>intmain(){floatA[2][3]={{1.1,2.2,3.3},{4.4,5.5,6.6}};floatB[3][2]={{1.6,2.5},{3.4,4.3},{5.2,6.1}};floatC[2][2],D[3][3],E[3][3];inti,j;//C=AXBC[0][0]=A[0][0]*B[0][0]+A[0][1]*B[1][0]+A[0][2]*B[2][0];C[0][1]=A[0][0]*B[0][1]+A[0][1]*B[1][1]+A[0][2]*B[2][1];C[1][0]=A[1][0]*B[0][0]+A[1][1]*B[1][0]+A[1][2]*B[2][0];C[1][1]=A[1][0]*B[0][1]+A[1][1]*B[1][1]+A[1][2]*B[2][1];for(i=0;i<2;i++){for(j=0;j<2;j++){printf(\"%7.2f\",C[i][j]);}printf(\"\n\");}printf(\"\n\n\");//D=BxAfor(i=0;i<3;i++){for(j=0;j<3;j++){*(*(D+i)+j)=*(*(B+i)+0)**(*(A+0)+j)+*(*(B+i)+1)**(*(A+1)+j);}}for(i=0;i<3;i++){for(j=0;j<3;j++){printf(\"%7.2f\",*(*(D+i)+j));}printf(\"\n\");}printf(\"\n\n\");//E=C+Dfor(i=0;i<3;i++){for(j=0;j<3;j++){if(i==2)*(*(E+i)+j)=*(*(D+i)+j);elseif(j==2)*(*(E+i)+j)=*(*(D+i)+j);else*(*(E+i)+j)=*(*(C+i)+j)+*(*(D+i)+j);printf(\"%7.2f\",*(*(E+i)+j));}printf(\"\n\");}printf(\"\n\n\");zamijeni(*E,*(E+2)+2);for(i=0;i<3;i++){for(j=0;j<3;j++){printf(\"%7.2f\",*(*(E+i)+j));}printf(\"\n\");}return0;}"}
    fputs(tekstTrecegZadatka,file);
    fclose(file);
    file = fopen("4. Zadatak - Dinamicka Alokacija Memorije i Datoteka", "w");
    const char * tekstCetvrtogZadatka = {"#include<stdio.h>#include\"popravni.h\"#include<stdlib.h>intmain(){//aintbroj,i;structcvor*trenutni=NULL;structcvor*prvi=NULL;structcvor*glava=NULL;charime[20];printf(\"Unesitesvojeime(MAX20):\");gets(ime);trenutni=(structcvor*)malloc(sizeof(structcvor));if(trenutni==NULL)return1;glava=prvi=trenutni;for(i=0;i<strlen(ime);i++){trenutni->sljedeci=(structcvor*)malloc(sizeof(structcvor));//napravinovicvor(sljedeci)if(trenutni==NULL)return1;trenutni->slovo=ime[i];//dodijelivrijednostustrukturicvora(trenutni)-uovomslucajuslovotrenutni=trenutni->sljedeci;//pomjeripokazivactrenutninasljedecicvortrenutni->sljedeci=NULL;//PostavipokazivackojijeustrukturinovostvorenogcvoranasljedecicvornaNULL}printaj_listu(prvi);//bstructcvor*pomocni=prvi;for(i=0;i<(strlen(ime)-1);i++){//printf(\"%c\",prvi->slovo);pomocni=pomocni->sljedeci;}pomocni->sljedeci=prvi;pomocni=prvi;prvi=prvi->sljedeci;pomocni->sljedeci=NULL;printaj_listu(prvi);//cFILE*p;p=fopen(\"lista.dat\",\"w+\");if(p==NULL)printf(\"Datotekanijeotvorena\");for(i=0;i<strlen(ime);i++){fwrite(&prvi->slovo,1,sizeof(char),p);prvi=prvi->sljedeci;}fclose(p);printf(\"Problemnijeuc\n\");//dstructcvor*citaj;charslovo1;p=fopen(\"lista.dat\",\"r\");if(p==NULL)printf(\"Datotekanijeotvorena\");while(fread(&slovo1,sizeof(char),1,p)==1)printf(\"\nIzlista.dat:%c\",slovo1);fclose(p);return0;}"}
    fputs(tekstCetvrtogZadatka,file);
    fclose(file);
    file = fopen("Header fajl - popravni.h", "w");
    const char * tekstHeaderFile = {"#ifndefPOPRAVNI_H_INCLUDED#definePOPRAVNI_H_INCLUDED#include<string.h>#defineMAX(X,Y)((X)>(Y)?(X):(Y))voidpalindrom3(charstr1[]){inti,j;charpom_str[strlen(str1)];for(i=0,j=0;i<=strlen(str1);i++,j++){pom_str[j]=str1[i];if((i+1)%3==0)j--;}printf(\"\n\n%s\",pom_str);}voidzamijeni(float*jedan,float*dva){floatpomocni;pomocni=*jedan;*jedan=*dva;*dva=pomocni;}structcvor{charslovo;intbroj;structcvor*sljedeci;};voidprintaj_listu(structcvor*glava){do{printf(\"Slovo:%c\n\",glava->slovo);glava=glava->sljedeci;}while(glava!=NULL);}#endif//POPRAVNI_H_INCLUDED"}
    fputs(file,tekstHeaderFile);
    fclose(file);
    return 0;
}

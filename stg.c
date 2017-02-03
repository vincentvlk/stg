#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include <time.h>

#define MAX_DLZKA 246

char  ident[9];

int   generuj(int i);
void  gen_task(int narocnost, int pocet);
void  gen_file(int narocnost, int testov, int otazok);
int   gen_mask(int dlzka);
char* gen_ident();
int   prevod(char retaz[255]);
int   mocnina(int x, int n);
void  vypis_uvod();
void  vypis_narocnost();

int main()
{
  //---------------------------
  srand(time(NULL)); // zabezpecuje nahodne generovanie
  //---------------------------
  char znaky[255];
  int testov = 0, otazok = 0, narocnost = 0;
  
  do {
  
      vypis_uvod();
          
      switch(_getch()) {
      
      case 'p':
      case 'P':
           
      do {
               
           printf("\n\nZadajte pocet OTAZOK (MIN 1, MAX 100): ");
           scanf("%s", znaky);
           otazok = prevod(znaky);
  
           vypis_narocnost();
           scanf("%s", znaky);
           narocnost = prevod(znaky);
           
      if (narocnost < 1 || narocnost > 3 || otazok < 1 || otazok > 100)
           printf("\nZADALI STE PARAMETER MIMO RELEVANTNYCH HODNOT!\n");
      
       }
         while (narocnost < 1 || narocnost > 3 || otazok < 1 || otazok > 100);     
    
      gen_task(narocnost, otazok);
      
      break;
      
      case 'g':
      case 'G':
           
      do { 
           printf("\t\n\nZadajte pocet TESTOV (MIN 1, MAX 100): ");
           scanf("%s", znaky);
           testov = prevod(znaky);
           //printf("testov: %d", testov);
  
           printf("\t\nZadajte pocet OTAZOK (MIN 1, MAX 100): ");
           scanf("%s", znaky);
           otazok = prevod(znaky);
  
           vypis_narocnost();
           scanf("%s", znaky);
           narocnost = prevod(znaky);
      
           if (narocnost < 1 || narocnost > 3 ||testov < 1 || testov > 100 || otazok < 1 || otazok > 100)
           printf("\nZADALI STE PARAMETER MIMO RELEVANTNYCH HODNOT !\n");
 
           }
           while (narocnost < 1 || narocnost > 3 || testov < 1 || testov > 100 || otazok < 1 || otazok > 100);
  
           gen_file(narocnost, testov, otazok);
           
           break;
      
      case 'k':
      case 'K':
      
      printf("\n\n\t\t---KONIEC PROGRAMU---\n\n");
      printf("\n\t\t---DAKUJEM ZE STE POUZILI MOJ PROGRAM---\n\n");
      system("pause");
      return 0;
      
      default:
              break;  
      }   
     
     }
  
  while(1);
   
  printf("\n\n\t\t---KONIEC PROGRAMU---\n\n");
  system("pause");
  return 0;
}
//------------------------------------------------------------------------------
//-------------------------POUZITE FUNKCIE--------------------------------------
//------------------------------------------------------------------------------
//--------------------FUNKCIA VYPISE ZOZNAM NAROCNOSTI--------------------------
void vypis_narocnost()
{
   printf("\nNAROCNOST: 1 - Generuje zadanie s dlzkou masky /24 a viac");
   printf("\nNAROCNOST: 2 - Generuje zadanie s dlzkou masky /16 a viac");
   printf("\nNAROCNOST: 3 - Generuje zadanie s dlzkou masky /8 a viac");
   printf("\t\n\nZadajte NAROCNOST(MIN 1, MAX 3): ");  
 }
//------------------------PEVADZA RETAZEC NA CELE CISLO-------------------------
int prevod(char retaz[255])
{
    unsigned int i = 0;
    int vysledok = 0;
    for(i = 0; i <= strlen(retaz)-1; i++) 
    {
          vysledok *= 10;
          if ((retaz[i] - 48) >= 0 && (retaz[i] - 48) <= 9)
          vysledok = vysledok + (retaz[i] - 48); //ak to nie je cislo, vrat 0
          else vysledok = 0;
          }
    return vysledok;

}
//------------GENERUJE NAHODNE CISLO V ROZSAHU PODLA PARAMETRA------------------
int generuj(int i)
{
  int j = (rand()%i);
  return j;
}
//----------------FUNKCIA NA VYPOCET CELOCISELNEJ MOCNINY-----------------
int mocnina(int x, int n)
{
int vys;
for (vys = 1; n > 0; --n)
    vys *= x;
return vys;
}
//---------------FUNKCIA VYPISE UVITANIE---------------------
void vypis_uvod()
{
system("cls");
printf("-------------------------------------------------------------------");
printf("-------------");
printf("\tVITAJTE V PROGRME \"STG\" - SUBNETTING TEST GENERATOR\n");
printf("-------------------------------------------------------------------");
printf("-------------\n");
printf("\n\tHLAVNA PONUKA:\t(p)recvicovanie na obrazovke\n");
printf("\t\t\t(g)enerovanie testov do suboru\n\t\t\t(k)oniec programu\n\n");
printf("\t   Vasa VOLBA:  ");
}
//---------------FUNKCIA GENERUJE PRECVICOVANIE NA OBRAZOVKU--------------------
void gen_task(int narocnost, int pocet)
{
   int A=0,B=0,C=0,D=0, maskA=0, maskB=0, maskC=0, maskD=0;
   int zaklad=0;
   int Opodsiete=0, Obroadcast=0, adries=0;
   int i=0;
   int c = 0;
   
   system("cls");
   
   for (i = 1; i <= pocet; i++) { 
   
       int volba1 = generuj(narocnost);
       int volba2 = generuj(12);
       int volba3 = generuj(5);
       short tvar = 0;
       int pocet = generuj(7);
       int sum = gen_mask(pocet);
   
   switch (volba1) {

     case 0:
     zaklad = 24;
     A = generuj(254)+1;
     B = generuj(254)+1;
     C = generuj(254)+1;
     D = generuj(253)+1;
     if (sum != 0){
       while((D == (D&sum)) || (D == (D | (~sum+256)))){
    
       D = generuj(253)+1;
      }
    }
     maskA = 255; maskB = 255; maskC=255; maskD = sum;
     Opodsiete = D & sum;
     Obroadcast = D | (~sum+256);
     adries = ((D | (~sum+256)) - (D & sum)) - 1;
     break;
  
     case 1:
     zaklad = 16;
     A = generuj(254)+1;
     B = generuj(254)+1;
     C = generuj(253)+2;
     D = generuj(254)+1;
     switch (volba3) {
            case 0:
                 sum = 254;
                 pocet = 7;
                 break;
            case 1:
            case 2:
            case 3:
            case 4:
                 while((C == (C&sum)) || (C == (C | (~sum+256)))){
                 
                 C = generuj(253) + 2;
                 }
                 break;
            }     
  
     maskA = 255; maskB = 255; maskC = sum; maskD = 0;
     Opodsiete = C & sum;
     Obroadcast = C | (~sum+256);
     adries = ((((C | (~sum+256)) - (C & sum)) + 1)*256) - 2;
     break;
  
     case 2:
     zaklad = 8;
     A = generuj(254)+1;
     B = generuj(253)+2;
     C = generuj(254)+1;
     D = generuj(254)+1;
     switch (volba3) {
         case 0:
              sum = 254;
              pocet = 7;
              break;
         case 1:
         case 2:
         case 3:
         case 4:
              while((B == (B&sum)) || (B == (B | (~sum+256)))){
              
              B = generuj(253) + 2;
              }
              break;
         }     
  
     maskA = 255; maskB = sum; maskC = 0; maskD = 0;
     Opodsiete = B & sum;
     Obroadcast = B | (~sum+256);
     adries = ((((B | (~sum+256)) - (B & sum)) + 1)*256*256) - 2;
     break;
}

        printf("\n----------------OTAZKA c.%d------------\n", i);

switch (volba2) {
    case 0:
    
    printf("\nAka je adresa siete a broadcast adresa ");
    printf("pre adresu stanice s dlzkou masky ?");
    tvar = 0;
    break;
    
    case 1:
    
    printf("\nAka je adresa siete a broadcast adresa ");
    printf("pre adresu stanice s maskou podsiete ?");
    tvar = 1;
    break;
    
    case 2:
    
    printf("\nAka je -BROADCAST- adresa podsiete ");
    printf("pre danu adresu stanice a masku podsiete ?"); 
    tvar = 1;
    break;
    
    case 3:
    
    printf("\nAka je -BROADCAST- adresa podsiete ");
    printf("pre danu adresu stanice a dlzku masky ?");
    tvar = 0;
    break;
    
    case 4:
    
    printf("\nDo akej -PODSIETE- patri adresa ");
    printf("stanice s maskou podsiete ?"); 
    tvar = 1;
    break;
    
    case 5:
    
    printf("\nDo akej -PODSIETE- patri adresa ");
    printf("stanice so zadanou dlzkou masky ?");
    tvar = 0;
    break;
    
    case 6:
    
    printf("\nAka je -POSLEDNA- platna adresa -STANICE- ");
    printf("v podsieti,\nkde sa nachadza adresa s maskou podsiete ?"); 
    tvar = 1;
    break;
    
    case 7:
    
    printf("\nAka je -POSLEDNA- platna adresa -STANICE- ");
    printf("v podsieti,\nkde sa nachadza adresa so zadanou dlzkou masky ?");
    tvar = 0;
    break;
    
    case 8:
    
    printf("\nKolko -POUZITELNYCH- adries pre -STANICE- ");
    printf("poskytuje podsiet,\nkde sa nachadza adresa s maskou podsiete ?"); 
    tvar = 1;
    break;
    
    case 9:
    
    printf("\nKolko -POUZITELNYCH- adries pre -STANICE- poskytuje ");
    printf("podsiet,\nkde sa nachadza adresa so zadanou dlzkou masky ?");
    tvar = 0;
    break;
    
    case 10:
    
    printf("\nAka je -PRVA- platna adresa -STANICE- ");
    printf("v podsieti,\nkde sa nachadza adresa s maskou podsiete ?"); 
    tvar = 1;
    break;
    
    case 11:
    
    printf("\nAka je -PRVA- platna adresa -STANICE- ");
    printf("v podsieti,\nkde sa nachadza adresa so zadanou dlzkou masky ?");
    tvar = 0;
    break;
    }
    if (tvar == 0) {
             printf("\n\n\t%d.%d.%d.%d /%d", A, B, C, D, pocet+zaklad);
             }
    else printf("\n\n\t%d.%d.%d.%d %d.%d.%d.%d",A,B,C,D,maskA,maskB,maskC,maskD);
    
    printf("\t[Pre riesenie stlacte klaves \"ENTER\"]\n\n");
    
    do
    ;
    while (_getch() != 13);
    switch (volba1) {
    case 0:
    printf("\n----------------RIESENIE--------------\n");
    printf("\n\nADRESA PODSIETE JE: %d.%d.%d.%d \n", A & 255, B & 255, C & 255, Opodsiete);
    printf("\nBROADCAST ADRESA JE: %d.%d.%d.%d \n", A & 255, B & 255, C & 255, Obroadcast);
    printf("\nPOCET VZNIKNUTYCH PODSIETI : %d\n", mocnina(2,pocet));
    printf("\nPOCET POUZITELNYCH ADRIES V DANEJ PODSIETI: %d\n", adries);
    printf("\nROZSAH POUZITELNYCH ADRIES PRE STANICE JE : ");
    printf("%d.%d.%d.%d - %d.%d.%d.%d\n", A,B,C, Opodsiete+1, A,B,C, Obroadcast-1);
    break;
    case 1:
    printf("\n----------------RIESENIE--------------\n");
    printf("\n\nADRESA PODSIETE JE: %d.%d.%d.%d \n", A & 255, B & 255, Opodsiete, D & 0);
    printf("\nBROADCAST ADRESA JE: %d.%d.%d.%d \n", A & 255, B & 255, Obroadcast, D | 255);
    printf("\nPOCET VZNIKNUTYCH PODSIETI : %d\n", mocnina(2,pocet));
    printf("\nPOCET POUZITELNYCH ADRIES V DANEJ PODSIETI: %d\n", adries);
    printf("\nROZSAH POUZITELNYCH ADRIES PRE STANICE JE : ");
    printf("%d.%d.%d.%d - %d.%d.%d.%d\n", A,B,Opodsiete, 1, A,B,Obroadcast, 254);
    break;
    case 2:
    printf("\n----------------RIESENIE--------------\n");
    printf("\n\nADRESA PODSIETE JE: %d.%d.%d.%d \n", A & 255, Opodsiete, C & 0, D & 0);
    printf("\nBROADCAST ADRESA JE: %d.%d.%d.%d \n", A & 255, Obroadcast, C | 255, D | 255);
    printf("\nPOCET VZNIKNUTYCH PODSIETI : %d\n", mocnina(2,pocet));
    printf("\nPOCET POUZITELNYCH ADRIES V DANEJ PODSIETI: %d\n", adries);
    printf("\nROZSAH POUZITELNYCH ADRIES PRE STANICE JE : ");
    printf("%d.%d.%d.%d - %d.%d.%d.%d\n", A,Opodsiete,0,1, A,Obroadcast,255, 254);
    break;
    }
    printf("\n\n--Pre dalsiu otazku stlacte klaves \"ENTER\"--\n--Alebo \"ESC\" pre navrat do hlavnej ponuky--\n");
    do
    if (c == 27)
    return;
    while ((c = _getch()) != 13);
    system("cls");
    } //toto je ukoncenie for cyklu na pocet otazok
}

//-----------------GENEROVANIE MASKY PODSIETE-------------------
int gen_mask(int dlzka)
{
   short i, j;
   char bin[9];
   int pocet = dlzka;
   int b, k, n;
   int len;
   int sum = 0;
    
    for( i = 0; i <= 7; i++)        
   {
        for (j = 0; j <= pocet-1; j++)
           bin[0 + j] = '1';
        
           bin[pocet + i] = '0';                   
   }
   
   bin[8] = 0; // ukoncujuci znak

//-----------------PREVOD, BIN/DEC-------------------
len = strlen(bin) - 1;
  for(k = 0; k <= len; k++) 
  {
   b = 1;
    n = (bin[k] - '0'); // char to numeric value
     b = b<<(len-k);
    // sum it up
    sum = sum + n * b;
    //printf("%d*%d + ",n,b);  // uncomment to show the way this works
  }
  return(sum);
}
//----------------------FUNKCIA GENERUJE TESTY DO SUBOROV-----------------------
void gen_file(int narocnost, int testov, int otazok)
{
   char nazov_suboru[MAX_DLZKA] = "";
   char povodny_nazov[MAX_DLZKA] = "";
   char povodny2[MAX_DLZKA] = "";
   char *id;
   int chyba;
   FILE* fzadanie;
   FILE* fodpovede;
   gets_s(nazov_suboru);
   do {
       printf("\n\nZADAJTE NAZOV SUBORU: ");
       gets_s(nazov_suboru);
       strcpy_s(povodny_nazov, nazov_suboru);
       strcpy_s(povodny2, nazov_suboru);
       chyba = 0;
       
       if (!strcmp(nazov_suboru,"")) {
         printf("\nSubor sa NEDA OTVORIT, zadajte znova nazov !");
         fzadanie = NULL;
         chyba = 1;
       }
       if ((fzadanie = fopen(strcat(nazov_suboru,".txt"),"rt")) != NULL) {
                     printf("\n POZOR SUBOR %s UZ EXISTUJE !!", nazov_suboru);
                     printf("\n\n Prajete si ho prepisat ? (a)no / ALEBO LUBOVOLNY klaves pre novy nazov\n");
                     switch(_getch()) {
                                     case 'a':
                                     case 'A':
                                       chyba = 0;
                                       break;
                                     
                                     default:
                                       chyba = 1; 
                                       fzadanie = NULL;
                                       break;
                                       }          
                                       
        } // patri k IF
       
       
       if (chyba == 0) {
       fzadanie = fopen(nazov_suboru,"wt");
       if (!fzadanie)
       printf("\nSubor %s sa NEDA OTVORIT, zadajte znova nazov !", nazov_suboru);
       }
     }
     while(fzadanie == NULL);
     printf("\n ZAPISUJEM SUBOR \"%s\" A \"%s[ODPOVED].txt\"", nazov_suboru, povodny_nazov);
   
   fodpovede = fopen(strcat(povodny_nazov,"[ODPOVED].txt"),"wt");
   
   int A=0,B=0,C=0,D=0, maskA=0, maskB=0, maskC=0, maskD=0, i = 0, j = 0;
   int zaklad=0;
   int Opodsiete=0, Obroadcast=0, adries=0; 
   
for (i = 1; i <= testov; i++) {
    
   id = gen_ident();
   fprintf(fzadanie,"\n-=-=-=-=-=-=-=-=-=-=-=-=TEST CISLO %d-=-=-=-=-=-=-=-=-=-=-=-=-=-=", i);
   fprintf(fodpovede,"\n-=-=-=-=-=-=-=-=-=-=-=-=TEST CISLO %d-=-=-=-=-=-=-=-=-=-=-=-=-=-=", i);
   fprintf(fzadanie,"\n\nMENO:______________ PRIEZVISKO:______________\n\nSKUPINA:______________ DATUM:______________\n");
   fprintf(fzadanie,"\nIDENTIFIKATOR TESTU CISLO %d: %s\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=",i, id);
   fprintf(fodpovede,"\nIDENTIFIKATOR TESTU CISLO %d: %s\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=",i, id);
   
   for (j = 1; j <= otazok; j++) {
   
   fprintf(fzadanie,"\n----------------------------------------------------\n");
   fprintf(fzadanie," %d. OTAZKA V TESTE CISLO %d\n", j,i);
   fprintf(fzadanie,"----------------------------------------------------\n");
   fprintf(fodpovede,"\n----------------------------------------------------\n");
   fprintf(fodpovede," %d. OTAZKA V TESTE CISLO %d\n", j,i);
   fprintf(fodpovede,"----------------------------------------------------\n");
   int volba1 = generuj(narocnost);   
   int volba2 = generuj(12);
   int volba3 = generuj(5);
   short tvar = 0;
   int pocet = generuj(7);
   int sum = gen_mask(pocet);
   
switch (volba1) {

  case 0:
  zaklad = 24;
  A = generuj(254)+1;
  B = generuj(254)+1;
  C = generuj(254)+1;
  D = generuj(253)+1;
 if (sum != 0){
  while((D == (D&sum)) || (D == (D | (~sum+256)))){
    
    D = generuj(253)+1;
    }
  }
  maskA = 255; maskB = 255; maskC=255; maskD = sum;
  Opodsiete = D & sum;
  Obroadcast = D | (~sum+256);
  adries = ((D | (~sum+256)) - (D & sum)) - 1;
  break;
  
  case 1:
  zaklad = 16;
  A = generuj(254)+1;
  B = generuj(254)+1;
  C = generuj(253)+2;
  D = generuj(254)+1;
  switch (volba3) {
         case 0:
              sum = 254;
              pocet = 7;
              break;
         case 1:
         case 2:
         case 3:
         case 4:
              while((C == (C&sum)) || (C == (C | (~sum+256)))){
              
              C = generuj(253) + 2;
              }
              break;
         }     
  
  maskA = 255; maskB = 255; maskC = sum; maskD = 0;
  Opodsiete = C & sum;
  Obroadcast = C | (~sum+256);
  adries = ((((C | (~sum+256)) - (C & sum)) + 1)*256) - 2;
  break;
  
  case 2:
  zaklad = 8;
  A = generuj(254)+1;
  B = generuj(253)+2;
  C = generuj(254)+1;
  D = generuj(254)+1;
  switch (volba3) {
         case 0:
              sum = 254;
              pocet = 7;
              break;
         case 1:
         case 2:
         case 3:
         case 4:
              while((B == (B&sum)) || (B == (B | (~sum+256)))){
              
              B = generuj(253) + 2;
              }
              break;
         }     
  
  maskA = 255; maskB = sum; maskC = 0; maskD = 0;
  Opodsiete = B & sum;
  Obroadcast = B | (~sum+256);
  adries = ((((B | (~sum+256)) - (B & sum)) + 1)*256*256) - 2;
  break;
}

switch (volba2) {
    case 0:
    
    fprintf(fzadanie,"\nAka je adresa siete a broadcast adresa ");
    fprintf(fzadanie,"pre adresu stanice s dlzkou masky ?");
    fprintf(fodpovede,"\nAka je adresa siete a broadcast adresa ");
    fprintf(fodpovede,"pre adresu stanice s dlzkou masky ?");
    tvar = 0;
    break;
    
    case 1:
    
    fprintf(fzadanie,"\nAka je adresa siete a broadcast adresa ");
    fprintf(fzadanie,"pre adresu stanice s maskou podsiete ?");
    fprintf(fodpovede,"\nAka je adresa siete a broadcast adresa ");
    fprintf(fodpovede,"pre adresu stanice s maskou podsiete ?");
    tvar = 1;
    break;
    
    case 2:
    
    fprintf(fzadanie,"\nAka je -BROADCAST- adresa podsiete ");
    fprintf(fzadanie,"pre danu adresu stanice a masku podsiete ?");
    fprintf(fodpovede,"\nAka je -BROADCAST- adresa podsiete ");
    fprintf(fodpovede,"pre danu adresu stanice a masku podsiete ?");
    tvar = 1;
    break;
    
    case 3:
    
    fprintf(fzadanie,"\nAka je -BROADCAST- adresa podsiete ");
    fprintf(fzadanie,"pre danu adresu stanice a dlzku masky ?");
    fprintf(fodpovede,"\nAka je -BROADCAST- adresa podsiete ");
    fprintf(fodpovede,"pre danu adresu stanice a dlzku masky ?");
    tvar = 0;
    break;
    
    case 4:
    
    fprintf(fzadanie,"\nDo akej -PODSIETE- patri adresa ");
    fprintf(fzadanie,"stanice s maskou podsiete ?");
    fprintf(fodpovede,"\nDo akej -PODSIETE- patri adresa ");
    fprintf(fodpovede,"stanice s maskou podsiete ?");
    tvar = 1;
    break;
    
    case 5:
    
    fprintf(fzadanie,"\nDo akej -PODSIETE- patri adresa ");
    fprintf(fzadanie,"stanice so zadanou dlzkou masky ?");
    fprintf(fodpovede,"\nDo akej -PODSIETE- patri adresa ");
    fprintf(fodpovede,"stanice so zadanou dlzkou masky ?");
    tvar = 0;
    break;
    
    case 6:
    
    fprintf(fzadanie,"\nAka je -POSLEDNA- platna adresa -STANICE- ");
    fprintf(fzadanie,"v podsieti,\nkde sa nachadza adresa s maskou podsiete ?");
    fprintf(fodpovede,"\nAka je -POSLEDNA- platna adresa -STANICE- ");
    fprintf(fodpovede,"v podsieti,\nkde sa nachadza adresa s maskou podsiete ?");
    tvar = 1;
    break;
    
    case 7:
    
    fprintf(fzadanie,"\nAka je -POSLEDNA- platna adresa -STANICE- ");
    fprintf(fzadanie,"v podsieti,\nkde sa nachadza adresa so zadanou dlzkou masky ?");
    fprintf(fodpovede,"\nAka je -POSLEDNA- platna adresa -STANICE- ");
    fprintf(fodpovede,"v podsieti,\nkde sa nachadza adresa so zadanou dlzkou masky ?");
    tvar = 0;
    break;
    
    case 8:
    
    fprintf(fzadanie,"\nKolko -POUZITELNYCH- adries pre -STANICE- ");
    fprintf(fzadanie,"poskytuje podsiet,\nkde sa nachadza adresa s maskou podsiete ?");
    fprintf(fodpovede,"\nKolko -POUZITELNYCH- adries pre -STANICE- ");
    fprintf(fodpovede,"poskytuje podsiet,\nkde sa nachadza adresa s maskou podsiete ?");
    tvar = 1;
    break;
    
    case 9:
    
    fprintf(fzadanie,"\nKolko -POUZITELNYCH- adries pre -STANICE- ");
    fprintf(fzadanie,"poskytuje podsiet,\nkde sa nachadza adresa so zadanou dlzkou masky ?");
    fprintf(fodpovede,"\nKolko -POUZITELNYCH- adries pre -STANICE- ");
    fprintf(fodpovede,"poskytuje podsiet,\nkde sa nachadza adresa so zadanou dlzkou masky ?");
    tvar = 0;
    break;
    
    case 10:
    
    fprintf(fzadanie,"\nAka je -PRVA- platna adresa -STANICE- ");
    fprintf(fzadanie,"v podsieti,\nkde sa nachadza adresa s maskou podsiete ?");
    fprintf(fodpovede,"\nAka je -PRVA- platna adresa -STANICE- ");
    fprintf(fodpovede,"v podsieti,\nkde sa nachadza adresa s maskou podsiete ?");  
    tvar = 1;
    break;
    
    case 11:
    
    fprintf(fzadanie,"\nAka je -PRVA- platna adresa -STANICE- ");
    fprintf(fzadanie,"v podsieti,\nkde sa nachadza adresa so zadanou dlzkou masky ?");
    fprintf(fodpovede,"\nAka je -PRVA- platna adresa -STANICE- ");
    fprintf(fodpovede,"v podsieti,\nkde sa nachadza adresa so zadanou dlzkou masky ?");
    tvar = 0;
    break;
    }
    
    if (tvar == 0) {
             fprintf(fzadanie,"\n\n\t%d.%d.%d.%d /%d", A, B, C, D, pocet+zaklad);
             fprintf(fodpovede,"\n\n\t%d.%d.%d.%d /%d", A, B, C, D, pocet+zaklad);
             }
    else {
         fprintf(fzadanie,"\n\n\t%d.%d.%d.%d %d.%d.%d.%d",A,B,C,D,maskA,maskB,maskC,maskD);
         fprintf(fodpovede,"\n\n\t%d.%d.%d.%d %d.%d.%d.%d",A,B,C,D,maskA,maskB,maskC,maskD);
         }
    
    fprintf(fzadanie,"\n\n VASA ODPOVED:_____________________________\n");
    fprintf(fzadanie,"\n   HODNOTENIE:_____________________________\n");


    switch (volba1) {
    case 0:
    fprintf(fodpovede,"\n\nRIESENIE:");
    fprintf(fodpovede,"\n\nADRESA PODSIETE JE: %d.%d.%d.%d \n", A & 255, B & 255, C & 255, Opodsiete);
    fprintf(fodpovede,"\nBROADCAST ADRESA JE: %d.%d.%d.%d \n", A & 255, B & 255, C & 255, Obroadcast);
    fprintf(fodpovede,"\nPOCET VZNIKNUTYCH PODSIETI : %d\n", mocnina(2,pocet));
    fprintf(fodpovede,"\nPOCET POUZITELNYCH ADRIES V DANEJ PODSIETI: %d\n", adries);
    fprintf(fodpovede,"\nROZSAH POUZITELNYCH ADRIES PRE STANICE JE : ");
    fprintf(fodpovede,"%d.%d.%d.%d - %d.%d.%d.%d\n", A,B,C, Opodsiete+1, A,B,C, Obroadcast-1);
    break;
    case 1:
    fprintf(fodpovede,"\n\nRIESENIE:");
    fprintf(fodpovede,"\n\nADRESA PODSIETE JE: %d.%d.%d.%d \n", A & 255, B & 255, Opodsiete, D & 0);
    fprintf(fodpovede,"\nBROADCAST ADRESA JE: %d.%d.%d.%d \n", A & 255, B & 255, Obroadcast, D | 255);
    fprintf(fodpovede,"\nPOCET VZNIKNUTYCH PODSIETI : %d\n", mocnina(2,pocet));
    fprintf(fodpovede,"\nPOCET POUZITELNYCH ADRIES V DANEJ PODSIETI: %d\n", adries);
    fprintf(fodpovede,"\nROZSAH POUZITELNYCH ADRIES PRE STANICE JE : ");
    fprintf(fodpovede,"%d.%d.%d.%d - %d.%d.%d.%d\n", A,B,Opodsiete, 1, A,B,Obroadcast, 254);
    break;
    case 2:
    fprintf(fodpovede,"\n\nRIESENIE:");
    fprintf(fodpovede,"\n\nADRESA PODSIETE JE: %d.%d.%d.%d \n", A & 255, Opodsiete, C & 0, D & 0);
    fprintf(fodpovede,"\nBROADCAST ADRESA JE: %d.%d.%d.%d \n", A & 255, Obroadcast, C | 255, D | 255);
    fprintf(fodpovede,"\nPOCET VZNIKNUTYCH PODSIETI : %d\n", mocnina(2,pocet));
    fprintf(fodpovede,"\nPOCET POUZITELNYCH ADRIES V DANEJ PODSIETI: %d\n", adries);
    fprintf(fodpovede,"\nROZSAH POUZITELNYCH ADRIES PRE STANICE JE : ");
    fprintf(fodpovede,"%d.%d.%d.%d - %d.%d.%d.%d\n", A,Opodsiete,0,1, A,Obroadcast,255, 254);
    break;
    }
    
   }
  }
  printf("\n\n ZAPISOVANIE SUBOROV \"%s.txt\" \n\t\t     \"%s\" USPESNE DOKONCENE !", povodny2, povodny_nazov);
  printf("\n\n Pokracutje klavesom \"ENTER\"");
  do
  ;
  while (_getch() != 13);
}

//-----------------FUNCKIA GENERUJE ID TESTU-------------------
char* gen_ident()
{
   char znak = 0;
   short i;
  
   for( i = 7; i >= 0; i--)        
   {
         znak = rand()%126;
         while ((znak < 48 || znak > 57) && (znak < 97 || znak > 122)) {
               znak = rand()%123;
               }
         ident[7 - i] = znak;
                  
   }
   
  ident[8] = 0; // nastavi ukoncujuci znak
  return ident;
}
//----------------------------KONIEC ZDROJOVEHO SUBORU--------------------------

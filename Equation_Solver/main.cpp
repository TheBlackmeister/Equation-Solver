//#include <stdio.h>
#include <math.h> // zakladni knihovna
//#include <string.h>
#include <clocale> // pro ceskou lokalizaci
#include <windows.h> //windows funkce zde (barvy)
#include <stdlib.h> //zakladni knihovna
#include <iostream> // zakladni cout/cin
#include <iomanip> //knihovna pro pevne dana desetinna mista korenu
#include <time.h> // potreba pro nahodna cisla
#include <fstream> //prace se soubory
#include "rescource.h"


using namespace std;
int a,b,c,nahMax,nahMin; float d;   string NAZEVSOUBORU; string NAZEVSOUBORUVYSL; string NAZEVSOUBORUTEMP;
int pocet; int view; int choice = 0;
float r[100][100], zpet[100];
int pocet_radku; string radek; //promenne pro cteni ze souboru

void Gauss() {   //Gaussova eliminace, zpetny chod z adresy: https://www.codesansar.com/numerical-methods/gauss-elimination-method-using-c-plus-plus-output.htm
    for(a=1;a<=pocet-1;a++){

        for(b=a+1;b<=pocet;b++){

            d = r[b][a]/r[a][a]; //d...koeficient
            for(c=1;c<=pocet+1;c++) {
                r[b][c] = r[b][c] - d*r[a][c];

            }


        }
    }
    zpet[pocet] = r[pocet][pocet+1]/r[pocet][pocet];

    for(a=pocet-1;a>=1;a--){
        zpet[a] = r[a][pocet+1];
        for(b=a+1;b<=pocet;b++){

            zpet[a] = zpet[a] - r[a][b]*zpet[b];
        }
        zpet[a] = zpet[a]/r[a][a];
    }


}

void EMPTYSTRINGS() {
NAZEVSOUBORU.clear();
NAZEVSOUBORUVYSL.clear();
NAZEVSOUBORUTEMP.clear();

}

void CramRule(){
float det, detX1,detX2,detX3,ex1,ex2,ex3;
det=(r[1][1]*r[2][2]*r[3][3])+(r[1][2]*r[2][3]*r[3][1])+(r[1][3]*r[2][1]*r[3][2])-(r[1][2]*r[2][1]*r[3][3])-(r[1][1]*r[2][3]*r[3][2])-(r[1][3]*r[2][2]*r[3][1]);
detX1=(r[1][4]*r[2][2]*r[3][3])+(r[1][2]*r[2][3]*r[3][4])+(r[1][3]*r[2][4]*r[3][2])-(r[1][2]*r[2][4]*r[3][3])-(r[1][4]*r[2][3]*r[3][2])-(r[1][3]*r[2][2]*r[3][4]);
detX2=(r[1][1]*r[2][4]*r[3][3])+(r[1][4]*r[2][3]*r[3][1])+(r[1][3]*r[2][1]*r[3][4])-(r[1][4]*r[2][1]*r[3][3])-(r[1][1]*r[2][3]*r[3][4])-(r[1][3]*r[2][4]*r[3][1]);
detX3=(r[1][1]*r[2][2]*r[3][4])+(r[1][2]*r[2][4]*r[3][1])+(r[1][4]*r[2][1]*r[3][2])-(r[1][2]*r[2][1]*r[3][4])-(r[1][1]*r[2][4]*r[3][2])-(r[1][4]*r[2][2]*r[3][1]);
ex1=(detX1/det);
ex2=(detX2/det);
ex3=(detX3/det);

cout << "Chcete vypocitat vsechny koreny? 1 pro vypis vsech, 0 pro konkretn� koren." << endl;
int jeden;
cin >> jeden;
    if (jeden==1){
    cout << "Koreny Rovnice jsou: \n" << endl; ///vypis jednotliv�ch korenu
    cout << "x1 = "<< ex1 <<endl;
    cout << "x2 = "<< ex2 <<endl;
    cout << "x3 = "<< ex3 <<endl;
    cout << "\n \n" <<endl;
    }
        else {
           int jedenn;
           jedenn = 1;
           int volbaX;
         while (jedenn==1) {

            cout << " \n" <<endl;
            cout << "Ktery ze tri korenu chcete vypsat?" <<endl;
            cout << "Nabidka 1,2,3,nula pro hlavni menu" << endl;
            cin >> volbaX;
            switch(volbaX) {
            case 1:
                {cout << "x1 = "<< ex1 <<endl;}
                break;
            case 2:
                {cout << "x2 = "<< ex2 <<endl;}
                break;
            case 3:
                {cout << "x3 = "<< ex3 <<endl;}
                break;
            case 0:
                {cout << "Vracim se do menu" <<endl;
                jedenn=0;}
                break;
            default:
                {cout << "Nespravne cislo!" << endl;}
                break;
            }
         }
        }
}
void NahodnyArray(){

        for(a=1;a<=pocet;a++) { ///ZAPIS POLE

            for(b=1;b<=pocet+1;b++) {
                //cout << "a" << a << "," << b << "=";
                //cin >> r[a][b];
               r[a][b]=rand()%(nahMax-nahMin+1)+nahMin;
            }
        }

}

void VypisX(){
    cout << "Koreny Rovnice jsou: \n" << endl; ///vypis jednotlivych korenu
        for (a=1;a<=pocet;a++){
            cout << "x" << a << "  " << "=" << "  " << zpet[a] << endl;
        }
                            //cin >> a >> b >> c >> d; MINULA VERZE
                            //cout << a   << c   << c   << b   << d   << endl; RADEK PRO ZKOUSKU ZAPISU
        cout << "\n";
}


void Continue(){
                cout << "\n" << endl;
                cout << "Pokracovat?" << endl;
                cout << "Pokud ano, zadej 1 a stiskni ENTER" << endl;
                cout << "Pokud ne, zadej 0 a stiskni ENTER" << endl;
                        cin >> choice;
                cout << "\n \n \n";

}
void VypisArray() {
        for(a=1;a<=pocet;a++) { ///ZAPIS POLE

            for(b=1;b<=pocet+1;b++) {
                cout <<" "<<r[a][b]<<" ";

            }
            cout<<"\n";
        }
}

int main() //HLAVNI FUNKCE ZDE
{       //HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        system("Color F0");
        //system("mode 650");
        ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
        //SetConsoleTextAttribute
        //(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_GREEN | BACKGROUND_BLUE);

        srand (time(NULL)); //aby byla cisla vzdy nahodna v moznosti 3
        setlocale(LC_ALL, ""); // pro ceskou lokalizaci v programu
    ///int choice = 0; Od verze 0.5 presunuto pred funkci main!!!

    do
    {   cout << setprecision(2) << fixed;
        cout << "Program na reseni soustav linearnich rovnic \n "  << endl;
        cout << "Program pocita pomoci Gaussovy eliminace, popripade Cramerovym pravidlem\n" << endl;
        cout << "Vyber 1-3, '0' pro ukonceni: \n \n" << endl;
        cout << "1. Rucni zadani" << endl;
        cout << "2. Zadani ze souboru" << endl;
        cout << "3. Nahodna cisla (s vyberem hranice)" << endl;
        cout << "4. Cramerovo pravidlo pro 3 rovnice" << endl;
        cout << "0. Ukonceni programu" << endl;
        cout << "zadej volbu:" << endl;
            cin >> choice;

        switch (choice)  //MENU
        {
        case 1:
                cout << "Rucni zadani vybrano \n" << endl;
                cout << "Zadej pocet rovnic:" << endl;
                    cin >> pocet;
                cout << "Misto zadavani celeho tvaru rovnice zadej pouze vzdy promennou, oddeluj enterem \n" << endl;
                cout << "Zadej promenne: \n" << endl;
                    for(a=1;a<=pocet;a++) { ///ZAPIS POLE

                        for(b=1;b<=pocet+1;b++) {
                            cout << "a" << a << "," << b << "=";
                            cin >> r[a][b];
                        }
                    }

                cout << "Chcete zapsat soustavu do souboru? 1 pro zapis, 0 pro preskoceni kroku." << endl; ///zapis do souboru zde
                        int Dosouboruu;
                        cin >> Dosouboruu;
                        if (Dosouboruu == 1){
                            cout << "Zadej nazev souboru: (bez pripony .txt, nebo .dat, doplni se automaticky:" << endl;
                            //string NAZEVSOUBORU;
                            cin >> NAZEVSOUBORU;
                            NAZEVSOUBORUTEMP = NAZEVSOUBORU;
                            NAZEVSOUBORU = NAZEVSOUBORU + ".txt";
                            ofstream SouborZapis(NAZEVSOUBORU);
                                for (a=1;a<=pocet;a++) {
                                    if (a>1){SouborZapis << endl;}
                                    for(b=1;b<=pocet+1;b++){
                                        SouborZapis << r[a][b];
                                        SouborZapis << "  ";
                                    }

                                }
                            SouborZapis.close();
                            cout << "Soubor " << NAZEVSOUBORU << " byl uspesne vytvoren a soustava zapsana" << endl;
                        }

                system("pause");



                Gauss(); ///odkaz na funkci Gaussovy eliminace
                VypisX();
                        if (Dosouboruu == 1) {
                            cout << "Chcete vypsat koreny do souboru?" << endl;
                            int vypsatkoreny;
                            cin >> vypsatkoreny;
                            if (vypsatkoreny == 1) {
                                NAZEVSOUBORUVYSL = NAZEVSOUBORUTEMP + "Vysledky.txt";
                                ofstream SouborZapiss(NAZEVSOUBORUVYSL);
                                //for(a=1;a<=pocet;a++){SouborZapiss << "\n";}
                                SouborZapiss << "Koreny Rovnice jsou: \n" << endl; ///vypis jednotliv�ch korenu
                                        for (a=1;a<=pocet;a++){
                                            SouborZapiss << "x" << a << "  " << "=" << "  " << zpet[a] << endl;
                                        }
                            SouborZapiss.close();
                            cout << "Koreny vypsany do souboru" << " " << NAZEVSOUBORUVYSL << "." << endl;
                            }
                        }     ///NEDORESENO
                EMPTYSTRINGS();

                Continue();

            break;

        case 2:
        {   cout << "Zadani ze souboru vybrano" << endl;
            cout << "Zadej nazev souboru: (bez pripony .txt, nebo .dat, doplni se automaticky:" << endl;
                cin >> NAZEVSOUBORU;
                    NAZEVSOUBORUTEMP = NAZEVSOUBORU;
                    NAZEVSOUBORU = NAZEVSOUBORU + ".txt";
            ifstream SRead(NAZEVSOUBORU);
                if(SRead.fail()) { ///*je soubor k nalezeni?
                cout << "\n" << NAZEVSOUBORU << " neexistuje, nebo program nema k souboru pristup!" << endl;
                cout << "\n" << endl;
                system("pause");
                cout << "\n" << endl;
                cout << "Vracim se do hlavni nabidky:" << "\n \n \n" << endl;
                SRead.close();
                EMPTYSTRINGS();
                break;
                }///konec chybove zpravy

            while(!SRead.eof()){//zjisteni poctu rovnic/RADKU!!!
                getline(SRead,radek);
                cout << radek << endl;
                pocet_radku++;
            }
                SRead.close();
                cout << "Pocet soustav:" << pocet_radku << "\n \n" << endl;
                pocet = pocet_radku;
                cout << "Nacitani soustavy do pole..." << endl;
                    ifstream SSRead(NAZEVSOUBORU);
                    for (a=1;a<=pocet;a++) {
                            for(b=1;b<=pocet+1;b++){
                                SSRead >> r[a][b];
                    }
                            }
                SRead.close();
                cout << "Hotovo" << endl;
                cout << "Chcete soustavu vyresit? 1 pro ANO, 0 pro NE." << endl;
                    int res;
                    cin >> res;
                    if(res==1) {
                        //VypisArray();
                        //system("pause");
                        Gauss();


                        VypisX();

                            cout << "Chcete vypsat koreny do souboru?" << endl;
                            int vypsatkoreny;
                            cin >> vypsatkoreny;
                            if (vypsatkoreny == 1) {
                                NAZEVSOUBORUVYSL = NAZEVSOUBORUTEMP + "Vysledky.txt";
                                ofstream SouborZapiss(NAZEVSOUBORUVYSL);
                                //for(a=1;a<=pocet;a++){SouborZapiss << "\n";}
                                SouborZapiss << "Koreny rovnice jsou: \n" << endl; ///vypis jednotliv�ch korenu
                                        for (a=1;a<=pocet;a++){
                                            SouborZapiss << "x" << a << "  " << "=" << "  " << zpet[a] << endl;
                                        }
                            SouborZapiss.close();
                            cout << "Koreny vypsany do souboru" << " " << NAZEVSOUBORUVYSL << "." << endl;
                            }
                        EMPTYSTRINGS();



                        Continue();


                        pocet_radku = 0;
                        break;
                    }
                    else{
                        cout << "Soustava ulozena v poli." << endl;
                      /*  cout << "Chcete zapsat soustavu do souboru? 1 pro z�pis, 0 pro p�esko�en� kroku." << endl;
                        int Dosouboruu;
                        cin >> Dosouboruu;
                        if (Dosouboruu == 1){
                            cout << "Zadej n�zev souboru: (bez p��pony .txt, nebo .dat, vytvo�� se automaticky:" << endl;
                            //string NAZEVSOUBORU;
                            cin >> NAZEVSOUBORU;
                            NAZEVSOUBORUTEMP = NAZEVSOUBORU;
                            NAZEVSOUBORU = NAZEVSOUBORU + ".txt";
                            ofstream SouborZapis(NAZEVSOUBORU);
                                for (a=1;a<=pocet;a++) {
                                    if (a>1){SouborZapis << endl;}
                                    for(b=1;b<=pocet+1;b++){
                                        SouborZapis << r[a][b];
                                        SouborZapis << "  ";
                                    }

                                }
                            SouborZapis.close();
                            cout << "Soubor " << NAZEVSOUBORU << " byl �sp�sn� vytvo�en a soustava zaps�na" << endl;

                            */
                        EMPTYSTRINGS();
                        }

                        system("pause");
                        cout << "\n \n \n";
                        pocet_radku = 0;
                        break;
                    }

        case 3: {
            cout << "Nahodne generovana soustava vybrana" << endl;
            cout << "Zadej mezni hodnoty pro generaci nahodnych promennych:" << endl;
            cout << "Nejvyssi:" << endl;
                cin >> nahMax;
            cout << endl;
            cout << "Nejnizsi: (muze byt nula)" << endl;
                cin >> nahMin;
            cout << "Zadej pocet rovnic:" << endl;
                cin >> pocet;
            NahodnyArray(); //vytvoreni nahodneho pole (matice)
            cout << "\n Chcete zobrazit soustavu? 1 pro zobrazeni, 0 pro preskoceni kroku." << endl;
                cin >> view;
                if(view == 1) {
                    cout<<"Vypis soustavy:" << endl;
                    VypisArray();

                }
                    cout<<" \n \n Chcete zapsat soustavu do souboru? 1 pro zapis, 0 pro preskoceni kroku." << endl;
                    int Dosouboru;
                    cin >> Dosouboru;
                    if (Dosouboru == 1){
                        cout << "Zadej nazev souboru: (bez pripony .txt, nebo .dat, doplni se automaticky:" << endl;
                        cin >> NAZEVSOUBORU;
                            NAZEVSOUBORUTEMP = NAZEVSOUBORU;
                            NAZEVSOUBORU = NAZEVSOUBORU + ".txt";
                            ofstream NahodnaSoustava(NAZEVSOUBORU);
                        for (a=1;a<=pocet;a++) {
                            if (a>1){NahodnaSoustava << endl;}
                            for(b=1;b<=pocet+1;b++){
                                NahodnaSoustava << r[a][b];
                                NahodnaSoustava << "  ";
                            }

                        }
                    NahodnaSoustava.close();
                    cout << "Soubor " << NAZEVSOUBORU << " byl uspesne vytvoren a soustava zapsana" << endl;
                    }
                    system("pause");


            Gauss();
            VypisX();

                        if (Dosouboru == 1) {
                            cout << "Chcete vypsat koreny do souboru?" << endl;
                            int vypsatkoreny;
                            cin >> vypsatkoreny;
                            if (vypsatkoreny == 1) {
                                NAZEVSOUBORUVYSL = NAZEVSOUBORUTEMP + "Vysledky.txt";
                                ofstream SouborZapiss(NAZEVSOUBORUVYSL);
                                //for(a=1;a<=pocet;a++){SouborZapiss << "\n";}
                                SouborZapiss << "Koreny rovnice jsou: \n" << endl; ///vypis jednotliv�ch korenu
                                        for (a=1;a<=pocet;a++){
                                            SouborZapiss << "x" << a << "  " << "=" << "  " << zpet[a] << endl;
                                        }
                            SouborZapiss.close();
                            cout << "Koreny vypsany do souboru" << " " << NAZEVSOUBORUVYSL << "." << endl;
                            }
                        }

            EMPTYSTRINGS();

            Continue();
        }
            break;
        case 4:
            {
                cout << "\n \n" << endl;
                cout << "Cramerovo pravidlo vybrano" << endl;
                pocet = 3;
                cout << "     Jak chcete zadat soustavu?" << endl;
                cout << "     1. Rucni zadani" << endl;
                cout << "     2. Zadani ze souboru" << endl;
                cout << "     3. Nahodna cisla (s vyberem hranice)" << endl;
                cout << "     0. N�vrat do hlavn�ho menu" << endl;

                int volbaCram;
                cin >> volbaCram;
                switch (volbaCram)
                {


                case 1: {
                    cout << "Rucni zadani vybrano \n" << endl;
                    cout << "Misto zadavani celeho tvaru rovnice zadej pouze vzdy promennou, oddeluj enterem \n" << endl;
                    cout << "Zadej promenne: \n" << endl;
                    for(a=1;a<=pocet;a++) { ///ZAPIS POLE

                        for(b=1;b<=pocet+1;b++) {
                            cout << "a" << a << "," << b << "=";
                            cin >> r[a][b];
                        }
                    }

                cout << "Chcete zapsat soustavu do souboru? 1 pro zapis, 0 pro preskoceni kroku." << endl; ///zapis do souboru zde
                        int Dosouboruu;
                        cin >> Dosouboruu;
                        if (Dosouboruu == 1){
                            cout << "Zadej nazev souboru: (bez pripony .txt, nebo .dat, doplni se automaticky:" << endl;
                            //string NAZEVSOUBORU;
                            cin >> NAZEVSOUBORU;
                            NAZEVSOUBORUTEMP = NAZEVSOUBORU;
                            NAZEVSOUBORU = NAZEVSOUBORU + ".txt";
                            ofstream SouborZapis(NAZEVSOUBORU);
                                for (a=1;a<=pocet;a++) {
                                    if (a>1){SouborZapis << endl;}
                                    for(b=1;b<=pocet+1;b++){
                                        SouborZapis << r[a][b];
                                        SouborZapis << "  ";
                                    }

                                }
                            SouborZapis.close();
                            cout << "Soubor " << NAZEVSOUBORU << " byl uspesne vytvoren a soustava zapsana" << endl;
                        }

                system("pause");


                CramRule();
                Continue();
                }///konec vedlejsi case 1
                break;

                case 2:
                    {
                    cout << "Zadani ze souboru vybrano" << endl;
            cout << "Zadej nazev souboru: (bez pripony .txt, nebo .dat, doplni se automaticky:" << endl;
            cout << "Zadej pouze soustavu 3 rovnic." << endl;
                cin >> NAZEVSOUBORU;
                    NAZEVSOUBORUTEMP = NAZEVSOUBORU;
                    NAZEVSOUBORU = NAZEVSOUBORU + ".txt";
            ifstream SRead(NAZEVSOUBORU);
                if(SRead.fail()) { ///*je soubor k nalezeni?
                cout << "\n" << NAZEVSOUBORU << " neexistuje, nebo program nema k souboru pristup!" << endl;
                cout << "\n" << endl;
                system("pause");
                cout << "\n" << endl;
                cout << "Vracim se do hlavni nabidky:" << "\n \n \n" << endl;
                SRead.close();
                EMPTYSTRINGS();
                break;
                }///konec chybove zpravy

            while(!SRead.eof()){//zjisteni poctu rovnic/RADKU!!!
                getline(SRead,radek);
                cout << radek << endl;
                pocet_radku++;
            }
                SRead.close();
                cout << "Pocet soustav:" << pocet_radku << "\n \n" << endl;
                pocet = pocet_radku;
                cout << "Nacitani soustavy do pole..." << endl;
                    ifstream SSRead(NAZEVSOUBORU);
                    for (a=1;a<=pocet;a++) {
                            for(b=1;b<=pocet+1;b++){
                                SSRead >> r[a][b];
                    }
                            }
                SRead.close();
                cout << "Hotovo" << endl;


                CramRule();
                Continue();

                    }

                break;

                case 3:
                    {
                    cout << "Nahodne generovana soustava vybrana" << endl;
                    cout << "Zadej mezni hodnoty pro generaci nahodnych promennych:" << endl;
                    cout << "Nejvyssi:" << endl;
                        cin >> nahMax;
                    cout << endl;
                    cout << "Nejnizsi: (muze byt nula)" << endl;
                        cin >> nahMin;


                    NahodnyArray(); //vytvoreni nahodneho pole (matice)
                    cout << "\n Chcete zobrazit soustavu? 1 pro zobrazeni, 0 pro preskoceni kroku." << endl;
                        cin >> view;
                        if(view == 1) {
                            cout<<"Vypis soustavy:" << endl;
                            VypisArray();

                        }
                            cout<<" \n \n Chcete zapsat soustavu do souboru? 1 pro zapis, 0 pro preskoceni kroku." << endl;
                            int Dosouboru;
                            cin >> Dosouboru;
                            if (Dosouboru == 1){
                                cout << "Zadej nazev souboru: (bez pripony .txt, nebo .dat, doplni se automaticky:" << endl;
                                cin >> NAZEVSOUBORU;
                                    NAZEVSOUBORUTEMP = NAZEVSOUBORU;
                                    NAZEVSOUBORU = NAZEVSOUBORU + ".txt";
                                    ofstream NahodnaSoustava(NAZEVSOUBORU);
                                for (a=1;a<=pocet;a++) {
                                    if (a>1){NahodnaSoustava << endl;}
                                    for(b=1;b<=pocet+1;b++){
                                        NahodnaSoustava << r[a][b];
                                        NahodnaSoustava << "  ";
                                    }

                                }
                            NahodnaSoustava.close();
                            cout << "Soubor " << NAZEVSOUBORU << " byl uspesne vytvoren a soustava zapsana" << endl;
                            }
                            system("pause");

                    CramRule();
                    Continue();

                    }

                break;

                case 0: { ///pro navrat
                   cout << "\n \n" << endl;
                break;
                }
                default:
                {cout << "Nespravne cislo!" << endl;
                break;
                }
            } ///konec Cramer switch

            }  ///konec hlavni case 4


            break;
        case 0:
            cout << "Program ukoncen" << endl;
            break;
        default:
            cout << "Nespravne cislo" << endl;
            break;
        }

    } while (   choice != 0 );


    cout << "Dekuji za vyuziti programu." << endl;
    system("pause");
    return 0;

}

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

void Masyvo_isvalymas(char Soviau[10][10])
{
    for (int a=0; a<10; a++)
    {
        for(int b=0; b<10; b++)
        {
            Soviau[a][b]='0';

            if(a%2==0 && b%2==0)
            {
                Soviau[a][b]='6';
            }
            else if(a%2==1 && b%2==1)
            {
                Soviau[a][b]='6';
            }
        }
    }
}

void Nusitaikymas(char Soviau[10][10], int x, int y) ///galimu laivo padeciu nustatymas
{
    if(Soviau[x-2][y-1]!='1' && Soviau[x-2][y-1]!='2' && Soviau[x-2][y-1]!='3' && x-2>=0 && y-1>=0 && x-2<10 && y-1<10) Soviau[x-2][y-1]='5';
    if(Soviau[x][y-1]!='1' && Soviau[x][y-1]!='2' && Soviau[x][y-1]!='3' && x>=0 && y-1>=0 && x<10 && y-1<10) Soviau[x][y-1]='5';
    if(Soviau[x-1][y-2]!='1' && Soviau[x-1][y-2]!='2' && Soviau[x-1][y-2]!='3' && x-1>=0 && y-2>=0 && x-1<10 && y-2<10) Soviau[x-1][y-2]='5';
    if(Soviau[x-1][y]!='1' && Soviau[x-1][y]!='2' && Soviau[x-1][y]!='3' && x-1>=0 && y>=0 && x-1<10 && y<10) Soviau[x-1][y]='5';
}

void Negalimu_Langeliu_Isvalymas (char Soviau[10][10], int x, int y) ///negalimu langeliu pasalinimas
{
    if(x-2>=0 && y-2>=0) Soviau[x-2][y-2]='1';
    if(x-2>=0 && y>=0 && x<10 && y<10) Soviau[x-2][y]='1';
    if(x>=0 && y-2>=0 && x<10 && y-2<10) Soviau[x][y-2]='1';
    if(x>=0 && y>=0 && x<10 && y<10) Soviau[x][y]='1';

    if(Soviau[x-1][y-1]=='3')
    {
        if(Soviau[x-2][y-1]!='2' && x-2>=0 && y-1>=0 && x-2<10 && y-1<10) Soviau[x-2][y-1]='1';
        if(Soviau[x][y-1]!='2' && x>=0 && y-1>=0 && x<10 && y-1<10) Soviau[x][y-1]='1';
        if(Soviau[x-1][y-2]!='2' && x-1>=0 && y-2>=0 && x-1<10 && y-2<10) Soviau[x-1][y-2]='1';
        if(Soviau[x-1][y]!='2' && x-1>=0 && y>=0 && x-1<10 && y<10) Soviau[x-1][y]='1';
    }
}

void Saudymas_Aplink(char Soviau[10][10], int &x, int &y)
{
    for(int a=9; a>=0; a--)
    {
        for(int b=9; b>=0; b--)
        {
            if(Soviau[a][b]=='5')
            {
                x=a+1;
                y=b+1;
            }
        }
    }
}

void Saudymas_Toliau(char Soviau[10][10], int &x, int &y) ///Saudau toliau i sesetus
{
    for(int a=9; a>=0; a--)
    {
        for(int b=9; b>=0; b--)
        {
            if(Soviau[x-1][y-1]=='3')
            {
                if(Soviau[a][b]=='5')
                {
                    Soviau[a][b]='1'; ///langeliu aplink nusauta laiva pasalinimas
                }
            }
            if(Soviau[a][b]=='6')
            {
                x=a+1;
                y=b+1;
            }
        }
    }
}

int main(){

    cout << "0 " << flush << endl; ///pranesa, kad teisingai veikia

    int laivai=17, x=1, y=1, Enemy_Ships=5;
    char duomenys='0';
    bool pataikymas=false;
    char Soviau [10][10];

    int table [100]  = {0, 0, 2, 2, 2, 2, 0, 0, 0, 0,
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 4,
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 4,
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 4,
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                        0, 0, 0, 1, 1, 1, 1, 1, 0, 0,
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                        0, 3, 3, 3, 0, 0, 0, 5, 5, 0};

    for (int a=0; a<100; a++)
    {
        cout << table[a] << " ";
    }
    cout << endl;

    Masyvo_isvalymas(Soviau); ///isvalau masyva ir kas antra langeli pasizymiu kaip saudytina

    while(duomenys!='4')
    {
        ///Suvis:
        cout << x << " " << y << flush << endl;

        ///Situacijos lemtis:
        cin >> duomenys;
        Soviau[x-1][y-1]=duomenys;

        if(duomenys=='1') ///Saudymas i kas antra:
        {
            if(!pataikymas) Saudymas_Toliau(Soviau, x, y);
            else Saudymas_Aplink(Soviau, x, y); ///saudau aplink laiva toliau
        }
        else if(duomenys=='2') ///Saudymas aplink laiva, kai pataikiau bent karta
        {
            laivai--;
            pataikymas=true;

            Negalimu_Langeliu_Isvalymas(Soviau, x, y);
            Nusitaikymas(Soviau, x, y);
            Saudymas_Aplink(Soviau, x, y);
        }
        else if(duomenys=='3') ///Saudymas (kol kas) toliau, bet nebesaudymas aplink laiva.
        {
            laivai--;
            Enemy_Ships--;
            pataikymas=false;

            Negalimu_Langeliu_Isvalymas(Soviau, x, y);
            Saudymas_Toliau(Soviau, x, y);
        }
    }

    return 0;
}

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

void Nusitaikymas(char Soviau[10][10], int x, int y)
{
    ///negalimu langeliu pasalinimas
    Soviau[x-2][y-2]='1';
    Soviau[x-2][y]='1';
    Soviau[x][y-2]='1';
    Soviau[x][y]='1';
    ///galimu laivo padeciu nustatymas
    if(Soviau[x-2][y-1]!='1' && Soviau[x-2][y-1]!='2' && Soviau[x-2][y-1]!='3' && x<11 && y<11) Soviau[x-2][y-1]='5';
    if(Soviau[x][y-1]!='1' && Soviau[x][y-1]!='2' && Soviau[x][y-1]!='3' && x<11 && y<11) Soviau[x][y-1]='5';
    if(Soviau[x-1][y-2]!='1' && Soviau[x-1][y-2]!='2' && Soviau[x-1][y-2]!='3' && x<11 && y<11) Soviau[x-1][y-2]='5';
    if(Soviau[x-1][y]!='1' && Soviau[x-1][y]!='2' && Soviau[x-1][y]!='3' && x<11 && y<11) Soviau[x-1][y]='5';
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

int main(){

    cout << "0 " << flush << endl; ///pranesa, kad teisingai veikia

    int laivai=17, x=1, y=1, Enemy_Ships=5; ///1=N, 2=E, 3=S, 4=W;
    char duomenys='0';
    bool pataikymas=false, Kryptis[4]={false};
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

    Masyvo_isvalymas(Soviau);

    while(duomenys!='4')
    {
        ///Suvis:
        cout << x << " " << y << " cia sauti" << flush << endl;

        ///Situacijos lemtis:
        cin >> duomenys;
        Soviau[x-1][y-1]=duomenys;

        if(duomenys=='1' && !pataikymas) ///Saudymas i kas antra:
        {
            for(int a=9; a>=0; a--)
            {
                for(int b=9; b>=0; b--)
                {
                    if(Soviau[a][b]=='6')
                    {
                        x=a+1;
                        y=b+1;
                    }
                }
            }
        }
        else if(duomenys=='1' && pataikymas) ///Saudymas aplink laiva, bet nepataikymas
        {
            Saudymas_Aplink(Soviau, x, y);
        }
        else if(duomenys=='2') ///Saudymas aplink laiva
        {
            laivai--;
            pataikymas=true;

            Nusitaikymas(Soviau, x, y);

            Saudymas_Aplink(Soviau, x, y);
        }
        else if(duomenys=='3') ///Saudymas kol kas toliau, bet nebesaudymas aplink laiva.
        {
            laivai--;
            Enemy_Ships--;
            pataikymas=false;

            for(int a=9; a>=0; a--)
            {
                for(int b=9; b>=0; b--)
                {
                    if(Soviau[a][b]=='6')
                    {
                        x=a+1;
                        y=b+1;
                    }
                    if(Soviau[a][b]=='5')
                    {
                        Soviau[a][b]='1';
                    }
                }
            }
        }

        for (int a=0; a<10; a++)
        {
            for(int b=0; b<10; b++)
            {
                cout << Soviau[a][b] << " ";
            }
            cout << endl;
        }

    }

    return 0;
}

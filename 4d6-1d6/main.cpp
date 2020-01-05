#include <iostream>

using namespace std;

int main()
{
    ///kauliukai nuo 1 iki 6 akučių, 4d6 - 1d6 (min)

    int Suma=0, unikalu=0, Kombinacijos[360], Viskas[4096], x=0; ///360, nes 6P4; 4096 nes 4^6;

    for(int a=0; a<6; a++)
    {
        for(int b=0; b<6; b++)
        {
            for(int c=0; c<6; c++)
            {
                for(int d=0; d<6; d++)
                {
                    if(/*nesutampa akuciu skaicius*/) ///gal parasyti funkcija? nes reikes dar pora kartu.
                    {
                        Kombinacijos[x]=1000*a+100*b+10*c+d;
                        x++;
                    }
                }
            }
        }
    }
    return 0;
}

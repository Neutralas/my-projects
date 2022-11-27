#include <iostream>

using namespace std;

int main()
{
    ///kauliukai nuo 1 iki 6 akučių, 4d6 - 1d6 (min)

    int Viskas[1296], x=0, maz; /// 1296 nes 6^4;
    float Suma=0;

    ///ieskau galimu kombinaciju
    for(int a=1; a<=6; a++)
    {
        for(int b=1; b<=6; b++)
        {
            for(int c=1; c<=6; c++)
            {
                for(int d=1; d<=6; d++)
                {
                    maz=min(min(a, b), min(c, d));
                    Viskas[x]=a+b+c+d-maz;
                    x++;
                }
            }
        }
    }

    for(int x=0; x<1296; x++)
    {
        Suma+=Viskas[x];
    }

    cout << Suma/1296;

    return 0;
}

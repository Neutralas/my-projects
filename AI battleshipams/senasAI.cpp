#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){

    cout << "0 " << flush << endl; //pranesa, kad teisingai veikia
    int a=0, laivai=17, laivai2=17;

    int table [100]  = {0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
                        0, 0, 1, 0, 0, 3, 0, 0, 0, 0,
                        0, 0, 1, 0, 0, 3, 0, 0, 0, 4,
                        0, 0, 1, 0, 0, 3, 0, 0, 0, 4,
                        0, 0, 1, 0, 0, 0, 0, 0, 0, 4,
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                        0, 0, 0, 2, 2, 2, 2, 0, 0, 0,
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                        0, 0, 0, 0, 0, 0, 0, 0, 5, 0,
                        0, 0, 0, 0, 0, 0, 0, 0, 5, 0};

    int table2 [100] = {0, 0, 1, 1, 1, 1, 1, 0, 0, 0,
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                        0, 0, 0, 3, 3, 3, 0, 4, 4, 4,
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                        0, 0, 0, 0, 2, 0, 0, 0, 0, 0,
                        0, 0, 0, 0, 2, 0, 0, 0, 0, 0,
                        0, 0, 0, 0, 2, 0, 0, 0, 0, 0,
                        0, 0, 0, 0, 2, 0, 0, 0, 0, 0,
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                        0, 0, 0, 0, 0, 0, 0, 0, 5, 5};

    for(int u=0; u<10; u++)
    {
        for (int i=0; i<10; i++)
        {
            if(a%2==0) cout << table [i+u*10] << " " << flush;
            else cout << table2 [i+u*10] << " " << flush;

            if(i%9==0 && i!=0)
            {
                cout << "          ";
                a++;
                if(a%2==0)
                {
                    cout << endl;
                }
                else if (a%2==1) i=-1;
            }
        }
    }
    cout << endl;

    int moves [100];
    for (int i=0; i<100; i++)  {
        moves [i] = i;
    }
    int moveCount = 100;

    int moves2 [100];
    for (int i=0; i<100; i++)  {
        moves2 [i] = i;
    }
    int moveCount2 = 100;

    while (true)
    {
        for(int u=1; u<=2; u++)
        {
            if(u==1)
            {
                srand (time(NULL));
                int currentMove = rand() % moveCount;
                int targetY = (moves [currentMove] / 10);
                int targetX = (moves [currentMove] - 10 * targetY);

                cout << "primas: " << targetX + 1 << " " << targetY + 1 << " " << flush;
                //char status = '0';

                if(table2[targetX*10+targetY]!=0)
                {
                    laivai2--;
                    cout << "pataike +";
                }
                cout << "\n";

                if (laivai2==0)
                {
                    cout << "laimejo pirmasis \n";
                    cout << "kitam liko " << laivai << " laivu, panaudota " << 101-moveCount;
                    return 0;
                }

                moves [currentMove] = 100;
                moveCount--;
                sort (moves, moves + 100);
            }
            else if(u==2)
            {
                srand (time(NULL));
                int currentMove2 = rand() % moveCount2;
                int targetY2 = (moves2 [currentMove2] / 10);
                int targetX2 = (moves2 [currentMove2] - 10 * targetY2);

                cout << "sekundas: " << targetX2 + 1 << " " << targetY2 + 1 << " " << flush;
                char status = '0';

                if(table[targetX2*10+targetY2]!=0)
                {
                    laivai--;
                    cout << "pataike +";
                }

                cout << "\n";

                if (laivai==0)
                {
                    cout << "laimejo antrasis \n";
                    cout << "kitam liko " << laivai2 << " laivu, panaudota " << 101-moveCount;
                    return 0;
                }

                moves2 [currentMove2] = 100;
                moveCount2--;
                sort (moves2, moves2 + 100);
            }
        }
    }
}

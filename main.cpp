#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){

    cout << "0 " << flush << endl; //pranesa, kad teisingai veikia
    int a=0;

    int table [100]  = {0, 0, 1, 1, 1, 1, 1, 0, 0, 0,
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                        0, 0, 0, 3, 3, 3, 0, 4, 4, 4,
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                        0, 0, 0, 0, 2, 0, 0, 0, 0, 0,
                        0, 0, 0, 0, 2, 0, 0, 0, 0, 0,
                        0, 0, 0, 0, 2, 0, 0, 0, 0, 0,
                        0, 0, 0, 0, 2, 0, 0, 0, 0, 0,
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                        0, 0, 0, 0, 0, 0, 0, 0, 5, 5};

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
    while (true && moveCount > 0) {
        srand (time(NULL));
        int currentMove = rand() % moveCount;
        int targetY = (moves [currentMove] / 10);
        int targetX = (moves [currentMove] - 10 * targetY);

        cout << targetX + 1 << " " << targetY + 1 << " " << flush;
        char status = '0';
        cin >> status;
        if (status == '4') {
            return 0;
        }
        moves [currentMove] = 100;
        moveCount--;
        sort (moves, moves + 100);
    }
}

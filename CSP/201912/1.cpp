#include <iostream>
#include <cmath>
using namespace std;

int res[4];

int num[5];

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int numCalled = 0;
    int turns = 0;
    int divid7 = 1;
    while (numCalled <= n)
    {
        num[0]++;
        

        bool isnot = true;
        for (int j = 0; j < 5; j++)
        {
            if (num[j] >= 10)
            {
                num[j] -= 10;
                num[j + 1] += 1;
            }
            else
            {
                break;
            }
        }

        int temp = 0;
        for (int i = 0; i < 5; i++)
        {
            if (num[i] == 7)
            {
                isnot = false;
                break;
            }
        }
        
        if (isnot && divid7 != 7)
        {
            numCalled++;
        }
        else
        {
            res[turns]++;
        }

        divid7++;
        if(divid7 == 8)
        {
            divid7 = 1;
        }
        turns++;
        if (turns == 4)
            turns = 0;
        
    }

    for (int i = 0; i < 4; i++)
    {
        cout << res[i] << endl;
    }
    return 0;
}

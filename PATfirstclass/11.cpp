#include <iostream>
#include <iomanip>

using namespace std;

char cha[3] = {'W', 'T', 'L'};
int main(int argc, char const *argv[])
{
    double pro = 1;
    for (int i = 0; i < 3; i++)
    {
        double max = -1;
        int index;
        double temp;
        for (int j = 0; j < 3; j++)
        {
            cin >> temp;
            if (temp > max)
            {
                max = temp;
                index = j;
            }
        }
        pro *= max;
        cout << cha[index] << " ";
    }
    cout << fixed << setprecision(2) << 2 * (pro * 0.65 - 1) << endl;
    return 0;
}
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    for(unsigned long long i = 1000000000;i<10000000000;i++)
    {
        if(i * (i + 1) ==  1001733993063167141)
        {
            cout << i;
        }
    }
    return 0;
}

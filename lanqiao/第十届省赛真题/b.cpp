#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    unsigned long long a, b, c;
    a = b = c = 1;
    for (int i = 4; i <= 20190324; i++)
    {
        int temp = a + b + c;
        a = b;
        b = c;
        c = temp;
    }
    cout << c << endl;  //856830691·

    return 0;
}

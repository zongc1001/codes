#include <iostream>

using namespace std;


bool is[100000000];
int main(int argc, char const *argv[])
{
    int a, b;
    cin >> a >> b;
    for(int i = 0;i < 1000;i++)
        for(int j = 0 ; j < 1000;j++)    
        {
            if(a*i + b*j > a*b) break;
            is[a*i + b*j] = true;
        }
    for(int i = a*b; i > 0;i--)
    {
        if(!is[i])
        {
            cout << i;
            break;
        }
    }
    return 0;
}

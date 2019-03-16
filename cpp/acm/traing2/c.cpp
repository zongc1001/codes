#include <iostream>
#include <algorithm>
using namespace std;
char s[100010];
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    cin >> s;
    int a[27] = {0};
    int b[27] = {0};
    for(int i = 0; i < n;i++)
    {
        a[s[i]-'a'+1]++;
    }
    for(int i = 1; i <= 26;i++)
    {
        for(int j = 0; j < a[i];j++)
        {
            char c = i + 'a' - 1;
            cout << c;
        }
    }
    cout << endl;
    return 0;
}

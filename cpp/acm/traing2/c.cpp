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

    memcpy(b, a, 27 * sizeof(int));
    sort(b + 1, b + 26);
    for(int i = 1; i <= 26;i++)
    {
        cout << "a[i]: " << a[i] << "   b[i]:  "<< b[i] << endl;
    }

    return 0;
}

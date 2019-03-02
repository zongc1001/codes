#include <iostream>

using namespace std;

char ans[2510];
int main(int argc, char const *argv[])
{
    // abaa
    int n, k;
    char s[51];
    cin >> n >> k;
    cin >> s;
    
    int equal = 0;  
    for(int i = n-2; i >= 0;i--)
    {
        bool is = true;
        for(int j = 0; j <= i ; j++)
        {
    //        cout << "s[j]: " << s[j] << "   s[j+n-i-1]: " << s[j+n-i-1] << endl;
            if(s[j] != s[j + n-i-1])
            {
                is = false;
                break;
            }
        }
  //      cout << i << ":  " << is << endl;
        if(is)
        {
            equal = i + 1;
            break;
        }
    }
  //  cout << "equal: " << equal  << endl;
    for(int i = 0; i < n;i++)
        ans[i] = s[i];
    int t = n;
    for(int i = 0; i < k-1;i++)
    {
        for(int j = equal; j < n;j++)
        {
            ans[t++] = s[j];
        }
    }

    cout << ans << endl;


    return 0;
}

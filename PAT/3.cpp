#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    string s;
    cin >> n;
    while (n--)
    {
        cin >> s;
        int len = s.length();
        if(len == 0)
        {
            cout << "NO" << endl;
        }
        else
        {
            int fronta = 0, mida = 0, backa = 0;

            bool metP = false;
            bool metT = false;
            bool over = false;
            for (int i = 0; i < len; i++)
            {
                if (s[i] == 'A')
                {
                    if (!metT && !metP)
                    {
                        fronta++;
                    }
                    else if (!metT && metP)
                    {
                        mida++;
                    }
                    else if (metP && metT)
                    {
                        backa++;
                    }
                }
                else if (s[i] == 'P' && !metP && !metT)
                {
                    metP = true;
                }
                else if (s[i] == 'T' && !metT && metP)
                {
                    metT = true;
                }
                else
                {
                    over = true;
                    cout << "NO" << endl;
                    break;
                }
            }
            if (!over)
            {
                if (metP && metT && mida > 0 && mida * fronta == backa)
                {
                    cout << "YES" << endl;
                }
                else
                {
                    cout << "NO" << endl;
                }
            }
        }
    }

    return 0;
}

//https://pintia.cn/problem-sets/994805342720868352/problems/994805411985604608

#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

string day[7] = {
    "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main(int argc, char const *argv[])
{
    string s1, s2, s3, s4;
    string day[7] = {
        "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    cin >> s1 >> s2 >> s3 >> s4;
    int size1 = min(s1.size(), s2.size());
    int size2 = min(s3.size(), s4.size());
    int i = 0;
    for (i; i < size1; i++)
    {
        if (s1[i] == s2[i] && s1[i] >= 'A' && s1[i] <= 'G')
        {
            cout << day[s1[i] - 'A'] << " ";
            i++;
            break;
        }
        // else if(s1[i] == s2[i] && s1[i] >= 'a' && s1[i] <= 'z')
        // {
        //     cout << day[s1[i] - 'a'] << " ";
        //     i++;
        //     break;
        // }
        
    }
    
    for (i; i < size1; i++)
    {
        if (s1[i] == s2[i])
        {
            if (s1[i] >= 'A' && s1[i] <= 'N')
            {
                cout << setw(2) << setfill('0') << s1[i] - 'A' + 10 << ":";
                break;
            }
            // else if (s1[i] >= 'a' && s1[i] <= 'n')
            // {
            //     cout << setw(2) << setfill('0') << s1[i] - 'a' + 10 << ":";
            //     break;
            // }
            else if (s1[i] >= '0' && s1[i] <= '9')
            {
                cout << setw(2) << setfill('0') << s1[i] << ":";
                break;
            }
        }
    }
    for (i = 0; i < size2; i++)
    {
        if (s3[i] == s4[i] && ((s3[i] >= 'a' && s3[i] <= 'z')
        || (s3[i] >= 'A' && s3[i] <= 'Z')))
        {
            cout << setw(2) << setfill('0') << i << endl;
            break;
        }
    }

    return 0;
}

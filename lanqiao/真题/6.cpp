#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool arr[1005];

struct Obj
{
    int index;
    int num;
    Obj(int i, int n) : index(i), num(n) {}
};

vector<Obj> vec;
int main(int argc, char const *argv[])
{
    string s1, s2;
    cin >> s1 >> s2;
    int len = s1.length();
    for (int i = 0; i < len; i++)
    {
        arr[i] = s1[i] == s2[i];
    }

    int res = 0;

    for (int i = 0; i < len; i++)
    {
        if (arr[i] == 0)
        {
            int j = i + 1;
            while (j < len && arr[j] == 0)
                j++;
            vec.push_back(Obj(i, j - i));
            i = j;
        }
    }

    for (int i = 0; i < vec.size(); i++)
    {
        // cout << vec[i].index << " " << vec[i].num << endl;
        if (vec[i].num & 1)
        {
            res += vec[i].num / 2 + vec[i + 1].index - (vec[i].index + vec[i].num - 1);
            vec[i + 1].index++;
            vec[i + 1].num--;
        }
        else
        {
            res += vec[i].num / 2;
        }
    }

    cout << res << endl;

    return 0;
}

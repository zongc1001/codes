#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int shuffle[52][11];
int wrongShuffle[52][11];
int target[52];
int wrong[52][11];
int group;

int main(int argc, char const *argv[])
{
    cin >> group;
    for (int i = 0; i < 52; i++)
    {
        shuffle[i][0] = i;
        wrongShuffle[i][0] = i;
    }

    for (int i = 1; i <= 10; i++)
    {
        for (int j = 0; j < 52; j++)
        {
            if (j & 1)
            {
                shuffle[j][i] = shuffle[j / 2][i - 1];
                wrongShuffle[j][i] = wrongShuffle[j / 2][i - 1];
            }
            else
            {
                shuffle[j][i] = shuffle[26 + j / 2][i - 1];
                wrongShuffle[j][i] = wrongShuffle[26 + j / 2][i - 1];
            }
        }
        int temp;
        if (i == 3)
        {
            temp = wrongShuffle[3][i];
            wrongShuffle[3][i] = wrongShuffle[4][i];
            wrongShuffle[4][i] = temp;
        }
        if (i == 7)
        {
            temp = wrongShuffle[11][i];
            wrongShuffle[11][i] = wrongShuffle[12][i];
            wrongShuffle[12][i] = temp;
        }
        if (i == 8)
        {
            temp = wrongShuffle[38][i];
            wrongShuffle[38][i] = wrongShuffle[39][i];
            wrongShuffle[39][i] = temp;
        }
    }

    for (int i = 1; i <= group; i++)
    {
        cout << "Case " << i << endl;
        for (int i = 0; i < 52; i++)
        {
            cin >> target[i];
        }
    }

    int n = 0, k = 100; //n代表洗牌的次数， k表示错误的次数
    for (int i = 1; i <= 10; i++)
    {
        int numOfError = 0;
        for (int j = 0; j < 52; j++)
        {
            if (shuffle[j][i] != target[j])
            {
                numOfError++;
            }
        }
        if (numOfError < k)
        {
            k = numOfError;
            n = i;
        }
    }

    cout << n << " " << k << endl;

    for (int i = 0; i < 52; i++)
    {
        wrong[i][n] = target[i];
    }

    for (int i = n; i >= 1 && k > 0; i--)
    {
        //记录不一样的
        vector<int> wronglist;
        for (int j = 0; j < 52; j++)
        {
            if (shuffle[j][i] != wrong[j][i])
            {
                wronglist.push_back((j & 1) ? wrong[j / 2][i] : wrong[j / 2 + 26][i]);
            }
        }
        for (int t = 0; t < wronglist.size() - 1; t++)
        {
            if (wronglist[t] + 1 == wronglist[t + 1])
            {
                int a = wronglist[t] > 26 ? (wronglist[t] - 26) * 2 : (wronglist[t] * 2 + 1);
                int b = wronglist[t] + 1 > 26 ? (wronglist[t] + 1- 26) * 2 : ((wronglist[t] + 1 )* 2 + 1);
                cout <<"location: " << wronglist[t] + 1 << endl;
                int temp = wrong[a][i];
                wrong[a][i] = wrong[b][i];
                wrong[b][i] = temp;
                cout << "Error in shuffle" << endl;
            }
        }
        cout << "i=" << i << ": " << endl;
        for (int j = 0; j < 52; j++)
        {
            cout << j << ": " << shuffle[j][i] << " ";
        }
        cout << endl;
        for (int j = 0; j < 52; j++)
        {
            cout << j << ": " << wrong[j][i] << " ";
        }
        cout << endl;

        for (int j = 0; j < 52; j++)
        {
            if (shuffle[j][i] != wrong[j][i])
            {
                cout << j << " ";
            }
        }
        cout << endl;
        for (int j = 0; j < 52; j++)
        {
            wrong[j][i - 1] = (j & 1) ? wrong[j / 2][i] : wrong[j / 2 + 26][i];
        }
    }

    // for (int i = 0; i < 11; i++)
    // {
    //     cout << "i=" << i << ": " << endl;
    //     for (int j = 0; j < 52; j++)
    //     {
    //         cout << j << ": " << shuffle[j][i] << " ";
    //     }
    //     cout << endl;
    //     for (int j = 0; j < 52; j++)
    //     {
    //         cout << j << ": " << wrongShuffle[j][i] << " ";
    //     }
    //     cout << endl;

    //     for (int j = 0; j < 52; j++)
    //     {
    //         if (shuffle[j][i] != wrongShuffle[j][i])
    //         {
    //             cout << j << " ";
    //         }
    //     }
    //     cout << endl;
    // }

    return 0;
}
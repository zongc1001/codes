#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>

using namespace std;

map<string, int> namelist;

struct obj
{
    int stu;
    double score;
    int rank;

    obj(int a1 = 0, double a2 = 0, int a3 = 0)
        : stu(a1), score(a2), rank(a3) {}
    bool operator<(obj &a)
    {
        return score > a.score;
    }
};

vector<vector<obj> > ranklist(4);

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    vector<obj> ranktemp(n);
    for (int i = 0; i < n; i++)
    {
        string s;
        double a[4];
        cin >> s;
        for (int j = 0; j < 3; j++)
        {
            cin >> a[j];
        }
        a[3] = (a[0] + a[1] + a[2]) / 3;
        namelist[s] = i;
        for (int j = 0; j < 4; j++)
        {
            ranklist[j].push_back(obj(i, a[j], 0));
        }
    }

    for (int i = 0; i < 4; i++)
    {
        sort(ranklist[i].begin(), ranklist[i].end());
    }
    for (int i = 0; i < 4; i++)
    {
        int len = ranklist[i].size();
        ranktemp.resize(len);
        for (int j = 0; j < len; j++)
        {
            ranklist[i][j].rank = j;
            obj &objtemp = ranklist[i][j];
            ranktemp[objtemp.stu] = obj(objtemp.stu, objtemp.score, objtemp.rank);
        }
        ranklist[i].swap(ranktemp);
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < ranklist[i].size(); j++)
        {
            cout << ranklist[i][j].stu << " " << ranklist[i][j].score << " "
                 << ranklist[i][j].rank << endl;
        }
        cout << endl
             << endl;
    }

    return 0;
}

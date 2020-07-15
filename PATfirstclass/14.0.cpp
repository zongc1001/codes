//https://pintia.cn/problem-sets/994805342720868352/problems/994805498207911936

#include <cstdio>
#include <stack>
#include <list>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;
struct obj
{
    int numOfCum;
    int minute;
    int line;
    int waitedTime;
    obj(int a = 0, int b = 0, int c = 0, int d = 0)
        : numOfCum(a), minute(b), line(c), waitedTime(d)
    {
    }
    ~obj() {}
    bool operator<(obj &a)
    {
        return waitedTime <= a.waitedTime;
    }
};

typedef deque<obj> stk;
int n, m, k, q;
vector<obj> line;
bool cmp(obj& a, obj& b)
{
    return a.numOfCum < b.numOfCum;
}
int main(int argc, char const *argv[])
{
    scanf("%d %d %d %d", &n, &m, &k, &q);
    vector<obj> last(n + 1);
    for (int i = 1; i <= n; i++)
    {
        last[i] = obj();
    }
    int count = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {

            int temp;
            scanf("%d", &temp);
            // window[j].push_back(obj((i - 1) * n + j, temp, j, temp + window[j].empty() ? 0 : window[j].back().waitedTime));
            line.push_back(obj((i - 1) * n + j, temp, j, last[j].waitedTime + temp));

            last[j].numOfCum = (i - 1) * n + j;
            last[j].minute = temp;
            last[j].line = j;
            last[j].waitedTime = last[j].waitedTime + temp;
            // printf("waitedTime: %d\n", last[j].waitedTime);
            count++;
            if (count == k)
                break;
        }
        if (count == k)
            break;
    }
    sort(line.begin(), line.end());
    // for (int i = 0; i < line.size(); i++)
    // {
    //     printf("line: %d  waitTime: %d\n", line[i].line, line[i].waitedTime);
    // }
    // printf("----------------\n");
    int index = 0;
    while (k > count)
    {
        int temp;
        scanf("%d", &temp);
        count++;
        int l = line[index++].line;
        last[l].numOfCum = count;
        last[l].line = l;
        last[l].minute = temp;
        last[l].waitedTime = last[l].waitedTime + temp;
        vector<obj>::iterator it;
        for (it = line.end() - 1; it != line.begin(); it--)
        {
            // printf("find insert, it->waitedTime: %d", it->waitedTime);
            if (it->waitedTime <= last[l].waitedTime)
            {

                break;
            }
        }
        // printf("\n");
        line.insert(it + 1, obj(last[l]));
        // printf("after insert, size: %d\n", line.size());
        // printf("line: %d  waitTime: %d\n", last[l].line, last[l].waitedTime);
    }

    // printf("%d-----------------\n", line.size());
    
    // for (int i = 0; i < line.size(); i++)
    // {
    //     printf("line: %d  waitTime: %d\n", line[i].line, line[i].waitedTime);
    // }

    sort(line.begin(), line.end(), cmp);
    // printf("after-------------------\n");

    // for (int i = 0; i < line.size(); i++)
    // {
    //     printf("line: %d  waitTime: %d\n", line[i].line, line[i].waitedTime);
    // }

    for(int i = 0; i < q; i++)
    {
        int temp;
        scanf("%d", &temp);
        int time = line[temp-1].waitedTime;
        int a = 8 + time / 60;
        int b = time % 60;
        if(a < 17 || (a == 17 && b == 0))
        {
            printf("%02d:%02d\n", 8 + time / 60, time % 60);

        }
        else
        {
            printf("Sorry\n");
        }
        
    }
    // printf("fafds\n");
    return 0;
}


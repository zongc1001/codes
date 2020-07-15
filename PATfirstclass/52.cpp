//https://pintia.cn/problem-sets/994805342720868352/problems/994805425780670464

#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
const bool debug = false;
struct Node
{
    int address, key = 100005, next = -1, flag = false;
    Node() {}
    bool operator<(Node &obj)
    {
        return (flag && !obj.flag || !flag && obj.flag) ? flag > obj.flag : key < obj.key;
    }
};

int n, head;
vector<Node> vec;
map<int, int> addrTab;

int main(int argc, char const *argv[])
{
    if (debug)
        freopen("52.txt", "r", stdin);
    vec.resize(100005);
    while (scanf("%d %d", &n, &head) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            vec[a].address = a;
            vec[a].key = b;
            vec[a].next = c;
            
        }
        int cur = head;
        int cnt = 0;
        while (cur != -1)
        {
            if (debug)
                printf("cur: %d\n", cur);
            vec[cur].flag = true;
            cur = vec[cur].next;
            cnt++;
        }
        if (debug)
            printf("cnt: %d\n", cnt);
        sort(vec.begin(), vec.end());
        if(cnt == 0) printf("0 -1\n");
        else printf("%d %05d\n", cnt, vec[0].address);
        
        for (int i = 0; i < cnt; i++)
        {
            
            if (i != cnt - 1)
            {
                printf("%05d %d %05d\n", vec[i].address, vec[i].key, vec[i + 1].address);
            }
            else
            {
                printf("%05d %d -1\n", vec[i].address, vec[i].key);
            }
        }
    }
    return 0;
}

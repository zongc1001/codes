#include <iostream>
#include <stack>

using namespace std;

struct Statu
{
    /* data */
    short x, y;
    struct Statu operator=(struct Statu& obj)
    {
        this->x = obj.x;
        this->y = obj.y;
    }
    struct Statu operator+(struct Statu&obj1)
    {
        struct Statu temp;
        temp.x = obj1.x + this->x;
        temp.y = obj1.y + this->y;

        return temp;
    }
};



short a[12][12];
bool visited[12][12];
int moveX[] = {-1, 1, 0, 0};
int moveY[] = {0, 0, -1, 1};

int main(int argc, char const *argv[])
{
    int m, n;
    cin >> m >> n;
    int sum = 0;
    int target;

    int max = 0;
    for(int i = 1; i <= m;i ++)
        for(int j = 1; j <= n;j++)
        {
            cin >> a[i][j];
            if(a[i][j] >= max)
                max = a[i][j];
            sum += a[i][j];
        }
    if(sum & 1 > 0)
    {
        cout << 0 << endl;
        return 0;
    }
    target = sum / 2;
    if(max > target)
    {
        cout << 0 << endl;
        return 0;
    }
    if(max == target)
    {
        cout << 1 << endl;
        return 0;
    }
    sum = a[1][1];
    visited[1][1] = true;
    for(int i = 1; i <= n;i++)
    {
        a[0][i] = true;
        a[m+1][i] = true;
    }
    for(int i = 1; i <= m;i++)
    {
        a[i][0] = true;
        a[i][m+1] = true;
    }

    stack<struct Statu> s;
    struct Statu start = {1, 1};
    s.push(start);
    struct Statu cur = start;

    int result = 0x7fffffff;
    while(!s.empty())
    {

        struct Statu next;
        //  = getNextV(cur);
        bool noway = true;
        for(int i = 0; i < 4;i++)
        {
            next.x = cur.x + moveX[i];
            next.y = cur.y + moveY[i];
            if(!visited[next.x][next.y])
            {
                
                if(sum + a[next.x][next.y] < target)
                {
                    
                    visited[next.x][next.y] = true;
                    sum += a[next.x][next.y];
                    cur = next;
                    s.push(cur);
                    noway = false;
                    break;
                }
                else if(sum +a[next.x][next.y] == target)
                {
                    if(s.size() + 1 < result)
                        result = s.size() + 1;
                    break;
                }
            }            
        }

        if(noway && !s.empty())
        {
            //无路
            visited[cur.x][cur.y] = false;
            
            cur = s.top();
            s.pop();
        }
    }

    if(result == 0x7fffffff)
    {
        result = 0;
    }

    cout << result << endl;


    //检测输入情况
    // for(int i = 0; i < m;i ++)
    // {
    //     for(int j = 0; j < n;j++)
    //     {
    //         cout << a[i][j] << "  ";
    //     }
    //     cout << endl;
    // }
    
    return 0;
}

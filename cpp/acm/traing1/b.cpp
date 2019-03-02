#include<iostream>
#include<algorithm>
using namespace std;

int a[10005];
bool is[10005];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n;i++)
        cin >> a[i];
    sort(a, a+n);
    int sum = 0;    //cp + 单身狗的数量
    int supply = n-2;   //下标 用来寻找补足当前正在检查的数字
    for(int i = n-1; i > -1; i--)
    {
        if(!is[i])
        {
            is[i] = true;
            if(!(a[i] < m) )
            {
                sum++;
            }
            else
            {
                for(int j = i-1;j > -1;j--)
                {
                    if(!is[j] && !(a[j] + a[i] > m))
                    {
                        is[j] = true;
                        break;
                    }
                }
                sum++;
            } 
        }
    }
    cout << sum << endl;

    return 0;
}
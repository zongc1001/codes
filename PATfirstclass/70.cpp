// https://pintia.cn/problem-sets/994805342720868352/problems/994805399578853376

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct Mooncake
{
    double amount;
    double price;
    double profit;
    Mooncake(double _amount = 0,
             double _price = 0)
        : amount(_amount),
          price(_price)
    {
    if(_amount == 0)
    {
        this->profit = 0;
    }
    else
        this->profit = _price / _amount;
    
    }
    bool operator<(Mooncake &obj)
    {
        return this->profit > obj.profit;
    }
};

int n, d;
vector<Mooncake> vec;
vector<double> inventorys;
int main(int argc, char const *argv[])
{
    scanf("%d %d", &n, &d);
    for (int i = 0; i < n; i++)
    {
        double temp;
        scanf("%lf", &temp);
        inventorys.push_back(temp);
        // printf("%lf", inventorys[i]);
    }
    for (int i = 0; i < n; i++)
    {
        double temp;
        scanf("%lf", &temp);
        // printf("%lf", temp);
        vec.push_back(Mooncake(inventorys[i], temp));
    }

    sort(vec.begin(), vec.end());
    // for (int i = 0; i < vec.size(); i++)
    // {
    //     for (int j = i + 1; j < vec.size(); j++)
    //     {
    //         if (vec[i].profit < vec[j].profit)
    //         {
    //             Mooncake temp = vec[i];
    //             vec[i] = vec[j];
    //             vec[j] = temp;
    //         }
    //     }
    // }

    int index = 0;
    double totalProfit = 0;
    while (d > 0 && index < n)
    {
        Mooncake &temp = vec[index++];
        if (d >= temp.amount)
        {
            d -= temp.amount;
            totalProfit += temp.price;
        }
        else
        {
            totalProfit += temp.profit * d;
            d = 0;
        }
    }
    printf("%.2lf\n", totalProfit);

    return 0;
}

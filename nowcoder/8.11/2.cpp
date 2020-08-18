#include <cstdio>
#include <vector>
#include <map>
using namespace std;
bool debug = false;

struct Node
{
  int val;
  vector<int> vec;
};

map<int, bool> table;

int k, n;

int main(int argc, char const *argv[])
{
  if (argc > 1)
    debug = true;
  if (debug)
  {
    freopen("2", "r", stdin);
  }
  scanf("%d %d", &k, &n);
  while (n--)
  {
    int temp;
    scanf("%d", &temp);
    if (temp >= 1)
    {
      int far;
      scanf("%d", &far);
      temp--;
      while(temp--) {
        table.insert()
      }
    }
  }

  return 0;
}

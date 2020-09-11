#include <cstdio>

using namespace std;

bool debug = false;

int main(int argc, char const *argv[])
{
  if(argc > 1) debug = true;
  if(debug)
  {
    freopen("3", "r", stdin);
  }
  int a1, b1, a2, b2;
  scanf("%d+%di\n", &a1, &b1);
  scanf("%d+%di\n", &a2, &b2);
  
  printf("%d+%di\n", a1 * a2 - b1 * b2, a1 * b2 + a2 * b1);



  return 0;
}

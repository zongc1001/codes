#include <iostream> 
#include <cstdlib>
#include <ctime>
using namespace std;
int n = 1000;
int k = 10;


int main(int argc, char const *argv[])
{
  freopen("50", "w", stdout);
  srand(time(NULL));
  cout << n << " " << k << endl;
  for(int i = 0; i < n; i++) {
    cout << rand() % (n + 1) << " ";
  }
  cout << endl;



  return 0;
}

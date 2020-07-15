//https://pintia.cn/problem-sets/994805342720868352/problems/994805470349344768

#include <cstdio>

using namespace std;

int arr[3];
char ch[13] = {'0', '1', '2', '3', '4','5', '6', '7','8','9','A', 'B', 'C'};

int main(int argc, char const *argv[])
{
    for(int i = 0; i < 3; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("#");
    for(int i = 0; i < 3; i++)
    {
        int temp = arr[i];
        char c1 = '0', c2 = '0';
        c2 = ch[temp % 13];
        c1 = ch[temp / 13];
        printf("%c%c", c1, c2);
    }
    printf("\n");




    return 0;
}

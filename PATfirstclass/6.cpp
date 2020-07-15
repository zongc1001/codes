#include <cstdio>
#include <string.h>
using namespace std;
char tempId[20];
char res1[20];
char res2[20];
struct Time
{
    int hour, minute, second;
    Time(int h = 0, int m = 0, int s = 0) : hour(h), minute(m), second(s) {}
};

bool lessthan(Time& t1, Time& t2)
{
    int temp1 = t1.hour * 60 * 60 + t1.minute * 60 + t1.second;
    int temp2 = t2.hour * 60 * 60 + t2.minute * 60 + t2.second;
    return temp1 < temp2;
}


int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);

    int a, b, c, x, y, z;
    
    Time max = Time(0, 0, 0);
    Time min = Time(59, 59, 59);
    
    Time tempmin = Time();
    Time tempmax = Time();
    
    while (n--)
    {
        scanf("%s %d:%d:%d %d:%d:%d", &tempId, &a, &b, &c, &x, &y, &z);
        tempmin.hour = a;
        tempmin.minute = b;
        tempmin.second = c;
        
        tempmax.hour = x;
        tempmax.minute = y;
        tempmax.second = z;

        if(lessthan(tempmin, min))
        {
            min = tempmin;
            strcpy(res1, tempId);
        }
        if(lessthan(max, tempmax))
        {
            max = tempmax;
            strcpy(res2, tempId);
        }
        // printf("%s %d:%d:%d %d:%d:%d\n", tempId, a, b, c, x, y, z);
    }
    printf("%s %s", res1, res2);

    return 0;
}

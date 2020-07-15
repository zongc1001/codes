//https://pintia.cn/problem-sets/994805342720868352/problems/994805493648703488

#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <map>
using namespace std;



struct Record
{
    string name;
    bool isStart;
    int month;
    int day;
    int hour;
    int minute;
    
    int length;
    int fee;

    Record() {}
    Record(string& name, bool isStart,
           int month, int day, 
           int hour, int minute,
           int length, int fee)
    :name(name), isStart(isStart), month(month),
     day(day), hour(hour), minute(minute),
     length(length), fee(fee)
     {}
    bool operator<(Record& obj)
    {
        return this->name < obj.name;
    }
};

typedef vector<Record> records;

struct OnesRecord
{
    string name;
    queue<Record> rocords;
    bool operator<(OnesRecord& obj)
    {
        return this->name < obj.name;
    }
};

map<string, records> res;

int toll[24];
int n;


/*
提供开始和结束的时间点, 计算时间长度
*/
int computeTime(Record& begin, Record& end)
{
    

}

int main(int argc, char const *argv[])
{
    for (int i = 0; i < 24; i++)
    {
        scanf("%d", &toll[i]);
    }
    scanf("%d", n);
    for (int i = 0; i < n; i++)
    {
        string name, ope;
        int month, day, hour, minute;
        bool isStart = false;
        scanf("%s %d:%d:%d:%d %s", &name, &month, &day, &hour, &minute, &ope);
        if(ope == "on-line")
            isStart = true;
        
        if(res.find(name) == res.end())
        {
            printf("not found %s\n", name.c_str());
        }
    }

    return 0;
}

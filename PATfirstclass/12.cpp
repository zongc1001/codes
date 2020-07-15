#include <algorithm>
#include <cstdio>
#include <map>
#include <string>
#include <vector>

using namespace std;

bool debug = false;

struct stu {
    int name;
    float a;
    float c, m, e;
    int rank = 4000;
    char simbol = '!';
    stu(int name, int clang, int math, int english, float ave)
        : name(name), c(clang), m(math), e(english), a(ave) {}
};
typedef pair<int, float> grade;

int n, m;
vector<stu> stus;
vector<grade> ave;
vector<grade> clang;
vector<grade> math;
vector<grade> english;
map<int, int> table;

bool cmp(grade& a, grade b) { return a.second > b.second; }

void resgistRank(vector<grade>& v, char simbol) {
    if (debug) {
        printf("\n\tsimbol: %c\n", simbol);
        for (int i = 0; i < v.size(); i++) {
            printf("%f ", v[i].second);
        }
        printf("\n");
    }
    int realRank = 0;
    float lastScore = -1;
    if (debug) {
        printf("\trank %c\n", simbol);
    }
    for (int i = 0; i < v.size(); i++) {
        int pos = table[v[i].first];  //指向stus中当前学生所处的位置
        if (lastScore != v[i].second) {
            realRank = i;
            lastScore = v[i].second;
        }

        if (realRank < stus[pos].rank) {
            if (debug) printf("%d: %d %d\n", v[i].first, i, realRank);
            stus[pos].rank = realRank;
            stus[pos].simbol = simbol;
        }
    }
    if (debug) {
        printf("\trank %c end\n", simbol);
    }
}

int main(int argc, char const* argv[]) {
    if (argc > 1) debug = true;
    if (debug) freopen("12", "r", stdin);
    scanf("%d %d", &n, &m);
    if (debug) {
        printf("\tinput data\n");
    }
    for (int i = 0; i < n; i++) {
        int name;
        float c, m, e;
        scanf("%d %f %f %f", &name, &c, &m, &e);
        float a = (c + m + e) / 3.0;
        if (debug) {
            printf("%d %f %f %f %f\n", name, c, m, e, a);
        }
        stu temp(name, c, m, e, a);
        stus.push_back(temp);

        table[name] = i;  //在stu中的下标

        ave.push_back(grade(name, a));
        clang.push_back(grade(name, c));
        math.push_back(grade(name, m));
        english.push_back(grade(name, e));
    }
    if (debug) {
        printf("\tinput data end\n");
    }

    sort(ave.begin(), ave.end(), cmp);
    sort(clang.begin(), clang.end(), cmp);
    sort(math.begin(), math.end(), cmp);
    sort(english.begin(), english.end(), cmp);

    resgistRank(ave, 'A');
    resgistRank(clang, 'C');
    resgistRank(math, 'M');
    resgistRank(english, 'E');

    for (int i = 0; i < m; i++) {
        int id;
        scanf("%d", &id);
        if (table.find(id) == table.end()) {
            printf("N/A\n");
        } else {
            printf("%d %c\n", stus[table[id]].rank + 1, stus[table[id]].simbol);
        }
    }
    return 0;
}

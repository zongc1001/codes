
#include <algorithm>
#include <cstdio>
#include <map>
#include <string>
#include <vector>
using namespace std;

struct Stu {
    char level = '+';
    int site = 0;
    int date = 0;
    int num = 0;
    int score = 0;
};
typedef pair<int, int> ii;

bool debug = false;
int n, m;
vector<Stu> stus;
vector<Stu> stus2;
map<int, ii> siteToNtAndNs;
map<int, vector<ii> > dateToSiteAndNt;

void process(int type) {
    if (type == 1) {
        char level;
        scanf(" %c", &level);
        printf("%c\n", level);
        if (level == 'B' || level == 'A' || level == 'T') {
            for (int i = 0; i < stus.size(); i++) {
                if (stus[i].level == level) {
                    Stu& a = stus[i];
                    printf("%c%03d%06d%03d %d\n", a.level, a.site, a.date,
                           a.num, a.score);
                }
            }
        } else {
            printf("NA\n");
        }
    } else if (type == 2) {
        int site;
        scanf("%d", &site);
        printf("%d\n", site);
        if (siteToNtAndNs.find(site) != siteToNtAndNs.end()) {
            printf("%d %d\n", siteToNtAndNs[site].first,
                   siteToNtAndNs[site].second);

        } else {
            printf("NA\n");
        }

    } else if (type == 3) {
        int date;
        scanf("%d", &date);
        printf("%d\n", date);
        if (dateToSiteAndNt.find(date) != dateToSiteAndNt.end()) {
            for (auto it = dateToSiteAndNt[date].begin();
                 it != dateToSiteAndNt[date].end(); it++) {
                printf("%d %d\n", (*it).first, (*it).second);
            }
        } else {
            printf("NA\n");
        }
    } else {
        char a[20];
        scanf("%s", &a[0]);
    }
}
bool cmp(Stu& a, Stu& b) { return a.score > b.score; }
bool cmp2(ii& a, ii& b) { return a.second > b.second; }
int main(int argc, char const* argv[]) {
    debug = argc > 1;
    if (debug) {
        freopen("153", "r", stdin);
    }
    scanf("%d %d\n", &n, &m);

    for (int i = 0; i < n; i++) {
        Stu temp;
        scanf("%c %3d %6d %3d %d\n", &temp.level, &temp.site, &temp.date,
              &temp.num, &temp.score);
        stus.push_back(temp);
        if (siteToNtAndNs.find(temp.site) != siteToNtAndNs.end()) {
            siteToNtAndNs[temp.site].first++;
            siteToNtAndNs[temp.site].second += temp.score;
        } else {
            siteToNtAndNs[temp.site] = ii(1, temp.score);
        }
        if (dateToSiteAndNt.find(temp.date) != dateToSiteAndNt.end()) {
            bool found = false;
            for (int i = 0; i < dateToSiteAndNt[temp.date].size(); i++) {
                if (dateToSiteAndNt[temp.date][i].first == temp.site) {
                    dateToSiteAndNt[temp.date][i].second++;
                    found = true;
                    break;
                }
            }
            if(!found) {
                dateToSiteAndNt[temp.date].push_back(ii(temp.site, 1));
            }
        } else {
            dateToSiteAndNt[temp.date] = vector<ii>();
            dateToSiteAndNt[temp.date].push_back(ii(temp.site, 1));
        }
        // if (debug)
        //     printf("%c%03d%06d%03d %d\n", temp.level, temp.site, temp.date,
        //            temp.num, temp.score);
    }

    sort(stus.begin(), stus.end(), cmp);
    for(auto it = dateToSiteAndNt.begin(); it != dateToSiteAndNt.end(); it++) {
        sort((*it).second.begin(), (*it).second.end(), cmp2);

    }
    // if (debug ) {
    //     for (int i = 0; i < n; i++) {
    //         Stu& temp = stus[i];
    //         printf("%c%03d%06d%03d %d\n", temp.level, temp.site, temp.date,
    //                temp.num, temp.score);
    //     }
    // }
    for (int i = 1; i <= m; i++) {
        int type;
        scanf("%d", &type);
        printf("Case %d: %d ", i, type);
        process(type);
    }

    return 0;
}

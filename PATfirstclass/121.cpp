#include <algorithm>
#include <cstdio>
#include <map>
#include <set>
#include <vector>
using namespace std;
bool debug = false;

vector<int> haveCouple;
vector<int> single;
set<int> st;

int numOfCp, guest;
int main(int argc, char const *argv[]) {
    if(debug) freopen("121", "r", stdin);
    haveCouple.resize(100005, -1);
    scanf("%d", &numOfCp);
    for (int i = 0; i < numOfCp; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        haveCouple[a] = b;
        haveCouple[b] = a;
    }
    scanf("%d", &guest);
    vector<int> later;
    for (int i = 0; i < guest; i++) {
        int a;
        scanf("%d", &a);
        st.insert(a);
        later.push_back(a);
    }
    for (int i = 0; i < later.size(); i++) {
        if (haveCouple[later[i]] == -1 ||
            st.find(haveCouple[later[i]]) == st.end()) {
            single.push_back(later[i]);
        }
    }

    printf("%d\n", single.size());
    if (single.size() > 0) {
        sort(single.begin(), single.end());
        for (int i = 0; i < single.size(); i++) {
            if (i != 0) printf(" ");
            printf("%05d", single[i]);
        }
        printf("\n");
    }

    return 0;
}

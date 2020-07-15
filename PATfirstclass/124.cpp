#include <iostream>
#include <set>
#include <string>
using namespace std;
bool debug = false;
int m, n, s;
set<string> st;
int main(int argc, char const *argv[]) {
    debug = argc > 1;
    if(debug) freopen("124", "r", stdin);
    cin >> m >> n >> s;
    for (int i = 1; i <= m && i <= s; i++) {
        string temp;
        cin >> temp;
        if (i == s) {
            st.insert(temp);
            cout << temp << endl;
        }
    }
    int index = 0;
    for (int i = s + 1; i <= m; i++) {
        index++;
        string temp;
        cin >> temp;
        // if(debug) cout << i << ", " << index << ": "<< temp << endl;
        if (index == n) {
            if(debug) {
                cout << "i: " << i <<", " << temp << endl;
            }
            if (st.find(temp) == st.end()) {
                st.insert(temp);
                cout << temp << endl;
                index = 0;
            } else {
                if(debug) cout << "pause: " << temp << endl;
                index--;
            }
        }
    }
    if (st.size() == 0) {
        cout << "Keep going..." << endl;
    }

    return 0;
}

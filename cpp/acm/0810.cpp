#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int a[5][5];
set<int> st;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};


void dfs(int i, int j, int k, int num)
{
    if(k==5) {
        st.insert(num);
        return;
    }

    for(int t = 0; t < 4;t++) {
        int xx = i + dx[t], yy = j + dy[t];
        if(xx >=0 && xx < 5 && yy >= 0 && yy < 5) {
            k++;
            dfs(xx, yy, k, num * 10 + a[xx][yy]);
            k--;
        }
    }

}


int main(int argc, char const *argv[])
{
    for(int i = 0; i < 5;i++){
        for(int j = 0; j < 5;j++) {
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < 5;i++){
        for(int j = 0; j < 5;j++) {
            dfs(i, j, 0, a[i][j]);
        }
    }

    cout << st.size() << endl;    
    

    return 0;
}


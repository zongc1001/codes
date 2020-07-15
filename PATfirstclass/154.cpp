#include <iostream>
#include <vector>
#include <set>
using namespace std;

int n, m;

struct Vertex
{
    int num;
    int color;
    Vertex(int n, int c) :num(n), color(c) {}
};




int main(int argc, char const *argv[])
{
    cin >> n >> m;
    vector<vector<int> > edges(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    int k;
    cin >> k;
    int colors[n];
    while(k--) {
        
        set<int> s;
        for(int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            s.insert(temp);
            colors[i] = temp;
        }
        bool yes = true;
        for(int i = 0; i < edges.size(); i++) {
            for(int j = 0; j < edges[i].size(); j++) {
                if(colors[i] == colors[edges[i][j]]) {
                    yes = false;
                    break;
                }
            }
            if(!yes) break;
        }
        if(yes) {
            cout << s.size() << "-coloring" << endl;
        } else {
            cout << "No" << endl;
        }

    }
    


    return 0;
}

int step[4][2] = {
    {0, -1},
    {0, 1},
    {1, 0},
    (-1, 0)
};
vector<int> far;
int n, m;
class Solution {
public:

    int find(int cur)
    {
        vector<int> vec;
        while(cur != far[cur])
        {
            vec.push_back(cur);
            cur = far[cur];
        }
        for(int i = 0; i < vec.size();i++)
        {
            far[vec[i]] = cur;
        }
        return cur;
    }    
    
    void combine(int a, int b)
    {
        int fa = find(a);
        int fb = find(b);
        far[fa] = fb;
    }

    int index(int x, int y)
    {
        return x * n + y;
    }



    void solve(vector<vector<char>>& board) {
        if(board.size() == 0 || board[0].size() == 0)
            return;
        n = board.size();
        m = board[0].size();
        int finalNum = n * m;
        for(int i = 0; i < n;i++)
        {
            for(int j = 0; j < m ;j++)
            {
                if((i == 0 || i == n-1) ||
                   (j == 0 || j == m-1))
                {
                    far.push_back(finalNum);                   
                }
                else
                {
                    far.push_back(i);
                }
            }
        }
        far.push_back(n * m);
        for(int i = 1; i < board.size() - 1; i++)
        {
            for(int j = 1; j < board[0].size() - 1;i++)
            {
                if(board[i][j] == 'O')
                {
                    for(int t = 0; t < 4;t++)
                    {
                        int x = i + step[t][0];
                        int y = j + step[t][1];
                        if(x >=0 && x < n && y >= 0 &&y <m)
                            if(board[x][y] == 'O')
                            {

                                combine(index(i, j), index(x, y));
                                cout << "here" << endl;
                                break;
                            }
                    }
                }
            }
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(far[index(i, j)]  != finalNum)
                    board[i][j] == 'X';
            }
        }







    }
};
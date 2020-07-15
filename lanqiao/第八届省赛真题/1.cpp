#include <iostream>

using namespace std;

char maze[12][12];

int dir[300][2];

int mazeSize = 10;

int main(int argc, char const *argv[])
{
    int n = 100;
    dir['U'][0] = -1;
    dir['U'][1] = 0;

    dir['D'][0] = 1;
    dir['D'][1] = 0;

    dir['L'][0] = 0;
    dir['L'][1] = -1;

    dir['R'][0] = 0;
    dir['R'][1] = 1;
    
    
    
    for(int i = 1; i <= mazeSize;i++)
    {
        for(int j = 1; j <= mazeSize;j++)
        {
            cin >> maze[i][j];
        }
    }
    int res = 0;
    for(int i = 1; i <= mazeSize;i++)
    {
        for(int j = 1; j <= mazeSize;j++)
        {
            int n = mazeSize * mazeSize + 5;
            int x = i;
            int y = j;
            while(n--)
            {
                if(maze[x][y] == 0)
                {
                    res ++;
                    cout << "(x, y): " << i << ", " << j << endl;
                    break;
                }
                else
                {
                    int tempx = x, tempy = y;
                    x = x + dir[maze[tempx][tempy]][0];
                    y = y + dir[maze[tempx][tempy]][1];
                }
                
            }
        }
    }
    
    cout <<"res: " <<res << endl;
    
    
    
    
    return 0;
}

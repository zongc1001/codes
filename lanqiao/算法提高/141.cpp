#include <iostream>
#include <string>
#include <queue>
#include <vector> 
#include <stack>
using namespace std;
struct Pos
{
	int row, col;
	Pos(int r = 1, int c = 1)
		: row(r), col(c){} 
	
};

bool maze[500+10][500+10];
char pre[500 + 5][500+5];  //记录该点是在上一点从哪个方向来的 
char dir[4][3] = {
	{
		1, 0, 'D'
	},
	{
		0, -1, 'L'
	},
	{
		0, 1, 'R'
	},
	{
		-1, 0, 'U'
	}
};
queue<Pos> q;
int step = -1;

void printRoad(int row, int col)
{
	stack<char> s;

	while(!(row == 1 && col == 1))
	{
		s.push(pre[row][col]);
		if(pre[row][col] == 'U')
		{
			row++;
		}
		else if(pre[row][col] == 'D')
		{
			row--;
		}
		else if(pre[row][col] == 'L')
		{
			col++;
		}
		else if(pre[row][col] == 'R')
		{
			col--;
		}
		else
		{
			break;
		}
	} 
	while(!s.empty())
	{
		cout << s.top();
		s.pop();	
	}
	cout << endl;
}


int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
	 	string temp;
		cin >>temp;
		     	
        for(int j = 1; j <= m;j++)
        {
        	
            maze[i][j] = temp[j-1] - '0';
        }	
	}
	for(int i = 0 ; i <= n +1; i++)
	{
		maze[i][0] = 1;
		maze[i][m+1] = 1;
	}
	for(int i = 0 ; i <= m +1; i++)
	{
		maze[0][i] = 1;
		maze[n +1][i] = 1;
	}
	
	q.push(Pos(1,1));
	maze[1][1] = true;
	
	
	while(!q.empty())
	{
		int loopOfCurLevel = q.size();
		
		if(loopOfCurLevel != 0)
		{
			step++;
			for(int loop = 0; loop < loopOfCurLevel; loop++)
			{
				Pos temp = q.front();
				q.pop();
				
				if(temp.row == n && temp.col == m)
				{
					cout << step << endl;
					printRoad(n, m);
					
					return 0;
				}
				else
				{
					for(int i = 0; i < 4; i++)
					{
						int x = temp.row + dir[i][0],
							y = temp.col + dir[i][1];
						if(!maze[x][y])
						{
							q.push(Pos(x, y));
							maze[x][y] = true;		//push后应修改maze数组 
							pre[x][y] = dir[i][2];
							
						}
					}
				}
			}
		}
	}	
    return 0;
}

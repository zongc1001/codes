#include <iostream>

using namespace std;

const int MAX = 1000005;
const int inf = 0x7ffffff;


int a[MAX][MAX] = {inf};


int main(int argc, char const *argv[])
{
	int n;
	int m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		int v1, v2;
		cin >> v1 >>v2;
		cin >> a[v1][v2];
	}
	for(int k = 1; k <= n;k++)
	{
		for (int i = 1; i <= n; ++i)
		{
			for(int j = 1; j <= n;j++)
			{
				if(a[i][k] + a[k][j] < a[i][j])
					a[i][j] = a[i][k] + a[k][j];
			}
		}
	}

	cout << a[1][n] ;
	return 0;
}

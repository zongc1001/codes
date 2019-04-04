#include<iostream>

using namespace std;

bool table[50000][20];
char num[50000];
int type = 1;
int index = -1;
int n, m;
int nextIndex()
{
	for(int i = index + 1; i < n;i++)
	{
		if(num[i] == 0)
			{
				index = i;
				return index;
			}
	}
	return -1;
}


int main()
{

	cin >> n >> m;
	for(int i = 0; i < n;i++)
		for(int j = 0; j < m;j++)
		{
			cin >> table[i][j];
		}
	
	
	while (true)
	{
		int index = nextIndex();
		if(index == -1) break;
		num[index] = type++;
		for(int i = index + 1;i < n;i++)
		{
			if(num[i] != 0)
				continue;
			int sum = 0;
			for(int j = 0; j < m;j++)
			{
				if(table[index][j] == table[i][j])
					sum++;
			}
			if(sum == m)
				num[i] = num[index];
			if(sum == 0)
				num[i] = -num[index]; 
		}
	}
//	cout << "type: " << type << endl;
	int result = 0;
	for(int i = 1; i <= n / 2 + 1;i++)
	{
		int temp1 = 0, temp2 = 0;
		for(int j = 0; j < n;j++)
		{
			if(num[j] == i) temp1++;
			if(num[j] == -i) temp2++;
		}
		result += temp1*temp2;
	}
	cout << result;
	
 } 

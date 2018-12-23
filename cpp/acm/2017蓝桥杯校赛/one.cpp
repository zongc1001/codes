#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 10000005;

int lines[MAX];
bool isTri(int a, int b, int c)
{
	return a + b > c &&
		   b + c > a &&
		   a + c > b;
}


int main(int argc, char const *argv[])
{
	int n;
	cin >> n;


	for(int i = 0; i < n;i ++)
	{
		cin>>lines[i];
		
	}

	sort(lines, lines + n);
	for(int i = 0; i < n -2;i ++)
	{
		if(isTri(lines[i], lines[i+1], lines[2]))
		{
			cout<<"YES"  << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	std::vector<string> v;
	string temp;
	v.push_back("123456789");	
	v.push_back("abcdefghij");	
	v.push_back("qwerdf");	

	cout << "find -----" << endl;

	for (int i = 0; i < 100; ++i)
	{
		cin >> temp;
		for (int j = 0; j < 3; ++j)
		{
			if(v[j].find(temp) != -1)
				cout << "found in "<<j << endl;
		}

	}


	return 0;
}
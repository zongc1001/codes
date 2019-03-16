#include <iostream>
using namespace std;
char* prefix(char* haystack_start, char* needle_start)
{
	char* haystack = haystack_start;
	char* needle = needle_start;
	// cout << haystack << endl;
	// cout << ++ haystack << endl;
	
	while(*haystack && *needle){
		if( ++haystack == ++needle) return NULL;  //填空位置
	}
	
	if(*needle) return NULL;
	
	return haystack_start;
}
int main(int argc, char const *argv[])
{
	char a[10];
	char b[10];
	cin >> a >> b;

	if(prefix(a, b))
		cout << "yes" << endl;
	else
		cout << "no" <<endl;

	return 0;
}
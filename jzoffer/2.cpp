#include <iostream>
#include <vector>
#include <malloc.h>
using namespace std;
class Solution {
public:
	void replaceSpace(char *str,int length) {
        int len = 0;
		while (str[len++] != '\0');
		
		
		char str2[len*3];
		int k = 0;

		for(int i = 0; i < len;i++) {
			if(str[i] == ' ') {
				str2[k] = '%';
				str2[++k] = '2';
				str2[++k] = '0';
			}
			else {
				str2[k] = str[i];

			}
				k++;

		}
		if(k > length) return;
		for(int i = 0; i < k;i++) {
			str[i] = str2[i];
		}
		str[k] = '\0';



	}
};


int main(int argc, char const *argv[])
{
	char str[100] = "hello world";
	int length = 100;
	Solution s;
	s.replaceSpace(str, length);
	
	cout << str << endl;
	return 0;
}




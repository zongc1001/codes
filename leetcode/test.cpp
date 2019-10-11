#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int s[10];
    int len = 10;
    for(int i = 0; i < len;i++) {
        s[i] = i;
    }
    int reverseNum = len - (len & 1);
    
    for(int i = len/2; i != len && i != -1;
        i =  (reverseNum < len ? ++reverseNum : --reverseNum) - i ) {
        cout << s[i] << endl;
    }







    return 0;
}

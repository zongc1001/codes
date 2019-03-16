#include<iostream>
#include<string>
#include<sstream>
using namespace std;

char num[100005];
int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    int temp;
    string stemp;
    string s;
    getline(cin, stemp);
    for(int i = 0; i < N;i++)
    {
        getline(cin, s);
        stringstream ss(s);
        while(ss>>temp)
            num[temp]++;
    }
    int begin;
    int m =0, n = 0;
    bool is = true;
    for(int i = 1; i <= 100000;i++)
    {
        if(is && num[i] != 0)
        {
            begin = i;
            is = false;
        }
        if(m == 0 && num[i] == 0 && (num[i-1] > 0 && num[i+1] > 0))
            m = i;
        if(num[i] == 2)
        {
             n = i; 
        }
        
    }
    if(m == 0)
    {
          m = begin-1;
          //cout << "here" << endl;
    }
      

    cout << m << " " << n;
    return 0;
}

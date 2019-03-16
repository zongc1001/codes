#include<sstream>
#include<string>
#include<iostream>
using namespace std;
int main(){
    string line;
    while(getline(cin,line)){
        int x;
        stringstream ss(line);  //建立stringstream对象，初始化流内容为line所代表的字符串
        while(ss>>x)            //从line中一次读取数字存入x
        cout<<x<<endl;
    }
    return 0;
}

#include<iostream>
using namespace std;

struct EV
{
	int result;  //计算结果 
	int n;       //消耗掉的字符数
};

struct EV evaluate(char* x)
{
	struct EV ev = {0,0};
	struct EV v1;
	struct EV v2;
	if(*x==0) 
	{
		cout << "*x == 0"<< endl;
		return ev;
	}
    if(x[0]>='0' && x[0]<='9') {
		ev.result = x[0]-'0';
		ev.n = 1;
		return ev;
	//- + 3 * 5 + 2 6 1	
    }
    // 3 + 5 * (2 + 6) - 1
	//cout << "---" << endl;
	v1 = evaluate(x+1);
	v2 = evaluate(x + v1.n + 1);  //填空位置
	if(x[0]=='+') ev.result = v1.result + v2.result;
	
	if(x[0]=='*') ev.result = v1.result * v2.result;

	if(x[0]=='-') ev.result = v1.result - v2.result;
	
	ev.n = 1+v1.n+v2.n;
	return ev;

}


//-+3*5+261
int main(int argc, char const *argv[])
{
    char a[10];
	cin >> a;
	struct EV re = evaluate(a);
	cout << re.result << endl;


    return 0;
}

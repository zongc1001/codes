#include <cstdio>
#include <vector>
using namespace std;

bool debug = false;

typedef int ll;

struct obj
{
	ll x, y;
	char type;
	// obj(x, y, type) : x(x), y(y), type(type) {}
};

int n, m;
vector<obj> vec;

int main(int argc, char const *argv[])
{
	if (argc > 1)
	{
		debug = true;
	}
	if (debug)
		freopen("1", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		obj temp = obj();
		scanf("%d %d %c", &temp.x, &temp.y, &temp.type);
		vec.push_back(temp);
	}

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		char tag; //代表在直线上面的类型
		if (a + b * vec[0].x + c * vec[0].y > 0)
		{
			tag = vec[0].type;
		}
		else
		{
			tag = vec[0].type == 'B' ? 'A' : 'B';
		}
		if(debug)
		{
			printf("tag: %c\n", tag);
		}
		bool res = true;
		for (int j = 0; j < vec.size(); j++)
		{

			ll sum = a + b * vec[j].x + c * vec[j].y;
			if(debug)
			{
				printf("%d %d %c\n", vec[j].x, vec[j].y, vec[j].type);
			}

			if (debug)
			{
				printf("sum: %ld\n", sum);
				printf("sum > 0 ?: %d\n", sum > 0);
			}
			
			bool temp = (sum > 0) ? (vec[j].type == tag) : (vec[j].type != tag);
			if (debug)
			{
				printf("temp: %d\n", temp);
			}

			if (!temp)
			{
				res = false;
				break;
			}
		}
		printf(res ? "Yes\n" : "No\n");
	}

	return 0;
}

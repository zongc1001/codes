//http://lx.lanqiao.cn/problem.page?gpid=T454

#include <cstdio>
#include <vector>
using namespace std;
bool debug = false;

int n, k;
const int MAX = 100000;
int arr[MAX + 10];
unsigned long long restNum[MAX + 10];
bool is[MAX + 10];
unsigned long long res = 0;
vector<int> scores;
int maxScore = 0;
vector<bool> visited;

void dfs(int cur, int result)
{
	if (debug)
	{
		printf("cur:%d, result:%d\n", cur, result);
	}
	if (result + restNum[scores[cur]] < res)
	{
		return;
	}

	if (result > res)
	{
		res = result;
	}

	for (int i = cur + 1; i < scores.size(); i++)
	{
		if (!(scores[i] - k >= 0 && visited[scores[i] - k]))
		{
			visited[scores[i]] = true;
			result += arr[scores[i]];
			dfs(i, result);
			visited[scores[i]] = false;
			result -= arr[scores[i]];
		}
	}
}

int main(int argc, char const *argv[])
{
	if (argc > 1)
	{
		debug = true;
	}

	if (debug)
	{
		freopen("50", "r", stdin);
	}

	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		int temp;
		scanf("%d", &temp);
		arr[temp]++;
		if (temp > maxScore)
		{
			maxScore = temp;
		}
	}
	visited.resize(maxScore + 1, false);
	int tempResult = 0;

	for (int i = 0; i <= maxScore; i++)
	{
		if (arr[i] > 0)
		{
			if ((i - k < 0 || arr[i - k] == 0) && (i + k > MAX || arr[i + k] == 0))
			{
				visited[i] = true;
				tempResult += arr[i];
			}
			else
			{
				scores.push_back(i);
			}
		}
	}
	if (debug)
	{
		printf("tempResult init:%d\n", tempResult);
	}
	if (k == 0)
	{
		printf("%d\n", scores.size());
		return 0;
	}
	if (scores.size() == 0)
	{
		res = tempResult;
		printf("%d\n", res);
		return 0;
	}
	restNum[scores.back()] = 0;

	for (int i = scores.size() - 2; i >= 0; i--)
	{
		restNum[scores[i]] = arr[scores[i + 1]] + restNum[scores[i + 1]];
	}
	if (debug)
	{
		for (int i = 0; i <= maxScore; i++)
		{
			printf("%d ", restNum[i]);
		}
		printf("\n");
	}

	for (int i = 0; i < scores.size(); i++)
	{
		visited[scores[i]] = true;
		tempResult += arr[scores[i]];
		dfs(i, tempResult);
		visited[scores[i]] = false;
		tempResult -= arr[scores[i]];
	}
	printf("%d\n", res);
	return 0;
}

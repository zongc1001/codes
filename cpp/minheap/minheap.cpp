#include <iostream>

using namespace std;

void siftAjust(int elem[], int low, int high)
{
	for(int f = low, i = 2*low+1; i <= high; i = 2*i+1)
	{
		if(i < high && elem[i] < elem[i+1])
		{
			i++;
		}
		if(elem[f] >= elem[i])
		{
			break;
		}
		int temp = elem[f];
		elem[f] = elem[i];
		elem[i] = temp;

		f = i;
	}
}


void heapSort(int a[], int n)
{
	for(int i = (n-2)/2; i>=0;i--)
	{
		siftAjust(a, i, n-1);
	}

	for(int i = n-1; i > 0;i--)
	{
		int temp = a[i];
		a[i] = a[0];
		a[0] = temp;
		siftAjust(a, 0, i-1);
	}

}


int main(int argc, char const *argv[])
{
	int a[10] = {36, 48, 48, 90, 88, 80, 76, 99};
	heapSort(a, 8);
	
	for (int i = 0; i < 8;i++)
	{
		cout << a[i] << "  ";
	}
	cout << endl;
	return 0;
}

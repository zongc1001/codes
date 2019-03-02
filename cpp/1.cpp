#include<stdio.h>
#include<math.h>
int n,i,j,k,a[100],m=0;
int judge()
 {
 	for(j=0;j<10;j++)
 	{
 		scanf("%d",&n);
 		k=sqrt(n);
 		for(i=2;i<=k;i++)
 			if(n%i==0)
 				break;
 		if(i>=k+1)
 		{
 			a[m]=n;
 			m++;
		}
	}
 	return m;
}

int main()
{
	m=judge();
	for(i=0;i<m;i++)
		printf("%d ",a[i]);
	return 0;
	
} 

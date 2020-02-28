#include <stdio.h>
#include <conio.h>
#define N 10
int x[N]={0},w[N],n,i,m;
void sumofsub(int s,int k,int r)
{
	int i;
	x[k]=1;
	if (s + w[k] == m)
	{	
		for (i = 1 ;i <= n;i++)
		{ printf("%d ",x[i]);}
	}
	else if (s + w[k] + w[k+1] <= m)
		sumofsub(s + w[k],k+1,r-w[k]);
	if ((s + r - w[k] >= m) && (s + w[k+1] <= m))
	{
		x[k] = 0;
		sumofsub(s,k+1,r-w[k]);
	}
	return;
}

void main()
{
	clrscr();
	printf("Enter no of items : ");
	scanf("%d",&n);
	printf("Enter Weights : ");
	for(i=1;i<=n;i++)
		scanf("%d",&w[i]);
	printf("Enter req sum : ");
	scanf("%d",&m);
	sumofsub(0,1,m);
}
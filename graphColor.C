#include <stdio.h>
#include <conio.h>
#define N 10
int adj[N][N]={
				{0,0,0,0,0},
				{0,0,1,1,1},
				{0,1,0,0,1},
				{0,1,0,0,1},
				{0,1,1,1,0},
};
int x[N]={0},n,m;
void nextvalue(int k)
{
	int j;
	pt:
	  x[k]=(x[k]+1)%(m+1);
	if(x[k]==0)
		return;
	for(j=1;j<=k-1;j++)
	{
		if(adj[j][k]==1 && x[j]==x[k])
			goto pt;
	}
}

void colorgraph(int k)
{
	int i;
	nextvalue(k);
	if(x[k]==0)
		return;
	if(k==n)
	{
		for(i=1;i<=n;i++)
			printf("%d  ",x[i]);
	}
	else
		colorgraph(k+1);
}

void main()
{
	clrscr();
	printf("Enter no of vertices :");
	scanf("%d",&n);
	printf("Enter no of colors : ");
	scanf("%d",&m);
	colorgraph(1);
	getch();

}
#include<stdio.h>
#include<conio.h>
void minmax(int x[],int i,int j,int *fmin,int *fmax)
{
	int m,gmin,gmax,hmin,hmax;
	if(i==j)
	{
		*fmin=x[i];
		*fmax=x[i];
	}
	else if(i==j-1)
	{
		if(x[i]<x[j])
		{
			*fmin=x[i];
			*fmax=x[j];
		}
		else
		{
			*fmin=x[j];
			*fmax=x[i];			
		}
	}
	else
	{
		m=(i+j)/2;
		minmax(x,i,m,&gmin,&gmax);
		minmax(x,m+1,j,&hmin,&hmax);
		if(gmin<hmin)
			*fmin=gmin;
		else
			*fmin=hmin;
		if(gmax>hmax)
			*fmax=gmax;
		else
			*fmax=hmax;
	}
}
void main()
{
	int i,n,fmin,fmax,x[10];
	clrscr();
	printf("Enter no of integers : ");
	scanf("%d",&n);
	printf("Enter elements : ");
	for(i=0;i<n;i++)
		scanf("%d",&x[i]);
	minmax(x,0,n-1,&fmin,&fmax);
	printf("MIN = %d \n MAX = %d ",fmin,fmax);
	getch();
}
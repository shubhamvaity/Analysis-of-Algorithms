#include <stdio.h>
#include <conio.h>
void merge(int x[],int lb,int m,int ub)
{
	int temp[20],i,j,k;
	i=lb;
	j=m+1;
	k=0;
	while(i<=m && j<=ub)
	{
		if(x[i]<x[j])
			temp[k++]=x[i++];
		else
			temp[k++]=x[j++];
	}
	while(i<=m)
		temp[k++]=x[i++];
	while(j<=ub)
		temp[k++]=x[j++];
	k=0;
	for(i=lb;i<=ub;i++)
		x[i]=temp[k++];
}

void mergesort(int x[],int lb,int ub)
{
	int m;
	if(lb<ub)
	{
		m=(lb+ub)/2;
		mergesort(x,lb,m);
		mergesort(x,m+1,ub);
		merge(x,lb,m,ub);
	}
}

void main()
{
	int x[10],i,n,lb,ub;
	clrscr();
	printf("Enter no of elements: ");
	scanf("%d",&n);
	lb=0;
	ub=n-1;
	printf("\nElements are :");
	for(i=0;i<n;i++)
	{
		scanf("%d",&x[i]);
	}
       mergesort(x,lb,ub);
       printf("\n Sorted elements are :");
       for(i=0;i<n;i++)
       {
		printf("%d  ",x[i]);
       }
       getch();
}
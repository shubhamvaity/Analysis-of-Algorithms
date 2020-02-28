
#include <stdio.h>
#include <conio.h>
int partition(int x[],int lb,int ub)
{
	int val=x[lb],down=lb+1,up=ub,t;
	while(down<=up)
	{
		while(down<=up && x[down]<val)
			down++;
		while(x[up]>val)
			up--;
		if(down<up)
		{
			t=x[down];
			x[down]=x[up];
			x[up]=t;
		}
	}

	x[lb]=x[up];
	x[up]=val;
	return up;
}

void quicksort(int x[],int lb,int ub)
{
	int p;
	if(lb<ub)
	{
		p=partition(x,lb,ub);
		quicksort(x,lb,p-1);
		quicksort(x,p+1,ub);
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
       quicksort(x,lb,ub);
       printf("\n Sorted elements are :");
       for(i=0;i<n;i++)
       {
		printf("%d  ",x[i]);
       }
       getch();
}
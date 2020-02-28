#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
	char T[30],P[10];
	int i,j,m,n;
	clrscr();
	printf("Enter Text : ");
	gets(T);
	printf("\nEnter Pattern : ");
	gets(P);
	n=strlen(T);
	m=strlen(P);
	for(i=0;i<=n-m;i++)
	{
		j=0;
		while(j<m && T[i+j]==P[j])
		{
			j=j+1;
		}
		if(j==m)
		{	printf("\nPattern found at %d location \n",i);
			puts(P);
			break;
		}
	}
	getch();
}


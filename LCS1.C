#include <stdio.h>
#include <conio.h>
#include <string.h>
#define N 10
int i,j,m,n,c[N][N];
char x[N],y[N],b[N][N];

void printlcs(int i,int j)
{
	if(i==0 || j==0)
		return;
	if(b[i][j]=='D')
	{
		printlcs(i-1,j-1);
		printf("%c",x[i-1]);
		
	}
	else if(b[i][j]=='U')
	{
		printlcs(i-1,j);
	}
	else
		printlcs(i,j-1);

}
void lcs()
{
	m=strlen(x);
	n=strlen(y);
	for(i=0;i<=m;i++)
		c[i][0]=0;
	for(i=0;i<=n;i++)
		c[0][i]=0;
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(x[i-1]==y[j-1])
			{
				c[i][j]=c[i-1][j-1]+1;
				b[i][j]='D';
			}
			else if(c[i-1][j]>=c[i][j-1])
			{
				c[i][j]=c[i-1][j];
				b[i][j]='U';
			}
			else
			{
				c[i][j]=c[i][j-1];
				b[i][j]='L';
			}
		}
	}
}
void main()
{
	clrscr();
	printf("Enter 1st sequence:\n");
	gets(x);
	printf("Enter 2nd sequence:\n");
	gets(y);
	printf("Longest Common Subsequence is : ");
	lcs();
	printlcs(m,n);
	getch();
}	



#include <stdio.h>
#include <conio.h>
#include <string.h> 
#define N 20
void kmpfailure(char p[],int m,int f[])
{
	int i=1,j=0;
	f[0]=0;
	while(i<m)
	{
		if(p[j]==p[i])
		{
			f[i]=j+1;
			i=i+1;
			j=j+1;
		}
		else if(j>0)
			j=f[j-1];
		else
		{
			f[i]=0;
			i=i+1;
		}
	}
}

int kmpmatch(char t[N],char p[],int m,int n,int f[])
{
	int i=0,j=0;
	while(i<n)
	{
		if(t[i]==p[j])
		{
			if(j==m-1)
				return i-m+1;
			else
			{
				i=i+1;
				j=j+1;
			}
		}
		else if(j>0)
			j=f[j-1];
		else
			i=i+1;
	}
	return -1;
}
void main()
{
	char t[N],p[N];
	int m,n,i,flag,f[N];
	clrscr();
	printf("Enter Text : ");
	gets(t);
	printf("Enter pattern : ");
	gets(p);
	n=strlen(t);
	m=strlen(p);
	kmpfailure(p,m,f);
	printf("prefix fn \n");
	for(i=0;i<m;i++)
		printf("%d   ",f[i]);
	flag=kmpmatch(t,p,m,n,f);
	if(flag==-1)
		printf("\npattern not found \n");
	else
		printf("\npattern found at %d\n",flag);
	getch();
}
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <math.h>
# define N 20
void rabinkarp(char text[],char pat[],int d,int q,int m,int n)
{
	long p=0,t=0,i,j,h,t0,t1,t2,flag;
	t0=pow(d,m-1);
	h=t0%q;
	for(i=0;i<m;i++)
	{
		t1=(d*p+pat[i]);
		t2=(d*t+text[i]);
		p=t1%q;
		t=t2%q;
	}
	for(i=0;i<=n-m;i++)
	{
		if(p==t)
		{
			for(j=0;j<m;j++)
			{
				if(text[i+j]!=pat[j])
				{
					goto label;
				}

			}
			label:
				if(j==m)
				{
					printf("Pattern found at %ld\n",i);
					flag=1;
				}
		}


		if(i<n-m)
		{
			t=(d*(t-text[i]*h)+text[i+m])%q;
			if(t<0)
				t=t+q;
		}
	}
	if(flag != 1)
		printf("\n Pattern not found ");
}

void main()
{
	char t[N],p[N];
	int m,n,d,q;
	clrscr();
	printf("Enter Text : ");
	gets(t);
	printf("Enter pattern : ");
	gets(p);
	printf("Enter size of ip alphabet : " );
	scanf("%d",&d);
	printf("Prime no :" );
	scanf("%d",&q);
	n=strlen(t);
	m=strlen(p);
	rabinkarp(t,p,d,q,m,n);
	getch();
}	
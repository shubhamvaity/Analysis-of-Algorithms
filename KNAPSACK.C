#include<stdio.h>
#include<conio.h>
float w[10],p[10];
void fknap(int n,int m)
{
	int i,j;
	float x[10],cp=0.0,cw=0.0,t;
	for(i=0;i<n;i++)
		x[i]=0.0;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if((p[i]/w[i])<(p[j]/w[j]))
			{
				t=p[i];
				p[i]=p[j];
				p[j]=t;
				t=w[i];
				w[i]=w[j];
				w[j]=t;

			}
		}
	}
	printf("Item\tPofit\tWeight\tP/w\n" );
	for(i=0;i<n;i++)
	{
		printf("%d\t%.2f\t%.2f\t%.2f\n",i+1,p[i],w[i],(p[i]/w[i]));
	}
	for(i=0;i<n;i++)
	{
		if(cw+w[i]<m)
		{
			x[i]=1.0;
			cp=cp+p[i];
			cw=cw+w[i];
		}	
		else
	    {
	    x[i]=(m-cw)/w[i];
	    cp=cp+(p[i]*x[i]);
	    cw=m;
	    }
	} 
	printf("\nProfit:%.2f\n",cp);
	printf("Weight:%.2f\n",cw);
	printf("Selection Array:\n");
	for(i=0;i<n;i++)
		printf("%.1f   ",x[i]);

}
void main()
{
	int n,i,m;
	clrscr();
	printf("Enter no of items : ");
	scanf("%d",&n);
	printf("Enter Capacity : ");
	scanf("%d",&m);
	for(i=0;i<n;i++)
	{
		printf("Enter weight and profit of item %d :",i+1);
		scanf("%f%f",&w[i],&p[i]);
	}
	fknap(n,m);
	getch();
}

/*
Enter no of items : 3
Enter Capacity : 20                                                             
Enter weight and profit of item 1 :18 25                                        
Enter weight and profit of item 2 :15 24                                        
Enter weight and profit of item 3 :10 15                                        
Item    Pofit   Weight  P/w                                                     
1       24.00   15.00   1.60                                                    
2       15.00   10.00   1.50                                                    
3       25.00   18.00   1.39                                                    
                                                                                
Profit:31.50                                                                    
Weight:20.00
Selection Array:                                                                
1.0   0.5   0.0

*/
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                

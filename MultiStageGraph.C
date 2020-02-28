#include <stdio.h>
#include <conio.h>
#define INF 9999
#define MAX 10
void multistage(int c[MAX][MAX],int k, int n , int P[MAX])
{       
    int COST[MAX],D[MAX],min,pmin,r,i,j;
    for (i = 1 ; i <= n ; i++)
    {
        COST[i] = 0;
        D[i]=0;
    }
    for (j = n-1 ; j >= 1 ; j--)
    {       
        min = INF;
        for(r = 1 ; r <= n ; r++)
            if (c[j][r] != 0 && (c[j][r] + COST[r]) < min)
            {      
                min = c[j][r] + COST[r];
                pmin = r;  
            }
            COST[j] = min;
            D[j] =pmin;     
    }
    P[1] = 1;
    P[k] = n;
    for (j = 2 ; j <= k-1; j++)
        { 
            P[j] = D[P[j-1]];     
        }
    return;
}
 void main()
{ 
    int x,y,P[MAX]={0},n=0,i=0,k=0;
    int c[MAX][MAX]={
             {INF, INF, INF, INF, INF, INF, INF, INF},
             {INF, INF, 1, 2, 5, INF, INF, INF, INF},
             {INF, INF, INF, INF, INF, 4, 11, INF, INF},
             {INF, INF, INF, INF, INF, 9, 5, 16, INF},
             {INF, INF, INF, INF, INF, INF, INF, 2, INF},
             {INF, INF, INF, INF, INF, INF, INF, INF, 18},
             {INF, INF, INF, INF, INF, INF, INF, INF, 13},
             {INF, INF, INF, INF, INF, INF, INF, INF, 2},
             {INF, INF, INF, INF, INF, INF, INF, INF, INF}};
    clrscr();
    printf("Enter no. of vertices :: ");
    scanf("%d",&n);
    printf("Enter no. of stages :: ");
    scanf("%d",&k);
    for (i = 0 ; i <= MAX-1 ; i++)
    {       
        P[i] = 0;       
    }
        multistage(c,k,n,P);
        printf("The shortest path is \n");
        for(i = 1; i <= k ; i++)
                printf("%d ",P[i]);
	getch();
}



// int graph[V][V]={
//                         {0,250,160,100,0},
//                         {250,0,80,0,70},
//                         {160,80,0,50,20},
//                         {100,0,50,0,40},
//                         {0,70,20,40,0},
//     };

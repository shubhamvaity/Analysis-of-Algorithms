#include<stdio.h>
#include <conio.h>
#define N 10
#define INF 9999

int findminvertex(int dist[],int visited[],int n)
{
	int minvertex=-1,i;
	for(i=0;i<n;i++)
	{
		if(visited[i]==0 && (minvertex ==-1 || dist[i]<dist[minvertex]))
		{
			minvertex=i;
		}
	}
	return minvertex;
}
void dijkstras(int edges[N][N],int n)
{
	int dist[N],visited[N],d,i,j,minvertex;
	for(i=0;i<n;i++)
	{
		visited[i]=0;
		dist[i]=INF;
	}
	dist[0]=0;
	for(i=0;i<n;i++)
	{
		minvertex=findminvertex(dist,visited,n);
		visited[minvertex]=1;
		for(j=0;j<n;j++)
		{
			if(edges[minvertex][j]!=0 && visited[j]==0)
			{
				d=dist[minvertex]+edges[minvertex][j];
				if(d<dist[j])
				{
					dist[j]=d;
				}
			}
		}
	}

	for(i=0;i<n;i++)
	{
		printf("  %d  -  %d  \n",i,dist[i]);
	}

}

void main()
{
	int graph[N][N]={
				{0,250,160,100,0},
				{250,0,80,0,70},
	            {160,80,0,50,20},
                {100,0,50,0,40},
                {0,70,20,40,0},
				};
	int v;
	clrscr();
	printf("Enter no of vertices : ");
	scanf("%d",&v);			
	dijkstras(graph,v);
	getch();

}
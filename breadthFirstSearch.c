//Vertices start from 1,2,3.....
#include<stdio.h>
#include<stdlib.h>
struct queue{
	int data[100];
	int front;
	int rear;
};
int v[10],k=0;
queue insert(queue q,int n)
{
	int i;
	if(q.rear==99)
	{
		printf("Overflow\n");
		return q;
	}
	for(i=0;i<=k;i++)
	{
		if(v[i]==n)
			return q;
	}
	for(i=q.front;i<=q.rear;i++)
	{
		if(q.data[i]==n)
			return q;
	}
	q.data[++q.rear]=n;
	return q;
}
int remove(queue *p)
{
	return p->data[p->front++];
}
main()
{
	int a[10][10];
	queue q;
	int i,j,n,s;
	q.front=0;
	q.rear=-1;
	queue* p=&q;
	printf("Enter no. of edges ");
	scanf("%d",&n);
	printf("Enter adjacency matrix\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	printf("Enter starting vertex ");
	scanf("%d",&s);
	s-=1;
	v[k]=s;
	int t=s;
	while(k!=n-1)
	{
		for(i=0;i<n;i++)
		{
			if(a[s][i]==1)
				q=insert(q,i);
		}
		v[++k]=remove(p);
		s=v[k];
	}
	while(q.front<=q.rear)
	{
		v[++k]=remove(p);
	}
	for(i=0;i<=k;i++)
	{
		printf("%d ",v[i]+1);
	}
}

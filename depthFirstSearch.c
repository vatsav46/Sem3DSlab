//Vertices start from 1,2,3.....
#include<stdio.h>
#include<stdlib.h>
struct stack{
	int data[100];
	int top;
};
int v[10],k=0;
stack push(stack st,int n)
{
	int i;
	if(st.top==99)
	{
		printf("Overflow\n");
		return st;
	}
	for(i=0;i<=k;i++)
	{
		if(v[i]==n)
			return st;
	}
	for(i=0;i<=st.top;i++)
	{
		if(st.data[i]==n)
			return st;
	}
	st.data[++st.top]=n;
	return st;
}
int pop(stack *p)
{
	return p->data[p->top--];
}
main()
{
	int a[10][10];
	stack st;
	int i,j,n,s;
	st.top=-1;
	stack* p=&st;
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
		for(i=n-1;i>-1;i--)
		{
			if(a[s][i]==1)
				st=push(st,i);
		}
		v[++k]=pop(p);
		s=v[k];
	}
	while(st.top!=-1)
	{
		v[++k]=pop(p);
	}
	for(i=0;i<=k;i++)
	{
		printf("%d ",v[i]+1);
	}
}

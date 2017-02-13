#include <stdio.h>
#include <stdlib.h>

void preOrder(int *a,int i,int n)
{
	if(i<n)
	{
		preOrder(a,2*i,n); //left child
		preOrder(a,2*i+1,n); //right child
		printf("%d, ",a[i]); //root
	}
}

void inOrder(int *a,int i,int n)
{
	if(i<n)
	{
		inOrder(a,2*i,n); //left child
		printf("%d, ",a[i]); //root
		inOrder(a,2*i+1,n); //right child
	}
}

void postOrder(int *a,int i,int n)
{
	if(i<n)
	{
		printf("%d, ",a[i]); //root
		postOrder(a,2*i,n); //left child
		postOrder(a,2*i+1,n); //right child
	}
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    //Inpreorder
    int n; //no of nodes
    scanf("%d",&n);
    int *a=(int*)malloc(sizeof(int)*n+5); //tree
    int i; //iter
    for(i=1;i<=n;i++)
    {
		scanf("%d",&a[i]);
	}
	printf("prorder : ");
	preOrder(a,1,n);
	printf("\ninorder : ");
	inOrder(a,1,n);
	printf("\npostorder : ");
	postOrder(a,1,n);
	printf("\n");
    return 0;
}

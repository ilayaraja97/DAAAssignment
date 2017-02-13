#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

//list data structure
struct node{
	int x;
	struct node *n;
};

void insert(struct node **head,int e)
{
	struct node *n=*head,*x=(struct node *)malloc(sizeof(struct node));
	x->x=e;
	if(*head==NULL)
	{
		//first element
		x->n=NULL;
		*head=x;
		return;
	}
	while(n->n!=NULL)
	{
		n=n->n;
	}
	{
		//insert at beginning
		n->n=x;
		x->n=NULL;
		return;
	}
}

int maxInArray(int *a,int start,int end)
{
	assert(a!=NULL&&start<end);
	int i,max=a[0];
	for(i=start+1;i<end;i++)
	{
		if(max<a[i])
		{
			max=a[i];
		}
	}
	return max;
}

void displayList(struct node *list,int *a,int *i)
{
	while(list!=NULL)
    {
        //printf("%d (%d) -> ", list->x,*i);
        a[*i]=list->x;
        (*i)++;
        list = list->n;
    }
    //printf("null\n");
}

void radixSort(int *a,int start,int end)
{
	int max=maxInArray(a,start,end);
	int j,k,p,pp;
	for(p=10,pp=1;pp<max;pp*=10,p*=10)
	{
		//start insertion
		struct node *b[10]={NULL};
		for(j=start;j<end;j++)
		{
			insert( &b[ (int)( (a[j] % p )/pp ) ] , a[j]);
		}
		for(k=0,j=start;k<10;k++)
		{
			displayList(b[k],a,&j);
		}
		//printf("%d\n\n",pp);
		
	}
	
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    //radixsort
    int n,i;
	scanf("%d",&n);
    int *a=(int*)malloc(n*sizeof(int));
    //struct node *list=NULL;
    for(i=0;i<n;i++)
    {
		scanf("%d",&a[i]);
		//insertSorted(&list,a[i]);
		//displayList(list);
	}
	radixSort(a,0,n);
	for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
        //printf("\n%f ", list->x);
        //list = list->n;
    }
    printf("\n");
    //displayList(list);
    return 0;
}

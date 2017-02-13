#include <stdio.h>
#include <stdlib.h>

//list data structure
struct node{
	float x;
	struct node *n;
};

//void displayList(struct node *);

void insertSorted(struct node **head,float e)
{
	struct node *n=*head,*p=*head,*x=(struct node *)malloc(sizeof(struct node));
	x->x=e;
	if(*head==NULL)
	{
		//first element
		x->n=(void*)0;
		*head=x;
		return;
	}
	while(n!=NULL && n->x <= x->x)
	{
		p=n;
		n=n->n;
	}
	if(p==n)
	{
		//insert at beginning
		x->n=p;
		*head=x;
		return;
	}
	else
	{
		x->n=n;
		p->n=x;
		return;
	}
	//displayList(*head);
}

void displayList(struct node *list,float *a,int *i)
{
	while(list!=NULL)
    {
        //printf("%f (%d) -> ", list->x,*i);
        a[*i]=list->x;
        (*i)++;
        list = list->n;
    }
    //printf("null\n");
}

void bucketSort(float *a,int start,int end)
{
	int i,n=end-start;
	struct node **list=(struct node **)calloc(sizeof(struct node *),n);
	for(i=start;i<end;i++)
	{
		insertSorted(&list[(int)(a[i]*n)],a[i]);
	}
	int j=0;
	for(i=0;i<n;i++)
	{
		displayList(list[i],a,&j);
	}
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    //bucketsort
    int n,i;
	scanf("%d",&n);
    float *a=(float*)malloc(n*sizeof(float));
    struct node *list=NULL;
    for(i=0;i<n;i++)
    {
		scanf("%f",&a[i]);
		insertSorted(&list,a[i]);
		//displayList(list);
	}
	bucketSort(a,0,n);
	for(i=0;i<n;i++)
    {
        printf("%f ",a[i]);
        //printf("\n%f ", list->x);
        //list = list->n;
    }
    printf("\n");
    //displayList(list);
    return 0;
}

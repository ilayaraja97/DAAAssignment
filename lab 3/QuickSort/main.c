#include <stdio.h>
#include <stdlib.h>
#define swap(a,b) \
{\
    temp=a;\
    a=b;\
    b=temp;\
}
int steps=1,temp;

int partition(int *a,int start,int end,int mode)
{
    int i=start+1,j;
    steps++;
    switch(mode)
    {
        case 1:swap(a[(end-start)/2+start],a[start]);  //put the pivot element in start.
        break;
        case 2:swap(a[end-1],a[start]);  //put the pivot element in start.
    }
    int piv=a[start];
    steps++;
    for(j =start + 1; j < end&&steps++ ; j++ )
    {
        /*rearrange the array by putting elements which are less than pivot
           on one side and which are greater that on other. */
        if(a[j]<piv&&steps++)
        {
            if(i!=j&&steps++)
            {
                swap(a[i],a[j]);
                steps++;
            }
            i++;
        }
    }

    if(start==i-1&&steps++)
        return i;
    swap(a[start],a[i-1]);  //put the pivot element in its proper place.
    steps++;
    return i-1;                      //return the position of the pivot
}

void quickSort(int *a,int start,int end,int mode)
{
    if(start<end-1&&steps++)
    {
        int pivot=partition(a,start,end,mode);
        steps++;
        quickSort(a,start,pivot,mode);
        steps++;
        quickSort(a,pivot,end,mode);
        steps++;
    }
}

int main()
{
	freopen("output.txt","w",stdout);
	freopen("input.txt","r",stdin);
	int n;
	scanf("%d",&n);
    int *a=(int*)malloc(n*sizeof(int)),i;
    for(i=0;i<n;i++)
    {
		scanf("%d",&a[i]);
	}
    quickSort(a,0,n,0);
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\nsteps : %d\n",steps-1);
    free(a);
    steps=1;
    freopen("input.txt","r",stdin);
	scanf("%d",&n);
    a=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
		scanf("%d",&a[i]);
	}
    quickSort(a,0,n,1);
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\nsteps : %d\n",steps-1);
    free(a);
    steps=1;
    freopen("input.txt","r",stdin);
	scanf("%d",&n);
    a=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
		scanf("%d",&a[i]);
	}
    quickSort(a,0,n,2);
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\nsteps : %d\n",steps-1);
    free(a);
    return 0;
}

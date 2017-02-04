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
        quickSort(a,start,pivot-1,mode);
        steps++;
        quickSort(a,pivot,end,mode);
        steps++;
    }
}

int main()
{
    int a[9]={54,26,93,17,77,31,44,55,20},i;
    quickSort(a,0,9,0);
    for(i=0;i<9;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\nsteps : %d\n",steps-1);
    steps=1;
    int b[9]={54,26,93,17,77,31,44,55,20};
    quickSort(b,0,9,1);
    for(i=0;i<9;i++)
    {
        printf("%d ",b[i]);
    }
    printf("\nsteps : %d\n",steps-1);
    steps=1;
    int c[9]={54,26,93,17,77,31,44,55,20};
    quickSort(c,0,9,2);
    for(i=0;i<9;i++)
    {
        printf("%d ",c[i]);
    }
    printf("\nsteps : %d\n",steps-1);
    return 0;
}

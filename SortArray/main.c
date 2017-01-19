#include <stdio.h>
#include <stdlib.h>

void merge(int *a,int start,int mid,int end)
{
    int *t=(int*)calloc(end-start+5,sizeof(int)),i=start,j=mid,k=0;
    while(k<=end-start)
    {
        if(i>=mid)
        {
            t[k++]=a[j++];
        }
        else if(j>=end)
        {
            t[k++]=a[i++];
        }
        else if(a[i]<a[j])
        {
            t[k++]=a[i++];
        }
        else
        {
            t[k++]=a[j++];
        }
    }
    for(i=0;i<end-start;i++)
    {
        a[start+i]=t[i];
    }
}

void mergeSort(int *a,int start,int end)
{
    if(start+1<end)
    {
        int mid=(end-start)/2+start;
        mergeSort(a,start,mid);
        mergeSort(a,mid,end);
        merge(a,start,mid,end);
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,i;
    scanf("%d",&n);
    int *a=(int*)calloc(n+5,sizeof(int));
    for(i=0;i<n;i++)
    {
        scanf("%d",a+i);
    }
    mergeSort(a,0,n);
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}

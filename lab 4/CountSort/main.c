#include <stdio.h>
#include <stdlib.h>

int ops=0;
void countingSort(int *a,int start,int end)
{
    const int RANGE=1000;
    int count[1000]={0};
    int i;
    int *b=(int*)malloc((end-start)*sizeof(int));
    for(i=start; i<end; i++,ops++)
    {
        count[a[i]]++;
    }
    for(i=1; i<RANGE; i++,ops++)
    {
        count[i]+=count[i-1];
    }
    for(i=end-1;i>=start;i--)
    {
		b[count[a[i]]-1]=a[i];
		count[a[i]]--;
	}
	for(i=start;i<end;i++)
	{
		a[i]=b[i];
	}
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
	scanf("%d",&n);
    int *a=(int*)malloc(n*sizeof(int)),i;
    for(i=0;i<n;i++)
    {
		scanf("%d",&a[i]);
	}
	countingSort(a,0,n);
	for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}

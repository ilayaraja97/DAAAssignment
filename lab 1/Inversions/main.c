#include <stdio.h>
#include <stdlib.h>

int main()
{
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //inversions
    int n,*a,i,j,inv;
    scanf("%d",&n);
    a=(int*)malloc(sizeof(int)*n);
    for (i=0;i<n;i++)
    {
    	scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    	for(j=0;j<i;j++)
    		if(a[j]>a[i])
    			inv++;
    
    printf("%d\n",inv);
    return 0;
}

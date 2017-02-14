#include <stdio.h>
#include <stdlib.h>

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int m,n,p,*a,*b,*c,i,mi,ni,pi;
    scanf("%d %d %d",&m,&n,&p);
    a=(int *)calloc(m+7,sizeof(int));
    b=(int *)calloc(m+7,sizeof(int));
    c=(int *)calloc(m+7,sizeof(int));
    for(i=0; i<m; i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0; i<n; i++)
    {
        scanf("%d",&b[i]);
    }
    for(i=0; i<p; i++)
    {
        scanf("%d",&c[i]);
    }
    mi=ni=pi=0;
    while(!(mi>=m||ni>=n||pi>=p))
    {
        if(a[mi]==b[ni])
        {
            if(b[ni]==c[pi])
            {
                printf("%d ",c[pi]);
                mi++;
                ni++;
                pi++;
            }
            else if(b[ni]>c[pi])
            {
                pi++;
            }
            else
            {
                mi++;
                ni++;
            }
        }
        else if(a[mi]>b[ni])
        {
            ni++;
        }
        else
        {
            mi++;
        }
    }
    return 0;
}

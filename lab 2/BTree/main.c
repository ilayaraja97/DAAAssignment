#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //Btree
    int n;
    scanf("%d",&n);
    printf("depth = %d\ntotal nodes = %d\nleaf nodes = %d\n",
		(int)(log(n)/log(2))+1,
		n,
		(int)(n-pow(2,(int)(log(n)/log(2))))+1);
    return 0;
}

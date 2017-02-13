#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int a,b,f,c;
    scanf("%dT(N/%d)+%dN^%d",&a,&b,&f,&c);
    //printf("%d\n",(int)(log(a)/log(b)));
    if(log(a)/log(b)>c)
    {
		//case 3
		printf("O(N^(log_%d(%d)))\n",b,a);
	}	
	else if(log(a)/log(b)==c)
	{
		//case 2
		printf("O(N^%dlog_%d(N))\n",c,b);
	}
	else
	{
		//case 1
		printf("O(N^%d)\n",c);
	}
    return 0;
}

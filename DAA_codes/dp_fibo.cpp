#include<stdio.h>
#include<stdlib.h>
int main()
{
        int n,i;
        scanf("%d",&n);
        int fib[n+1];
        fib[0]=0;
        fib[1]=1;
        for(i=2;i<n;i++)
        {
                fib[i]=fib[i-1]+fib[i-2];
        }
        for(i=0;i<n;i++)
        {
                printf("%d ",fib[i]);
        }
 return 0;
}

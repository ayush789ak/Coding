#include<stdio.h>
#include<stdlib.h>
#define swap(a,b) a=a+b;b=a-b;a=a-b;
void main()
{
int x=5,y=10;
swap(x,y);
printf("%d%d",x,y);
swap2(x,y);
printf("%d%d",x,y);

}
int swap2(int a,int b)
{
        int temp;
        temp=a;
        b=a;
        a=temp;
        return 0;
}

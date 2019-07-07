#include<stdio.h>
#include<stdlib.h>
int i=1;
int main()
{
printf("main calles again %d\n",i);
i++;
main();
}

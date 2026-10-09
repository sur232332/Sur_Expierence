#include <stdio.h>
int main()
{
	int number=0;
	printf("enter a index size = ");
	scanf("%d", &number);
	int i=0;
	int tmp=0;
	int array[number];
for(int i=0; i<number; i++)
{
if(i % 2 == 0)
{
printf("%d", i);
}
}
return 0;
}

#include <stdio.h>
int main()
{
	int number = 0;
	printf("enter a number = ");
	scanf("%d", &number);
if(number % 3 == 0){
        printf("number is divisibled 3 = %d", number);
}
if(number % 5 == 0)
{
	printf("number is divisibled 5 = %d", number);
}
else
{
	printf("number isn't divisibled:");
}
        return 0;
}


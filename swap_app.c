#include <stdio.h>
int main()
{
	int number = 0;
	int number1 = 0;
	int tmp = 0;
	printf("enter two intgers = "); 
	scanf("%d %d", &number, &number1);
        tmp = number1;
	printf("I have already swaped this number = %d %d", tmp, number);
	return 0;
}

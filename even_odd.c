#include <stdio.h>
int main()
{
	int number=0;
        printf("enter a number = ");
	scanf("%d", &number);
if(number % 2 == 0){
	printf("number is odd = %d", number);
} 
else
{
	printf("number is negative = %d", number); //tiv@ bacasakan e
}
        return 0;
}


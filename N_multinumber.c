#include <stdio.h>
int main()
{
    int number = 0;
    int number1 = 0;
    int tmp = 0;
    printf("enter a number = ");
    scanf("%d", &number);
for(int i = 1; i < 11; i++)
{
    tmp=number * i;
    printf(" result = %d\n", tmp);
    }
    return 0;
}
#include <stdio.h>
int main()
{
	int array[4] = {0};
        int counter = 0;
	int i = 0;
	printf("enter arrays index:");
for(i = 0; i < 4; i++)
{
	scanf("%d", &array[i]);
        counter = array[i];
}
        printf("I have seperated one example = %d", counter);
        return 0;
}

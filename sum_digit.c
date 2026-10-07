#include <stdio.h>
int main()
{
	char number [3];
	int arr = 0;
	printf("enter a number:");
        int counter [3];
        scanf("%s", number);
for(int i = 0; i < 3; i++)
{
	counter[i] = number[i]-'0';
        arr = counter[i] + counter[i];
}
	printf("sums %d",arr); 
        return 0;
}



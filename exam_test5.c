#include <stdio.h>
int main(){
        int number = 1;
        int sum = 0;
while(number != 0){
        scanf("%d", &number);
if(number == 0){
        printf("nothing number is 0\n");
        break;
}
        sum+=number;
}
        printf("result %d", sum);
        return 0;
}
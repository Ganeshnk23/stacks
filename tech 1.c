#include <stdio.h>
int main()
{
    int numbers[]={9,8,7,6,5};
    int size=sizeof(numbers)/sizeof(numbers[0]);
    int result=sumWithIncrement(numbers,size);
    printf("Sum with increment: %d\n",result);
    return 0;
}
int sumWithIncrement(int numbers[], int size)
 {
    int sum=0,i;
    for(i=0;i<size;i++)
    {
        sum=sum+numbers[i];
        sum=sum+1;
    }
    return sum;
}


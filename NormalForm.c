#include <stdio.h>
#include<conio.h>
int main()

{
    int a, b, sum;
    float average;

    {
        printf("Enter the first number:");
        scanf("%d", &a);
        printf("Enter the second number:");
        scanf("%d", &b);

        sum = a + b;
        average = (float)(a + b) / 2;

        printf("The sum of a and b will be %d\n",sum);
        printf("The average of a and b will be %f\n",average);
    }
    return 0;
}
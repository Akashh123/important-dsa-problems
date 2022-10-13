#include <stdio.h>

int main()
{
    int a1 = 7;
    unsigned short integer = 8;
    long integer1 = 8;
    short integer2 = 8;
    float b2 = 0.5;
    double myfloat1 = 7.45;
    long double myfloat2 = 7.525252;
    char c3 = 't';
    printf("The size of int is taken by %d", sizeof(int));

    printf("Hello World\n");
    int a = 7, b = 7, c = 8;
    printf("The sum of the a and b is %d\n", a + b);
    printf("The multiplication of a and b will be %d\n", a * b);
    printf("The difference of a and b is %d\n", a - b);
    printf("The division result of a and b is %d\n", a / b);
    printf("The modulo result of a and b is %d\n", a % b);
    printf("The icrement result of a is %d\n", ++a);
    printf("The derement result of a is %d\n", --a);

    int Akash = 7, Choudhury = 8;
    printf("%d\n", a == b);
    printf("%d\n", a != b);
    printf("%d\n", a > b);
    printf("%d\n", a, b);
    int h = 6, g = 9;
    printf("The logical operator returned %d\n", h && g);
    printf("The logical operator returned %d\n", h || g);
    printf("The logical operator returned %d\n", !g);
    printf("The logical operator returned %d\n", !h);
    //Assignment Operators
    //=,+=,-=,*=,%= etc;
    int ha = 9;
    ha *= 9;
    printf("ha is %d\n", ha);
    //Desicion making in C
    int age;
    printf("Enter your age\n");
    //scanf("%d", &age);
    age = 50;
    if (age < 18)
    {
        printf("You cannot drive");
    }
    else if (age >= 18 && age <= 24)
    {
        printf("You go home and use your cycle");
    }
    else
    {
        printf("You can go home alone but go carefully");
    }
    //switch statements:
    int i5 = age > 3 ? 100 : 200;
    printf("%d\n", i5);
    printf("\n\n``````Loop in C``````\n\n");
    int index = 0;
    while (index < 5000)
    {
        printf("%d\n", index);
        index++;
    }
    //For loop in C
    int j = 5;
    for (int j = 0; j < 100; j++)
    {
        printf("%d\n", j);
    }
    //Do while loop in C
    do
    {
        printf("Do while loop is coming to your home");
    } while (j < 5);
    return 0;
}
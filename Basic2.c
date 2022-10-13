#include <stdio.h>
//data__type func_name(parameter_type parametername){
//   return value_of_type_data_type;
//}
//void newPrint(char * char1)
//{
//   printf("The value of string will be%s\n\n\n\n\n\n", char1);
//}
//int main()
//{
//    int a, b, sum;
 //   float average;
   // {
     //   printf("Enter the first number:");
       // scanf("%d", &a);
       // printf("Enter the second number:");
        //scanf("%d", &b);
        //sum = a + b;
        //average = (a + b) / 2;
        //printf("Sum of a and b will be %d\n",sum);
        //printf("Average of a and b will be %f\n", average);
    //}
    //return 0;
//}
void NewPrint(char * char1)
    {
    printf("The value of a and b is %s\n",char1);
    }
    int sum(int a,int b)
    {
        return a+b;
    }
    int main()
    {
         printf("The sum of a and b will be %d\n",sum(15,85));
         return 0;
    }
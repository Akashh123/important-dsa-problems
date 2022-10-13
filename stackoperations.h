#define MAX_SIZE 303
struct data{
    int top;
    int number[MAX_SIZE];
}s1;
void push()
{
    if(s1.top>=(MAX_SIZE-1))
    {
        printf("\n---------------------\n|Stack is overflowed|\n---------------------\n");
    }
    else
    {   int type;
        printf("Enter the data you want to Insert\n");
        scanf("%d",&type);
        s1.top = s1.top + 1;
        s1.number[s1.top]=type;
        printf("\n--------------------------------------------\n|Data is successfully pushed onto the stack|\n--------------------------------------------\n");
    }
}
void pop()
{
    if(s1.top == (-1))
    {printf("-----------------------\n|stack is already empty|\n-----------------------\n");}
    else{
        printf("Popped element is: %d\n",s1.number[s1.top]);
        printf("\n-------------------------------------------\n|Data is successfully popped out the stack|\n-------------------------------------------\n");
        s1.number[s1.top]=0;
        s1.top = s1.top - 1;
        }
}
void display()
{int i;
    for(i=s1.top;i>=0;i--)
    {
        printf("\n---------\n|DATA--%d|\n---------\n",s1.number[i]);
    }
}
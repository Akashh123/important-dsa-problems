struct operandStack{
    int topp;
    int arr[15];
}att;
void postfixEvaluation()
{
    int i,a;
    att.topp=-1;char p[1];
    char str[15];
    printf("Enter the expression to be evaluated");
    scanf("%s",str);
    for(i=0;i<15;i++)
    {
        if(str[i]=='\0')
        {
            break;
        }
       else if(str[i]>=48 && str[i]<=57)
       {
        p[0]=str[i];
           a=atoi(p);
           att.topp=att.topp+1;
           att.arr[att.topp]=a;
       }
       else
       {  int b[2],j,result=0,operator;
       if(str[i]=='+')
       {
           operator=1;
       }
       else if(str[i]=='-')
       {
           operator=2;
       }
        else if(str[i]=='*')
       {
           operator=3;
       }
        else if(str[i]=='/')
       {
           operator=4;
       }
       for(j=0;j<2;j++)
       {
       b[j]=att.arr[att.topp];
       att.topp=att.topp-1;
       }
       switch(operator)
       {
           case 1: {
               att.topp=att.topp+1;
               att.arr[att.topp]=b[0]+b[1];
               break;
           }
           case 2: {
               att.topp=att.topp+1;
               att.arr[att.topp]=b[0]-b[1];
               break;
           }
           case 3: {
               att.topp=att.topp+1;
               att.arr[att.topp]=b[0]*b[1];
               break;
           }
           case 4: {
               att.topp=att.topp+1;
               att.arr[att.topp]=b[0]/b[1];
               break;
           }
       }
    }
}
printf("%d",att.arr[att.topp]);

}
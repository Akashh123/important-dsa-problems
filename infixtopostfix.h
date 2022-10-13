struct table{
    int priority;
    char symbol;
    int tr;
}column[11];

void infixToPostfix()
{
    int i,j;
    char arr[15];
    struct check
    {
        char symb;
        int prior;
        int atr;
    }str[15];
    int top=-1;
    printf("Enter the expression");
    scanf("%s",arr);
    for(i=0;i<=15;i++)
    {
        if(arr[i]!='\0')
        {
        if(arr[i]<=57 && arr[i]>=48|| arr[i]<=90 &&arr[i]>=65 || arr[i]<=122 && arr[i]>=97)
          {
              printf("%c",arr[i]);
          }
          else{
        for(j=0;j<11;j++)
        {
          if(arr[i]==column[j].symbol)
          {
              if(top==-1)
              {
                  if(column[j].tr<0)
                  {
                      printf("wrong expression entered. Cant convert to postfix");
                      goto last;
                  }
                  else
                  {
                    top=top+1;
                    str[top].symb=arr[i];
                    str[top].prior=column[j].priority;
                    str[top].atr=column[j].tr;
                  }
                  break;
              }
              else{int k,count=0;
                  for(k=0;k<=top;k++)
                  {
                     if(str[k].prior < column[j].priority && column[j].tr >= 0)
                     {int h,chck;
                     top=top+1;
                     chck=top;
                     for(h=top;h>k;h--)
                     { 
                         str[h].symb=str[h-1].symb;
                         str[h].prior=str[h-1].prior;
                         str[h].atr=str[h-1].atr;
                         chck=chck-1;
                     }
                    str[chck].symb=arr[i];
                    str[chck].prior=column[j].priority;
                    str[chck].atr=column[j].tr;
                    count=count+1;
                   break;
                     }
                     else if(str[k].prior>column[j].priority && column[j].tr<0)
                     {
                         int g,m,h,position;
                         position=top;
                         m= -(column[j].tr);
                         if(str[k].atr==m)
                           { 
                               for(g=k+1;g<=top;g++)
                               {
                                   printf("%c",str[g].symb);
                               }
                               for(h=k;h<=position;h++)
                               {
                                   top=top-1;
                               }
                           }
                           count=count+1;
                           break;
                     }
                     else{continue;}
                }
                if(count==0)
                {
                 top=top+1;
                        str[top].symb=arr[i];
                        str[top].prior=column[j].priority;
                        str[top].atr=column[j].tr;
                        break;
                    }
              }
              break;
          }
          else
          {continue;}
          }
           
          }
        }
        else{
            break;
           }
        }
        for(j=0;j<=top;j++)
        {
            printf("%c",str[j].symb);
        }
        last:;
}
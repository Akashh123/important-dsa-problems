#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include "stackoperations.h"
#include "infixtopostfix.h"
#include "postfixevaluation.h"
int main()
{   
column[0].priority=11; column[0].symbol='(';column[0].tr=1;
column[1].priority=10; column[1].symbol=')';column[1].tr=-1;
column[2].priority=9; column[2].symbol='[';column[2].tr=2;
column[3].priority=8; column[3].symbol='[';column[3].tr=-2;
column[4].priority=7; column[4].symbol='!';column[4].tr=0;
column[5].priority=6; column[5].symbol='-';column[5].tr=0;
column[6].priority=5; column[6].symbol='*';column[6].tr=0;
column[7].priority=4; column[7].symbol='/';column[7].tr=0;
column[8].priority=3; column[8].symbol='%';column[8].tr=0;
column[9].priority=2; column[9].symbol='+';column[9].tr=0;
column[10].priority=1; column[10].symbol='-';column[10].tr=0;
    int _num;
    for(;;){
        printf("\n------------------------------------------------------------\n------------------------------------------------------------\n");
    printf("Enter the choice from the list mentioned below\n");
    printf("1. Enter data in Stack\n2. Delete data from stack\n3. Print data\n4. INfix to Postfix Conversion\n5. Postfix Evualtion\n6. Quit\n\n");
    scanf("%d",&_num);
    switch(_num)
    {
        case 1:
        {  push();
        break;
        }
        case 2:{
            pop();
            break;
        }
        case 3:{
        display();
        break;}
        case 4:{
        infixToPostfix();
        break;}
        case 5:{
            postfixEvaluation();
            break;
        }
         case 6:{
        goto end;
        break;}
    }
    }
    end:
    return 0;

}
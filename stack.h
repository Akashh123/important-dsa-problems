#include <stdlib.h>
#include <stdio.h>
#define MAX 100
struct stack
{
struct node *t[MAX];
int top;
}s1;
void push(struct node *u){
if(s1.top == MAX -1){
printf("STACK IS FULL !!");
}
else{
s1.top = s1.top +1;
s1.t[s1.top] = u;
}
}
void pop(){
if(s1.top == -1){
printf("STACK IS EMPTY");
}
else{
s1.top = s1.top -1;
}
}

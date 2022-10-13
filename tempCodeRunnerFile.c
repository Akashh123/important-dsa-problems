#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include"stackfile.h"
struct node
{
    int key;
    struct node *left,*right;
};
 
struct node* createnode(int data)
{ struct node *temp = NULL;
temp=(struct node*)malloc(sizeof(struct node));
temp->left=NULL;
temp->right=NULL;
temp->key=data;
return temp;
}

struct node* insertnode(struct node * head,struct node *check)
{
if(head==NULL)
{ head=check;
return head;
}
else{ struct node *p=head;
    while(p!=NULL)
    {
        if(p->key < check->key)
        { if(p->right!=NULL) 
           { p=p->right;}
           else
           {
             p->right=check;
             break;
           }
        }
        else if(p->key > check->key)
        {  if(p->left!=NULL) 
           { p=p->left;}
           else
           {
               p->left=check;
               break;
           }
        }
        else
        {
              printf("\n-------------------------\n|duplicate value entered|\n-------------------------\n");
              break;
        }
    }
     return head;
}
}

void preorder(struct node * head)
{
if(head==NULL)
{
    return;
}
else
{
   printf("\n--------\n|  %d  |\n--------\n",head->key); 
   preorder(head->left);
   preorder(head->right);
}
}
void postorder(struct node * head)
{ if(head==NULL)
    {
       return;
    }
    else{
       postorder(head->left);
       postorder(head->right);
       printf("\n--------\n|  %d  |\n--------\n",head->key);
       
       }
}

void printnode(struct node *head)
{
    if(head==NULL)
    {
      printf("No Data Found");
    }
    else{ struct node *p=head;
           try : while(p!=NULL)
          {
            push(p);
            p=p->left;
          }
          if(p==NULL && s1.top!=-1)
          {
              printf("\n-------\n|  %d  |\n-------\n",s1.t[s1.top]->key);
              p=s1.t[s1.top]->right;
              pop();
              goto try;
          }
}
}

void deletenode(struct node *p,int value)
{
    if(p==NULL)
    {
        printf("There is no item available to be Deleted");
    }
    else
    { 
        struct node *t=NULL;
    int d;
        while(p!=NULL)
        {
            if(p->key<value && p->right!=NULL)
            {
                if(p->right->key==value)
                {
                t=p;
                d=1;
                }
                p=p->right;
                
            }
            else if(p->key>value && p->left!=NULL)
            {
                if(p->left->key==value)
                {
                    t=p;
                    d=2;
                }
                 p=p->left;
            }
            else if(p->key==value && (p->left!=NULL || p->right!=NULL))
            {
                int x;
               printf("Caution : The node you want to delete is not a leaf node.\nAll nodes connected to it will also be deleted.");
               printf("select whether to continue or not.\n1. Yes(Continue)\n2. No(Don't Continue)");
               scanf("%d",&x);
               switch(x)
               {
                   case 1:
                   {
                           if(d==1)
                           {t->right=NULL;}
                           else{t->left=NULL;}
                           free(p);
                           goto end;
                   }
                   case 2:
                   {
                             goto end; 
                   }
               }
            }
            else if(p->key==value && p->left==NULL && p->right==NULL)
            {
                if(d==1)
                {t->right=NULL;}
                else{t->left=NULL;}
                free(p);
                break;
            }
        }
    }
    end:;
}

int searchelement(struct node *p,int value)
{
    if(p==NULL)
    {
        printf("No such element found");
    }
    else{
        while(p!=NULL)
        {
            if(p->key<value)
            {
                if(p->right!=NULL)
                {
                p=p->right;
                }
                else{
                    printf("Element Not Found");
                    break;
                }
            }
            else if(p->key>value)
            {
                if(p->left!=NULL)
                { p=p->left;}
                else{
                    printf("Element Not Found");
                    break;
                }
            }
            else if(p->key==value)
            {
                printf("Element Found");
                break;
            }
        }
    }
}

int main()
{
    s1.top=-1;
    struct node* head=NULL;
    int x;
    for(;;)
    {
    printf("\n---------------------------------------------------------------\n---------------------------------------------------------------");
    printf("\n|  Enter your's choice  |\n-------------------------\n1. Enter a value in BST\n2. Print data in inorder\n3. Print data in preorder\n4. Print data in postorder\n5. Delete the node\n6. Search an element\n7. EXIT\n");
    scanf("%d",&x);
    switch(x)
    { 
        case 1:{ int value;struct node *check=NULL;
                 printf("Enter the value to be inserted\n");
                 scanf("%d",&value);
                 check=createnode(value);
                 head=insertnode(head,check);
                 break;
        }
        case 2:{
            printnode(head);
            break;
        }
        case 3:{
            preorder(head);
            break;
        }
        case 4:{
            postorder(head);
            break;
        }
        case 5:
        {
                int value;
                 printf("Enter the value to be deleted\n");
                 scanf("%d",&value);
                 deletenode(head,value);
                 break;
        }
        case 6:{
            int value,a;
                 printf("Enter the value to be searched\n");
                 scanf("%d",&value);
                 searchelement(head,value);
                 break;
        }
        case 7:{
            goto last;
        }
    }
    }
    last:;
    return 0;
}
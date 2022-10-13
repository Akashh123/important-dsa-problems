#include<stdio.h>
#include<stdlib.h>

struct BSTUMAHAN
{
    int data;
    struct BSTUMAHAN* left;
    struct BSTUMAHAN* right;
};

struct BSTUMAHAN* create (struct BSTUMAHAN* head,int data);
{
    if (head==NULL)
    {
       head=newNode(data);
       return head;
    }
    else if (data<=head->left,data)
    head->left=create(head->left,data);
    else
    head->right=create(head->left,data);
    return head;
    
}
struct BSTUMAHAN* newNode(int data)
{
    struct BSTUMAHAN *t = (struct BSTUMAHAN*)malloc(sizeof(struct BSTUMAHAN));
    t->data = data;
    t->left = t->right = NULL;
    retun t;
}
void inorder(struct BSTUMAHAN* head)
{
    if(head==NULL)
    {
        inorder(head->left)
        inorder(head=data)
        inorder(head->right)
    }
}

int main(
    struct BSTUMAHAN *head=NULL;
    head=create(head,10);
    head=create(head,20);
    head=create(head,30);
    inorder(head);

    return 0;
)
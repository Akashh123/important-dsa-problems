#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <ctype.h>
struct node
{
 int data;
 struct node* left;
 struct node* right;
};
struct node *root=0;
void insert();
void insert(int x)
{
 struct node *p,*t;
 t=(struct node *)malloc(sizeof(struct node));
 t->data=x;
 t->left=0;
 t->right=0;
 p=root;
 if(root==0)
 {
 root=t;
 }
 else
 {
 struct node *curr;
 curr=root;
 while(curr)
 {
 p=curr;
 if(t->data >curr->data)
 {
 curr=curr->right;
 }
 else
 {
 curr=curr->left;
 }
 }
 if(t->data > p->data)
 {
 p->right=t;
 }
 else
 {
 p->left=t;
 }
 }
}
void inorder(struct node *root)
{
 struct node *current,*pre;
 current=root;
 if (root == 0)
 {
 return ;
 }
 while (current != 0)
 {
 if (current->left == 0)
 {
 printf("%d\t", current->data);
 current = current->right;
 }
 else
 {
 pre = current->left;
 while (pre->right != 0 && pre->right != current)
 {
 pre = pre->right;
 }
 if (pre->right == 0)
 {
 pre->right = current;
 current = current->left;
 }
 else
 {
 pre->right = 0;
 printf("%d\t", current->data);
 current = current->right;
 }
 }
 }
}
int main()
{
 insert(50);
 insert(30);
 insert(20);
 insert(10);
 insert(80);
 insert(100);
 printf("inorder Traversal \n");
 inorder(root);
}
/*Insert all given Router IDs into a Binary Search Tree (BST).
If any input is -1, print "Invalid input" and stop.
Insert the new Router ID into the BST.
Perform inorder traversal (Left → Root → Right).
Print the routing table in sorted ascending order.*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}*node;
node create(int data);
node insert(node root,int data);
void inorder(node root);
int main()
{
    node root=NULL;
    int n,x;
    scanf("%d",&n);
    if(n==-1)
    {
        printf("invalid input");
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        if(x==-1)
        {
            printf("invalid input");
            return 0;
        }
        root=insert(root,x);
    }
    scanf("%d",&x);
    if(x==-1)
    {
        printf("invalid input");
        return 0;
    }
    root=insert(root,x);
    inorder(root);
    return 0;

}
node create(int data)
{
    node newnode=(node)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=newnode->right=NULL;
    return newnode;
}
node insert(node root,int data)
{
    if(root==NULL)
    {
        return create(data);
    }
    if(data<root->data)
    {
        root->left=insert(root->left,data);
    }
    else if(data>root->data){
        root->right=insert(root->right,data);
    }
    return root;
}
void inorder(node root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

/*Store given node values in a Binary Search Tree where left < root < right.
Insert all initial nodes into the BST.
Insert one additional node into the tree.
Delete a specified node from the BST.
Print the final tree using in order traversal*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int id;
    struct node *left;
    struct node *right;
}*node;
node insert(node root);
node delete_(node root,int id);
void inorder(node root);
int main()
{
    node root=NULL;
    int n,data;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        root=insert(root);
    }
    root = insert(root);
    scanf("%d",&data);
    root=delete_(root,data);
    printf("Current File Index sorted in ascending order: ");
    inorder(root);
    return 0;
}
node create()
{
    node newnode=(node)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        return NULL;
    }
    scanf("%d",&newnode->id);
    newnode->left=newnode->right=NULL;
    return newnode;
}
node insert(node root)
{
    node newnode=create();
    if(root==NULL)
    {
        root=newnode;
    }
    else{
        node cur=root,parent=NULL;
        while(cur!=NULL)
        {
            parent=cur;
            if(newnode->id<cur->id)
            {
                cur=cur->left;
            }
            else{
                cur=cur->right;
            }
        }
        if(newnode->id<parent->id)
        {
            parent->left=newnode;
        }
        else{
            parent->right=newnode;
        }
    }
    return root;
}
node delete_(node root,int id)
{
    if(root==NULL)
    {
       return root;
    }
    else{
        node cur=root,parent=NULL;
        while(cur!=NULL&&id!=cur->id)
        {

             parent=cur;
             if(id<cur->id)
             {
                 cur=cur->left;
             }
             else{
                cur=cur->right;
             }
        }
        if(cur==NULL)
        {
            return root;
        }
        if(cur->left!=NULL&&cur->right!=NULL)
        {
            node c=cur->right;
            node cp=c;
            while(c->left!=NULL)
            {
                cp=c;
                c=c->left;
            }
            cur->id=c->id;
            cur=c;
            parent=cp;
        }
        node child=NULL;
        if(cur->left!=NULL)
        {
            child=cur->left;
        }
        else{
            child=cur->right;
        }
        if(parent==NULL)
        {
            free(cur);
            return child;
        }
        if(parent->left==cur)
        {
            parent->left=child;
        }
        else{
            parent->right=child;
        }
        free(cur);
    }
    return root;
}
void inorder(node root)
{
    if(root!=NULL){
    inorder(root->left);
    printf("%d ",root->id);
    inorder(root->right);
    }
}

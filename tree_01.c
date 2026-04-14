#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}*node;
node insert(node root);
node delete_node(node root,int data);
void preorder(node root);
void inorder(node root);
void postorder(node root);
int main()
{
   node root=NULL;
   int choice,data;
   while(1)
   {
       printf("\n enter the choice :");
       scanf("%d",&choice);
       switch(choice)
       {
           case 0:exit(0);break;
           case 1:root=insert(root);
           break;
           case 2:
               printf("enter data :\n");
               scanf("%d",&data);
               root=delete_node(root,data);
           break;
           case 3:preorder(root);
           break;
           case 4:inorder(root);
           break;
           case 5:postorder(root);
           break;
           default:
            printf("invalid choice:\n");
            break;
       }
   }
   return 0;
}
node create()
{
    node newnode=(node)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("the memory is not allocated:\n");
        return NULL;
    }
    printf("enter the data :\n");
    scanf("%d",&newnode->data);
    newnode->left=newnode->right=NULL;
    return newnode;
}
node insert(node root)
{
    node newnode=create();
    node cur=root,parent=NULL;
    if(root==NULL)
    {
        root=newnode;
    }
    else{
        while(cur!=NULL)
        {
            parent=cur;
            if(newnode->data<cur->data)
            {
                cur=cur->left;
            }
            else{
                cur=cur->right;
            }
        }
        if(newnode->data<parent->data)
        {
            parent->left=newnode;
        }
        else{
            parent->right=newnode;
        }
    }
    return root;
}
void preorder(node root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
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
void postorder(node root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
node delete_node(node root,int data)
{
    if(root==NULL)
    {
        printf("tree is empty :\n");
        return root;
    }
    else{
        node cur=root,parent=NULL;
        while(cur!=NULL&&data!=cur->data)
        {
            parent=cur;
            if(data<cur->data)
            {
                cur=cur->left;
            }
            else{
                cur=cur->right;
            }
        }

        if(cur==NULL)
        {
            printf("the element is not found:\n");
            return root;
        }
        //node has two children
        if(cur->left!=NULL&&cur->right!=NULL)
        {
            node sc=cur->right;
            node sparent=cur;
        while(sc->left!=NULL)
        {
            sparent=sc;
            sc=sc->left;
        }
        cur->data=sc->data;
        cur=sc;
        parent=sparent;
      }
      //case 2 one child OR No child
      node child;
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

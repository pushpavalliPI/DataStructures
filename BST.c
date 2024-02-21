#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* root=NULL;
void inorder(struct node* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d  ",root->data);
        inorder(root->right);
    }
}
struct node* insert(struct node* node, int key)
{
    struct node* newNode= malloc(sizeof(struct node));
    newNode->left=NULL;
    newNode->right=NULL;
    if(node==NULL)
    {
        newNode->data=key;
        node=newNode;
    }
    if(key < (node->data))
        node->left = insert(node->left,key);
    else if(key > (node->data))
        node->right=insert(node->right,key);
    return node;
}
struct node* minValueNode(struct node* node)
{
    struct node* current = node;
    while(current && current->left!=NULL)
        current=current->left;
    return current;
}
struct node* deleteNode(struct node* root, int data)
{
    if(root==NULL)
        return root;
    if(data < (root->data))
        root->left=deleteNode(root->left,data);
    else if(data > (root->data))
        root->right=deleteNode(root->right,data);
    else
    {
        if(root->left == NULL)
        {
            struct node* temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right ==NULL)
        {
            struct node* temp =root->left;
            free(root);
            return temp;
        }
        struct node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right=deleteNode(root->right,temp->data);
    }
    return root;
}
int main()
{
    int c,idata,ddata,choice=0;
    do
   {
    printf("Enter \n1.For Insertion\n2.For Deletion\n3.Inorder Traversal\n");
    scanf("%d",&c);
        switch(c)
        {
            case 1:
                printf("Enter data to be inserted\n");
                scanf("%d",&idata);
                root=insert(root,idata);
                printf("BST:\n");
                inorder(root);
                break;
            case 2:
                printf("Enter data to be deleted\n");
                scanf("%d",&ddata);
                deleteNode(root,ddata);
                printf("BST:\n");
                inorder(root);
                break;
            case 3:
                printf("Inorder traversal of this Binary Search tree:\n");
                inorder(root);
                break;
            default:
                printf("Invalid choice!Enter 1/2/3\n");
                break;
        }
        printf("\nDo you wish to continue?(1/0)\n");
        scanf("%d",&choice);
    }while(choice==1);
    return 0;
}



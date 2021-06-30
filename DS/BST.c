#include<stdio.h>
#include<stdlib.h>

int leaf=0;

struct node
{
    int data;
    struct node *left,*right;
};

struct node *create(int data)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    if(newnode == NULL)
    {
        printf("\nMemory allocation failed...\n");
        exit(0);
    }
    newnode->data = data;
    newnode->left=newnode->right=NULL;

    return newnode;
}

struct node *insert(struct node *node,int data)
{
    if(node==NULL)
        return create(data);

    if(data < node->data)
        node->left = insert(node->left,data);
    else
        node->right = insert(node->right,data);

    return node;
}

void inorder(struct node *root)
{
    if(root!=NULL)
    {   printf("$$$ %d $$$\n",root->data);
        inorder(root->left);
        printf("%d \n",root->data);
        inorder(root->right);
        printf("---%d--- \n",root->data);
    }
}

void preorder(struct node *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

void *display(struct node *root)
{
    if(root==NULL)
    {
        printf("\nTree is empty...\n");
        return NULL;
    }
    printf("\nINORDER : ");
    inorder(root);
    printf("\nPREORDER : ");
    preorder(root);
    printf("\nPOSTORDER : ");
    postorder(root);
    printf("\n");
}

void *search(struct node *root,int key)
{
    if(root==NULL)
        return NULL;
    if(key==root->data)
        return root;
    if(key<root->data)
        return search(root->left,key);
    if(key>root->data)
        return search(root->right,key);
}

struct node *minimum(struct node *node)
{
    struct node *IS = node;
    while(IS && IS->left!=NULL)
        IS = IS->left;

    return IS;
}

void *delete(struct node *root,int del)
{
    struct node *temp = NULL;

    if(root==NULL)
    {
        printf("\nElement does not exist...\n");
        return root;
    }

    if(del<root->data)
        root->left = delete(root->left,del);
    else if(del>root->data)
        root->right = delete(root->right,del);

    //if del == root->data and either left or right is NULL...
    else if(del==root->data &&((root->left==NULL && root->right!=NULL)||(root->left!=NULL && root->right==NULL)))
    {
        if(root->left==NULL)
        {
            temp=root->right;
            root->data=temp->data;
            free(temp);
            root->right=NULL;
            printf("\nNode Deleted...\n");
        }
        else
        {
            temp=root->left;
            root->data=temp->data;
            free(temp);
            root->left=NULL;
            printf("\nNode Deleted...\n");
        }
    }
    else
    {
        if(root->left==NULL && root->right==NULL)   //Delete leaf node.
        {
            free(root);
            printf("\nNode Deleted...\n");
            return NULL;
        }
        else    //if node has 2 children...
        {
            temp = minimum(root);      //Find minimum number...
            root->data = temp->data;
            root->left = delete(root->left,temp->data);
        }
    }
    return root;
}

int leafNodes(struct node *root)
{
    if(root==NULL)
        return 0;
    if(root->left==NULL && root->right==NULL)
        return 1;

    return leafNodes(root->left)+leafNodes(root->right);
}

int main(void)
{
    int choice,x,key,del;
    struct node *root = NULL;
    for(;;)
    {
        printf("\n    MENU    \n");
        printf("1.  Insert.\n");
        printf("2.  Display.\n");
        printf("3.  Search.\n");
        printf("4.  Delete.\n");
        printf("5.  Total no. of nodes.\n");
        printf("6.  No. of leaves.\n");
        printf("7.  No. of Non-leaves.\n");
        printf("0.  Exit.\n");
        printf("Enter choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("\nEnter data : ");
                scanf("%d",&x);
                if(root==NULL)
                {
                    root = insert(root,x);
                }
                else
                    insert(root,x);
                break;

            case 2:
                display(root);
                break;

            case 3:     //Search an element...
                printf("\nEnter key : ");
                scanf("%d",&key);
                if(search(root,key))
                    printf("\nElement found...\nParent node : %d\n",root->data);
                else
                    printf("\nNot found...\n");
                break;

            case 4:     //Delete an element...
                printf("\nEnter the key to delete : ");
                scanf("%d",&del);
                if(root==NULL)
                {
                    printf("\nTree is empty...\n");
                    break;
                }
                root=delete(root,del);
                break;

            case 5:     //Calculate total no. of nodes...
                leaf = leafNodes(root);
                if(leaf!=0)
                    printf("\nTotal no. of nodes : %d\n",2*leaf-1);
                else
                    printf("\nTree is empty...\n");
                break;

            case 6:     //Calculate total no. of leaf nodes...
                leaf = leafNodes(root);
                printf("\nTotal no. of leaf nodes : %d\n",leaf);
                break;

            case 7:     //Calculate total no. of non-leaf nodes...
                leaf = leafNodes(root);
                if(leaf==1)
                    printf("\nTotal no. of non-leaf nodes : %d\n",leaf);
                else if(leaf!=0)
                    printf("\nTotal no. of non-leaf nodes : %d\n",leaf-1);
                else
                    printf("\nTree is empty...\n");
                break;

            case 0:
                inorder(root);
                //exit(0);
        }
    }
}

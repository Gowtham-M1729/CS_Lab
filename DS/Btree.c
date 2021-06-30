#include<stdio.h>
#include<stdlib.h>
//#include<stdbool.h>

typedef struct node node;
struct node
{
    int data;
    node *left,*right;
};

node *root = NULL,*parent=NULL;
int flag = 0;

node *create()
{
    node *newnode = (node *)malloc(sizeof(node));
    if(newnode==NULL)
    {
        printf("\nMemory allocation is not possible...\nProgram exited...\n");
        exit(0);
    }
    printf("\nEnter data(Enter 0 for no data) : ");
    scanf("%d",&newnode->data);
    if(newnode->data==0)
    {
        return NULL;
    }
    newnode->left=newnode->right=NULL;

    printf("\nEnter left child of %d :-",newnode->data);
    newnode->left = create();

    printf("\nEnter right child of %d :-",newnode->data);
    newnode->right = create();

    return newnode;
}

node *search(node *root,int x,node **parent)
{
    if(root==NULL)
    {
        printf("\nTree is empty...\n");
        return NULL;
    }
    node *searchdata=NULL;
    /*if(root->data==x)
    {
        //parent=root;
        searchdata = root;
        flag = 1;
        //return root;
    }
    if(root->data!=x && root->left!=NULL)
    {
        *parent = root;
        searchdata=search(root->left,x,parent);
        return searchdata;
    }
    if(root->data!=x &&root->right!=NULL)
    {
        *parent=root;
        searchdata = search(root->right,x,parent);
        return searchdata;
    }
    return searchdata;*/
    if(root->data==x){
        searchdata=root;
    }
    if(searchdata==NULL){
        *parent=root;
        searchdata=search(root->left,x,parent);
    }
    if(searchdata==NULL){
        *parent=root;
        searchdata=search(root->right,x,parent);
    }
    return searchdata;
}

node *delete(node *root)
{
    if(root==NULL)
    {
        printf("\nTree is empty...\n");
        return NULL;
    }

    int data;
    printf("\nEnter the data to delete : ");
    scanf("%d",&data);

    if(root->data==data && (root->left!=NULL || root->right!=NULL)){
        printf("Root node can't be deleted unless it has no child.\n");
        return root;
    }

    if(root->data==data && root->left==NULL && root->right==NULL)
    {
        printf("\n1\n");
        printf("\nDeleted data : %d...\n",root->data);
        free(root);
        return root;
    }

    node *parent;
    node *nodeDel = search(root,data,&parent);
    if(nodeDel==NULL)
    {
        printf("\nNo such element exits in the tree...\n");
        return root;
    }
    /*else
    {
        printf("\n2\n");
        printf("\nDeleted data : %d\n",nodeDel->data);
        free(nodeDel);
        return root;
    }*/

    if(nodeDel->left==NULL && nodeDel->right==NULL)
    {
        if(nodeDel==parent->left)
            parent->left=NULL;
        else
            parent->right=NULL;

        printf("\n3\n");
        printf("\nDeleted data : %d\n",nodeDel->data);
        free(nodeDel);
    }

    else if((nodeDel->left!=NULL && nodeDel->right==NULL) || (nodeDel->left==NULL && nodeDel->right!=NULL))
    {
        if(nodeDel->right==NULL)
        {
            if(nodeDel==parent->left)
            {
                parent->left = nodeDel->left;
            }
            else
                parent->right = nodeDel->left;
        }
        else
        {
            if(nodeDel==parent->left)
            {
                parent->left = nodeDel->right;
            }
            else
                parent->right = nodeDel->right;
        }

        printf("\n4\n");
        printf("\nDeleted data : %d\n",nodeDel->data);
        free(nodeDel);
    }

    else
    {
        node *IS = nodeDel->right, *ISP = nodeDel;

        while(IS->left!=NULL)
        {
            ISP = IS;
            IS = IS->left;
        }

        nodeDel->data = IS->data;

        if(IS->left==NULL && IS->right==NULL)
        {
            if(IS==IS->left)
                ISP->left=NULL;
            else
                ISP->right=NULL;
        }
        else
        {
            if(IS==ISP->left)
                ISP->left=IS->right;
            else
                ISP->right=IS->right;
        }

        free(IS);
    }
    printf("\n5\n");
    printf("\nDeleted data : %d...\n",data);
    return root;
}

void inorder(node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
void preorder(node *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

void display(node *root)
{
    if(root==NULL)
    {
        printf("\nTree is empty...\n");
        return;
    }
    printf("\nINORDER TRAVERSAL : ");
    inorder(root);
    printf("\nPREORDER TRAVERSAL : ");
    preorder(root);
    printf("\nPOSTORDER TRAVERSAL : ");
    postorder(root);
}

int main()
{
    int i,x,choice;
    printf("\nEnter data for root : ");
    root = create();
    if(root==NULL)
    {
        printf("\nTree is empty...\n");
        exit(0);
    }
    for(;;)
    {
        printf("\n     MENU     \n");
        printf("1.  Display.\n");
        printf("2.  Search.\n");
        printf("3.  Delete.\n");
        printf("0.  Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                display(root);
                printf("\n");
                break;
            case 2:
                printf("\n\nEnter the element to search : ");
                scanf("%d",&x);
                //search(root,x,parent);
                if((search(root,x,&parent)))
                {
                    printf("\nElement found...\n");
                }
                else
                {
                    printf("\nElement not found...\n");
                }
                break;
            case 3:
                root = delete(root);
                display(root);
                break;
            case 0:
                exit(0);
        }
    }
}

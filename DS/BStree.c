#include <stdio.h>
#include <stdlib.h>

struct node {
	int key;
	struct node *left, *right;
};
void postorder(struct node *root);
void preorder(struct node *root);
void inorder(struct node *root);
void display(struct node* root);

struct node* newNode(int item)
{
	struct node* temp
		= (struct node*)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}
void inorder(struct node* root)
{
	if (root != NULL) {
		inorder(root->left);
		printf("%d ", root->key);
		inorder(root->right);
	}
}
struct node* insert(struct node* node, int key)
{

	if (node == NULL)
		return newNode(key);


	if (key < node->key)
		node->left = insert(node->left, key);
	else
		node->right = insert(node->right, key);


	return node;
}


struct node* minValueNode(struct node* node)
{
	struct node* current = node;
	while (current && current->left != NULL)
		current = current->left;

	return current;
}
struct node* deleteNode(struct node* root, int key)
{

	if (root == NULL)
		return root;
	if (key < root->key)
		root->left = deleteNode(root->left, key);

	else if (key > root->key)
		root->right = deleteNode(root->right, key);


	else {
		if (root->left == NULL) {
			struct node* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			struct node* temp = root->left;
			free(root);
			return temp;
		}

		struct node* temp = minValueNode(root->right);
		root->key = temp->key;
		root->right = deleteNode(root->right, temp->key);
	}
	return root;
}
struct node* search(struct node* root, int key,struct node **parent)
{
  struct node* j;
	if (root == NULL)
		return root;
	if (key < root->key)
	  { *parent=root;
		  j = search(root->left, key,parent);
		}

	else if (key > root->key)
	{ *parent=root;
		j = search(root->right, key,parent);
	}
	else
	return root;
	return j;
}
int main()
{
  int i,k;
	struct node* root = NULL,*parent,*j;
	for(i=1;i<=3;i++)
	{
		scanf("%d",&k);
		root = insert(root, k);
	}
	printf("Inorder traversal of the given tree \n");
	inorder(root);
		printf("\nDelete 20\n");
		root = deleteNode(root, 20);
		printf("Inorder traversal of the modified tree \n");
		inorder(root);

		printf("\nDelete 30\n");
		root = deleteNode(root, 30);
		printf("Inorder traversal of the modified tree \n");
		inorder(root);

		printf("\nDelete 50\n");
		root = deleteNode(root, 50);
		printf("Inorder traversal of the modified tree \n");
		display(root);
    j=search(root,2,&parent);
		printf("%d\n",parent->key);
	  if(j!=NULL)
		{
			printf("Element Found\n");
		}
		else
		printf("Element is not there\n");
		printf("Inorder traversal of the given tree \n");
		display(root);
		return 0;
	}



void display(struct node* root)
{
	printf("Inorder traversal of the given tree \n");
	inorder(root);
	printf("Preorder traversal of the given tree \n");
	preorder(root);
	printf("Postorder traversal of the given tree \n");
	postorder(root);
}
void preorder(struct node *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->key);
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
        printf("%d ",root->key);
    }
}

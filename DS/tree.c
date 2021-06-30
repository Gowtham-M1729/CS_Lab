#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct node
{
  int info;
  struct node *llink;
  struct node *rlink;
  };
  typedef struct node *NODE;
  NODE Insert(NODE);
  void Disp(NODE);
// NODE Search(NODE, int);//, *NODE, *NODE);
 NODE Search(NODE, int, NODE*);
 void Inorder(NODE);
 void Preorder(NODE);
 void Postorder(NODE);
 NODE Delete(NODE);

  void main()
  {
    int ch, key;
    NODE Root = NULL, NS=NULL, PN=NULL ;
    //clrscr();
    for(;;)
      {
	printf("enter choice:\n1:Isertion\n2:Disp\n3:Search\n4:Delete\n");
	scanf("%d", &ch);
	 switch(ch)
	 {
	    case 1:  Root = Insert(Root);  break;
	    case 2:  Disp(Root);  break;
	   case 3:  /* printf("enter thekey of node to be searched\n");
		     scanf("%d", &key);
		    NS = Search(Root,key);//, &NS, &PN);
		     if(NS==NULL)
		       printf("Node doens't exist\n");
		     else
		      printf("Searching node info = %d and its parent is: \n",NS->info);//, PN->info);
		     break; */
		     printf("enter thekey of node to be searched\n");
		     scanf("%d", &key);
		     if(Root->info == key)
		     {
		      printf("Searching node info = %d and No parent for the root n",Root->info);

		     }
		     else
		     {
		     NS=Search(Root,key, &PN);
		     if(NS==NULL)
		       printf("Node doens't exist\n");
		     else
		      printf("Searching node info = %d and its parent is:%d \n",NS->info, PN->info);
		      }
		     break;
	    case 4: Root =Delete(Root); Disp(Root); break;
	    default: exit(0);
	 }
      }
  }

  NODE Insert(NODE R)
  {
     NODE NN, CN, PN;
     int i;
     char dir[6];
     NN = (NODE) malloc(sizeof(struct node));
     printf("enter info:");
     scanf("%d", &NN->info);
     NN->llink=NN->rlink=NULL;
     if(R==NULL)  return NN;
   L1: printf("enter direction\n");
     scanf("%s", dir);
     CN = R;
     PN = NULL;
     for(i=0; i<strlen(dir); i++)
     {
       PN = CN;
       if(CN == NULL) break;
       if(dir[i] =='L')
	CN = CN->llink;
       else
	  CN = CN->rlink;
     }
     if(i!=strlen(dir)  || CN !=NULL)
     {
       printf("insertion of new node in this direction not possible  Read new direction\n");
       goto L1;
     }
     if(dir[i-1]=='L')
      PN->llink = NN;
      else
      PN->rlink = NN;
      return R;
  }

 void Disp(NODE R)
 {  int ch;
    if(R==NULL)
    {
      printf("Tree empty\n");
      return;
    }
    printf("\nInorder Traversal is: ");
    Inorder(R);
    printf("\nPreorder Traversal is: ");
    Preorder(R);
    printf("\nPostorder Traversal is: ");
    Postorder(R);
}
void Inorder(NODE R)
{
  if(R==NULL) return;
  Inorder(R->llink);
  printf("%d  ", R->info);
  Inorder(R->rlink);
}
void Preorder(NODE R)
{
  if(R==NULL) return;
   printf("%d  ", R->info);
  Preorder(R->llink);
  Preorder(R->rlink);
}
void Postorder(NODE R)
{
  if(R==NULL) return;
  Postorder(R->llink);
  Postorder(R->rlink);
  printf("%d  ", R->info);
}

/*NODE Search(NODE R,int key) // only for searching
 {  NODE NS=NULL;
   if(R==NULL) return NULL;
   if(R->info==key)
     NS = R;
   if(NS==NULL)

   NS = Search(R->llink, key);
   if(NS ==NULL)

   NS = Search(R->rlink, key);
   return NS ;
 } */
 NODE Search(NODE R,int key,  NODE *PN) // Search to delete
 { NODE NS=NULL;
   if(R==NULL) return NULL;
   if(R->info==key)
   {
     NS = R;
    }
   if(NS==NULL)
  {
   *PN = R;
   NS = Search(R->llink, key,PN);
  }
   if(NS ==NULL)
   {
    *PN=R;
    NS = Search(R->rlink, key, PN);
  }
  return NS;
 }

 NODE Delete(NODE R)
 {  int key;
   NODE  ND=NULL, PN=NULL, IS, ISP;// IS:Inorder succ ISP: Inoredr Succ parent
   if(R==NULL)
    {
       printf("tree empty\n"); return NULL;
    }
   printf("enter key of the node to be deleted:\n");
   scanf("%d", &key);

   if(R->info==key && R->llink==NULL && R->rlink==NULL)
    {
      printf("deleted: %d\n", R->info);
      free(R);
      return NULL;

   }
   ND = Search(R, key, &PN);
   if(ND==NULL)
   {
      printf("Node doesn't exist\n");
      return R;
   }

   printf("node to be deleted is %d and ites parent is:%d\n", ND->info, PN->info);
   // CASE 1
   if(ND->llink==NULL && ND->rlink==NULL)
   {
     if(ND==PN->llink)
       PN->llink=NULL;
     else
       PN->rlink=NULL;
       printf("deleted:%d\n", ND->info);
       free(ND);
     return R;
   }
   else  // CASE 2
   if(ND->llink!=NULL&&ND->rlink==NULL || ND->llink==NULL && ND->rlink!=NULL)
   {
     if(ND->rlink==NULL)
     {
       if(ND==PN->rlink)
	  PN->rlink=ND->llink;
       else
	    PN->llink=ND->llink;
     }
     else
     if(ND->llink==NULL)
     {
	if(ND==PN->rlink)
	  PN->rlink=ND->rlink;
       else
	    PN->llink=ND->rlink;
     }
      printf("deleted:%d\n", ND->info);
       free(ND);
       return R;
 }
 else  // CASE 3
 {
   IS=ND->rlink;  ISP = ND;
   while(IS->llink !=NULL)
   {
     ISP = IS;
     IS = IS->llink;
   }
   printf("deleted:%d \n",ND->info);
   ND->info = IS->info;
   if(IS->llink==NULL && IS->rlink==NULL)
   {
     if( IS == ISP->llink)
	 ISP->llink = NULL;
     else
	  ISP->rlink=NULL;
   }
   else
   {
     if( IS == ISP->llink)
	 ISP->llink = IS->rlink;
     else
	  ISP->rlink=IS->rlink;
   }
   free(IS);
    return R;
 }// else case 3

 }

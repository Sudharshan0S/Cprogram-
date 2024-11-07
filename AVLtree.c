#include <stdio.h> 

#include <stdlib.h> 

struct AVL 

{ 

 int key; 

 struct AVL *left; 

 struct AVL *right; 

 int height; 

}; 

typedef struct AVL node;

int getHeight(node *n){ 

 if(n==NULL) 

 return 0; 

 return n->height; 

} 

node *createNode(int key)
{ 

 node* n = (node *) malloc(sizeof(node)); 

 n->key = key; 

 n->left = NULL; 

 n->right = NULL; 

 n->height = 1; 

 return n; 

} 

int max (int a, int b)

{ 

 return (a>b)?a:b; 

} 

int getBalanceFactor(node * n)

{ 

 if(n==NULL)

 { 

 return 0; 

 } 

 return getHeight(n->left) - getHeight(n->right); 

} 

node* leftRotate(node* y)

{ 

 node* x = y->left; 

 node* T2 = x->right; 

 x->right = y;
// Left Left Case 

 if(bf>1 && key < n->left->key)

 { 

 return leftRotate(n); 

 } 

 // Right Right Case 

 if(bf<-1 && key > n->right->key)

{ 

 return rightRotate(n); 

 } 

 // Left Right Case 

 if(bf>1 && key > n->left->key)

{ 

 n->left = rightRotate(n->left); 

 return leftRotate(n); 

 } 

 // Right Left Case 

 if(bf<-1 && key < n->right->key)

{ 

 n->right = leftRotate(n->right); 

 return rightRotate(n); 

 } 

 return n; 

} 

void printtree(node *root, int space,int n)
{

int i;

 if (root == NULL)

 return;

 space +=n; // The variable space is incremented by n, the indentation level for the next level of nodes

 printtree(root->right, space,n);

 printf("\n");

 for (i =n; i < space; i++)

 printf(" ");

 printf("(%d)\n", root->key);

 printtree(root->left, space,n);

}

int main()

{ 

node * root = NULL; 

 int n,i,key;

 printf("enter the number of nodes\n");

 scanf("%d",&n);

 for(i=0;i<n;i++)

 {

 printf("enter the key\n");

 scanf("%d",&key);

 root = insert(root, key);

} 

 printtree(root, 0, n) ;
return 0; 

}

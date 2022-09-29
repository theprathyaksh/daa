#include<stdio.h>
#include<stdlib.h>
struct node 
{
	struct node *left;
	int data;
	struct node *right;
};
struct node *create(int d)
{
	struct node *nn;
	nn=(struct node *)malloc(sizeof(struct node));
	nn->data=d;
	nn->left=NULL;
	nn->right=NULL;
	return nn;
}
struct node *insert(struct node *root,int d)
{
	if(root==NULL)
		root=create(d);
	else if(d < root->data)
	{
		if(root->left==NULL)
			root->left=create(d);
		else
			insert(root->left,d);
	}
	else
	{
		if(root->right==NULL)
			root->right=create(d);
		else
			insert(root->right,d);
	}
	return root;
}
void inorder(struct node *root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}
void search(struct node *root,int key)
{
	if(root==NULL)
		printf("------Key not found-------");
	else if(key==root->data)
		printf("------Key found---------");
	else if(key < root->data)
		search(root->left,key);
	else 
		search(root->right,key);
}
int main()
{
	struct node *root=NULL;
	int ch,key,d;
	while(1)
	{
		printf("\n1.insert");
		printf("\n2.display");
		printf("\n3.search");
		printf("Entere your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			printf("Enter the data to insert:");
			scanf("%d",&d);
			root=insert(root,d);
			break;
			case 2:
			inorder(root);
			break;
			case 3:
			printf("Enter the key to search:");
			scanf("%d",&key);
			search(root,key);
			break;
		}
		
	}
}


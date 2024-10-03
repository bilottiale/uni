#include <stdio.h>
#include <stdlib.h>

// A Binary Tree Node
struct Node
{
	int data;
	struct Node *left, *right;
};

// Utility function to create a new tree node
struct Node* newNode(int data)
{
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

// function to print right view of binary tree
void printRightView(struct Node* root)
{
	if (!root)
		return;

	struct Node* queue[1000]; // Assuming a maximum of 1000 nodes
	int front = 0, rear = 0;
	int level_nodes = 0;

	queue[rear++] = root;

	while (front < rear)
	{ 
		// number of nodes at current level
		level_nodes = rear - front;
		
		// Traverse all nodes of current level 
		for(int i = 1; i <= level_nodes; i++)
		{
			struct Node* temp = queue[front++];
			
			// Print the rightmost element at the level
			if (i == level_nodes)
				printf("%d ", temp->data);
			
			// Add left node to queue
			if (temp->left != NULL)
				queue[rear++] = temp->left;

			// Add right node to queue
			if (temp->right != NULL)
				queue[rear++] = temp->right;
		}
	}
} 

// Driver program to test above functions
int main()
{
	// Let's construct the tree as shown in the example

	struct Node* root = newNode(10);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(7);
	root->left->right = newNode(8);
	root->right->right = newNode(15);
	root->right->left = newNode(12);
	root->right->right->left = newNode(14);

	printRightView(root);
	
	return 0;
}


#include <iostream>
#include<bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
   int data;
   struct node* left;
   struct node* right;
};

int printKDistant(struct node * root , int distance)
{
    // Base case
    if (root == NULL)
        return 0;
 
    // Initialize result
    int result = 0;
 
    // Do Level order traversal keeping track of number
    // of nodes at every level.
    queue<node*> q;
    q.push(root);
    int level = 0;
    while (!q.empty())
    {
        // Get the size of queue when the level order
        // traversal for one level finishes
        int count = q.size() ;
       level++; 
        // Update the maximum node count value
       // result = max(count, result);
 
        // Iterate for all the nodes in the queue currently
        while (count--)
        {
     
            // Dequeue an node from queue
            node *temp = q.front();
            if(level == distance )
            std::cout << "\n " << temp->data;
            q.pop();
 
            // Enqueue left and right children of
            // dequeued node
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
      
    }
 
    return result;
}

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node* newNode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
 
  return(node);
}
 




/* Driver program to test above functions*/
int main()
{
 
  /* Constructed binary tree is
            1
          /   \
        2      3
      /  \    /
    4     5  8
  */
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
  root->right->left = newNode(8); 
 
  printKDistant(root, 3);
 
  //getchar();
  return 0;
}

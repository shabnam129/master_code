#include <iostream>
#include <cstdlib>
#include <vector>
#include <iterator>
struct node 
{
  int data;
  struct node *left;
  struct node *right;

};






 /* Compute the "height" of a tree -- the number of
    nodes along the longest path from the root node
    down to the farthest leaf node.*/
int height(struct node* node)
{
  static int max_count = 1;
   int count = 0 ;
    if (node==NULL)
        return 0;
    else
    {
        /* compute the height of each subtree */
        int lheight = height(node->left);
        int rheight = height(node->right);
     
         count = lheight + rheight;
         if(count >= max_count )
            {
                max_count = count + 1 ;
                std::cout << "\n max_count === " << max_count;
            }
 
        /* use the larger one */
        if (lheight > rheight)
            return(lheight+1);
        else return(rheight+1);
    }


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
    struct node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
  //  root->right->left       = newNode(9);
    //root->right->left->left       = newNode(10);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    //add nodes to 5 left
   /* root->left->right->left = newNode(11);
    root->left->right->left->left = newNode(12);
    root->left->right->left->left->left = newNode(13);
    root->left->right->left->left->left->left = newNode(14);
    root->left->right->left->left->left->left->left = newNode(15);
  
    root->left->left->left = newNode(7);
    root->left->left->right = newNode(8);
     */

    height(root); 
    return 0;
}



#include <iostream>
#include <cstdlib>
struct node 
{
  int data;
  struct node *left;
  struct node *right;

};


struct node * newNode(int data)
{

  struct node *node = (struct node *) malloc(sizeof(struct node) );
  node->data = data;

  return node;

}

int height_tree(struct node *);


int main()
{
    struct node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->right->left       = newNode(9);
    root->right->left->left       = newNode(10);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    //add nodes to 5 left
    root->left->right->left = newNode(11);
    root->left->right->left->left = newNode(12);
    root->left->right->left->left->left = newNode(13);
    root->left->right->left->left->left->left = newNode(14);
    root->left->right->left->left->left->left->left = newNode(15);
  
    root->left->left->left = newNode(7);
    root->left->left->right = newNode(8);
 

    /* struct node *root  = new_node(1);
     root->left             = new_node(2);
     root->right           = new_node(3);
     root->left->left     = new_node(4);
     root->left->right   = new_node(5);
    */
      std::cout << "\n Inorder===";
    //  inorder(root);
     std::cout << "\n height ===" << height_tree(root);
}



int height_tree(struct node * node)
{

  if(node==NULL)
  return 0;
   
   int lh = 1+height_tree(node->left);
   int rh = 1+height_tree(node->right);
   
   if(lh > rh)
    return (lh);
  else
   return (rh); 

}
 

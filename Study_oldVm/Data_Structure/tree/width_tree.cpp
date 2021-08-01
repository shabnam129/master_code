#include <iostream>

#include<bits/stdc++.h>
using namespace std ;

//LOGic behind the progeamm ..The current number of entries in queue determine the number of element in level

 
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data ;
    struct Node * left ;
    struct Node * right ;
};


 /* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct Node * newNode(int data)
{
    struct Node * node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

int maxWidth(struct Node *root)
{

  std::vector<struct Node*> queue;
  int max_width= 1;

  queue.push_back(root);
  struct Node *node =root;
  
  while( !queue.empty() ) 
   {

     node = queue.front();
     std::cout << "\n front node ===" << node->data;
     //queue.erase(queue.begin());

    
    if(max_width < queue.size() )
     {
       max_width =  queue.size();
     }
   
   if(node->left)
    queue.push_back(node->left);
   if(node->right)
    queue.push_back(node->right);  

    queue.erase(queue.begin()); 
   
  /* node = queue.front();

   std::cout << "\n front node ===" << node->data;
   //queue.pop_front();
   queue.erase(queue.begin());*/

  }

return max_width;


}

int main()
{
    struct Node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->left->left  = newNode(9);
    root->left->left->right  = newNode(10);
    root->left->right = newNode(5);
    root->left->right->left = newNode(11);
    root->left->right->right = newNode(12);
    root->right->right = newNode(8);
    root->right->right->left  = newNode(6);
    root->right->right->right  = newNode(7);
 
    /*   Constructed Binary tree is:
                 1
               /   \
             2      3
           /  \       \
          4     5         8
        /  \   /  \     /   \
       9    10 11  12   6     7    */
    cout << "Maximum width is "
         << maxWidth(root) << endl;
    return 0;
}
 

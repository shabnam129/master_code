#include <iostream>
#include <cstdlib>

#include <vector>

struct node 
{
  int data;
  struct node *left;
  struct node *right;

};


struct node * new_node(int data)
{

  struct node *node = (struct node *) malloc(sizeof(struct node) );
  node->data = data;
  node->left = NULL;
  node->right =NULL;

  return node;

}



struct node * insert ( struct node * , int );
void inorder(struct node * );

struct node * search_key(struct node * ,int );

struct node * find_inorder_prec(struct node * , int );
struct node * find_inorder_succ(struct node * , int );

int main()
{

  int i = 0;
  //struct node * root = NULL;
  int data = 0;

    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
   // insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
  
    // print inoder traversal of the BST

    inorder(root);
    queue.clear();
    
    std::cout << "\n Now going to delete element " << find_inorder_prec(;
    
     

    std::cout << "\n Now print inorder of  modififed BST";
}


struct node * insert ( struct node *node  , int data)
{
  static struct node * root  = node ;
  
  if(root ==NULL)
  {
   root= new_node( data);
   node = root;
  return root ;

  }

  if(node ==NULL)
  return new_node(data)  ;

  

  if( data > (node)->data)
  {
    
    (node)->right = insert( (node)->right , data);

  }

  if( data <  (node)->data)
  {
   (node)->left = insert(  (node)->left , data);

  } 
   
  
  return node;
}
  
 





void inorder(struct node * node)
{

  if(node ==NULL) //DOnt put node->next= Null bcaouse when its reaches to 5 then since its deosnt have any child sto its revert back to node(node->rihgt) and it will not get printted

   return ;

   inorder(node->left);
   std::cout << " " << node->data;
   inorder(node->right);

}


//left most of to the right of deleted node will be the inorder sucess ..Bcoz leftmost will be the next element in increasing order after the node which has to be  deleted
struct node * find_inorder_prec(struct node * root , int key )
{
   struct node * node = search_key(root ,key);

  struct node *current = node->left;
  if(current->right == NULL)
   return current; 
  
 while(current->right !=NULL)
   current = current->right;
  return current; 

}


//left most of to the right of deleted node will be the inorder sucess ..Bcoz leftmost will be the next element in increasing order after the node which has to be  deleted
struct node * find_inorder_succ(struct node * root , int data)
{

  struct node * node = search_key(root ,key);

  struct node *current = node->right;

  if(current->left == NULL)
   return current;

 while(current->left !=NULL)
   current = current->left;
  return current;



}


struct node * search_key(struct node *node ,int key)
{

 if(node->data ==key ||  node==NULL)
  return node;

 if(key > node->data)
  search(node->right , key);
 
  if(key <  node->data)
  search(node-left , key);

}


 






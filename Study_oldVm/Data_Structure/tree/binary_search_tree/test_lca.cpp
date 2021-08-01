#include <iostream>
#include <cstdlib>
#include <vector>

/*Logic_prog::::
 * Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 
           /
          35

LCA::Its the node from which branch is cut and two nodes are present in that branch.THe LCa node itself can be present in one of the branches
Lets assume n1and n2 are the numbers for which we need to find out the lca.(n1<n2).So lca in BST will node lies between n1 and n2 or either n1or n2 itself.
so we check the current node with n1 if smaller than n1 lies in right half else in first half.we need to jest check condtion first occurenece where n1<lca<n2.

*/

using namespace std;
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

void  find_lca(struct node *  ,  int ,int);

bool search_key(struct node * , std::vector<struct node *> &, int);

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
    insert(root, 20);
    
   // insert(root, 35);
    insert(root, 40);
    insert(root,35);
    insert(root, 70);
    insert(root, 60);

    insert(root, 65);
    insert(root, 80);
  
    // print inoder traversal of the BST
    inorder(root);
   // std::cout <<"\n enter the element for cwhich u want to know the succ";
   // std::cin >> data;
    find_lca(root,20,80);

   // std::cout <<"\n we are back in main and successor=======" <<  find_succ(root , data );
}


void find_lca(struct node * node ,  int n1,int n2)
{
   if( (node->data >= n1) && (node->data <=n2)  )
   {
      std::cout <<"\n ancsetor===" <<node->data;
      return;
   }
    
   else
   if(node->data < n1)
    find_lca(node->right ,n1,n2);
   else
    find_lca(node->left,n1,n2);
   

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
 


bool search_key(struct node *node , std::vector<struct node *> &node_queue, int key)
{

 if(node == NULL )
  return false ;

 if(node->left->data ==key )
  {
   node_queue.push_back(node);
   node_queue.push_back(node->left);
   return true ;

  }

  if(node->right->data ==key )                         
  {
   node_queue.push_back(node);
   node_queue.push_back(node->right);
   return true ;

  }

  if(node->data > key)
   {
     if ( search_key(node->left , node_queue,key) )
     return true;
   }
 
  if(node->data < key)
  {
    if(  search_key(node->right , node_queue,key) )
    return true;
  }


}
  
   








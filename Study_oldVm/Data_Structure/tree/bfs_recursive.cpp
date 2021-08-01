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


struct node * new_node(int data)
{

  struct node *node = (struct node *) malloc(sizeof(struct node) );
  node->data = data;

  return node;

}

void bfs_recursive(struct node *);
void inorder (struct node * );//LPR (left , parent ,right) 
void preorder (struct node * );//PLR (parent , left ,right )
void postorder (struct node * );//LRR (left , right ,parent )


int main()
{
 
     struct node *root  = new_node(1);
     root->left             = new_node(2);
     root->right           = new_node(3);
     root->right->left           = new_node(8);
     root->left->left     = new_node(4);
     root->left->right   = new_node(5);
     root->left->left->left     = new_node(6);
     root->left->left->right    = new_node(7);
    
    // std::cout << "\n Inorder===";
   //  inorder(root);
    bfs_recursive(root);
   
}



void inorder(struct node * node)
{

  if(node ==NULL) //DOnt put node->next= Null bcaouse when its reaches to 5 then since its deosnt have any child sto its revert back to node(node->rihgt) and it will not get printted

   return ;

   inorder(node->left);
   std::cout << " " << node->data;
   inorder(node->right);

   

}
 

void bfs_recursive(struct node *node)
{

 static std::vector<struct node *  > array;
  int i;
  //std::cout << "\n root node ===" << node->data;
  
  if(node->data ==1)
  {
  std::cout << "\n root node ===" << node->data;
  array.push_back(node->left);
  array.push_back(node->right);
  }

  if( !array.empty() )
   {
    // std::cout << array.front();
   struct node *curr_node = array.front();
   std::cout << " "  << curr_node->data;
   

    if(curr_node->left!=NULL)
       array.push_back(curr_node->left);
    
    if(curr_node->right!=NULL)
       array.push_back(curr_node->right);
     
     array.erase(array.begin() + 0);
     
     bfs_recursive(curr_node);
         

    }
    



}

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;
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

void inorder (struct node * );//LPR (left , parent ,right) 
void preorder (struct node * );//PLR (parent , left ,right )
void postorder (struct node * );//LRR (left , right ,parent )


bool fill_path_queue( struct node * , std::vector<int> &  , int );

int findLCA(struct node * , int , int);

int main()
{
    // Let us create the Binary Tree shown in above diagram.
    struct node  * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
   // cout << "LCA(4, 5) = " << findLCA(root, 4, 5);

    cout << "\nLCA(4, 6) = " << findLCA(root, 4, 6);
   // cout << "\nLCA(3, 4) = " << findLCA(root, 3, 4);
   // cout << "\nLCA(2, 4) = " << findLCA(root, 2, 4);
    return 0;
}

/*
int main()
{
 
     struct node *root  = new_node(1);
     root->left             = new_node(2);
     root->right           = new_node(3);
     root->left->left     = new_node(4);
     root->left->right   = new_node(5);
    
      std::cout << "\n Inorder===";
     inorder(root);
     std::vector<int> path1;
     std::vector<int> path2;

     find_lca_bst(root , path1 , );
 
     
  
}*/



void inorder(struct node * node)
{

  if(node ==NULL) //DOnt put node->next= Null bcaouse when its reaches to 5 then since its deosnt have any child sto its revert back to node(node->rihgt) and it will not get printted

   return ;

   inorder(node->left);
   std::cout << " " << node->data;
   inorder(node->right);

}
 
int findLCA(struct node *root , int n1, int n2)
{
  int i=0;
  std::vector<int> path1 , path2;
  
  fill_path_queue(root, path1,n1);

 
  fill_path_queue(root, path2,n2);
  
  std::cout <<"\n element in path1====:";
  for(i = 0; i< path1.size(); i++)
   {
    std::cout <<" "  <<path1[i];
   }
   
  std::cout <<"\n element in path2====:";
  for(i = 0; i< path2.size(); i++)
   {
    std::cout <<" "  <<path2[i];
   }


  for( i = 0 ; i < path1.size() && i< path2.size(); i++)
   {
    if(path1[i]!=path2[i])
      break;

   }   


  return path1[i-1];


}

bool fill_path_queue( struct node *root , std::vector<int> &path , int key)
{

  if(root ==NULL)
  return false;

  if(root->data == key)
   return true;

  path.push_back(root->data); 
 
  //check if the key is in left subtree....if return false than delete the nodes from queue i.e path last setmatent: 
  if(root->left)
   {
    if( fill_path_queue(root->left , path , key) )
     return true;

   }

 // check if the key is in right subtree....if return false than delete the nodes from queue i.e path last setmatent:
    if(root->right)
   {
    if( fill_path_queue(root->right , path , key) )
     return true;

   }

  path.pop_back();
  return false;


}
     
 




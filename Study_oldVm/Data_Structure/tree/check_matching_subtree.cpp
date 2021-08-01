#include <iostream>
#include <cstdlib>
#include <map>
#include <vector>
#include <iterator>
//Logic ::Stor the each node left and right child  data in map as value and key as parent node..Check if the this key value pair already exit or not if its their then its a sub tree... (rem not node becuase its an adreses the same data in tree can have difference adress )in map as value and key as parent node..Check if the 


struct node 
{
  char data;
  struct node *left;
  struct node *right;

};

typedef std::pair<char , char > left_right_pair;
//typedef std::pair<struct node * ,struct node *> left_right_pair;
typedef std::map<char, left_right_pair> my_map;

my_map my_map_var;
struct node * newNode(int data)
{

  struct node *node = (struct node *) malloc(sizeof(struct node) );
  node->data = data;

  return node;

}

void inorder (struct node * );//LPR (left , parent ,right) 
void preorder (struct node * );//PLR (parent , left ,right )
void postorder (struct node * );//LRR (left , right ,parent )

void subtree(struct node* node);
int main()
{
 

    struct node *root = newNode('A');
    root->left = newNode('B');
    root->right = newNode('C');
    root->left->left = newNode('D');
    root->left->right = newNode('E');
    root->right->right = newNode('B');
    root->right->right->right = newNode('E');
    root->right->right->left= newNode('D');
    /* struct node *root  = new_node(1);
     root->left             = new_node(2);
     root->right           = new_node(3);
     root->left->left     = new_node(4);
     root->left->right   = new_node(5);
     root->left->right->left   = new_node(6);
   */ 
     std::cout << "\n Inorder===";
     inorder(root);
     std::cout << "\n Preorder===";
     preorder(root );
  
     std::cout <<"\n lets check duplicate subtree"; 
     subtree(root);
}



void inorder(struct node * node)
{

  if(node ==NULL) //DOnt put node->next= Null bcaouse when its reaches to 5 then since its deosnt have any child sto its revert back to node(node->rihgt) and it will not get printted

   return ;

   inorder(node->left);
   std::cout << " " << node->data;
   inorder(node->right);

}
 


void preorder(struct node * node)//PLR
{


  if(node ==NULL) //DOnt put node->next= Null bcaouse when its reaches to 5 then since its deosnt have any child sto its revert back to node(node->rihgt) and it w
   return ;
 
   std::cout << " " << node->data;
   preorder(node->left);
   preorder(node->right);

}




void postorder(struct node * node)//LRP
{

  if(node ==NULL) //DOnt put node->next= Null bcaouse when its reaches to 5 then since its deosnt have any child sto its revert back to node(node->rihgt) and it w

   return ;

   postorder(node->left);
   postorder(node->right);
   std::cout << " " << node->data;
   
}


void subtree(struct node* node)
{
  char lc='\0';
  char rc='\0';
  if(node ==NULL)
     return ;
  
  my_map::iterator it = my_map_var.find(node->data);
  if(it ==my_map_var.end())
   {
     std::cout <<"\n key not found than store the child data";
     if(node->left!=NULL)
     lc = node->left->data;
     if(node->right!=NULL)
     rc = node->right->data;

     my_map_var.insert(std::make_pair(node->data, std::make_pair(lc,rc) ) );
   }
   else
   {

    std::cout <<"\n the key already exist";      
    if( (my_map_var[node->data].first == node->left->data) && (my_map_var[node->data].second == node->right->data)  )
     std::cout<<"\n Subtree happend occured for node " << node->data  << "\n l=" << node->left->data  << "\nR = " << node->right->data;
 
     
    

   } 
   subtree(node->left);
   subtree(node->right);
     
}
 

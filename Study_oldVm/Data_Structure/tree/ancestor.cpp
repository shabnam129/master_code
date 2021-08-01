#include <iostream>
#include <cstdlib>
#include <map>
#include <iterator>
#include <vector>
struct node 
{
  int data;
  struct node *left;
  struct node *right;

};

std::vector< struct node *> queue;

struct node * newNode(int data)
{

  struct node *node = (struct node *) malloc(sizeof(struct node) );
  node->data = data;

  return node;

}

//void inorder (struct node * );//LPR (left , parent ,right) 
std::map<struct node * , int > preorder (struct node *, int );//PLR (parent , left ,right )
void postorder (struct node * , int );//LRR (left , right ,parent )


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
 




#if 0
    struct node *root  = new_node(1);
     root->left             = new_node(2);
     root->right           = new_node(3);
     root->left->left     = new_node(4);
     root->left->right   = new_node(5);
    
     /* std::cout << "\n Inorder===";
     inorder(root);
      std::cout << "\n Preorder===";
     preorder(root );*/
#endif
     std::cout << "\n Lets check numer of ancersrotr===";
   
     std::map<struct node * , int > anc_map=    preorder(root, 15); 
     std::map<struct node * , int >::iterator it;

     std::cout <<"\n anc list";
     for(it = anc_map.begin();it!=anc_map.end();++it)
    {
      std::cout <<" " << (it->first)->data;
    }
   
   
     // postorder(root ,  root->left->right->data ); 
}



std::map<struct node * , int > preorder(struct node * node, int act_data)//PLR
{

  static std::map<struct node * , int > my_map;

  static int flag =0;
 
  if(node ==NULL) //DOnt put node->next= Null bcaouse when its reaches to 5 then since its deosnt have any child sto its revert back to node(node->rihgt) and it w
   return my_map;

  if(node->data ==act_data || flag ==1)
  { 
     flag=1;
     return my_map;
  }

   my_map[node]=1; 
   //std::cout << " " << node->data;
   preorder(node->left,act_data);
   preorder(node->right,act_data);
  
   if(flag==0)
  {
    std::map<struct node * , int >::iterator it;
    it = my_map.find(node);
   // if(it!=my_map.end())
  //  {
    //found
    my_map.erase(it);
   // }
  }

 return my_map;
}




/*void postorder(struct node * node , int key)//LRP
{
  static int  flag = 0;
  static node * root;
  if(node ==NULL) //DOnt put node->next= Null bcaouse when its reaches to 5 then since its deosnt have any child sto its revert back to node(node->rihgt) and it w

   return ;
   
  if( node->data == key)
   {
     flag = 1;
   }
   
   postorder(node->left ,  key);
   postorder(node->right,key);
   if( flag ==1 && node->data !=root->data )
   {
      queue.push_back(node);
   }     
  // std::cout << " " << node->data;
  
   
   
}

*/

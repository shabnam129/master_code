#include <iostream>
#include <cstdlib>
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


int sum_till_kth_elem(struct node *  , int * ,int , int * );
void inorder (struct node * );//LPR (left , parent ,right) 


int main()
{
 
     struct node *root  = new_node(1);
     root->left             = new_node(2);
     root->right           = new_node(3);
     root->left->left     = new_node(4);
     root->left->right   = new_node(5);
    
      std::cout << "\n Inorder===";
     inorder(root);

     int count = 0;
     int key = 3;
     int sum = 0;
     int sum_till_kth_elem(node  , count,key , sum );
}



void inorder(struct node * node)
{

  if(node ==NULL) //DOnt put node->next= Null bcaouse when its reaches to 5 then since its deosnt have any child sto its revert back to node(node->rihgt) and it will not get printted

   return ;

   inorder(node->left);
   std::cout << " " << node->data;
   inorder(node->right);

}
 

int sum_till_kth_elem(struct node *  node , int *count ,int key, int *sum )
{
 
  if(node ==NULL)
   {
    if(*count!=key)
     return 0;
    else
     return 1;
   
   }   
  
  
  int found =   sum_till_kth_elem (node->left , &count , key , &sum);

  

  if( found == 0)
  
  {
 
   if(*count != key)
    { 
      *sum = *sum + node->data;
      *count++;

    }
   
     if(*count ==Key)
     {
      *sum = *sum +  node->data;
       return sum;

      }
 
    sum_till_kth_elem( node->right , &count , key , &sum ) ;
    return 0;
  
  }
    

}  
    
   
   
   
 



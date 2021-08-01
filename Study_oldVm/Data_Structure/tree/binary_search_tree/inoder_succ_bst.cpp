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
In this find the node address(30) of elelement ...i .then go to right of that node(40)... if its not null then move to left most of this element it will give the succ.....becasuse that would the elment which will be less than current but more than acutal node


case 1::node->right !=NULL ...would be successdull by avoe stataement


case 2::node->right==NULL.
a)In this case the parent of this node would be sucess only if the parent->data > node->data. Like tre 50,30,20...Then for 30, 50 would be the succ
b) if(parent->data ->node->Data) ///for e.g in case of 80 ...then return null

To save prent i have put an queue...which will return parent and node addess  

Note:Prog fails at root node :: so kindly refer geeks for geeks for this
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

int find_succ(struct node *  ,  int );

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
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
  
    // print inoder traversal of the BST
    inorder(root);
    std::cout <<"\n enter the element for cwhich u want to know the succ";
    std::cin >> data;

    std::cout <<"\n we are back in main and successor=======" <<  find_succ(root , data );
}


int find_succ(struct node * node ,  int key)

{
  int i =0 ;
  std::vector<struct node *> queue;//queue which would contain the parent addess of key lement and node as its owen element
  
  search_key(node ,queue, key);
  std::cout << "\n data in quueue===" ;

  //Print queue
  for(i = 0; i< queue.size();i++)
   {
    struct node *temp = queue[i];
    std::cout << " " <<  temp->data;
   }
    
   std::cout <<endl;

   
   struct node *parent = queue[0];//queue.front();
   struct node *key_node = queue[1];//queue.end();//It contaings the node
   struct node *temp =  key_node;
  
   
   //traverses for case 1  
   if(temp->right !=NULL)
    {
      temp= temp->right;
     while(temp->left!=NULL)
     {
       temp=temp->left;
     }
     return(temp->data);
   
    }
//for case 2
  else
   if(parent->data > key_node->data)
     return parent->data;
   else 
    return -1;


    
       
   


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
  
   








#include <iostream>
#include <cstdlib>
#include <stack>
#include <vector>
#include <map>
#include <iterator>

/*Logic:Introduce a pointer attach into tree node.this pointer will be pointer to parent in case of right child and pointing to neighbour i.e right child of parent if current node is left child node 
*/

struct node 
{
  int data;
  struct node *left;
  struct node *right;
 // struct node *neig;
 // struct node *parent;
  struct node *attach;


};


struct node * new_node(int data)
{

  struct node *node = (struct node *) malloc(sizeof(struct node) );
  node->data = data;
//  node->neig =NULL;
 // node->parent=NULL;
  node->left =NULL;
  node->right=NULL;

  return node;

}

void inorder (struct node * );//LPR (left , parent ,right) 
void preorder (struct node * );//PLR (parent , left ,right )
void postorder (struct node * );//LRR (left , right ,parent )

void print_inorder_without_stack_recur(struct node *);


int main()
{
 
     struct node *root  = new_node(1);
     root->left             = new_node(2);
     root->right           = new_node(3);
     root->left->left     = new_node(4);
     root->left->right   = new_node(5);
  
     root->left->right->left   = new_node(6);

     //struct node * current = root;
     
    print_inorder_without_stack_recur (root);
   //  while(current!=NULL)
     
   

 
}


void print_inorder_without_stack_recur(struct node *current)
{
struct node *lc =NULL;
struct node *rc =NULL;
struct node *prev= NULL;
std::map<struct node *, int> my_map;

std::map<struct node *, int>::iterator it;
  
  while(current!=NULL)
  {
    if(current->left==NULL )
    {
      if(current->right!=NULL)
      current = current->right;
      else
      {
           
           std::cout <<" " << current->data;
           it = my_map.find(current);
           if(it==my_map.end())
            { 
             //not found
             my_map[current] = 1;//put it in visited node..So that when u come back again then tat link can be removed
             current = current->attach;
            }
           else
           {
               //Remove link when ur enterint second time 
               prev =current;
               current =current->attach;         
 
               prev->attach=NULL;
             
           }           
 
      }

    }
    else
    {
           
     // pre = findsuccsor(current); 
        lc = current->left;
        rc = current->right;

        it = my_map.find(lc);
        if(it!=my_map.end())
        { 
           //  found
           //if the child is already vistied then ....print the parent means current node and move to its next attach 
             my_map[current] = 1;
             std::cout <<" " << current->data;
             current = current->attach;
            continue;
       }
           	 	
       //Assigning attach pointer to left child and right child 
        if(lc!=NULL && rc!=NULL)
         {
           lc->attach = current->right;
           rc->attach =current; 
         }
   
       if(lc==NULL)
       rc->attach =current;
       if(rc==NULL)
       lc->attach=current;
  
  
        current = current->left;
    }//end of else

   
  }

}    /*  while(pre->right !=NULL && pre->right!=(current->right))
         {
            pre = pre->right;
         }
         if(pre->right ==NULL)
          {
            pre->right =current->right;//create link
          //  std::cout <<" " <<current->data;//preorder
            current= current->left;
           // std::cout <<" " <<current->data;
          }
         else
         {
          
          pre->right=NULL;//remove link 
        //  std::cout <<" " <<current->data; //inorder    
          current = current->right;
            std::cout <<"hello" <<current->data;  
         }
          
    }
  }
  



}*/

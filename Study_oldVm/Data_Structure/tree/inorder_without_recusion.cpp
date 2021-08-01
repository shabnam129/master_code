#include <iostream>
#include <cstdlib>
#include <stack>


/*Logic:First push the element into stack till left is not empty and then pop stack top and repeat same task for itsright



*/
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

void inorder (struct node * );//LPR (left , parent ,right) 
void preorder (struct node * );//PLR (parent , left ,right )
void postorder (struct node * );//LRR (left , right ,parent )


int main()
{
 
     struct node *root  = new_node(1);
     root->left             = new_node(2);
     root->right           = new_node(3);
     root->left->left     = new_node(4);
     root->left->right   = new_node(5);
  
     root->left->right->left   = new_node(6);

     struct node * node = root;
 
     std::stack<struct node * > stack;
    
     stack.push(root);
    
     std::cout << "\n inoreder ===";
     
     while(!stack.empty()  || node!=NULL )
     {
         // node =stack.top();
          while( node!=NULL )
            {
               if(node!=root) //becasuse root is already added into the stack
                 { 
                      stack.push(node);
                 } //push intop stack before moving so that the right element also get added
               node = node->left;
            }
           node = stack.top();

            std::cout << "  " << node->data;
            stack.pop();
             
            node = node->right;
           /* if(node->right!=NULL)
             {
                 
               node = node->right;
               stack.push(node);
             }
           */
    }
            
std::cout << "\n";
     
    
/*      std::cout << "\n Inorder===";
     inorder(root);
      std::cout << "\n Preorder===";
     preorder(root );
     std::cout << "\n Postorder===";
     postorder(root); */
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
   inorder(node->left);
   inorder(node->right);

}




void postorder(struct node * node)//LRP
{

  if(node ==NULL) //DOnt put node->next= Null bcaouse when its reaches to 5 then since its deosnt have any child sto its revert back to node(node->rihgt) and it w

   return ;

   inorder(node->left);
   inorder(node->right);
   std::cout << " " << node->data;
   
}



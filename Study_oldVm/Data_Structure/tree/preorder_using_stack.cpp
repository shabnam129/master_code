#include <iostream>
#include <cstdlib>
#include <stack>
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
    
     std::cout << "\n Inorder===";
     inorder(root);
     std::cout << "\n Preorder===";
     preorder(root );
     std::cout << "\n Postorder===";
     postorder(root); 
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

 /*std::stack<struct node *> my_stack;

 my_stack.push(node);
 struct node *temp;

 while( ! my_stack.empty()) 
 {
  
   temp = my_stack.top();
   std::cout <<" " <<  temp->data;
  
   my_stack.pop();

   if(temp->right!=NULL)
     my_stack.push(temp->right);
   if(temp->left!=NULL)
     my_stack.push(temp->left);

  }

}*/
 
  
   
  
   


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



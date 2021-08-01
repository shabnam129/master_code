#include <iostream>
#include <cstdlib>
//Logic::Utilize the right pointer in case its null.Point the right pointer to sucessor of inorder to that node like 5 is linked in this case.To get sucessor.U need to first left of current node.Then from this node move to right most node ....The loop will exit when on right hand side of root node has right pointer set ti null

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
}



void inorder(struct node * node)
{
  struct node *cur ,*prev ;
  cur = node;
  int flag=0;
  while(cur->right!=NULL)
  {
     if(cur->left!=NULL)
   //Lets find out the succssor
    {
     
      prev= cur->left;
      while(prev->right!=NULL && prev->right!=cur)
       {
                      prev= prev->right;
      }
     if(prev->right==cur)
      {
               prev->right=NULL;     
               std::cout <<" " <<cur->data;
               cur =cur->right;
 	       continue;
      }
     
      prev->right=cur;
      cur = cur->left;

   }
   else
   {
    std::cout << " " << cur->data;
    //prev = cur;
    cur = cur->right;
   }


  }//Out of while
 
   std::cout << " "<<cur->data;

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



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

void inorder (struct node * );//LPR (left , parent ,right) 
void preorder (struct node * );//PLR (parent , left ,right )
void postorder (struct node * );//LRR (left , right ,parent )
bool isBST(struct node* );


int main()
{
 
     struct node *root  = new_node(8);
     root->left             = new_node(6);
     root->right           = new_node(9);
     root->left->left     = new_node(5);
     root->left->right   = new_node(1);
    
      std::cout << "\n Inorder===";
     inorder(root);

    std::cout << "the tree is ==="<< isBST(root);
}





bool isBST(struct node* root)
{
    static struct node *prev = NULL;
     
    // traverse the tree in inorder fashion and keep track of prev node
    if (root)
    {
        if (!isBST(root->left))
          return false;
 
        // Allows only distinct valued nodes
        if (prev != NULL && root->data <= prev->data)
          return false;
 
        prev = root;
 
        return isBST(root->right);
    }
 
    return true;
}

void inorder(struct node * node)
{

  if(node ==NULL) //DOnt put node->next= Null bcaouse when its reaches to 5 then since its deosnt have any child sto its revert back to node(node->rihgt) and it will not get printted

   return ;

   inorder(node->left);
   std::cout << " " << node->data;
   inorder(node->right);

}
 


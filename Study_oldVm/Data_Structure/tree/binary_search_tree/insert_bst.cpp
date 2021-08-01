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
  node->left = NULL;
  node->right =NULL;

  return node;

}


struct node * insert ( struct node * , int );
void inorder(struct node * );

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

  /*while(1)
  {
    
    std::cout << "\n Enter 1 to insert \n2 display \n3 for exit" ;
    std::cin >> i;

    switch(i)
    {
     
     case 1 : std::cout << "\n Enter the data to insert";  
              std::cin >> data;
              insert(&root , data);
               break;

     case 2 :  std::cout << "\n disipaly inorder of BST";
               inorder(root);
               break;
     
     case 3 : std::cout << "\n Exiting from this program";
              exit(0);


    }
   
     
  }*/
 
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
 


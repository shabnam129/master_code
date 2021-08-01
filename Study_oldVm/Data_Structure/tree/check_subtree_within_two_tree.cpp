#include <stdio.h>
#include <stdlib.h>
#include <iostream>

//LOGIC:::Using preorder  
/*Treverse the left half of  root1 untill its data is not similar to root2 and then right half ..Once its matched than do preorder and check each node data .The moment there is mismtach return 0.

*/
 
/* A binary tree node has data, left child and right child */
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data)
{
    struct node* node =
        (struct node*)malloc(sizeof(struct node));
    node->data  = data;
    node->left  = NULL;
    node->right = NULL;
    return(node);
}


int check_preorder_wise(struct node *T , struct node *S)
{

   int left_flag = 0;
   int right_flag = 0;

   if( ( T ==NULL && S ==NULL ) )  //|| (T->right ==NULL && S->right ==NULL) )
   {
    return 1;
   }
  /*  if( ( T ==NULL || S ==NULL  )  //|| (T->right ==NULL && S->right ==NULL) )
   {
    return 1;
   }*/

   
   if(T->data !=S->data)
    {
      std::cout << "\n tree are not same";
      return 0;
    }
    
    //Traversse preorder for T and S ..
   //First check left half ...if any point it return false then right half wont be checked 
    left_flag =  check_preorder_wise(T->left , S->left) ;
   if(left_flag)
    {  
      right_flag =  check_preorder_wise(T->right , S->right);
    }
 
   //If left_flag comes out to be zero then automatincally right_flag will be zero and whole thing return 0
  // iF right_flag ==1 after traversing then return 1 
   if(right_flag) //left_flag && right_flag)
   return 1;
   else
   return 0;
 
 
}
   

 




int isSubtree(struct node *T,struct node *S)
{
    
    if(T==NULL)
    return 0;

    if(T->data ==S->data)
     {
       if( check_preorder_wise(T,S) ) 
        { std::cout << "\n we are in subtree  and tree are same";
         return 1;
        }
       else 
        return 0;
     }
    
    if( ! isSubtree(T->left , S)  ) //If not present in left tree then check right half of main  tree
     {
      if ( isSubtree(T->right ,S) )
        return 1;
      else 
       return 0;

      }
     
     else 
      return 1; 
    
    

  


}




 /* Driver program to test above function */
int main()
{
    // TREE 1
    /* Construct the following tree
              26
            /   \
          10     3
        /    \     \
      4      6      3
       \
        30
    */
    struct node *T        = newNode(26);
    T->right              = newNode(3);
    T->right->right       = newNode(3);
    T->left               = newNode(10);
    T->left->left         = newNode(4);
    T->left->left->right  = newNode(30);
    T->left->right        = newNode(6);
 
    // TREE 2
    /* Construct the following tree
          10
        /    \
      4      6
       \
        30
    */
    struct node *S    = newNode(10);
    S->right          = newNode(6);
    S->left           = newNode(4);
    S->left->right    = newNode(30);//30);

 
 
    if (isSubtree(T, S))
        std::cout <<"Tree 2 is subtree of Tree 1";
    else
        std::cout << "Tree 2 is not a subtree of Tree 1";
 
    return 0;
}

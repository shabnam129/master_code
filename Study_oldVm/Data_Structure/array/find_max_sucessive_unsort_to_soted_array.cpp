// C program to demonstrate insert operation in binary search tree
#include <iostream>
#include <vector>
std::vector<int> B;  
struct node
{
    int key;
    struct node *left, *right;
};
  
// A utility function to create a new BST node
struct node *newNode(int item)
{
    struct node *temp =  new node();//(struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key);
 
    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);   
 
    /* return the (unchanged) node pointer */
    return node;
}

  
// A utility function to do inorder traversal of BST
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        std::cout<<root->key;
 	B.push_back(root->key);
       // printf("%d \n", root->key);
        inorder(root->right);
    }
}
  




int main () {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    std::vector<int> A= {1,1,1}; //{ 10,1,9,6,8};
 //   std::vector<int> B;
    struct node *root = NULL;
    int i =0;
    for(i=0; i <A.size();i++)
    {
        if(i==0)
         root = insert(root, A[i]);
         else
         insert(root, A[i]);
         
        
    }
   
    /*insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);*/
  
    // print inoder traversal of the BST
    inorder(root);
    std::cout <<"B size=== " <<B.size();
  if(B.size()==1)
   {
     std::cout <<" mmax_diff==="<< 0;
    return 0;
  }
   int max_diff = B[1] - B[0];

   for(i=2; i <B.size();i++)
    {

	std::cout<<" " <<B[i];
        int cons_diff = B[i] - B[i-1] ;
        if(  cons_diff > max_diff)
          max_diff= cons_diff;
                        

    }

    std::cout <<"max_diff==" << max_diff;
    
}

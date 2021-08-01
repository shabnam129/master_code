#include <iostream>
#include <cstdlib>
struct node 
{
  char data;
  struct node *left;
  struct node *right;

};


void printInorder(struct node * );
char search_in (char * ,  char  , int );


struct node * new_node(char data)
{

  struct node *node = (struct node *) malloc(sizeof(struct node) );
  node->data = data;

  return node;

}




struct node * buildTree(char in[] , char pre[] , int start , int end)
{
  static int preIndex = 0;
  int in_index=0;

  if(start > end)
 {  std::cout << "start ===" << start << "and end== " << end; 
   return NULL;}
  struct node *node = new_node(pre[preIndex++]);

  if(start==end)
  return node;
  
 in_index = search_in ( in , node->data , end);

 node->left = buildTree(in , pre , start , in_index -1);
 node->right = buildTree(in , pre , in_index+1 , end);
  
  return node;   



}

char search_in (char * in  ,  char root, int len )
{
std::cout << "\n WE are in search ";
 int i = 0;
 int j = 0;

 for( i = 0; i <len; i++)
 {
   if(root ==in[i])
   return i;  
  
  }  


}
 
    
     
     
   
  



int main()
{
  char in[] = {'D', 'B', 'E', 'A', 'F', 'C'};
  char pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};
  int len = sizeof(in)/sizeof(in[0]);
  struct node *root = buildTree(in, pre, 0, len - 1);
 
  /* Let us test the built tree by printing Insorder traversal */
 // printf("Inorder traversal of the constructed tree is \n");
  printInorder(root);
//  getchar();
}
    


void printInorder(struct node * node)
{

  if(node ==NULL) //DOnt put node->next= Null bcaouse when its reaches to 5 then since its deosnt have any child sto its revert back to node(node->rihgt) and it will not get printted

   return ;
 
   printInorder(node->left);

   std::cout << " " << node->data;
   printInorder(node->right);

}





#include <iostream>
#include <deque>
#include <new>

//LOGIC::Using dqueue and iterative method of level order traversel of binary tree...If level if odd then print elemnt in fwd dirct of deque else print from back ward director elemtn of deque.Also insert elemet in deque at the back


/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

// A utility function to create a new node
struct node* newNode(int data)
{
    struct node* node = new struct node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return(node);
}
 

using namespace std;

void printSpiral(struct node *root)
{
 
 deque<struct node *> my_que;

 my_que.push_back(root);
 
 struct node * node =root;
// int que_size = 0;
 int count = 0; 
 
 int level =0 ;
 while(! (my_que.empty() ) ) 
 {

  count  = my_que.size(); 
  level++;

  std::cout <<"\n level===" << level;
  while(count!=0)
  {
    if(level%2 ==0)
    {
      node = my_que.front();
      std::cout << " data ==" << node->data ;//my_que.front();
      my_que.pop_front();
    }
       
    else
    {
      node = my_que.back();
      std::cout << " data ==" << node->data ;// my_que.back();
      my_que.pop_back();
    }
  
    if(node->left!=NULL)
      my_que.push_back(node->left);
    if(node->right!=NULL)
      my_que.push_back(node->right);

   count--;
  }
  

 }
   
 //*/  
}

 
int main()
{
    struct node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(7);
    root->left->right = newNode(6);
    root->right->left  = newNode(5);
    root->right->right = newNode(4);
    cout << "Spiral Order traversal of binary tree is \n";
    printSpiral(root);

    char SubjectLine[4] = {0};
SubjectLine[0] = 70;
SubjectLine[1] = 0x50;
SubjectLine[2] = 144%73;
SubjectLine[3] = '\0';

  int i =0;
  
  for(i = 0 ;i < 4; i++)
   {
   std::cout <<"\nback in main   and teting arra data===" << SubjectLine[i]; 
   }
 
    return 0;
}

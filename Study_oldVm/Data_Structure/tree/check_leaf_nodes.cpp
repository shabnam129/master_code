#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <semaphore.h>
#include <stack>
using namespace std;

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

int l1;
int l2;
int flag=0;
sem_t sem1;
sem_t sem2;

void *tree1(void *);
void *tree2(void *);



int main()
{
 
     struct node *root1  = new_node(1);
     root1->left             = new_node(2);
     root1->right           = new_node(3);
     root1->left->left     = new_node(4);
     root1->left->right   = new_node(5);
     root1->left->right->left   = new_node(6);
    
     std::cout << "\n Inorder===";
     inorder(root1);
    /* std::cout << "\n Preorder===";
     preorder(root );
     std::cout << "\n Postorder===";
     postorder(root); */

     struct node *root2  = new_node(1);
     root2->left             = new_node(2);
     root2->right           = new_node(3);
     root2->left->left     = new_node(4);
     root2->left->right   = new_node(5);
     root2->left->right->left   = new_node(6);
    
     std::cout << "\n Inorder===";
     inorder(root2);
    
    

     sem_init(&sem1,0,1);
     sem_init(&sem2,0,0);

     pthread_t threads[2];
     int rc = 0;
     rc = pthread_create(&threads[0], NULL, tree1, (void *)root1); 
  
     if (rc)
      { 
         cout << "Error:unable to create thread," << rc << endl; 
         exit(-1); 
      }

     rc = pthread_create(&threads[1], NULL, tree2, (void *)root2); 
  
     if (rc)
      { 
         cout << "Error:unable to create thread," << rc << endl; 
         exit(-1); 
      }
     pthread_join(threads[0],NULL);
     pthread_join(threads[1],NULL);

    if(flag==1)
    std::cout <<"\n leaf nodes are not same";
    else
    std::cout <<"\n They are same";


}




void *tree1(void * root)
{


struct node * node = (struct node *)root;
 
     std::stack<struct node * > stack;
    
     stack.push(node);
    
     std::cout << "\n inoreder ===";
     
     while(!stack.empty()  || node!=NULL )
     {

            
         // node =stack.top();
          while( node!=NULL )
            {
              if(node->left==NULL && node->right==NULL)
              {
               sem_wait(&sem1);
               l1= node->data;
               sem_post(&sem2);
            //  sem_wait(sem1);
              }  
         	
               if(node!=root) //becasuse root is already added into the stack
                 { 
                      stack.push(node);
                 } //push intop stack before moving so that the right element also get added
               node = node->left;
            }
           node = stack.top();

            //std::cout << "  " << node->data;
            stack.pop();
             
            node = node->right;
    }



}



void *tree2(void  * root)
{

struct node * node = (struct node *)root;
 
//struct node * node = root;
 
     std::stack<struct node * > stack;
    
     stack.push(node);
    
     std::cout << "\n inoreder ===";
     
     while(!stack.empty()  || node!=NULL )
     {

            
         // node =stack.top();
          while( node!=NULL )
            {

	     if(node->left==NULL && node->right==NULL)
                {
               sem_wait(&sem2);
               l2= node->data;
               std::cout <<"\n l1===" << l1 <<" and l2 ==="<< l2;
               if(l1!=l2)
               {
                  flag=1;
                  std::cout <<"\n not equal";
                  // pthread_exit(NULL);
               }
                   
               sem_post(&sem1);
            //  sem_wait(sem1);
              }  
         

               if(node!=root) //becasuse root is already added into the stack
                 { 
                      stack.push(node);
                 } //push intop stack before moving so that the right element also get added
               node = node->left;
            }
           node = stack.top();

          //  std::cout << "  " << node->data;
            stack.pop();
             
            node = node->right;
    }



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



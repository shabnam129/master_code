#include <iostream>
#include <cstdlib>


using namespace std;
struct node
{
   int data;

   struct node *next;

};// *root;


int count= 0;

void insert(struct node ** , int);
void display(struct node *);

void divide_two_part_check_palin(struct node * );

void swap (struct node ** , int ,int );

struct node * find(struct node * , int );

//struct node * reverse(struct node **  , struct node ** );

int main()
{
  
 std::cout <<"\n func===" << __func__;
 int vertex = 5;
 int option;
 int data;

 struct node *root=NULL ;//= (struct node *  start) malloc ( sizeof(struct node) );
 

 while(1)
 {
  std::cout << "\n enter 1 for insert data ,  2 for display and 3  for divide_two_part_check_palin and 4 ===for exit " ;
  
  cin>> option;

  switch(option)
  {
    
   case 1: std::cout << "\n enter the dagta element";
           cin >> data;
           insert (&root, data);
           break;
   case 2: display(root);
           break ;
   
   case 3: std::cout << "\n enter the position ";
           cin >>data;
           find(root , data );
           display(root);
           break;
   case 4: exit(0);


  }

 }
   

}


struct node * find(struct node *start , int pos_from_last)
{

 int count= 0;

 struct node * node =start;

 struct node *p1,*p2;
 p1 = p2 = node;
 
 while(count !=pos_from_last )
  {

   p2=p2->next;
   count++;
 
  }

  while(p2!=NULL)
  {
   p1=p1->next;
  
   p2=p2->next;
  
  }

  std::cout <<"\n p1 and p2=====" << p1->data;

  return p1;


  





}
#if 0
void swap (struct node **start ,int first , int second)
{

 struct node *tmp;
 struct node *node = *start;
 struct node *p1,*p2;
 p1= p2 = node;

 while(node->data !=first)
  {
   p1=node;
   p2=p1;
   node = node->next;

  }

 while(node->data !=second)
 {
  p2=node;
  node=node->next;
 
 }

 std::cout << "\n before swapping p1===" << p1->data << "\n p2====" <<p2->data;
 tmp=p1->next->next;

 p1->next->next = p2->next->next;
 p2->next->next = tmp;
    
 tmp =p2->next;

 p2->next = p1->next;
 p1->next = tmp;


} 
#endif




void insert(struct node **start , int data)
{
 
 struct node *tmp = (struct node *) malloc(sizeof(struct node));
 struct node *node;

 tmp->data = data;
 tmp->next =NULL;

 if(*start ==NULL)
  {
   *start =tmp;

  }

 else
  {
    node = *start;
    
    while(node->next!= NULL)
     {
       node =node->next;

     }
    
   node->next =  tmp;
   node =tmp;

  }
   
    
       
}
  



void display(struct node * root)

{
  std::cout << "\n HI IAM IN DISPLAY OF LINK LIST";

  if(root==NULL)
  {
    std::cout << "\nno element to display\n";
  }

  else
   {
     struct node *node=root;
     std::cout << "\ndisplay ELEMENT =====";

    while(node->next!=NULL)
      {
        std::cout << "   " << node->data;
        node=node->next;
      }

     std::cout << "\nandlast lemet ==  " << node->data << "\n" ;
   }


}


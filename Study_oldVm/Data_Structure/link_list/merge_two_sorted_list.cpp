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

struct node * merge (struct node * ,struct node * );

//struct node * reverse(struct node **  , struct node ** );

int main()
{
  
 std::cout <<"\n func===" << __func__;
 int vertex = 5;
 int option;
 int data;

 struct node *root1=NULL ;//= (struct node *  start) malloc ( sizeof(struct node) );
 
 struct node *root2=NULL ;

 while(1)
 {
  std::cout << "\n enter 1 for insert data  list 1 , \n insert for list 2 ,\n press 3 for dislay list 1 \n  press 4 for dislay list 2  and \n press 5 for  merge and \n press 6 ===for exit " ;
  
  cin>> option;

  switch(option)
  {
    
   case 1: std::cout << "\n enter the dagta element";
           cin >> data;
           insert (&root1, data);
           break;
 
   case 2: std::cout << "\n enter the dagta element";
           cin >> data;
           insert (&root2, data);
           break;

   case 3: display(root1);
           break; 

   case 4: display(root2);
           break ;
   
   case 5: display( merge(root1 , root2) );
         
           break;
   case 6: exit(0);


  }

 }
   

}



struct node * merge (struct node *root1, struct node * root2)
{

 struct node *node1 , *node2;
 struct node *tmp;
 struct node *node3;
 
 node1 = root1;
 node2 = root2;
 
 node3 =tmp =NULL; 

 for(int i=0; node1!= NULL && node2!= NULL ; i++)
  {
   if(node1->data < node2->data )
   { 
     if(tmp == NULL)
    { tmp = node1;
      node3= node1;
      node1 = node1->next;

    }
    
    else
     {
      node3->next = node1;
      node3 =  node1;
      node1 = node1->next;
     }

   }
  
  else
   { 

     if(tmp == NULL)
    { tmp = node2;
      node3= node2;
      node2 = node2->next;

    }
  
   else 
   {
    node3->next = node2;
    node3 =  node2;
    node2 = node2->next; 
   }
  
  } //enf of else

 } //end of for llop


  if(node1==NULL)
   {
    node3->next = node2;

   }

  if(node2==NULL)
   {
    node3->next = node1;

   }
    
  return tmp;     


    
  
 
}  




void insert(struct node **start , int data)
{
 
 struct node *tmp = (struct node *) malloc(sizeof(struct node));
 struct node *node;

 std::cout <<"\n enter the data====" ;
 //std::cin >> (tmp->data);i
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


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


void swap_alter_node (struct node ** );



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
  
   case 3: swap_alter_node(&root);
           display(root); 
   case 4: exit(0);


  }

 }
   

}


void swap_alter_node(struct node **head)
{

std::cout <<"\nWE are in swapping of number"; 
 struct node *prev = *head;
  
 struct node *cur = (*head)->next;
  
 *head = cur;
 struct node *node =cur;
 struct node *prev_link = prev;
 int count =0;
 

 while(true)
 {
 
    node = node->next;    
    count++;
   
     
     prev->next = cur->next;
     cur->next = prev;
  //   prev_link = prev;
  
      
      if(node==NULL)
      {
     
        
       prev_link->next = cur;
       prev_link= prev;
      
 
      break;      

      }

     if(node->next!=NULL )
     {
     
       

       //  prev=node;
      if(count>1)
      {
        prev_link->next = cur;
       prev_link= prev;
      
      }

      prev=node;
              
          
         cur = node->next;
         node = node->next;
         
      }
      else
      {
        if(count>1)
       {
        prev_link->next = cur;
      //  prev_link= prev;
      
       }
              
          
      
         
       break;
      }
     
  }   
  
       
}   




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


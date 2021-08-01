#include <iostream>
#include <cstdlib>



/*LOGic:::: First check whether the last node has been reached then set that node as start node focus on line *root= node....now return this back to recursive function...Now set the next pointer for the node(previous_node) return from recursion to current node(node) present in stack .. and set previus node as current node...now run this process untill first element of orig_list is not reached...
 createa a recurivse function which returns the latest node of reverse link list.....




*/
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

struct node * reverse(struct node **  , struct node ** );

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
   
   case 3: reverse(&root ,&root );
           display(root);
           break;
   case 4: exit(0);


  }

 }
   

}



struct node * reverse(struct node **head , struct node **root)
{

  struct  node * node = *head;

  static  int data = (*head)->data;

  std::cout <<"\n value of first data====" << data;
  
  struct node   * previous_node =NULL;

// head1 = head2 =NULL;
 
 if(node->next ==NULL)

 {
 
  head = &node; 
  *root = node;//to store the starting address of reverse list

  //head->next =NULL; 
  //head1 = node;
 
  return *head;

 }

 previous_node = reverse(&node->next , root);
 previous_node->next = node;

 previous_node = node;

 if(node->data == data)
  { previous_node->next =NULL;
   return *root;}
 else
 return previous_node;

// return head2;

}

void insert(struct node **start ,int  num)//Using double star u are accessing the start1 pointer instead of creating a new start

{

  struct node *tmp;
  tmp =(struct node  *  ) malloc(sizeof(struct node));
  tmp->data = num;
  tmp->next=NULL;

  if(*start==NULL)
  {
    *start=tmp;
  }

  else
   {
     struct node *node = *start;

    while(node->next!=NULL)
      {
        node=node->next;
      }

    node->next=tmp;
   }

  count++;

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


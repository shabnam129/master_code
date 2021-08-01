#include <iostream>
#include <cstdlib>

//LOGIC BEHIND THIS PROG WAS TO CREATE TWO HALVES....SECOND HALF WILL BE REVERSED AND THEN CHECK THAT EACH ELEMENT OF FIRST HALF AND SECOND REVERSE HALF ARE 
//EQUAL ...IF THEY ARE THEN ITS PALINDROME OTHERWISE ITS  NOT

using namespace std;
struct node
{
   int data;

   struct node *next;

};


int count= 0;

void insert(struct node ** , int);
void display(struct node *);

void divide_two_part_check_palin(struct node * );

struct node * reverse(struct node **);

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
   
   case 3: divide_two_part_check_palin(root);
   case 4: exit(0);


  }

 }
   

}

void divide_two_part_check_palin(struct node * start)
{

 int middle_elem = (count/2) +1;

 std::cout <<"\n middle element" << middle_elem; 
 
 struct node * head1 = start;
 struct node *head2 = NULL;
 struct node *node2 = NULL;

 struct node *node1 = start;

 // Dividing array in two half ...
 int i=0;
 for( i=0; i < middle_elem ;i ++)
  {
    node1 = node1->next;
  }
     
  
  head2 = node1;
  node2 = head2;

  //head1 will containing pointerto first hal inclding middle element while head2 will  be pointing to second half till list end
  for(i=0; node2->next!=NULL;i ++)
  {
    node2 = node2->next;
  }

  display(head2);

  //reverse the second half and reassgin the address  of reverse second half to head2 pointer
  head2 = reverse(&head2);

  std::cout << "\n dispay head2 aferter rever";

  display(head2);

  //CHeck wheather reversed 2half is equal to first half till middle element
  node1 = head1;
  node2 = head2;

  for( i=0; i < middle_elem-1 ;i ++)
  {

    std::cout << "\n node1->data =====" << node1->data << "\n node2->data =====" <<  node2->data;
    if(node1->data !=node2->data)
     {   std::cout << "\n they are not pallindrome";
         break;  
     }
     
    node1=  node1->next;
    node2=  node2->next;

   
  }

 if(i == middle_elem - 1 )

 {

  std::cout <<"\n yipppe its palindorm";


 }




}


struct node * reverse(struct node **start)
{

  struct  node * node = *start; 
 static struct node *old_start = *start;  
 static struct  node *head1 , *head2 ; 

 head1 = head2 =NULL;
 
 if(node->next ==NULL)

 {
  
  head2= node;//to store the starting address of reverse list 
  head1 = node;
 
  return head1;

 }

 reverse(&node->next);
 head1->next = node;//head1 is instaillized by if condiotn 
 head1 = node ;

 if(head1 == old_start)
 {
   head1->next = NULL;
   return head2;

 }

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


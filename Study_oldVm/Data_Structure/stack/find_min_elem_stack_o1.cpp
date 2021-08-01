#include <iostream>
#include <cstdlib>


using namespace std;
struct node
{
   int data;
   int min_elem;

   struct node *next;

};// *root;


class stack
{
  public:
  int min_elem;
 // node stack_node;
 /* void set_min(int data ) 
  {
   stack_node.min_elem = data;

  }
 */ 
  int get_min()
  {
    return min_elem;
  }
 
  void push( int );
  int pop();
  
  int count;
  int capacity;
  node *root;
 
  stack(int stack_size)
  {
    std::cout << "\n Stack Consructior";
   // stack_node.data = 0;
    //stack_node.min_elem = 0;
   // stack_node.next=NULL;
    root = NULL;
    count = 0;
    min_elem=0;
    capacity =  stack_size; 

  }
  
 ~stack()
  {

    std::cout << "\n Stack Desrtuctor";
  }   
  
};

void display(struct node *);


int main()
{
  
 std::cout <<"\n func===" << __func__;
 int vertex = 5;
 int option;
 int data;

 struct node *root=NULL ;//= (struct node *  start) malloc ( sizeof(struct node) );
 stack own_stack(10); 
 own_stack.push(109);
 own_stack.push(2);
 own_stack.push(8);
 own_stack.push(9);
 own_stack.push(5);
 own_stack.push(6);
 own_stack.push(7);
  
 std::cout <<"\n min value in stack" << own_stack.get_min(); 

}


void stack::push (int data)
{


 std::cout <<"\n we are in push";

 if(count == capacity)
 {
   std::cout <<"\n stack full completely";
   return;

 }

 struct node *tmp = (struct node *) malloc(sizeof(struct node));

 tmp->data = data;
 tmp->next =NULL;


 if(root ==NULL)
  {
    root=tmp;
    min_elem= root->data;
    count++;
    return ;
  }

 if(min_elem > tmp->data)
  {
    min_elem = tmp->data;
  }
 
   
  tmp->next =root;
  root=tmp;  
  
  count++;
 

}


int stack::pop ()
{
 std::cout <<"\n we are in push";

}


/*void insert(struct node **start , int data)
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
  
*/


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


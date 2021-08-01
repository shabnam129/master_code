#include <iostream>
#include <cstdlib>

struct node
{
 int data;
 struct node * next;

};

struct list_head
{

 struct node *head;

};


struct Graph
{

 int V;

 struct list_head *arr;

};
 

int  display( struct node *);
void insert (struct Graph * , int , int);



int main()

{
  int V;
  struct Graph *G = (struct Graph *) malloc(sizeof (struct Graph ) ) ;
  
 /* std::cout << "\n enter the number of vertex";
  std::cin >> G->V;
  */
  G->V= 7;
  V= G->V;

  G->arr= (struct list_head *) malloc ( V * sizeof(struct list_head ) );

  int i=0;
  for( i =0 ; i< V;i++)
   {

   G->arr[i].head==NULL;
 
   }
 
   /*insert(G,1,3);
   insert(G,1,2);
   insert(G,2,3);*/

    insert(G, 0, 1);
    insert(G, 0, 4);
    insert(G, 1, 2);
    insert(G, 1, 3);
    insert(G, 1, 4);
    insert(G, 2, 3);
    insert(G, 3, 4);

    
   display(G->arr[0].head);

   display(G->arr[1].head);


   display(G->arr[2].head);

   display(G->arr[3].head);
   
    display(G->arr[4].head);
  
 // insert(G,0,4);


} 

struct node * create_node(int data)
{
 struct node *tmp = (struct node * ) malloc (sizeof (struct node ));
 tmp->data = data;
 tmp->next = NULL;

 return tmp;

}
  
void insert(struct Graph *G , int i , int j)
{ 

 struct node * node1; 
 struct node * node2;
  
  if(G->arr[i].head ==NULL)
   {
    G->arr[i].head=create_node(i) ;
    node1= G->arr[i].head;

   }
   
  else
  {  
     node1= G->arr[i].head;
    while(node1->next !=NULL)
    {
      node1 = node1->next;

    }

  }   
  
   node1->next= create_node(j) ;

 
   if(G->arr[j].head ==NULL)
   {
    G->arr[j].head=create_node(j) ;
    node2= G->arr[j].head;

   }

  else
  {
     node2= G->arr[j].head;
    while(node2->next !=NULL)
    {
      node2 = node2->next;

    }

  }

   node2->next= create_node(i) ;


  /* node1->next = G->arr[j].head;     
   node1=  G->arr[j].head;
   node1->next = NULL; 
  */
 

}


int  display( struct node *root )

{

 if(root==NULL)
 {
   std::cout <<"\n Nothin to print ";
   return -1;

 }

 else  

  {

   struct node * node =root ;
   std::cout <<"\n data for " << node->data <<"====\n"; 
   while(node->next !=NULL)
   {

   node =node->next;
   std::cout <<" " << node->data;

   }
   
   
 
  } 
 

}


#include <iostream>
#include <cstdlib>

struct node
{
 int data;
 struct node * next;

};


struct Graph
{

 int V;

 struct node **arr;

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

  G->arr= (struct node **) malloc ( V * sizeof(struct node * ) ); //Here its means if its malloc is type cast (struct node * ) then means arr is pointer  one box (sttuc node)/ one element (not data)  of linklost ...If u want than arr contains array where each ellement of array point sttart of link list...make it (int **) and array to be (int **arr in graph) ... now its means that each location return by malloc will contains address of something which can head pointer as u type casst...

  int i=0;
  for( i =0 ; i< V;i++)
   {

   G->arr[i]==NULL;//A[i] will hold adress head pointers of thier respective link list
 
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

    
   display(G->arr[0]);

   display(G->arr[1]);


   display(G->arr[2]);

   display(G->arr[3]);
   
    display(G->arr[4]);
  
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
  
  if(G->arr[i]==NULL)
   {
    G->arr[i] =create_node(i) ;
    node1= G->arr[i] ;

   }
   
  else
  {  
     node1= G->arr[i];
    while(node1->next !=NULL)
    {
      node1 = node1->next;

    }

  }   
  
   node1->next= create_node(j) ;

 
   if(G->arr[j] ==NULL)
   {
    G->arr[j]=create_node(j) ;
    node2= G->arr[j];

   }

  else
  {
     node2= G->arr[j];
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


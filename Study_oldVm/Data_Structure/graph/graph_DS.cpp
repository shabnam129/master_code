#include <iostream>
#include <cstdlib>
#include <string.h>


/*  Logic of this code::
                      1
                  2        4   
                           3
                         6---5   
pick edge from the alraedy graph.....Create array (arr)  which will store the root parent of the nodes ...Intially they are -1 ...NOW start making set but before that check parent of each node .....if the node belong to some set then the 2nd node should be added to that set by making parent of that 2nd to be repseanative to f that set ......Create array arr_2 which will check whehter  node  have been traversed  already as its uniderected graph


*/

struct node
{
 int data;
 struct node * next;

};


int arr_size = 7;
int *arr = (int * ) malloc ( arr_size * sizeof (int));

struct list_head
{

 struct node *head;

};


struct Graph
{

 int V;

 struct list_head *arr;

};
 

int check_cycle(struct Graph *);


int  display( struct node *);
void insert (struct Graph * , int , int);

void makeset ( int , int );


int main()

{
  int V;
  struct Graph *G = (struct Graph *) malloc(sizeof (struct Graph ) ) ;
  
  G = (struct Graph *) malloc(sizeof (struct Graph ) ) ;
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

    insert(G, 1, 2);
    insert(G, 1, 4);
    insert(G, 4, 3);
    
    insert(G, 3, 5);
    insert(G, 3, 6);
    insert(G, 5, 6);

    
   display(G->arr[0].head);

   display(G->arr[1].head);


   display(G->arr[2].head);

   display(G->arr[3].head);
   
   display(G->arr[4].head);
  
   display(G->arr[5].head);
   display(G->arr[6].head);

   std::cout << "\n G->arr[1].head"  << G->arr[1].head->data; 
   check_cycle(G);


}


/*int findset(node1->data)
{
 int i=0;

 for(i=0; i< 7;i++)
  {
*/


void makeset ( int sec , int rep)

{

  arr[sec] = rep;


}

int findset(int child)
{
  int j=0;
 
  int parent ; 
  int i;
  j = child;
 for(i=0 ; arr[j] !=-1; i++)
  {

   j=arr[j];

  }


if(j ==child)
{
parent = -1;

}
else
parent = j;
 
 return parent; 



}



int check_cycle(struct Graph *G)
{

std::cout << "\n we are in CHCK CYCLE";

int i = 0;
int j = 0;
int rep = 0;

int p=0;
int q=0;

int arr_2[20][2];//Will contain all the visited pair like (1,2) (1,4)

int flag_rep =0;

int flag_cycle = 0 ;

memset(arr, -1,  arr_size * sizeof (int));

int l,m;
l= m=0;
int parent1 ,parent2;
struct node * node1 , *node2;

  for( i=0 ; i < G->V ;i++)
   {
      if(G->arr[i].head ==NULL) ///If the loop variable is not part of graph  then continue to next array
       {continue;}
  
     node1 = G->arr[i].head; 
     node2 = node1;
     //parent1 = findset(node1->data);
    // std::cout << "\nHELLO i===="  << i << "parent of head===" << node1->data << "=====" << parent1;
 
     for(j=0 ;node2->next!=NULL ; j++)
      {
         arr_2[l][0] = node1->data;
         node2 = node2->next;
         
         arr_2[l][1] = node2->data;
         l++; 
     
         //Check whether this two nodes are already been checkd....Like 4->3 and 3->4...If yes then make repetive flag and continue with other nodes 
         for (int p = 0; p<20; p++)
           {
             
             if(arr_2[p][0] == node2->data && arr_2[p][1] == node1->data)
              {
                  std::cout <<" \n here iam " ;
                  flag_rep=1;
                  break;
              }
           }     
  
         if(flag_rep ==1)
          {
             flag_rep =0;
             continue;
          }

      
            
          parent1 = findset(node1->data);
          parent2 = findset(node2->data);

          std::cout << "\nparent of " << node2->data << "=====" << parent2;

          if (  (parent1 == parent2) && (parent1  !=-1) && (parent2  !=-1) ) //check if two nodes have same parent and nodes are not their own parent
           {
             std::cout << "\n bahii cycecl exit between  =====" << node1->data << "&&&&"   << node2->data;
             flag_cycle = 1; 
             break;
           }
           
               
          if(parent1 == -1 && parent2 == -1) //if both nodes are new or parents of its own
            {
              rep = node1->data;  
              makeset(node2->data,rep);
  
            }
            

           else if (parent1 == -1 && parent2 != -1)//If the node1 is unset and node 2 is set  then make that parent of that node1 repsenetative of node2
            { 
              rep = parent2;
              //rep = node2->data;
              makeset(node1->data,rep);
            }
   
            else if (parent1 != -1 && parent2 == -1)////If the node2 is unset and node 1 is set  then make that parent of that node2 repsenetative of node1

            {
              rep = parent1;
              makeset(node2->data,rep);
            }


      }//END of inner most for loop

     if(flag_cycle == 1)
       {
         std::cout <<"\n yo babay cycle found out ....now exit from the loop" ;
          break;

       }
        
           
  

     l++;
   }//ENd of outer for loop

 
 std::cout << "\n new arr====";
 for ( j =0 ; j < 7; j++)
  {   std::cout << "\n j  ===="  << j << " arr=== "  << arr[j];}
  
  

}
 

struct node * create_node(int data)
{
 struct node *tmp = (struct node * ) malloc (sizeof (struct node ));
 tmp->data = data;
 tmp->next = NULL;

 return tmp;

}



//Create link both ways between node to make it undirected graph 
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


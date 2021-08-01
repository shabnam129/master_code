#include <iostream>
#include <cstdlib>

struct graph
{
 int V;
 int E;
 int **adj;

};
//CHeck last commented list  lines to understand the code
int main()
{
 int u,v;
  u=v=0;
 struct graph *G = (struct graph *) malloc (sizeof(struct graph));

 std::cout << "\nEnter the inumber of  nodes and  the edges";
 std::cin >> G->V  >> G->E;

 G->adj= (int **)   malloc(sizeof(int) * (G->V ));//Here  ...It mean b is pointing to a memory localation which contains b[0] b[1]

 std::cout << "\n memory address from" << G->adj;
//  * G->V));

    
 for ( u=0 ; u < G->V  ; u++)
 {
   
   G->adj[u] = (int *)   malloc(sizeof(int) * (G->V )); //Here b[0] whill be pointing to actaul element of array that will be storing the data
  for(v=0;v < G->V;v++)
  {
   G->adj[u][v]=0;//Accessing the actaul element
  }
 }

 


 for ( u=0 ; u <4  ; u++)
 {
   std::cout <<"\n value of == ==="  <<u << "  row ====";
  for(v=0;v < 4 ;v++)
  {
   std::cout << G->adj[u][v];
  }
 }




 for (int i=0 ; i <G->E ; i++)
 {
  std::cout << "\nEnter the 1  node ie  the edges";
  std::cin >> u;
  std::cout << "\nEnter the 2  node ie  the edges";
  std::cin >> v;
  G->adj[u][v]=1;
  G->adj[v][u]=1;

 }
 

   for ( u=0 ; u <4  ; u++)
 {
   std::cout <<"\n value of == ==="  <<u << "  row ====";
  for(v=0;v < 4 ;v++)
  {
   std::cout << G->adj[u][v];
  }
 }




}


/*


19	 std::cin >> G->V  >> G->E;
(gdb) n
Enter the inumber of  nodes and  the edges4
2
21	 G->adj= (int **)   malloc(sizeof(int) * (G->V ));
(gdb) n
23	 std::cout << "\n memory address from" << G->adj;
(gdb) p G->adj
$1 = (int **) 0x603030
(gdb) p G->adj[0]
$2 = (int *) 0x0
(gdb) n

27	 for ( u=0 ; u < G->V  ; u++)
(gdb) n
30	   G->adj[u] = (int *)   malloc(sizeof(int) * (G->V )); 
(gdb) n
31	  for(v=0;v < G->V;v++)
(gdb) p G->adj[0]
$3 = (int *) 0x603050
(gdb) p G->adj[0][0]
$4 = 0
(gdb) p &G->adj[0]
$5 = (int **) 0x603030
(gdb) p &G->adj[1]
$6 = (int **) 0x603038
(gdb) p G->adj+1
$7 = (int **) 0x603038
(gdb) 
*/




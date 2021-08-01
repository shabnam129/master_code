#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

#define V 5

/*Prim's algorithm for Minimum Spanning Tree in (Hindi, English) with Example
https://www.youtube.com/watch?v=xENj6Ns3CfU
https://www.youtube.com/watch?v=mas07czjUSA

spanning tree & Minimum spanning tree ::: it the subgraph or tree of given undirected graph which contain all the vertex but few edges which makes its uncyclic...
this is called as spanning tree...there can be many many such sub-graph but the one with minimum wieght of edges is called the minimum spanning tree




logic of the prog::Three queues will be there...First contains  non visisted vertex....2..prenet queue vertex contain the parent of the vertex for which it has mininum wiehgt...3.. key(quueu) contains the minium weight for that particular vertex which can be added to the tree....


:CHECK GEEKS FOR GEEKS PROG::::THAT IS MORE SIMPLER AND HAVE SAME FUNCTIONALIT

REfer the the youtube videos ...to understand it....

Pick the smallest key value and  
*/


using namespace std;
//vector<int> neigbour;

int graph[V][V] =   { {0, 2, 0, 6, 0}, 
                      {2, 0, 3, 8, 5},
                      {0, 3, 0, 0, 7},
                      {6, 8, 0, 0, 9},
                      {0, 5, 7, 9, 0},
                     };



int extract_min(   vector<int> key)
{
  int i;
  int index = 0;
  int min_value = key[0];
  

  for(i=0; i < V; i++)
  {
     if(min_value >  key[i])
      {
         min_value = key[i];
         index = i ;
      }
  
     

  } 
 return index;

}


vector<int> find_neigbour(int u)
{
 int i=0;
  int count =0;

  std::cout << "\n HI IAM IN FIND NEIFBOUR of =========" <<  u ;
  vector<int> neigbour;
 
  for(i=0; i< 5;i++)
   {
    if(graph[u][i] !=0)
    {
      neigbour.push_back(i);

    }

   }  
    
   return neigbour;

}



void primMST()

{
  //creating 3 queues
  vector<int> Queue;//mstSet;
  vector<int> key;
  vector<int> parent(5);
  
  
 
  int i=0;
 
  for(i = 0 ; i < V ;i++)
   {
    Queue.push_back(i);//enetering all the vertex in the queue and will delete them one by one
    key.push_back(INT_MAX);//Put max value in key vector
   // parent.push(-1);
   }

  //  mstSet[i]=1;

   parent[0] = -1;
   key[0]=0;

   int u,v;
    
 
   for(i = 0 ; !Queue.empty() ;i++)
   {
    
    u = extract_min(key);//get the next minimum key value from the key vector  which will be added to tree 
    std::cout <<"\n smallest key valye is " << u; 
    vector<int> N_vec  =  find_neigbour(u);//find its neigbour:w

    //check the key value of its childs and checks is weight from edge  parent(u) till child ....If its less than the current than update the key's value and parent for that vertex

    for(vector<int>::iterator it = N_vec.begin(); it != N_vec.end(); it++)
     {
        cout <<"all neigbout for thiszz===="<<  *it << endl;
         v= *it;
        
       if( (std::find(Queue.begin(), Queue.end(), v) != Queue.end() )  && graph[u][v] < key[v])

        {
            parent[v]= u;
            key[v] =  graph[u][v];

            cout << "chuildd  v==== "<< v << "\n kvalue -====" <<  key[v] << endl;
             
        }        
      }
  
      //attach this u to it parent
     key[u] = INT_MAX;
     // key.erase(key.begin() + u); 

      Queue.erase( std::remove( Queue.begin(), Queue.end(), u  ), Queue.end() );  //remove the vertx from queue
      //Queue.erase(Queue.begin());   
  
   
      
   } 

    std::cout <<"\n parent ===" ;

    std::cout << "Edge   Weight\n ";
   for (int i = 1; i < V; i++)
     {
       std::cout <<  parent[i] << "=====" <<  i << "====" <<  graph[i][parent[i]];
       std::cout <<"\n";
     }

     
  /*
      for(vector<int>::iterator it = parent.begin(); it != parent.end(); it++)
     {
        cout << *it << endl;
     }
  */    

 
   // find_nebour(u);   
    
        

      
    



}








// driver program to test above function
int main()
{
   /* Let us create the following graph
          2    3
      (0)--(1)--(2)
       |   / \   |
      6| 8/   \5 |7
       | /     \ |
      (3)-------(4)
            9          */

/*   int graph[V][V] = {{0, 2, 0, 6, 0},
                      {2, 0, 3, 8, 5},
                      {0, 3, 0, 0, 7},
                      {6, 8, 0, 0, 9},
                      {0, 5, 7, 9, 0},
                     };
*/ 
    // Print the solution
    primMST();
    std::cout << "\n HI IAM IN MAIN";

   // vector<int> N_vec  =  find_neigbour(2);
   
   
    /*for(vector<int>::iterator it = N_vec.begin(); it != N_vec.end(); it++)
     { cout << *it << endl;}
   */

 
    return 0;
}

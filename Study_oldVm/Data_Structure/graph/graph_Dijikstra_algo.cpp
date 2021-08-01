#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

#define V 5

/*
If Your new than please refer Prim's algo then this one
This algo is lit bit similar to prim's algo only difference in prime algo we check for mininum key value or edge or weight  for a particular  node(Means the lowest edge it has no matter which parent is ) ,while in dijkistra we check for minmum value of sum of ( distance of  that node from parent and key value of parent )

For  example in below graph:::
              3   
           (1)--(2)
       |   / \   |
      6| 8/   \5 |7
       | /     \ |
      (3)-------(4)
            9       

According to prime the parent of node number (4) should bt (1) as its smallest weight or edge...But since 1 is coming from 2(source node) which has weight of 3 which when combine with weight(1,4) which is 5 makes a total path 8  is greateer than  path 7  which is from (2,4) ...So according to dijkistra its parent is 2 rather than 1


https://www.youtube.com/watch?v=eVHvcfD7K5o&index=63&list=PLsFNQxKNzefJNztGGoQC-59UhSwIaiIW3

logic of the prog::Three queues will be there...First contains  non visisted vertex....2..prenet queue vertex contain the parent of the vertex for which it has mininum wiehgt...3.. key(quueu) contains the minium weight for that particular vertex which can be added to the tree....


:CHECK GEEKS FOR GEEKS PROG::::THAT IS MORE SIMPLER AND HAVE SAME FUNCTIONALIT

REfer the the youtube videos ...to understand it....

Pick the smallest key value and  
*/


using namespace std;

int extract_min_key( vector<int> );
void Find_shortest_path(int );
vector<int> find_neigbour(int );

/* int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
*/

int graph[V][V] =   { {0, 2, 0, 6, 0}, 
                      {2, 0, 3, 8, 5},
                      {0, 3, 0, 0, 7},
                      {6, 8, 0, 0, 9},
                      {0, 5, 7, 9, 0},
                     };



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
    int start  = 0;
    std::cout << "\n HI IAM IN MAIN";
    std::cout << "\n enter the source element";
    std::cin >>  start;
    Find_shortest_path(start);


    return 0;
}



void Find_shortest_path(int start)

{
  //creating 4  queues
  vector<int> Queue;//mstSet;
  vector<int> key;
  vector<int> parent;
  vector<int> new_key;
  int u,v;
  int i=0;
 
  for(i = 0 ; i < V ;i++)
   {
    Queue.push_back(i);//enetering all the vertex in the queue and will delete them one by one
    key.push_back(INT_MAX);//Put max value in key vector
    new_key.push_back(INT_MAX);
    parent.push_back(-1);

   }


   parent[start] = -1;
   key[start]=0;
   new_key[start] = 0;
   
   
  for(i = 0 ; !Queue.empty() ;i++)
   {
    
    u = extract_min_key(key);//get the next minimum key value from the key vector  which will be added to tree 
    std::cout <<"\n smallest key valye is " << u; 
    vector<int> N_vec  =  find_neigbour(u);//find neibhour of u 

//Check which parent  of a particular vertex has minumu of sum ( lowest key of parent and edge from parent to child)..If its small than update the key value of that child vertex or node and also update the entry of parent for that particular vertex


    for(vector<int>::iterator it = N_vec.begin(); it != N_vec.end(); it++)
     {
        cout <<"all neigbout for thiszz===="<<  *it << endl;
         v= *it;
        
       if( (std::find(Queue.begin(), Queue.end(), v) != Queue.end() )    &&   ( graph[u][v] + key[u] < key[v]) )

        {
            parent[v]= u;
            key[v] =  key[u] + graph[u][v];
            new_key[v] = key[v];
            cout << "chuildd  v==== "<< v << "\n kvalue -====" <<  key[v] << endl;
             
        }        
      }//End of inner for loop
  
      //attach this u to it parent
     key[u] = INT_MAX;

      Queue.erase( std::remove( Queue.begin(), Queue.end(), u  ), Queue.end() ); //Search the above visited  vertex in queue and then remove it from queue.
      //Queue.erase(Queue.begin());   
      
   }//End of for loop 

    std::cout <<"\n check parent and  and their shortest distance ===" ;


    for (int i = 0; i < V; i++)
     {
       std::cout <<  parent[i] << "=====" <<  i << "====" <<  new_key[i];
       std::cout <<"\n";
     }


}


int extract_min_key( vector<int> key)
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

  for(i=0; i< V;i++)
   {
    if(graph[u][i] !=0)
    {
      neigbour.push_back(i);

    }

   }

   return neigbour;

}


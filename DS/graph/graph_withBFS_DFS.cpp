//
//  main.cpp
//  Graph
//
//  Created by MLS Mac 1 on 09/01/21.
//  Copyright © 2021 MLS Mac 1. All rights reserved.
//



// A simple representation of graph using STL

#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <list>

/*Logic: Create 2-d vector..Each vector contains its all the child node
FOR BFS:  Use queue as BFS for tree and an visited vector which will store if the child been already traverseed from somewhere else
this node been called since its graph any node can point to anyone.
Link:https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/
FOR DFS: Pick a elem print it  and call its child.. Stop the recursion untill an elem with no child or all the child has already been traversed
we need to keep visited Vector here too.
LINK:https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/
 
 */


using namespace std;

//DIRECTED GRAPH
class graph{
public:
    //constructor
    graph( int size){
        //Intialize 2-d vec
        for(int i=0;i<size;i++) {
            vector<int> vec;
            m_vec.push_back(vec);
        }
    }
    void BFS(int n);
    void addEdge(int source, int dest );
    vector<vector<int>> m_vec; // set of 1-d vector
    void DFS(int n);
    void DFSHelper( int cur_elem , vector<bool> &visited);
};

// Driver code
int main()
{
    int V = 5;
    
    graph g(4);
    
    vector<vector<int>> adj(V);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    
    std::cout << "Following is Breadth First Traversal(starting from vertex 2" <<std::endl;
    
    g.BFS(2);
    g.DFS(2);
    return 0;
}


// A utility function to add an edge in an
// directed graph.
//Add u is source and v is destination
void graph::addEdge( int source, int dest)
{
    m_vec[source].push_back(dest);
}
//Tree like BFS
void graph::BFS( int start)
{
    deque<int> que;
    std::vector<bool> visited;
    
    for(int i=0;i<m_vec.size();i++)
        visited.push_back(false);

    que.push_back(start);
    visited[start]=true;
    
    while(!que.empty())
    {
        int cur_elem  = que.front();
        int level  =  que.size();
        while(level--)
        {
           int cur_elem = que.front();
           //Print Current element
           std::cout <<"  " << cur_elem;
            
           que.pop_front();
          //Push all the child elem in que for next processing
          for( auto child_elem: m_vec[cur_elem])
          {
              //Check if child not already traverserd then only traverse
              if(visited[child_elem]==false)
              {
                  que.push_back(child_elem);
                  visited[child_elem]=true;
              }
              
          }
        }//end of inner  while
    }//end of outer while loop
 
}

void graph::DFS(int cur_elem)
{
    int len = m_vec.size();
    vector<bool> visited(len);
     
    for(int i=0;i<len;i++)
        visited[i]=false;
    
    DFSHelper(cur_elem,visited);
}
  
void graph::DFSHelper( int cur_elem , vector<bool> &visited)
{
    int len = m_vec[cur_elem].size();
    std::cout << " " << cur_elem;
    visited[cur_elem]=true;
    
    //If no child left
    if(len==0)
    {
        return ;
    }
    
    
    //Traverse through all child
    for( auto child :m_vec[cur_elem] )
    {
        if(visited[child]!=true)
         DFSHelper(child,visited);
        
    }
    
    
}

  
// A utility function to print the adjacency list
// representation of graph
void printGraph(vector<vector<int>>& adj, int V)
{
    for (int v = 0; v < V; ++v)
    {
        cout << "\n Adjacency list of vertex "
             << v << "\n head ";
        for (auto x : adj[v])
           cout << "-> " << x;
        printf("\n");
    }
}
  

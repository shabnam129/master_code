//
//  main.cpp
//  Dijkstra_Algorithm_graph
//
//  Created by MLS Mac 1 on 17/01/21.
//  Copyright © 2021 MLS Mac 1. All rights reserved.
//

/*Dijkstra_Algorithm: Its used to get the smallest distance/weight from one location/node to all other node/location
 it should be connected or via..
 
VIDLInK:https://www.youtube.com/watch?v=sD0lLYlGCJE&list=PL-Jc9J83PIiHfqDcLZMcO9SsUDY4S3a-v&index=15&ab_channel=Pepcoding
Logic: Use BFS...While traversing check which child to be visited first the smaller wieght or higher weight..
For that we can use prioerity queue..In this way u can traverse all the node.
 
NODE:I have created a node which have data and weight..This is the node which will be inserted instead of data
to print the data from src nodes.
 
 */


// A simple representation of graph using STL

#include <iostream>
#include <vector>
#include <deque>
#include <queue>// for proiority queue
#include <set>
#include <algorithm>


using namespace std;

//Node will contains data and weight for every node in graph
class node{
public:
    
    node(int data ,int weight):data(data) ,weight(weight){}
    int data;
    int weight;
    
    // We compare node objects by their data
    //operator required in case u want to create set or map for this class
    bool operator<(const node& t) const
    {
        return (this->data < t.data);
    }
    
};
//Graph interface
class IGraph
{
     public:
     virtual void BFS(int n)=0;

     virtual void DFS(int n)=0;
};

//DIRECTED GRAPH
class WeightGraph :public IGraph
{
public:
    //constructor
    WeightGraph( int size){
        //Intialize 2-d vec
        for(int i=0;i<size;i++) {
            vector<node> vec;
            m_vec.push_back(vec);
        }
    }
    //For weighted Graph
    void addEdge(int source, int dest ,int weight );
    void BFS(int n)override;
    void DFS(int n)override;
    
    vector<vector<node>> m_vec; // set of 1-d vector

    void Dijkstra(int source);
    
   
};


// Driver code
int main()
{
    int V = 7;
    //Create graph

    WeightGraph g(7);
    // 1st is Cur_node , 2nd  is child node and Third is weight from cur_node to chidl
    g.addEdge(0, 3,40);
    g.addEdge(0, 1,10);
    g.addEdge(1, 2,10);
    g.addEdge(2, 3,10);
    g.addEdge(3, 4,2 );
    g.addEdge(4, 5,3);
    g.addEdge(4, 6,8);
    g.addEdge(5, 6,3);
    
    std::cout << "Following is Distance  vertex 0" <<std::endl;
    
    g.Dijkstra(0);
    return 0;
}


// A utility function to add an edge in an
// directed graph.
//Add u is source and v is destination also add weight
void WeightGraph::addEdge( int source, int dest_data ,int weight)
{
    //Create a node with data and weight
    node newnode(dest_data,weight);
    m_vec[source].push_back(newnode);
}


// this is an strucure which implements the
// operator overloading for Proority queue of MIN heap
class CompareWeight {
public:
    bool operator()(node const& n1, node const& n2)
    {
        // return "true" if "p1" is ordered
        // before "p2", for example:
        return n1.weight > n2.weight;
        
        
    }
};

void WeightGraph::Dijkstra(int src)
{
    //Create min_heap by using compareotr
    priority_queue<node, vector<node> , CompareWeight> min_heap;
    //This set is used to get the visited nodes and
    //also contains nodes with their distance from source
     
    set<node> visit_map;
    //vector<bool> visited_node(m_vec.size(),false);
    node data(src,0);
    
    min_heap.push(data);
        
    while(!min_heap.empty()){
        //Get Minimum path Child
        node Cur_node= min_heap.top();
        
        int Curdata = Cur_node.data;
        //Insert the node into visited node
        if(!visit_map.count(Cur_node))
            visit_map.insert(Cur_node);
    
        min_heap.pop();
        
        //Access all child element
        auto itr = m_vec[Curdata].begin();
        
        for(itr; itr!=m_vec[Curdata].end();itr++)
        {
          //Check child already traverserd to stop looping
          if(!visit_map.count(*itr) ) {
              //Change nodes weight from source instead of from their parent
              itr->weight =  itr->weight +Cur_node.weight;
              min_heap.push(*itr);
           }
        }//end of child traversing
        
    }//End of while
   
    //Print the nodes distance  from source
        auto itr2  = visit_map.begin();
        std::cout <<"\n node= " << "   Wegiht";
        
        for(itr2;itr2!=visit_map.end();itr2++){
           std::cout <<"\n node=" <<itr2->data <<"   W=" << itr2->weight;
        }
        
        
}





//Tree like BFS
void WeightGraph::BFS( int start)
{
  /*  deque<int> que;
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
 */
}

void WeightGraph::DFS(int cur_elem)
{
  /*  int len = m_vec.size();
    vector<bool> visited(len);
     
    for(int i=0;i<len;i++)
        visited[i]=false;
    
    DFSHelper(cur_elem,visited);*/
}
  
/*void WeightGraph::DFSHelper( int cur_elem , vector<bool> &visited)
{
   /* int len = m_vec[cur_elem].size();
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
    
    
}*/



    
    
    
    

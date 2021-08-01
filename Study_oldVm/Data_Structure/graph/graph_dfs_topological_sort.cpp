// C++ program to print DFS traversal from a given vertex in a  given graph
#include<iostream>
#include<list>
#include<vector>
#include<stack>

using namespace std;

//Topological sort means :::if there is an edeg from u to v then....In while printing the u should comes before v.
//Logic for impleting the same ...Keep all the vertex into array until all the its child element is not trevsererd and once they are tranvseresd ...keep that vertex into stack...In this way parent will be before the child element when u print the stack...

 
// Graph class represents a directed graph using adjacency list representation
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // Pointer to an array containing adjacency lists
    void DFSUtil(int v, bool visited[] );  // A function used by DFS
public:
    Graph(int V);   // Constructor
    void addEdge(int v, int w);   // function to add an edge to graph
    void DFS(int v);    // DFS traversal of the vertices reachable from v

    stack<int> Stack;


};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}
 
void Graph::DFSUtil(int v, bool visited[])
{
    // Mark the current node as visited and print it
    visited[v] = true;
    cout << v << " ";
   
   // parent = v; 
    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
    {
         if (!visited[*i])
             DFSUtil(*i, visited );
       /* else
        {
            if(*i !=parent)
           {   cout << "\n the loop exitin ===== " << *i ;
 
      break;}
         }*/
     }
    Stack.push(v);
    //stack[count] = v;
   
}
 
// DFS traversal of the vertices reachable from v. 
// It uses recursive DFSUtil()
void Graph::DFS(int v)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    // Call the recursive helper function to print DFS traversal
    DFSUtil(v, visited );

    

    for (int i = 0; i < V; i++)
      if (visited[i] == false)
        DFSUtil(i, visited ); 

    std::cout << "\n NOW SEE THE TOPOLOGICAL SORT"; 
 
     while (Stack.empty() == false)
    {
        cout << Stack.top() << " ";
        Stack.pop();
    } 
   
}
 
int main()
{
    // Create a graph given in the above diagram
    Graph g(7);


     g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

/*    g.addEdge( 1, 2);
    g.addEdge( 1, 4);
    g.addEdge( 4, 3);

    g.addEdge( 3, 5);
    g.addEdge( 3, 6);
    g.addEdge( 5, 6);

*/
    
/*    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
   // g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
*/ 
    cout << "Following is Depth First Traversal (starting from vertex 2) \n";
    g.DFS(0);
 
    return 0;
}

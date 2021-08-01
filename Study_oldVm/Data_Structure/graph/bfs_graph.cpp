#include <iostream>
#include <list>
#include <vector>

class Graph
{
public:
 int V;

 std::list<int> *arr;

 Graph(int);
 void  BFS(int );
 void addEdge(int , int);


};

Graph::Graph(int v)
{
 V=v;

 arr = new std::list<int>[v];

}


void Graph::addEdge(int u  , int w)
{
std::cout << "\n we are in  Graph::addEdge";
 arr[u].push_back(w);


}


int main()
{
  std::cout << "\n we are in main";
  Graph G(4);

  G.addEdge(0, 1);
  G.addEdge(0, 2);
  G.addEdge(1, 2);
  G.addEdge(2, 0);
  G.addEdge(2, 3);
  G.addEdge(3, 3);
  std::cout <<"\n WE ARE before BFS";  
  G.BFS(2);

}



void Graph::BFS(int s)
{

 std::cout <<"\n WE ARE IN BFS";
 std::vector<bool> marked_array;
 std::list<int> queue;
 int i=0;

 for(i=0;i<4;i++)
  {
    marked_array.push_back(false);

      //marked_array[i] = false;

  }

  marked_array[s]=true;
  queue.push_back(s);

 
  while( !queue.empty() )
   {
       s= queue.front();

       marked_array[s]=true;
 
       std::cout << "\ndata===" << s;//since it returns iterator
       queue.pop_front();
  
      for (std::list<int>::iterator it=arr[s].begin(); it != arr[s].end(); ++it)
       {   //std::cout << ' ' << *it;
           
           if(!marked_array[*it])
            {std::cout << "we are cominh inside" ;
              queue.push_back(*it);
            }
       }
    
   }

}

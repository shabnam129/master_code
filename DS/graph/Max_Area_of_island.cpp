/*Logic: Graph dfs or bfs.. I have used bfs..
Link:https://leetcode.com/problems/max-area-of-island/

*/
int getMaxAreaofIsland(vector<vector<int>>& vec)
{
    
    int m  = vec.size();
    if(m==0)
        return 0;
    int n  = vec[0].size();
    
    
    
    vector<vector<int>> visitor(m, vector<int>(n,0));
    
    deque<pair<int,int>> deq;
    
    
    
    int maxres = 0;
    int res = 0;
    
    
    for(int i=0; i< m;i++)
    {
        
        for(int j=0;j<n ;j++)
        {
            
            if(vec[i][j]==0  || visitor[i][j]==1)
              continue;
            //insert in case of 1
            deq.push_back({i,j});
        
            res =0;
           
            while(!deq.empty())
            {
                
                auto cur_ind = deq.front();
                int row = cur_ind.first;
                int col = cur_ind.second;
                
                //std::cout  << "\n row=" <<  row << "  col=" << col << " res=" <<res;
                //remove current item
                deq.pop_front();
                
                if(visitor[row][col]==1)
                    continue;
                //Mark it visited
                visitor[row][col]=1;
                
               
                //increament result
                res++;
                
                 //traverse throrugh all child of it
                
                //Left child && check left side boundry
                if(col-1 >= 0 && vec[row] [col-1]==1 && visitor[row] [col-1]==0) {
                     deq.push_back(std::make_pair (row,col-1));
                    // std::cout <<"\n Left child traversed";
                }
                   
                
                
                
                //right child && check right side boundry
                if ( col+1 < n  && vec[row] [col+1]==1  && visitor[row] [col+1]==0){
                     deq.push_back(std::make_pair(row,col+1));
                
                   // std::cout <<"\n Right child traversed";
                }
                   
                
                //below child  && check row boundry
                if( row+1 < m && vec[row+1] [col]==1  && visitor[row+1] [col]==0){
                     deq.push_back(std::make_pair (row+1,col));
                
               // std::cout <<"\n Below child traversed";
                }
                   
                
                
                //Top child
                if(row-1 >= 0 && vec[row-1] [col]==1  && visitor[row-1] [col]==0){
                    
                    deq.push_back(std::make_pair (row-1,col));
                    
                //std::cout <<"\n Top child traversed";
                    
                }
                
                
            }//end of while
            
           // std::cout << "res= " << res;
            
            maxres = max(maxres,res);
            
        }
    }
    
    
    return maxres;
}

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int res = getMaxAreaofIsland(grid);
        return res;
        
    }
};

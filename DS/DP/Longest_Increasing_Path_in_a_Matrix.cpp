//
//  main.cpp
//  Longest_Increasing_Path_in_a_Matrix
//
//  Created by MLS Mac 1 on 09/05/21.
//  Copyright © 2021 MLS Mac 1. All rights reserved.
//Link:https://leetcode.com/problems/longest-increasing-path-in-a-matrix/submissions/
/*Logic: For every pos try four path check ,if the cur_pos value is less than the path value (for INC order). if its yes than move ahead and call recurssively else return back and sent the result to parent/caller. For every position we get the Increasing count from four path, get the max out of the four and store in DP[row][col]. so that next time if someone calls then its not recacluated*/


#include <iostream>
#include <vector>
using namespace std;


typedef vector<vector<int>> dp_t;


int  maxHelper(int left,int right,int top, int down)
{
    
    int max1= max(left,right);
    int max2= max(top,down);
    
    int res = max(max1,max2);
    return res;
    
}

int RecurLongpath(int i,int j , vector<vector<int>>& vec,dp_t& dp )
{
    int row = vec.size();
    int col = vec[0].size();
  
    int left =0;
    int right = 0;
    int top = 0;
    int down=0;
    
    int cur_max=0;
    
    //Check if pos already pre computed and store in dp.
    if(dp[i][j]!=0)
        return dp[i][j];
    
    // Check all the four path
    //left
    if( j>0 && vec[i][j] < vec[i][j-1] )
      left  =   RecurLongpath(i,j-1,vec,dp);
    //right
    if(j < col-1 && vec[i][j] < vec[i][j+1])
      right =  RecurLongpath(i,j+1,vec,dp);
    //top up
    if(i>0 &&  vec[i][j] <  vec[i-1][j])
      top =   RecurLongpath(i-1,j,vec,dp);
    
     //top down
     if(i < row-1 &&  vec[i][j]  <  vec[i+1][j])
      down =  RecurLongpath(i+1,j,vec,dp);
    
    //Get the max of all the four path squenece and 1 itself to it
    cur_max  = maxHelper(left,right,top,down) + 1;
    //store in dp
    dp[i][j] = cur_max;
    
    return dp[i][j];
  
    
}



class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& vec) {
        
    int row = vec.size();
    int col = vec[0].size();
     
    dp_t dp(row, vector<int>(col,0));
    int res_Max=0;
        
    //check for every pos the paths
    for(int i=0;i<row;i++)
    {
            for(int j=0; j<col;j++)
            {
              int ret =  RecurLongpath(i,j,vec,dp);
              res_Max =max(ret,res_Max);
            }
    }
     return res_Max;
    }
};


int main(int argc, const char * argv[]) {
    
    Solution obj;
    
    vector<vector<int>> vec = {
        {9,9,4},
        {6,6,8},
        {2,1,1}

    };
    
    int res = obj.longestIncreasingPath(vec);
    std::cout <<"\n res=" <<res;
    
    
    
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

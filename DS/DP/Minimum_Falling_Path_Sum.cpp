/*Promlem statement:In this prograam we have to find minimum path from row 0 to till last row.At each position we have option to go next row with coloumn position 1 to left and centre pos and coloumn position 1 to right.
vid link for question: https://www.youtube.com/watch?v=T0h30zOtCmM&ab_channel=codebix
 
Logic:Its DP Problem..At postion we have to get the minimum from three position
 
TOP DOWN (recusive solution with memotization):So at every postion we have to get the minimum from three position.Store min for every position in hash and pass in to parents.
Bottom UP DP: Start from last row, since last row dont have any path so it will act as DP.
 Now this can be used for row above to it..At every postion we need to check the result for below row and add to the current number and modify element of cur postion to this minimum value.. This row data will help to the above it.
 result will the minimum path value in first row data.
 
Question Link:https://leetcode.com/problems/minimum-falling-path-sum/submissions/
*/
//
//  main.cpp
//  Minimum_Falling_Path_Sum
//
//  Created by Shabnam Mac 1 on 29/12/20.
//  Copyright © 2020 MLS Mac 1. All rights reserved.
//

#include<iostream>
#include<vector>
using namespace std;

int getMinSum(vector<vector<int>>& vec)
{

    int minres=INT_MAX;
    int row = vec.size()-1;
    
    int col  = row;
    int j=col;
    
    
    //Start from second last row
    for(int i=row-1; i>=0;i--)
    {
        //travers every coloum for row
        for(int j=0; j<= col;j++)
        {
           //Check for three path
            
            //next row centre col/pos
            int res = vec[i+1][j];
            
            //next row leftmost col/pos
            if(j-1>=0)
             res  = min( res ,vec[i+1][j-1] );
            
             //next row irghtmost next  col/pos
            if(j+1<=col)
             res  =  min( res , vec[i+1][j+1]);
            
            //store min plus current pos value to current pos so that it can be used by above row
            vec[i][j] = res + vec[i][j];
            
        }//col for loop
        
    }//row for loop
    
    
    //Now check the minimum from first row
    for(int j=0; j<=col;j++)
    {
        minres = min(minres, vec[0][j]);
    }
    
    
    return minres;
    
    
    
}


class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        
        int res = 0;
        
         res = getMinSum(A);
        return res;
        
    }
};


#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

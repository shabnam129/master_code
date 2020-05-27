//
//  main.cpp
//  NQueensProblem
//
//  Created by MLS Mac 1 on 26/05/20.
//  Copyright © 2020 MLS Mac 1. All rights reserved.
//
/*Logic:: NQueens is classic problem of backtracing..Place first queen q1 as 'q' 1st row in  matrix..While placing check current pos is valid or not, by doing coloumn validation(it should not colide in upper vertical..also do digonal validation( like left and right digonal) no q should be present in matrix..
 After the pos is valid then check with next row queens.. and do whole procedure above as again
 
 Note::In this question dont stop if u have found matrix.. instead check for the current pos is there any other combination with the next rows..Means intead of returning true or false to pos...Return the valid paths or string..
 Link:https://www.interviewbit.com/problems/nqueens/
 
 */

#include <iostream>
#include <vector>
using namespace std;

typedef vector<char> singleVecType;

typedef vector<string> stringVecType;

typedef vector<stringVecType> twoDStringvec;

typedef vector<char> singleVecType;

typedef vector<string> stringVecType;

typedef vector<stringVecType> twoDStringvec;



bool ColoumValidation(vector<singleVecType > &vec, int row, int col , int n )
{
    //Upper half
    
    for(int i=row-1; i >= 0; i--){
        
        if(vec[i][col]=='Q')
            return false;
    }

    
    //it means we have not found any conflict in coloumn wise
    return true;
}

bool DiagonalValidation(vector<singleVecType > &vec, int row, int col , int n )
{
    //Right diagonal check
    
    int i =row;

    int j = col;
    
    while( i>0 &&  j  < n)
    {
        
        if(vec[--i][++j] == 'Q')
            return false;
       
    }
    
    //Left diagonal check
    i=row;
    j=col;
    
    while( i!=0 && j!=0)
    {
        
        if(vec[--i][--j] == 'Q')
            return false;
       
    }
    
    //it means we have not found any conflict in coloumn wise
    return true;
}



bool isCurrentMovevalid(vector<singleVecType> &vec, int row, int col ,int n)
{
    //check coloum validation..vertical
    int colValid  = ColoumValidation(vec,row,col,n);
    if(colValid == false)
      return false;
    
    //check Diagonal.. Horizontal
    int digValid = DiagonalValidation(vec,row,col,n);
   
    if(digValid ==false)
        return false;
    
   
    else
    return true;
    
}


twoDStringvec NextQueenCheck(vector<singleVecType > &vec,int row ,int n)
{
    twoDStringvec ret_vec;
    
    //base condition for termination of recurssion or backtracing..
    if(row >=n )
    {
        string s("");
        stringVecType vec;
        vec.push_back(s);
        ret_vec.push_back(vec);
        
        return  ret_vec ;
    }
    
    for(int col=0;col<n ;col++)
    {
        vec[row][col] ='Q';
        
        bool isCorrectMove = isCurrentMovevalid(vec,row , col , n);
        
        if(isCorrectMove ==false)
        {
            vec[row][col] ='.';
            if(col == n-1 )
            {
                return ret_vec;
            }
                
            continue;
        }//end  of doing validation
        
        twoDStringvec ret_val  = NextQueenCheck(vec,row+1,n);
        
        
        string s;
        //Create string for current elemen in its row.. lie  s= .Q..
        for (int i  =0 ;i <n;i++){
            s.append(1,vec[row][i]);
        }
        
        //add this current s into all the vector which has been return from next row by func"NextQueenCheck"
        //it might be that for current row and element ..it can have multiple solution/combination from next //row which are valid
        for( auto elem : ret_val){
            //to this vector add our own string
            elem.insert(elem.begin(), s);
            ret_vec.push_back(elem);
        
        }
         
       //again set element to .
       vec[row][col] ='.';
        
    }//end of checking each elemetn
 
    
  return ret_vec;

}//end of function


vector<vector<string>> GetNqueensResult(int n)
{
    vector<vector<char> > vec;
    
    vector<char> oneDVec = {'.'};
    
    //create matrix of n*n with all elements containg '.' intiallly
    for(int i=0;i<n;i++) {
         oneDVec.clear();

        for(int j= 0; j<n;j++)
            oneDVec.push_back('.');
        
         vec.push_back(oneDVec);
    }
    //resultant vector of question
    vector<vector<string> > res_vec;
    
    res_vec = NextQueenCheck(vec,0,n);
    
    //remove the last element which has been introduce due to space check res_vec before pop back
    for( auto &elem : res_vec)
    {
        elem.pop_back();
    }
   

   return res_vec;
    
    
}



int main()
{
    //chess-board or matrix size
    int n =4;
    vector<vector<string> >  res_vec ;
    
   
    res_vec =   GetNqueensResult(n);
    return 0;
   
}

//Interview bit code

class Solution
{
public:
    vector<vector<string> > solveNQueens(int A);
    
};
   
vector<vector<string> > Solution::solveNQueens(int A) {
    
    vector<vector<string> >  res_vec ;
    
    if(A==0)
    {
        return  res_vec;
        
    }
    
    if(A==1)
    {
        vector<string> vec_str;
        string s;
        s.append(1,'Q');
        
        vec_str.push_back(s);
        res_vec.push_back(vec_str);
        return  res_vec;
        
    }
    
     res_vec =   GetNqueensResult(A);;
    return  res_vec;
   
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}

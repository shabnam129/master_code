//
//  main.cpp
//  Minimum_Difficulty_of_a_Job_Schedule
//
//  Created by MLS Mac 1 on 26/01/21.
//  Copyright © 2021 MLS Mac 1. All rights reserved.
//
/*Questiion Link :https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/
 Logic: In this we can make to have to make combination let assume we have arr as 6,5,4,3,2,1 and day 2.
 first  day: 6.. max =6
 second day: 5,4,3,2,1.. max=5..  res_till_now (5 +6 )= 11
 first  day: 6,5.. max =6
 second day: 4,3,2,1.. max =6 .. res_till_now(6+4)=10.
 first  day: 6,5,4.. max =6
 second day: 3,2,1.. max =3 .. res_till_now(6+3)=9.
 first  day: 6,5,4,3.. max =6
 second day: 2,1.. max =2 .. res_till_now(6+2)=
 first  day: 6,5,4,3...max =6
 second day: 2,1.. max =2 .. res_till_now(6+2)=8.
 first  day: 6,5,4,3,2.. max =6
 second day: 1.. max =1 .. res_till_now(6+1)=7.
 first  day: 6,5,4,3,2,1.. max =6
 second day: no left.. so back as is left

 So its like on every day1 fix a postion and then check furthre combination...then again add number next number like in next lopp 5 is added to 6 do this untill number of days are 0.
 
 This can also serve dp  like
 6,5,4,3,2,1
 0,1,2,3,4,5
 if day=3
 
 [6]- day3
 [5,4]- day2
 [3,2,1]- day1
 
 so for arr for pos 3 with day 1 could have been called from below combo
 [6,5] day3 and [4] as day 2
 [6]   day3 and [5,4] as day 2

 dp[pos][day]--- dp[3][1] can be saved instead of getting called everytime
 
*/

// C++ program to find out execution time of
// of functions
#include <algorithm>
#include <chrono>
#include <iostream>
#include<vector>
using namespace std;
using namespace std::chrono;


//----------------------------------------- Recursion + DP -----------------------------------------//
#include <iostream>
#include <vector>

using namespace std;


int getMinTimeDP(vector<int>& vec, int day,int cur_pos,vector<vector<int>> & dp  )
{
   
    
    int len= vec.size();
    
    //Check if days are 0 and all the element treaveserd
    if( day ==0 && cur_pos==len)
    {
        return  0 ;
    }
    //check if all the element traversersed and day is still not zero
     if(cur_pos ==len || day ==0 )
       {
           return  -1 ;
       }
    
    //Check if we have the pos + day combination already traversed
    if(dp[cur_pos][day]!=-1)
        return dp[cur_pos][day];
   
    int cur_day_max = vec[cur_pos];
    
    int Min_DiffTillNow=INT_MAX;
    int res  =INT_MAX;
   
    //From this cur_pos, add elements into that day and also check max element in that day/windows
    for(int pos=cur_pos; pos< len ;pos++)
    {
       //Get  max in that jobs for that day window
       cur_day_max = max(vec[pos] , cur_day_max);
        
       res = getMinTimeDP(vec,day-1,pos+1,dp);
       //check if getting result from next day is minimum and we also need to add it to cur_max
       if(res!=-1 )
       Min_DiffTillNow = min (Min_DiffTillNow , cur_day_max + res);
        
    }
    
    if(Min_DiffTillNow ==INT_MAX)
    {
        Min_DiffTillNow=-1;
    }
    
    dp[cur_pos][day] =Min_DiffTillNow;
    
    return  Min_DiffTillNow;
    
    
    
    
}



class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        
        int len = jobDifficulty.size();
        vector<vector<int>> dp(len+1,vector<int>(d+1,-1) );
        
        int res = getMinTimeDP(jobDifficulty,d ,0, dp);
        
        return res;
        
        /* Recurssion approach
            int start =0;
               int end = jobDifficulty.size()-1;
               int res = getMinTimeRecursion(jobDifficulty,d , start ,end);
         
         */
        
       // return res;
        
      
    }
};



int main(int argc, const char * argv[]) {
    // insert code here...
    
    // Get starting timepoint
   auto start = high_resolution_clock::now();
     
    Solution obj;
    vector <int > vec ={380,302,102,681,863,676,243,671,651,612,162,561,394,856,601,30,6,257,921,405,716,126,158,476,889,699,668,930,139,164,641,801,480,756,797,915,275,709,161,358,461,938,914,557,121,964,315};
    int days=10;
    
    int res = obj.minDifficulty(vec, days);
    
    std::cout <<"Res=" <<res << endl;
    
    
    // Get ending timepoint
       auto stop = high_resolution_clock::now();
     
       // Get duration. Substart timepoints to
       // get durarion. To cast it to proper unit
       // use duration cast method
       auto duration = duration_cast<seconds>(stop - start);
     
       cout << "Time taken by function: "
            << duration.count() << " microseconds" << endl;

    
    return 0;
}


int getMaxElem(vector<int>& vec, int start ,int end)
{
    
    int maxElem = vec[start];
    for(int i=start; i<= end;i++)
    {
        maxElem = max(maxElem , vec[i]);
        
        
    }
    
    return maxElem;
    
    
}

// ------ Recursion Apporach-------------------------------//
int getMinTimeRecursion(vector<int>& vec, int d ,int start, int end )
{
    int total_Elem_Left = end-start +1;
    if( d < 1 || d > total_Elem_Left){
        return  -1 ;
    }
    
    if(d==1)
    {
        int MaxElem =  getMaxElem(vec,start,end);
        return MaxElem;
    }
    int cur_day_max = 0;
    
    int Min_DiffTillNow=INT_MAX;
    
    for(int i=start; i< end ;i++){
      
       cur_day_max = max(vec[i] , cur_day_max);
        
        
       int res = getMinTimeRecursion(vec,d-1,i+1,end);
        
        if(res == -1)
        {
            continue;
        }
        
       Min_DiffTillNow = min (Min_DiffTillNow , cur_day_max + res);
    
    }
    
    return  Min_DiffTillNow;
     
   
    
   
}



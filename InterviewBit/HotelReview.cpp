/*Logic:Since we need to check user reivew words with valid reviews.So we can put valid reviews in hashmap/unordered_map so that search is o(1).Now
        we have to check each user reivew are valid review and increment the count..We have to store this reviews into some storage.Since heights review comes first and then others
        and their position needs to be printed.There can be users with same review count so we cant use map directly. The key will be review count of user and vector of users pos which
        has this count. The map will be in reverse order so that greatest review count user will be first printed.  
*/ 


//
//  main.cpp
//  HotelReview
//
//  Created by MLS Mac 1 on 08/07/20.
//  Copyright © 2020 MLS Mac 1. All rights reserved.
//

#include <iostream>
#include <set>
#include <map>
#include <vector>

using namespace std;

typedef set<string>  reviewStrSetType;

typedef map<int, vector<int>,greater <int>  > ReviewCountMapType;

bool checkIfValidReview(reviewStrSetType & reviewStrMap , string InputReview )
{
    
    reviewStrSetType::iterator itr = reviewStrMap.find(InputReview);
    
    if(itr!=reviewStrMap.end())
    return true;
    
    else
    return false;
}


void FillActualReviewStr(string str , reviewStrSetType &reviewStrMap)
{
    
    
    
    int len = str.size();
    
    int pos = 0;
    //Fill the map of review words
    while( pos<len)
    {
        string reviewWords;
        
        
        // Find first occurrence of "_"
        size_t found = str.find('_',pos);
        if (found != string::npos)
        {
           reviewWords =  str.substr(pos,found-pos);
           reviewStrMap.insert(reviewWords);
            
        }
        
        else
         {
             reviewWords =  str.substr(pos,len-1);
             reviewStrMap.insert(reviewWords);
             break;
             
         }
        
        pos = found +1;
        
        
    }
    
    
}


ReviewCountMapType getReviewCount(string str, vector<string> &VecStr)
{
    
    reviewStrSetType   reviewStrMap;
    
    FillActualReviewStr(str,reviewStrMap );
    
    ReviewCountMapType resMap;
    
    int len = VecStr.size();
    
    for(int i=0; i<len ;i++)
    {
        //Check indidivual Reviews and fill the map
        int vecstrlen = VecStr[i].size();
        
        
        
        int count=0;
        int pos =0;
        //Fill the map of review words
      while( pos<vecstrlen)
       {
         string reviewWords;
        
        
        // Find first occurrence of "_"
        size_t found = VecStr[i].find('_',pos);
        if (found != string::npos)
        {
           reviewWords =  VecStr[i].substr(pos,found-pos);
           bool res = checkIfValidReview(reviewStrMap ,reviewWords );
           
           if(res)
           count++;
            
        }
        
        else
         {
             reviewWords =  VecStr[i].substr(pos,len-pos);
             bool res = checkIfValidReview(reviewStrMap ,reviewWords );
           
           if(res)
           count++;
            
             
             break;
             
         }//end of else
        
        pos = found +1;
        
        
        
     }//end of while checkin
        
        
      resMap[count].push_back(i);
        
        
    }//end of for loop
    
    
    
    return  resMap;
    
    
    
}




/*vector<int> Solution::solve(string A, vector<string> &B) {
    
    vector<int> res_vec;
    ReviewCountMapType resMap =  getReviewCount(A, B);
    
    for( auto & eachElem: resMap)
    {
        
        for(int elem: eachElem.second)
        {
            res_vec.push_back(elem);
        }
        
    }
    return res_vec;
    
    
    
}*/

int main()
{
    string A =  "cool_ice_wifi";
    vector<string> B  = { "water_is_cool", "cold_ice_drink", "cool_wifi_speed" };
    
    
    vector<int> res_vec;
       ReviewCountMapType resMap =  getReviewCount(A, B);
       
       for( auto & eachElem: resMap)
       {
           
           for(int elem: eachElem.second)
           {
               res_vec.push_back(elem);
           }
           
       }
   
    std::cout <<"\n lets check res_vec";
    
}

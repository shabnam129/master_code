//
//  main.cpp
//  Longest_Subarray_with_Ones_after_Replacement
//
//  Created by MLS Mac 1 on 23/05/20.
//  Copyright © 2020 MLS Mac 1. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <vector>

/* QUe Link:https://leetcode.com/problems/max-consecutive-ones-iii/
 
 LOGIC::This question is similar to Longest Repeating Character Replacement..you can check its logic in that prog..Just check number of 1s in current windows and take diff with total time if diff is greater than k it means that this window is overflowing by 1 size.so need to remove left element.

*/

using namespace std;

int maxoneAfterReplacementZero(vector<int> & vec, int k)
{
    int countStore[2] = {0};
    

    int l=0;//window start
    
    int r=0; // window end R and I are same..R is used for reporesetnation of window
    
    int len = vec.size();
    
    int onesCurrCount=0;
    
    int ret_val = 0;
    int total_elem = 0;
    
    int diff = 0;
    
    while( r< len){
        
        //Increment the count for that value in out store
        ++countStore[vec[r]];
        
        //get the number of 1s in current window
        onesCurrCount = countStore[1];
        
        //get total number of element
        int total_elem= r - l +1 ;
        
        //get total number of 0 in current window
        diff = total_elem - onesCurrCount;
        
        if( diff > k )
        {
            ret_val = max(ret_val , r-l );
            --countStore[vec[l]];
            
            l++;
        }
        
        r++;
        
        
    }
    
    if(diff <=k )
    ret_val = max(ret_val , r-l );
    
    return ret_val;
    
    
}





int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> vec = {0,0,0,0,0,0,0,0,0,1,1,0};

    int k=1;

    int ret_val = maxoneAfterReplacementZero(vec,k);
    std::cout << "result=" << ret_val <<std::endl;
    return 0;
}

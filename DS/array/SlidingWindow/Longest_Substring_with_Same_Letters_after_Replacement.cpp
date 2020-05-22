//
//  main.cpp
//  Longest_Substring_with_Same_Letters_after_Replacement
//
//  Created by MLS Mac 1 on 20/05/20.
//  Copyright © 2020 MLS Mac 1. All rights reserved.
//

#include <iostream>
#include <unordered_map>

/* QUe Link:https://leetcode.com/problems/longest-repeating-character-replacement/
 
 LOGIC::Start creating window. and while traversing check the character which has occured most and its count...now check the differnece between total element and that max_count...It means we have the difference the amnt of operation we need to do it make same as max_count wala elemnt..If diff > k then this winodow is not valid move element from left..if the left elemnt was the character which has the most elemnt then dec most elemment too.
 
 
*/

using namespace std;

int maxAllCharAfterReplacement(string s, int k)
{
    int char_count[26] = {0};
    
    int i=0;
    int win_St=0;//window start
    
    int win_End=0; // window end R and I are same..R is used for reporesetnation of window
    
    int len = s.size();
    
    int max_charCount=0;
    
    int ret_val = 0;
    int total_elem = 0;
    
    char max_elem=' ';
    int diff = 0;
    
    for(int i=0; i< len;i++ ){
        
        char cur_elem = s[i];
        
        //First put the count of elment in map..or array
        char_count[cur_elem- 'A']++;
        
        //Get count of curr elem..
        int cur_elemCount = char_count[cur_elem- 'A'];
        
        //Check if this current count is greater the maxcharcount which have in window
        //if yes then update max_charCount and element name also..it is used later on
        if( max_charCount  <= cur_elemCount)
        {
            max_charCount  = cur_elemCount;
            max_elem =  cur_elem;
            
        }
        
        //get total element in the window
        total_elem = win_End- win_St + 1;
        
        diff = total_elem -max_charCount;
        
        if ( diff > k) {
            //window not valid
            ret_val = max(ret_val , win_End-win_St);
            
            //New window left element
            char left_elem = s[win_St];
            char_count[ left_elem - 'A']--;
            win_St++;
            
            //Left element was the same character which has max count so decrease its max count value;
            if( left_elem ==max_elem )
                max_charCount--;
            
        }//end of checking window is valid
        
        win_End++;
        
    }//End of for loop
    
    if(diff <=k )
    ret_val = max(ret_val , win_End-win_St );
    
    return ret_val;
    
    
}



class Solution {
public:
    int characterReplacement(string s, int k) {
        
        
        
        int res = maxAllCharAfterReplacement(s,k);
        return res;
        
    }
};



int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::string str = "ABAA" ;//"AABABBA";//"ABAB";// ;"AABABBA";//"aabccbb";
    int k=0;
    int ret_val = maxAllCharAfterReplacement(str,k);
    std::cout << "resulf=" << ret_val <<std::endl;
    
  
    return 0;
}

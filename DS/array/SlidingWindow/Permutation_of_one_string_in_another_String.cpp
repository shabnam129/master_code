//
//  main.cpp
//  Permutation_in_String
//
//  Created by MLS Mac 1 on 23/05/20.
//  Copyright © 2020 MLS Mac 1. All rights reserved.
//


/*Logic::In this question we need to check if any permuation of s1 is present in s2.. s1== ecd and s2 ... abcde..so yes
 So we need to first store count/frequency of each character of s1 in hashmap/char array (s1Count)...
 
 also we need to store character count of elements of s2(s2Count) if they are part of s1.
 
 then need to traverse s2..create a window with l and r..Check two below cases for current element to shrink/play with window
 1)while traversing check if the current element is not part of s1. then the window need to be shrik or remove..One of the step is to reset s2 count but that again  o (m) if size is which create complexity.. so instead of that start shrinking the window and decremnt the count of char in that particular window in s2 count..so that they wont add into next windows.
 
 2)If the cur elemnt of s2 is part of s1 but its count is greater then...this element is causing the problem so start removing element from left untill this elemnt count becomes equal to s1...
 
 If the length of window is equal to size of s1..then check last charcter count is same or not..if same then yes this is valid subset..else
 remove element from left
 
 */
#include <iostream>

using namespace std;


bool checkInclusionPerm(string s1, string s2)
{
    //char array containing s1 count
    int s1Count[26]={0};
    //char array containing s2 count
    int s2Count[26]={0};
    
    int len1 = s1.size();
    int len2 = s2.size();
    
    //Intlaize s1Count which contains frequency of s1 characters
    for(int i = 0; i < len1;i++ )
        ++s1Count[s1[i]-'a'];
    
    int l=0;
    int r=0;
    
    int count1=0;
    int count2=0;
    
    bool isPerm =false;
    
    
    while(r<len2)
    {
        char curr_elem = s2[r];

        
        count1 = s1Count[curr_elem-'a'];
        
        
        if( count1==0  ){
           //std::cout <<"This elemment is not present in s1 so lets shrink window=" <<curr_elem <<std::endl;
           while(l<=r){
               //remove the frequenecy of element from this window ...so that it should not carry forward.
               //ex in aabbqaba...when we hit q then all preiovus count should be remove
               //char left_elem = s2[l];
               if( s2Count[s2[l]-'a'] != 0)
                  --s2Count[s2[l]-'a'];
                ++l;
           }
          ++r;
          continue;
        }
        
        
        count2 = ++s2Count[curr_elem-'a'];
        
        if(count2 > count1)
        {
            //this element is causing the problem so start removing element from left untill this elemnt count becomes equal to s1
            while(count2 > count1)
            {
                
                if( s2Count[s2[l]-'a'] != 0)
                --s2Count[s2[l]-'a'];
                ++l;
                count2 = s2Count[curr_elem - 'a'];
            }
            ++r;
            continue;
            
        }
        
       
        
        int total_elem = r-l+1;
        
        if(total_elem==len1 )
        {
            //check last character count
            if(count1==count2)
                isPerm=true;
            
            //remove elemnet from left and move window forward with new left and right
            //if elemment is already zero then dont decrement
            if( s2Count[s2[l]-'a'] != 0)
            --s2Count[s2[l]-'a'];
            
            l++;
        }
        
        r++;
        
        
    }
    
    return isPerm;
    
    
}


class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
      bool result =   checkInclusionPerm(s1,s2);
        
      return result;
        
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    
    string  s1 = "adc";
    string  s2 = "dcda";
    bool result = checkInclusionPerm(s1,s2);
    
    
    
    std::cout <<"result= " << (result ? "TRUE" : "FALSE" ) <<std::endl;
    
    //Diff input list
    //"baa";//"hello";//"bcdxabcdy"; //"ab" ;//"baa";;///"abc";//"dc";//
    ;//;"eressasbfafbabbaba";//;"ooolleoooleh" ;//"bcdyabcdx" ;// "eidboaoo";//"eressasbfafbabbaba";//"eidbaooo";;//"aaacb";//"odicf";//;//
    
    return 0;
}

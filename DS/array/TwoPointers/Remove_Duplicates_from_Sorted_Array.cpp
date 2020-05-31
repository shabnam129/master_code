/*Logic: We can use two pointers...When we found any elem is duplicate then move till u dont find non dupilcate to this elem.Now u need to put this non duplicate element at the next index of this elem.

we can have pointer NonDupPos which non duplicate and in any case a duplicate comes correposding NonDupPos then just move the index ...wheneve non dupldate comes then just put the non duplicate at NonDupPos+1...n just increment NonDupPos to one more..

Link:https://leetcode.com/problems/remove-duplicates-from-sorted-array/
*/ 

int fun(vector<int>& vec)
{
    int i=0;
    int len =vec.size();
    if(len==0 || len==1)
        return len;
        
    
    int NonDupPos=0;//it the position 
    
    for(i=1;i<len ;++i)
    {
      //If cur element is different then NonDupPos then just put cur elem  NonDupPos +1 position and increment NonDupPos by 1. 
      if(vec[NonDupPos] != vec[i])
        {
            
           // std::cout << "p= " << p;
            vec[NonDupPos+1] = vec[i];
            ++NonDupPos;
            
        }
    }
    
    
    vec.erase(vec.begin()+NonDupPos+1,vec.end() );
    return vec.size();
    
    
}    

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        
        
        return fun(nums);
        
    }
};

/*Logic: Kadane algorithim.

Check if adding prev_sum to cur elem is smaller than the cur_elem..than adding prev_sum is of no use , then cur_elem will be start of window

Link:https://leetcode.com/problems/maximum-subarray/
https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
Time Complexity: 0(n)
Space Complexity: 0
*/

class Solution {
public:
    int maxSubArray(vector<int>& vec) {
        
     
    int prev_sum = vec[0];
    int len = vec.size();
        
    int max_sum =   prev_sum;
        
    for(int i=1;i<len;i++)
    {
        
        
        int cur_sum = vec[i] + prev_sum;
        
        //Check if cur_sum is smaller than cur_elem then cur_elem will become new ssum in mvoing forward
        //else if no use of adding prev_sum as it will decasrse sum
        if( vec[i] > cur_sum )
        {
            prev_sum = vec[i] ;
            
        }
        
        else
            prev_sum = cur_sum;
        
        
        
        max_sum = max(max_sum,prev_sum);
        
        
        
            
    }
        
    return  max_sum;
        
        
        
        
    }
};

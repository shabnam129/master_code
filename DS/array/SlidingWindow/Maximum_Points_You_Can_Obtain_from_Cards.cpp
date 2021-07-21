/*Logic:
Approach 1 :  recurssion with memortication which will give TLE. 2powern complexity
Just for  every boundry check if start should be pick or end to be pick and also decrement the k value.
TimeComplexity:TLE

Approach 2: Sliding windw:(O(n)):
Select first few elemen from left and some from right corner



Watch video 1:https://www.youtube.com/watch?v=1DkVU2i3sOA

Watch Video 2: https://www.youtube.com/watch?v=x6BQ5XXUxbU ( FOR both appraoch)
Link:https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/submissions/

*/


#include <iostream>
#include <vector>

using namespace std;




int funWindow(vector<int>& vec , int k){
    
    int len = vec.size();
    int l=0;
    int r=0;
    //get Ksum from rightMost
    int count = k;
    int res =0;
    
    int right_Ksum = 0;
    
    for( r= len-1; count > 0; r--,count--)
    {
        right_Ksum = right_Ksum + vec[r];
    }
    
    int start_sum = 0 ;
    r++;
    int end_sum = right_Ksum ;
    
    
    for(int i=0; i < k+1 ;i++)
    {
        
        res = max(res , start_sum + end_sum);
        start_sum = start_sum +vec[i];
        if(r>=len)
            break;
        end_sum = end_sum - vec[r++];
        
    }
    
    return res;
    
    
    
}




int funRecursion(vector<int>& vec , int k ,int start,int end)
{
    
  // std::cout <<"\n k=" << k << " start=" << start << " end=" << end;
   if(k==1 )
       return max(vec[start], vec[end] );
    
   //Choose start element
   int startPick = vec[start] +  funRecursion(vec,k-1,start+1,end);
    
   //Choose end element
   int endPick = vec[end]  +  funRecursion(vec,k-1,start,end-1);
    
    
    
   return max(startPick, endPick);
   

}


class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int len =cardPoints.size();
        auto res =  funWindow(cardPoints,k);
        
        
        return res;
        
    }
};

/*        Best Time to Buy and Sell Stock II
Logic:While traverssin the array .Select minimum/small elem and check  if cur_elem is greater than small than it can be candiate and store it cur_greater. Move like this untill u get an element which smaller cur_greater elem.. Once u reach there u can get diff and add to profit and  update cur_small and greater to this eleme.Now again

Time Complexity: O(n)
Space : o(1)

leetcode:https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
*/

int getOwnProfit(vector<int>& vec)
{
    
    int cur_small = cur_greater = vec[0];
    int cur_greater = vec[0];
    int len = vec.size();
    
    int profit = 0;
    

    for(int i=0; i <len ;i++)
    {
        int cur_elem = vec[i];
        if( cur_elem > cur_small &&  cur_elem> cur_greater)
        {
            cur_greater = cur_elem;
        }
        
        if( cur_elem  < cur_greater )
        {
            profit  = profit + cur_greater - cur_small;
            cur_small  = cur_elem;
            cur_greater = cur_elem;
            
        }
    }
    
   // if(profit==0)
        profit  = profit + cur_greater - cur_small;
    
    return profit;
    
}

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = getOwnProfit(prices);
        return res;
    }
};

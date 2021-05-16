//
//  main.cpp
//  Power
//
//  Created by MLS Mac 1 on 16/05/21.
//  Copyright © 2021 Shabnam. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

/*Logic: for every n divide into two part.. if its even then first half pow(n/2) * other half pow(n/2)..if n is odd then n/2 and other will half will be n/2+1.
for Dp u can vector else even its not nesscary/.. Check geeks for geeks.
Link:https://leetcode.com/problems/powx-n/submissions/
geeks for geeks:https://www.geeksforgeeks.org/write-a-c-program-to-calculate-powxn/
 
*/


double getPower(double x, int n  , vector<int> & dp ,int orig)
{
   // std::cout <<"\n n=" <<n;
    
    if(n==0)
       return 1;
    if(n==1)
        return x;
    
    double left =0;
    double right =0;
    double res=0;
    
   
    if(dp[n]!=0 && n!= orig)
        return dp[n];
    
    if(n%2==0)
    {
        left = getPower(x,n/2,dp,orig);
        right= getPower(x,n/2,dp,orig) ;
        res =  left * right;
        //std::cout <<"\n n=" << n << " left" << left << "right" << right << " res=" << res ;
    }
    else
    {
        left = getPower(x,n/2,dp,orig);
        right= getPower(x,n/2 +1,dp,orig) ;
        res =  left * right;
        //std::cout <<"\n n=" << n << " left" << left << "right" << right << " res=" << res ;
    }
    
    if ( n!= orig)
         dp[n] =res;
    
    return res;
    
    
}


class Solution {
public:
    double myPow(double x, int n) {
        
        int pow = abs(n);

        vector<int> dp(pow,0);
         
        double res = getPower(x,pow,dp,x);
        
        
        if(n< 0)
            return 1/res;
        
        return res;
        
    }
};

int main(int argc, const char * argv[]) {
    
    double x= 0.00001;
    
    int n = 2147483647;
    
    Solution obj;
          
    double res = obj.myPow(x,n);

    
    std::cout <<"\n res=" <<res;
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

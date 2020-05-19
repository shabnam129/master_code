/*Que Link: https://leetcode.com/problems/fruit-into-baskets/

Logic:In this question we have to stop when diff element/fruit is encountered after basket is full with 2 diff type of fruit.. so b1 will f1 and b2 will have f2..in case while traverssing array we get f3..Then that will basket count...So we need to max the basket count..so create a window with l and r as soon new f3 commes...Remove the element at index l from basket or window as it cant contibute any more to diff basket.Now the new l will be first position will the elgible pos of  current right index elemnt.
*/


int getMaxWindfruit(vector<int>& vec){
    if(vec.size()==0)
           return 0;
       if(vec.size()==1)
           return 1;
    
    int len =vec.size();
    int l=0;
    int r=0;
    
    int e1=-1;
    int e2=-1;
    int NextLindx=-1;
    
    int ret_max =INT_MIN;
    
    for(int i=0;i<len;i++){
       
        int elem = vec[i];
        int pos=i;
        //If first bucket is free
        if(e1==-1   )
        {
            e1 = elem;
            l=pos;
            NextLindx= pos;
            continue;
        }
        //If Second bucket is free
        if(e2==-1 && elem!=e1)
        {
            e2 = elem;
            r=pos;
            NextLindx = pos;
            continue;
        }
        //If current element already present in bucket and check if its diff then the previous elemnt then
       // this pos can become the elgible candidate for nextleft index
        if(elem ==e1 || elem ==e2 )
        {
            if(vec[i-1]!=elem)
                NextLindx = pos;
            
            r=pos;
            
        }
        //If element is different then bucket elem
        else{
            //Now new elemnt comes so check for current window length.
            ret_max = max(ret_max,r-l+1);
            //create new window where new elemnt becomes e2 and NextLindx becomes the starting of window
            
            l = NextLindx;
            e1 = vec[i-1];
            e2=elem;
            r=pos;
            NextLindx=pos;

        }//end of checking element in bucket
                
        }//end of for loop
            
    ret_max = max(ret_max,r-l+1);
        
    return ret_max;
    
}
    
    

class Solution {
public:
    int totalFruit(vector<int>& tree) {
        
        
        int ret_val = getMaxWindfruit(tree);
        
        return ret_val;
            
        
    }
};

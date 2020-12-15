/*Logic:At any pos the person max jmp it can take will be its value or lastjmpInd called ...So traverser whole postion till lastjmpInd and while trvesing check if any other value(next_maxJmp) can help him   like from in case 9......4,1..Here lastjmpInd is 1 but 4 is good opption for next time.from there can be jmp of three...So in next jump we can use it...Its like new ladder provided to u .

LeetCode :https://leetcode.com/problems/jump-game-ii/submissions/
You tube Linkhttps://www.youtube.com/watch?v=vBdo7wtwlXs.
 */

#include <iostream>
#include <unordered_map>
#include <vector>


using namespace std;
typedef unordered_map<int ,int> map_type;


#include <iostream>
#include <unordered_map>
#include <vector>


using namespace std;
typedef unordered_map<int ,int> map_type;




int getMinJump(vector<int>& vec)
{
    
   int len = vec.size();
    
   
   int last_pos=0;
    
   int res_jmp=1;
    
   int next_maxJmp = 0;
    
   //Max jmp index for this position
   int MaxJmpInd =   vec[0] + 0;
  
   for(int i=1;i <len;i++)
   {
     
     //In case our moving pointer i reaches to max jmp allowed .. Then we need to update our new Max Jmpind and increment jmp count
     if(i >= MaxJmpInd)
     {
         //Check if max limit is already overpower the len then we dont need any jmp
         if(MaxJmpInd >= len-1)
            break;
         
          res_jmp++;
         
          //Update our upperlimit of jmp which is which is either the current MaxJmpInd varibale or which is i or Nextjmp valriable which we have stored while traversing.
          MaxJmpInd = max(vec[i], next_maxJmp) + i;
         
          next_maxJmp = 0;
         
     }
    //Traverse till maxjmp Index ..Check any jmp/ladder which can help while we about to reach  max
    else
    {
        int cur_jmpallowed= vec[i] ;
       
        //Get current jmp valuue...Subract current pos from max and check diff bw cur_jmp and the diff..
        //This will give the next avibale jmp.
        //It can be there are multiple candidates...The ladder with more steps will be usefull
        //Like 9...100.4.1/ In this and 4 and 100 are eligable but 100 provides more jmp
        int newjmpAvilable =    cur_jmpallowed -(MaxJmpInd-i);
        next_maxJmp =  max (next_maxJmp, newjmpAvilable);
    }
      
    
      
     
       
   }//end of for lop
       
     
    return res_jmp;
       
   
    
    
    
}


class Solution {
public:
    int jump(vector<int>& vec) {
        
        if(vec.size()==1)
            return 0;
        
        int resMinJmp = getMinJump(vec);
        return  resMinJmp;
        
    }
};







int main(int argc, const char * argv[]) {
    
    vector<int> vec = {2,3,5,9,0,9,7,2,7,9,1,7,4,6,2,1,0,0,1,4,9,0,6,3 };//{2,9,6,5,7,0,7,2,7,9,3,2,2,5,7,8,1,6,6,6,3,5,2,2,6,3};
    
    //{3,4,3,2,5,4,3};//{2,1,1,1,1};//{2,3,1,1,4};//;{5,9,3,2,1,0,2,3,3,1,0,0};
    Solution obj;
    int res  =  obj.jump(vec);
    
    std::cout <<"\n res=" <<res;
    
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}



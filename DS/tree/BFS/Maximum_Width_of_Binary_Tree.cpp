/*Logic:For every node..keep store a level position value.. Its left child value will be 2*p while for right child it will 2*p+1 where p is for parent.. During BFS check for the front and back of queue has which level pos value their difference will give the depth

Link:https://leetcode.com/problems/maximum-width-of-binary-tree/
Time Complexty: o(n)
Space Completxity: o(w)
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


int MaxWidth(TreeNode* root)
{

    typedef pair<TreeNode*,unsigned int> pair_type;
    unsigned int resMax=0;
    if(root==NULL)
    return resMax;
    
    
    
    std::deque<pair_type > deq;
    
    deq.push_front({root,1});

    
    //BFS using queue
    while( !deq.empty()){
        
      
        int deq_size=  deq.size();
        
       // auto front_data = deq.front();
        
        //auto back_data = deq.back();
        
        resMax = max(resMax, (deq.back().second - deq.front().second) +1 );
        
      
        
        while( deq_size-- ){
            
            auto front_data =   deq.front();
            auto node = front_data.first;
            
            
            unsigned int level_pos = front_data.second;
            
            //std::cout <<"\n node val=" <<node->val << " level_pos=" <<level_pos;
            
            unsigned int left_pos = level_pos*2;
            unsigned int right_pos = ( level_pos *2) +1;
            
            if(node->left)
            deq.push_back( {node->left,left_pos});
            
            if(node->right)
             deq.push_back( {node->right, right_pos });
        
            
           
            deq.pop_front();
           // deq_size--;
        }//end of inner while
        
        
    
    }//end of outerwhile
    

    
    return resMax;
    
}
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        
        int ret = MaxWidth(root);
        return ret;
        
    }
};

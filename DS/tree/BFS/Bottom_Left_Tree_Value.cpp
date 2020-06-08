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


/*Logic::It can be solved like level order traversal(BFS)..Capture every front element of queue and the last level of queue front will be the bottom left answer.  

Link:https://leetcode.com/problems/find-bottom-left-tree-value/
*/


template < typename T1,  typename T2> 
T2 getLevelOrderBottom (T1  root)
{
 
    
    T2  res_val;
    if(root==NULL)
    return res_val;
    
    std::deque<T1 > deq;
    
    deq.push_back(root);
   
    
    while( !deq.empty()){
        
        int deq_size=  deq.size();
        
        //This element can be candidate for the left most from bottom
        res_val = deq.front()->val;
        
        
        while( deq_size ){
            
            T1 node =   deq.front();
            
            if(node->left)
                deq.push_back(node->left);
            if(node->right)
                deq.push_back(node->right);
            
            deq.pop_front(); 
            deq_size--;
        }//end of inner while
        
        
    
    }//end of outerwhile
    

    
    return res_val;
    
    

 
}

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        
     return    getLevelOrderBottom<TreeNode* , int> (root);
        
    }
};

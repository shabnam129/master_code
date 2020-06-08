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

/*Logic::It can be solved like level order traversal(BFS)..Print the last element of queue and u will
get the right view of tree...   

Link:https://leetcode.com/problems/binary-tree-right-side-view/
*/


template < typename T1,  typename T2> 
T2 getLevelOrderBottom (T1  root)
{
 
    
    T2  res_vec;
    if(root==NULL)
    return res_vec;
    
    std::deque<T1 > deq;
    
    deq.push_back(root);
   
    
    //BFS using queue
    while( !deq.empty()){
        
        int deq_size=  deq.size();
       
        //put Last element in resultant vector 
        res_vec.push_back(deq.back()->val);
        
        
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
    

    
    return res_vec;
    
    

 
}


class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        
        return getLevelOrderBottom<TreeNode*, vector<int> > (root);
        
    }
};

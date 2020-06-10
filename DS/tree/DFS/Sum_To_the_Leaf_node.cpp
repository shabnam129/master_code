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

/*Logic:: Delete cur node from the sum above .....If the cur node is the leaf node and also  the left sum becomes zero it means u have reached to the right path..Now return true from it... Check for both left and right nodes...If anyone return
true it means there was the path

LINK:https://leetcode.com/problems/path-sum/

*/
bool  res_sum ( TreeNode* root,int sum_left  )
{
    if(root==NULL)
        return false;
    
   
    //Get the sum left for processing 
    sum_left = sum_left - root->val;
    
    //If sum is zero and its also leaf node
    if(sum_left==0 && root->left ==nullptr && root->right ==nullptr)
        return true;
    
     
     bool left_status= false;
     bool right_status= false;
    
     
    
    //check for left subtree
     if(root->left)
        left_status =  res_sum(root->left,sum_left);
     
    //check for right subtree 
    if(root->right)
       right_status =   res_sum(root->right,sum_left);
    
    //Status from any of the tree pass to the parent..or is needed so true || false becomes ..true
    return (left_status||right_status);
    
    
    
}
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        
        if(root==NULL)
        return false;
     
        return res_sum(root, sum);
        
    }
};

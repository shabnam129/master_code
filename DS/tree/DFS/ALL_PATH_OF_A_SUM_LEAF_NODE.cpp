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
/*Logic: Delete cur node data from the sum above. If the cur node is the leaf node and also  the left sum becomes zero it means u have reached to the right path.While Ur traverssing put each node data into vector so that later on when u reach the path u can push that vector into result. 

Also the delete the cur_eleme data from vec too so that it doesnt reach to the parent and parents have fresh vec which he inherits from parent.



LINK:https://leetcode.com/problems/path-sum-ii/

*/

*/
void  res_sum ( TreeNode* root,int cur_sum ,vector<int> &vec  ,vector<vector<int>> &res_vec)
{
    if(!root)
        return ;
    
   
    cur_sum = cur_sum - root->val;
    
    vec.push_back(root->val);
    
    if(!root->left  && ! root->right && cur_sum==0 )
    {
        res_vec.push_back(vec);
        vec.pop_back();
        return;
        
    }
    
     
     res_sum(root->left,cur_sum,vec,res_vec);

     res_sum(root->right,cur_sum,vec,res_vec);
         
    
     vec.pop_back();
    
     return ;
   
}

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        
        vector<int> vec;
        vector<vector<int>> res_vec;
        res_sum(root,sum,vec,res_vec);
        return res_vec;
        
    }
};

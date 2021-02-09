/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*Logic:At every node check if their right tree and left right height summation is greater than result found till now.. Their summatin result is diameter.
Link:https://leetcode.com/problems/diameter-of-binary-tree/submissions/
*/


int get_diameter_byHeight(TreeNode * node , int & result)
{      
    if(node==NULL)
         return 0;
        
   //get left tree height 
   int leftTreeHeight = get_diameter_byHeight(node->left,result) ;
   //get Right tree height  
   int rightTreeHeight = get_diameter_byHeight(node->right,result) ;

    //Max of those height will be sent to parent of currnet node
    int ret = max(leftTreeHeight,rightTreeHeight);
    
    //Every time at every node check if the left and right tree height is greater than res.
    result = max(result, leftTreeHeight+rightTreeHeight);
    
    return ret+1; 
}
    
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* node) {
        
      int res = 0;
      get_diameter_byHeight(node,res);
        
      return res;  
    }
};

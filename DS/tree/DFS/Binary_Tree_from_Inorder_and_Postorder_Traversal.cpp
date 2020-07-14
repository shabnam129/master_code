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

/*Logic..The last element of postorder will be parent as 
post --LRP
Inor-- LRP

So every elemn in post order will have be in Inorder..The Indorder or In_pos will of that elemt..all the elemt in from start to In_pos-1 will be left tree and In_pos+1 till end will right subtree..Just travverser the postorder in this way
Note::U we have created right tree first so that index from post order will have right first and left elem 

LINK:https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
*/

typedef unordered_map<int ,int> InPosMapType;//Map containg the key as Inorder vector values and value as their position 


TreeNode* GetTree(vector<int>& Inorder,vector<int>& post,int start,int end, int& cur_i , InPosMapType& InposMap )
{
    
    if(start> end)
        return NULL;
    
   int cur_elem = post[cur_i]  ;
    
    cur_i--;
    

   //Get index/pos of cur_leme of post order in inorder Map.
   int In_pos = InposMap[cur_elem];
   
    
   TreeNode*  node = new TreeNode(cur_elem);
    
   node->right = GetTree(Inorder, post, In_pos+1 , end,cur_i,InposMap) ;
    
   node->left = GetTree(Inorder, post, start , In_pos-1,cur_i,InposMap) ;
    
    
   return node;
    
    
    
}




class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
     int len = postorder.size();  
        
   InPosMapType my_map;
        
        
  for(int i =0 ; i<len;i++ )
  {
      my_map[inorder[i]] = i;
  }
        
         
    
    int cur_ind= len-1;   
     TreeNode* res =     GetTree(inorder,postorder,0,len-1,cur_ind,my_map);
     return res;   
        
    }
};

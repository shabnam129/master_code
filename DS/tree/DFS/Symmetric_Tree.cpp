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

/*Logic:: Since we have to check mirror image so left tree and right tree should be same...I have taken two pointers p1 and p2..p1 is for left tree and p2 is for right subtree...When assum tree is  1
                                 2.    2
                                3  4. 4  3.
here p1 will point left most 2 and p2 point 2 of rightmost.. Now we need check 
element of left and right subtree at same time.. so do Inorder for p1->left and p2-right they have to be same.. when reach there than again 3 of left become p1 and right most 3 become p2..again their respective left and right child .

Once 3 is done it get backs to 2..p1-2 and p-2...p1 left tree checked with p2 right portion tree.Now leftmost p1 right tree needs to be matched with p2 left tree so that become mirror image.
   
Link:https://leetcode.com/problems/symmetric-tree/   
                                
  */
bool checktreeSymmetric(TreeNode* p1 ,TreeNode* p2)
{
    if( p1==nullptr && p2==nullptr)
       return true;
   
    if( !p1 || !p2  )
        return false;


    if(p1->val != p2->val)
     return false;
       
    bool left_res =  checktreeSymmetric(p1->left, p2->right);    
    
    bool right_res =  checktreeSymmetric(p1->right, p2->left);   
       
   
   return  ( left_res &&  right_res );   
    
    
    
}


class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        
    if(root==nullptr)  
        return true;

    bool res=  checktreeSymmetric(root->left , root->right);
    
    return res;
        
    }
};

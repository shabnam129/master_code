/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*logic: To print the digaonal of tree we need to create some logic which makes all the digonal get in some place.. so there is trick add some extra knowledge to cur_node like int value.. so pass
         this value as its to right child like if parent is d0 then right child will also have d0, while left child will have one value greater than parent like d1.Now store there node value in map
         like parent and right child will be in one key while right child in another kye.
*/ 
 
typedef  vector<int> ValueType;
typedef  map<int ,  ValueType > DigonalMapType;


void FillDiagonalMap(TreeNode * node, int p_DigVal,DigonalMapType &  DigonalMap)
{
    if( node==nullptr)
    return ;
    
    //PLR..Preorder
    
    DigonalMap[p_DigVal].push_back(node->val);
    
    //sent parent diag value to  left and fill map
    FillDiagonalMap(node->left,p_DigVal+1, DigonalMap);
    
     //sent parent diag value to  right and fill map
    
    FillDiagonalMap(node->right,p_DigVal, DigonalMap);
    
    
    
}


vector<int> Solution::solve(TreeNode* A) {
   
   DigonalMapType  DigonalMap;
   vector<int> res_vec;
   
   FillDiagonalMap(A,0,DigonalMap);
   
   
  
   
   for( auto & diagElemVec:DigonalMap )
   {
       
       for(int elem : diagElemVec.second)
       res_vec.push_back(elem);
   }
   
   
   return res_vec;
   
   
    
}


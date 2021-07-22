/*Logic::Simple create  new resList .

Travers through two node pointer to respective input list.. If p1 elemnt is smaller than p2 than add that into link of resList and move  resList vice versa..
Time complexity: o(n)
Space complexity: o(1)
Linkhttps://leetcode.com/problems/merge-two-sorted-lists/submissions/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


ListNode* mergeLists(ListNode* A, ListNode* B){
    
    ListNode* node1=A;
    ListNode* node2=B;
    ListNode* resheadNode=nullptr;
    ListNode* resNode=nullptr;
    
    while(node1 && node2)
    {
        //std::cout <<"\n node1=" <<node1->val << " node2->val=" <<node2->val;
        
        if(node1->val<=node2->val)
        {
            if(!resheadNode){
                resheadNode = node1;
                resNode = node1;
            }
            else
            {
                resNode->next= node1;
                resNode = resNode->next;
            }
            
            node1= node1->next;
            
            
        }
        else
        {
            
            if(!resheadNode){
                resheadNode = node2;
                resNode = node2;
            }
            else
            {
                resNode->next= node2;
                resNode = resNode->next;
                
            }
            
            node2= node2->next;
            
        }//end of else
        
        
    }//end of while
    
    
    if(node1)
    {
        //Just appaend whole string which is left into res string
        if(resheadNode)
        resNode->next= node1;
        else
            resheadNode= node1;
    }
    
    if(node2)
    {
        //Just appaend whole string which is left into res string
        if(resheadNode)
        resNode->next= node2;
        else
            resheadNode= node2;
    }
    
    return   resheadNode;
    
    
    
}





class Solution {
public:
    ListNode* mergeTwoLists(ListNode* A, ListNode* B) {
         ListNode* res= mergeLists(A,B);
         return res;
    }
};

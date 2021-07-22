/*Logic:
1)Since this is linklist so we cant move in reverse directon.. So first divide the list in two parts at middle
called them as firstlist and secondlist.
2)Reverse the first list
3)Now traverse the first and secondlist and check if the they are same.

Time Complexity: O(n)
Link:https://leetcode.com/problems/palindrome-linked-list/

*/

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

ListNode* ReverseList( ListNode* head)
{
        if (head == NULL || head->next == NULL)
            return head;
 
        /* reverse the rest list and put
          the first element at the end */
        ListNode*rest = ReverseList(head->next);
        head->next->next = head;
 
        /* tricky step -- see the diagram */
        head->next = NULL;
 
        /* fix the head pointer */
        return rest;
}


bool isPalindromeTwoList( ListNode* FirstList ,ListNode* SecondList ){
    
    bool isPalindrome=true;
    while(FirstList &&SecondList)
    {
        if(FirstList->val !=SecondList->val){
           isPalindrome=false;
           return isPalindrome;
        }
        FirstList= FirstList->next;
        SecondList= SecondList->next;
        
    }
    
    if(FirstList||SecondList)
    {
        isPalindrome=false;
        return isPalindrome;
        
    }
    
    return isPalindrome;
    
}

/*void PrintList(ListNode* node)
{
    
    while(node){
        std::cout <<" " <<node->val;
        node= node->next;
    }
}*/

int totalEleminList(ListNode* node)
{
    int rescount = 0;
    while(node)
    {
        rescount++;
        node=node->next;
    }
    
    return rescount;
}




bool isPalindromeList(ListNode* head)
{
    
    int count = totalEleminList(head);
    
    ListNode* slowPtr =  head;
    ListNode* fastPtr =  head;
    
    ListNode* prevPtr = head;
    
    ListNode* FirstList = head;
    ListNode* SecondList = head;
    
        
   
    
    while(fastPtr && fastPtr->next!=nullptr )
    {
         prevPtr =  slowPtr;
         slowPtr =  slowPtr ->next;
         fastPtr =  fastPtr->next;
         if(fastPtr)
         fastPtr = fastPtr->next;
        
         //std::cout <<"\n slow-"
        
    }

    FirstList =head;
    
    //std::cout <<"\n prevPtr data=" <<prevPtr->val;
    
    prevPtr->next=nullptr;
    
    if(count%2!=0)
    {
        
        SecondList= slowPtr->next;
    }
    else
    {
        SecondList= slowPtr;
    }
    
    
    
    /*//std::cout << "PrintList Fist=" ;
    PrintList(FirstList);
    //std::cout << "PrintList Second=" ;
    PrintList(SecondList);*/
    
    
   FirstList  = ReverseList(FirstList);
    
   //std::cout <<"\n reverse List=";
   //PrintList(FirstList);
    
   auto res =  isPalindromeTwoList(FirstList,SecondList);
    
    return res;
    
    

    
    
    
    
}

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        
        if(head->next==nullptr || !head)
        {
            return true;
        }
        
        bool res = isPalindromeList(head);
        return res;
        
    }
};

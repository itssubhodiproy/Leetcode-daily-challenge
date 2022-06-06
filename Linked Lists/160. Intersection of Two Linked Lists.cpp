/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode*> s;
        //putting b into the set
        while(headB!=NULL){
            s.insert(headB);headB=headB->next;
        }
        ListNode* ans=NULL;
        while(headA!=NULL){
            if(s.count(headA)){
                ans=headA;break;
            }
            headA=headA->next;
        }
        return ans;
    }
};

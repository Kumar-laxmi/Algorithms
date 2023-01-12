/*
Problem:-
Given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order, and each of their nodes contains a single digit.
Add the two numbers and return the sum as a linked list.The two numbers do not contain any leading zero, except the number 0 itself.

Problem Link :- https://leetcode.com/problems/add-two-numbers/
Time complexity
O(n+m)-> Where, n is length of l1 and m is length of l2. Thus, it is equal to max of n and m

Space complexity
O(n)--> In creating another linked list where answer is stored

Ex:-
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
*/

  struct ListNode {
    int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*dummy = new ListNode();
        //a node pointing to dummy 
        ListNode*temp=dummy;
        int carry=0;

//at last when l1== NULL and l2==NULL and carry!=0 do one more iteration and add carry=1 as a node 
        while(l1 != NULL || l2!= NULL || carry==1){
            int sum=0;
           
           //sum from l1
           if(l1!=NULL){
               sum+=l1->val;
               //move l1 to next node
               l1=l1->next;
           }

           //sum from l2
           if(l2!=NULL){
               sum+=l2->val;
               //move l2 to next node
               l2=l2->next;
           }

          //add sum  alongwith carry 
          sum+=carry;
          carry=sum/10;

          //add sum%10 as a new node 
          ListNode* node= new ListNode(sum%10);
          //make temp point to new node created
          temp->next = node ; 
          //move temp to next position
          temp=temp->next;
        }

        //now our answer is node from duumy->next to last 
        return dummy->next;
    }
};

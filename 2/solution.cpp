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
        int carry = 0;
        int sum = 0;
        ListNode* result = nullptr;
        while (l1 != nullptr && l2 != nullptr){
            sum = l1->val + l2->val + carry;
            carry = sum/10;
            sum %= 10;
            if(result == nullptr) result = new ListNode(sum);
            else{
                ListNode* curr = result;
                while(curr->next != nullptr){
                    curr = curr->next;
                }
                curr->next = new ListNode(sum);
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != nullptr){
            sum = l1->val + carry;
            carry = sum/10;
            sum %= 10;
            if(result == nullptr) result = new ListNode(sum);
            else{
                ListNode* curr = result;
                while(curr->next != nullptr){
                    curr = curr->next;
                }
                curr->next = new ListNode(sum);
            }
            l1 = l1->next;
        }
        while(l2 != nullptr){
            sum = l2->val + carry;
            carry = sum/10;
            sum %= 10;
            if(result == nullptr) result = new ListNode(sum);
            else{
                ListNode* curr = result;
                while(curr->next != nullptr){
                    curr = curr->next;
                }
                curr->next = new ListNode(sum);
            }
            l2 = l2->next;
        }
        while(carry != 0){
            ListNode* curr = result;
            while(curr->next != nullptr){
                curr = curr->next;
            }
            curr->next = new ListNode(carry);
            carry /= 10;
        }
        return result;
    }
};
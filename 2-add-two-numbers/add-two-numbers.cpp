
// struct ListNode {
//      int val;
//      ListNode *next;
//      ListNode() : val(0), next(nullptr) {}
//      ListNode(int x) : val(x), next(nullptr) {}
//      ListNode(int x, ListNode *next) : val(x), next(next) {}
//  };
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int carry=0;
        ListNode* head=nullptr;
        ListNode* tail=nullptr;

        while (temp1 != nullptr || temp2 != nullptr || carry != 0){

            int sum;
            int val1 = (temp1 != nullptr) ? temp1->val : 0;
            int val2 = (temp2 != nullptr) ? temp2->val : 0;
            sum = val1+val2+carry;
            carry = sum/10;
            sum = sum%10;
            ListNode* node = new ListNode(sum);
            if(head==nullptr){
                head = node;
                tail = node;
            }
            else{
                tail->next=node;
                tail = node;
            }
            temp1=(temp1!=nullptr)? temp1->next: nullptr;
            temp2=(temp2!=nullptr)? temp2->next: nullptr;
        }
        
        return head;        
    }
};
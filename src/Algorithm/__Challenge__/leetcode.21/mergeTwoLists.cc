
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(l1 == nullptr) return l2;
    
    else if(l2 == nullptr) return l1;
    
    else if(l1->val < l2->val){
      this->mergeTwoLists(l1->next, l2);
      return l1;
    
    }else{
      this->mergeTwoLists(l1,l2->next);
      return l2;
    }
  }
};
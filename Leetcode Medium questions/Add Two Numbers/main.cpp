class Solution {
    private:
      void insertAttail(ListNode* &head,ListNode* &tail,int digit){
          ListNode *temp = new ListNode(digit);
          if(head == NULL){
              head = temp;
              tail = temp;
              return;
          }
 
         
             tail->next = temp;
             tail = temp;
          
      }
public:
    ListNode* add(ListNode* &l1, ListNode* &l2){
        
        if(l1 == NULL && l2 == NULL){
            return NULL;
        }
        int carry = 0;
        ListNode*anshead = NULL;
        ListNode*anstail = NULL;
      
       while(l1 != NULL && l2 != NULL){
           int sum = l1->val + l2->val + carry;
           int digit  = sum % 10;
           insertAttail(anshead,anstail,digit); 
           carry = sum/10;
           l1 =l1->next;
           l2 = l2->next;
       }
        
          while(l1 != NULL){
         
           int sum = l1->val + carry;
           int digit  = sum % 10;
           insertAttail(anshead,anstail,digit); 
           carry = sum/10;
           l1 =l1->next;
       }
          while(l2 != NULL){
        
           int sum = l2->val + carry;
           int digit  = sum % 10;
           insertAttail(anshead,anstail,digit); 
           carry = sum/10;
           l2 = l2->next;
       }
          while(carry != NULL){
          
           int sum = carry;
           int digit  = sum % 10;
           insertAttail(anshead,anstail,digit); 
           carry = sum/10;
       }
        
        return anshead;
        
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode*ans = add(l1,l2);
        
        return ans;
    }
};
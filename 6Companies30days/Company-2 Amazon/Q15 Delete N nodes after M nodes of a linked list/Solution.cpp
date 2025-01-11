class Solution {
  public:
    Node* linkdelete(Node* head, int n, int m) {
        // code here
        if(m==0 && n==0) return head;
        if(m==0) return NULL;
        
        Node* curr = head;
        Node* prev = NULL;
        while(curr!=NULL){
            int tempm = m, tempn = n;
            while(tempm-- && curr!=NULL){
                prev = curr;
                curr = curr->next;
            }
            while(tempn-- && curr!=NULL){
                curr = curr->next;
                prev->next = curr;
            }
        }
        return head;
    }
};
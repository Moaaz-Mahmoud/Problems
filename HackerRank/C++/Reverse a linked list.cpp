SinglyLinkedListNode* reverse(SinglyLinkedListNode* head) {
    SinglyLinkedListNode *n1, *n2;
    n1 = head;
    n2 = n1->next;
    if(n2 == nullptr) return n1;
    
    while(n2 != nullptr){
        n1->next = n2->next;
        n2->next = head;
        head = n2;
        n2 = n1->next;
    }
    return head;
}

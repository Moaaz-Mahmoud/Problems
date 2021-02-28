bool compare_lists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode *c1 = head1, *c2 = head2;
    for(;
        c1 != nullptr && c2 != nullptr;
        c1 = c1->next, c2 = c2->next){
            if(c1->data != c2->data) return 0;
        }
    return c1 == nullptr && c2 == nullptr;
}

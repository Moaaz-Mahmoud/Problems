int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    set<SinglyLinkedListNode*> S;
    for(auto ctrl = head1; ctrl != nullptr; ctrl = ctrl->next)
        S.insert(ctrl);
    for(auto ctrl = head2; ctrl != nullptr; ctrl = ctrl->next)
        if(S.find(ctrl) != S.end()) return ctrl->data;
    return -999111;
}

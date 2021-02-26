bool has_cycle(SinglyLinkedListNode* head) {
    set<SinglyLinkedListNode*> S;
    for(auto ctrl = head; ctrl != nullptr; ctrl = ctrl->next){
        if(S.find(ctrl) == S.end()) 
            S.insert(ctrl);
        else
            return 1;
    }
    return 0;
}

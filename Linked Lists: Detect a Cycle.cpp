/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/
#include <set>

bool has_cycle(Node* head) {
    set<Node*> S;
    for(Node* ctrl = head; ctrl != nullptr; ctrl = ctrl->next){
        if(S.find(ctrl) == S.end())
            S.insert(ctrl);
        else
            return 1;
    }
    return 0;
}

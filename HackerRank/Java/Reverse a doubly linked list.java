static DoublyLinkedListNode reverse(DoublyLinkedListNode head) {
        DoublyLinkedListNode ctrl = head;
        while(ctrl != null){
            DoublyLinkedListNode temp = ctrl.prev;
            ctrl.prev = ctrl.next;
            ctrl.next = temp;
            if(ctrl.prev == null) return ctrl;
            else                  ctrl = ctrl.prev;
        }
        return new DoublyLinkedListNode(-999);  // Diagnostic
    }

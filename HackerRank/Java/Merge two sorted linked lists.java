static SinglyLinkedListNode mergeLists(SinglyLinkedListNode head1,
                                           SinglyLinkedListNode head2) {
        SinglyLinkedListNode c1 = head1, c2 = head2,
                             res = new SinglyLinkedListNode(000), cres = new SinglyLinkedListNode(000);
        if(c1.data < c2.data){
            res.data = c1.data;
            c1 = c1.next;
        }
        else{
            res.data = c2.data;
            c2 = c2.next;
        }
        cres = res;
        while(c1 != null && c2 != null){
            if(c1.data < c2.data){
                cres.next = new SinglyLinkedListNode(000);
                cres = cres.next;
                cres.data = c1.data; cres.next = null;
                c1 = c1.next;
            }
            else{
                cres.next = new SinglyLinkedListNode(000);
                cres = cres.next;
                cres.data = c2.data; cres.next = null;
                c2 = c2.next;
            }
        }
        while (c1 != null) {
            cres.next = new SinglyLinkedListNode(000);
            cres = cres.next;
            cres.data = c1.data; cres.next = null;
            c1 = c1.next;
        }
        while (c2 != null){
            cres.next = new SinglyLinkedListNode(000);
            cres = cres.next;
            cres.data = c2.data; cres.next = null;
            c2 = c2.next;
        }
        return res;
    }

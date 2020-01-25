// swapPairs  两两交换链表中的节点
function swapPairs(head) {
    if(head == null || head.next == null) return head;
    let first = head, second = head.next;
    first.next = swapPairs(second.next);
    second.next = first
    return second
};





/**
 * @param {ListNode} head
 * @return {ListNode}
 */
function deleteDuplicates(head) {
    if(head == null) return null
    head.next = deleteDuplicates(head.next)
    return (head.next && head.val == head.next.val) ? head.next : head;
};
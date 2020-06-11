/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
function deleteDuplicates(head) {
    if (head == null || head.next == null) return head;
    if (head.val == head.next.val) {
        while (heade.next != null && head.val == head.next.val) {
            head = head.next.next;
        }
        return deleteDuplicates(head.next)
    }
    head.next = deleteDuplicates(head.next);
    return head
};

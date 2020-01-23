
// removeNthFromEnd 删除链表的倒数第N个节点
// expolit: 减治快慢双指针； T(n) = O(n)
function removeNthFromEnd(head, n) {
    let slowPoint = head, fastPoint = head;
    for(let i = 0; i < n; i++){
        if(fastPoint.next == null) return slowPoint.next;
        fastPoint = fastPoint.next;
    }
    while(fastPoint.next != null){
        fastPoint = fastPoint.next;
        slowPoint = slowPoint.next;
    }
    slowPoint.next = slowPoint.next.next;
    return head
};
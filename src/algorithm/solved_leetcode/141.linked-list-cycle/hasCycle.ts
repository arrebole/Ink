interface ListNode {
    val: number
    next: ListNode | null
}

const fastPointerSpeed = 3;

// hasCycle 判断链表是否有环路。[双指针/快慢指针 S(n) = 1]
function hasCycle(head: ListNode | null): boolean {
    if (head == null) return false;
    
    let fastPointer = head, slowPointer = head;
    while (true) {
        for (let i = 0; i < fastPointerSpeed; i++) {
            fastPointer = fastPointer.next!;
            if (fastPointer == null) return false;
            if (fastPointer == slowPointer) return true;
        }
        slowPointer = slowPointer.next!;
    }
};
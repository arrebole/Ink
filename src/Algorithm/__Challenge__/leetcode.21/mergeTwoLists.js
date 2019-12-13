/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var mergeTwoLists = function(l1, l2) {
    let queue = new Array();
    while (l1.next != null && l2.next != null) {
        if(l1.val > l2.val){
            queue.push(l2);
            l2 = le.next;
        }else{
            queue.push(l1);
            l1 = l1.next;
        }
    }

    for(let i = 0; i < queue.length; i++){
        queue[i].next = queue[i+1];
    }
    
    queue[queue.length-1].next = null;
    return queue[0]; 
};
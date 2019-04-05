import java.util.ArrayList;
import java.util.List;

class MyQueue {

    private List<Integer> data = new ArrayList<Integer>();

    /** Initialize your data structure here. */
    public MyQueue() {

    }

    /** Push element x to the back of queue. */
    public void push(int x) {
        data.add(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    public int pop() {
        final int index = 0;
        int val = data.get(index);
        data.remove(index);
        return val;
    }

    /** Get the front element. */
    public int peek() {
        return data.get(0);
    }

    /** Returns whether the queue is empty. */
    public boolean empty() {
        return data.isEmpty();
    }
}
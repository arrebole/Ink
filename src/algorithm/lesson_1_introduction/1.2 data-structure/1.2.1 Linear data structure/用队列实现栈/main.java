import java.util.ArrayList;
import java.util.List;

class MyStack {

    private List<Integer> data = new ArrayList<>();

    /** Initialize your data structure here. */
    public MyStack() {

    }

    /** Push element x onto stack. */
    public void push(int x) {
        data.add(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        int len = data.size();
        int element = data.get(len - 1);
        data.remove(len - 1);
        return element;
    }

    /** Get the top element. */
    public int top() {
        return data.get(data.size() - 1);
    }

    /** Returns whether the stack is empty. */
    public boolean empty() {
        return data.isEmpty();
    }
}
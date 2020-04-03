import java.util.*;

class MyStack {

    /** Initialize your data structure here. */
    private Queue<Integer> q = new LinkedList<>();
    public MyStack() {
        
    }
    
    /** Push element x onto stack. */
    public void push(int x) {
        q.add(x);
        int s = q.size();
        while (s > 1) {
            q.add(q.poll());
            --s;
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        return q.poll();
    }
    
    /** Get the top element. */
    public int top() {
        return q.peek();
    }
    
    /** Returns whether the stack is empty. */
    public boolean empty() {
        return q.isEmpty();
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * boolean param_4 = obj.empty();
 */

public class _225_Implement_Stack_using_Queues {
    public static void main(String[] args) {
        MyStack obj = new MyStack();
        obj.push(1);
        obj.push(2);
        obj.push(3);
        System.out.println(obj.top());
        System.out.println(obj.pop());
        System.out.println(obj.pop());
        obj.push(4);
        System.out.println(obj.pop());
        System.out.println(obj.pop());
    }
}

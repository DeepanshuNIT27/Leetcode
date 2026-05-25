class MyStack {
    queue<int>q1;
public:
// Implementing stack using 1 queue;
    MyStack() {
        
    }
    
    void push(int x) {
        int n = q1.size();
        q1.push(x);
       for(int i=0;i<n;i++){
        q1.push(q1.front());
        q1.pop();
       }
    }
    
    int pop() {
        if(q1.empty()) return -1;
        int pop_element = q1.front();
        q1.pop();
        return pop_element;

    }
    
    int top() {
        if(q1.empty()) return -1;
        return q1.front();
    }
    
    bool empty() {
        return (q1.size()==0);
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
class MyQueue {
    stack<int>s1,s2;
public:
//IMPLEMENT QUEUE USING 2 STACK BUT IT IS DIFFERENT FROM PREVIOUS 
// THIS METHOD IS  USED MORE WHEN THE PUSH OPERATION IS HIGHER THAN THEN POP AND TOP 
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(!s2.empty()){
            int element = s2.top();
            s2.pop();
            return element ;
        }
        else{
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
            int element = s2.top();
            s2.pop();
            return element ;
        }
    }
    
    int peek() {
        if(!s2.empty()){
           return s2.top();
        }
        else{
             while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
           return s2.top();
        }
    }
    
    bool empty() {
        return (s1.empty() && s2.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
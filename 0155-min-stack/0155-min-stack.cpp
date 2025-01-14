class MinStack {
public:
   vector<pair<int,int>>v;
   //1.val / 2 . minimum till now.
    MinStack() {
        
    }
    
    void push(int val) {
        if(v.empty()){
            v.push_back({val,val});
            return ;
        }
        else{
            v.push_back( {val , v.back().second < val ? v.back().second : val });
        }
    }
    
    void pop() {
        v.pop_back();
    }
    
    int top() {
        return v.back().first;
    }
    
    int getMin() {
        return v.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
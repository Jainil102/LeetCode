class MyStack {
public:
    queue<int> q;
    
    void push(int x) {
        q.push(x);        
    }
    
    int pop() {
        int a = q.back();
        int count = q.size();
        for(int i=0; i<count-1; i++){
            q.push(q.front());
            q.pop();
        }
        q.pop();
        return a;
    }
    
    int top() {
        return q.back();
    }
    
    bool empty() {
        return q.empty();
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
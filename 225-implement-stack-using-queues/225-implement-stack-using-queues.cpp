class MyStack {
public:
    queue<int> q;
    queue<int> temp;
    
    void push(int x) {
        q.push(x);        
    }
    
    int pop() {
        while(q.size() != 1){
            temp.push(q.front());
            q.pop();
        }
        int a = q.front();
        q.pop();
        temp.swap(q);
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
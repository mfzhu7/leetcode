class MyQueue {
public:
    stack<int> stk1;
    stack<int> stk2;
    MyQueue() {

    }
    
    void push(int x) {
        stk1.push(x);
    }
    
    int pop() {
        while(!stk1.empty()){
            stk2.push(stk1.top());
            stk1.pop();
        }
        int ret = stk2.top();
        stk2.pop();
        while(!stk2.empty()){
            stk1.push(stk2.top());
            stk2.pop();
        }
        return ret;
    }
    
    int peek() {
        while(!stk1.empty()){
            stk2.push(stk1.top());
            stk1.pop();
        }
        int ret = stk2.top();
        while(!stk2.empty()){
            stk1.push(stk2.top());
            stk2.pop();
        }
        return ret;
    }
    
    bool empty() {
        return stk1.empty();
    }
};
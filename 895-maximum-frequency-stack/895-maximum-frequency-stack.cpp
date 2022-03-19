class FreqStack {
    map<int,stack<int> > fs;
    map<int,int> f;
    int mf;
public:
    FreqStack() {
        mf = 0;
    }
    
    void push(int val) {
        f[val]++;
        if(mf < f[val]){
            mf = f[val];
        }
        fs[f[val]].push(val);
    }
    
    int pop() {
        int ret = fs[mf].top();
        fs[mf].pop();
        if(fs[mf].empty()) {
            fs.erase(mf);
            --mf;
        }
        f[ret]--;
        return ret;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
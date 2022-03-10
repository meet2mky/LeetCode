class Solution {
public:
    int precedance(char ch){
        return ch == '*' || ch == '/';
    }
    int getRes(int a, int b, char op){
        cout << a << op << b << endl;
        switch(op){
            case '*':
                return a*b;
            case '/':
                return a/b;
            case '+':
                return a + b;
            case '-':
                return a-b;
        }
        return 0;
    }
    int calculate(string s) {
        stack<int> operands;
        stack<char> operators;
        int num = 0;
        for(auto c: s){
            if(c == ' ')continue;
            if(c >= '0' && c <= '9'){
                num = num * 10 -'0' + c;
            }else{
                operands.push(num);
                num = 0;
                while(operators.size() && precedance(c) <= precedance(operators.top())){
                    int b = operands.top(); operands.pop();
                    int a = operands.top(); operands.pop();
                    char op = operators.top(); operators.pop();
                    operands.push(getRes(a,b,op));
                }
                operators.push(c);
            }
        }
        operands.push(num);
        while(operands.size() > 1){
            int b = operands.top(); operands.pop();
            int a = operands.top(); operands.pop();
            char op = operators.top(); operators.pop();
            operands.push(getRes(a,b,op));
        }
        return operands.top();
    }
};
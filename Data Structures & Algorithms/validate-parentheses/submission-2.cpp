class Solution {
public:
    bool isValid(string s) {
        stack<int> bracStack;
        for(int n: s){
            if(n=='('||n=='{'||n=='[') bracStack.push(n);
            else if(!bracStack.empty()){
                switch(n){
                    case '}': 
                        if(bracStack.top()=='{'){
                            bracStack.pop();
                            break;
                        }
                        else return false;
                    case ')':
                        if(bracStack.top()=='('){
                            bracStack.pop();
                            break;
                        }
                        else return false;
                    case ']':
                        if(bracStack.top()=='['){
                            bracStack.pop();
                            break;
                        }
                        else return false;
                }
            }
            else return false;
        }
        if(bracStack.empty()) return true; else return false;
    }
};

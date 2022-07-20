class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(int i=0; i<tokens.size(); i++){
            if(tokens[i].size() == 1 && (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")){
                int a = s.top();s.pop();
                int b = s.top();s.pop();
                if(tokens[i] == "+") a = b+a;
                else if(tokens[i] == "-") a = b-a;
                else if(tokens[i] == "*") a = b*a;
                else a = b/a;
                s.push(a);
            }
            else{
                int a = 0;
                int flag = 0;
                int j=0;
                if(tokens[i][0] == '-'){
                    flag = 1;
                    j = 1;
                }
                for(j; j<tokens[i].size(); j++){
                    a = a*10 + (tokens[i][j]-48);
                }
                if(flag) a = -a;
                s.push(a);
            }
        }
        return s.top();        
    }
};
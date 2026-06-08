class Solution {
public:
    bool checkValidString(string s) {
        stack<int> st1;
        stack<int> st2;
        int n = s.size();

        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                st1.push(i);
            }

            if(s[i] == '*'){
                st2.push(i);
            }

            if(s[i] == ')'){
                if(!st1.empty()){
                    st1.pop();
                }
                else if(st1.empty() && !st2.empty()){
                    st2.pop();
                }else{
                    return false;
                }
            }
        }


        while(!st1.empty() && !st2.empty()){
            int num1 = st1.top();
            st1.pop();
            int num2 = st2.top();
            st2.pop();

            if(num2 < num1){
                return false;
            }
        }

        if(!st1.empty()){return false;}

        return true;
        
    }   
};

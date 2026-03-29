class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 == 1) return false;
        stack<char> st;
        for(int i=0;i<s.size()/2;i++) {
            st.push(s[i]);
        }
        for(int i=s.size()/2;i<s.size();i++) {
            if(st.top() == '(' and s[i]!=')') return false; 
            else if(st.top() == '[' and s[i]!=']') return false;
            else if(st.top() == '{' and s[i]!='}') return false;
            st.pop();
        }
        return true;
        
    }
};

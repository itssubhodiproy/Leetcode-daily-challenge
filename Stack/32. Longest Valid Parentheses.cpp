class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(') st.push(i);
            else {
                if(st.empty()) st.push(i);
                else if(s[st.top()]=='(') st.pop();
                else st.push(i);
            }
        }
      //this part
        if(st.empty()) return s.length();
        int longg=0;int a=s.length(),b=0;
        while(!st.empty()){
            b=st.top();st.pop();
            longg=max(longg,a-b-1);
            a=b;
        }
        longg=max(longg,a);
        return longg;
    }
};

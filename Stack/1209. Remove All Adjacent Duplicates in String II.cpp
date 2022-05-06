// bool check(char c, int k, stack <char> st){
//     //check for k times c present in stack
//     int loop=k-1;
//     if(st.size()<k) return false;
//     while(loop--){
//         char top=st.top();                             
//         st.pop();
//         if(top==st.top())
//             continue;
//         else
//             return false;
//     }
//     return true;  
// }
// void remove(char c, int k, stack <char> &st){
//     //remove
//     while(k--)
//         st.pop();
// }

// class Solution {
// public:
//     string removeDuplicates(string s, int k) {               <-- TLE
//         int n=s.size();
//         if(n<k) return s;
//         stack<char>st;
        
//         for(auto it: s){
//             st.push(it);
//             if(check(it,k,st))
//                 remove(it,k,st);
//         }
//         //return stack element;
//         s.clear();
//         while(!st.empty()){
//             s.push_back(st.top());
//             st.pop();
//         }
//         reverse(s.begin(),s.end());
//         return s;
//     }
// };


class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n=s.size();
        if(n<k) return s;
        stack<pair<char,int>>st;
        
        for(int i=0;i<n;i++){
            if(st.empty()) st.push(make_pair(s[i],1));
            else if(st.top().first!=s[i]) st.push(make_pair(s[i],1));
            else if(st.top().second==k-1) st.pop();
            else{
                if(st.top().first==s[i])
                    st.top().second++;
                else
                    st.push(make_pair(s[i],1));
            }
        }
        s.clear();
        while(!st.empty()){
            string demo;demo.assign(st.top().second,st.top().first);
            s+=demo;
            st.pop();
        }
        reverse(s.begin(),s.end());
        return s;
       
    }
};

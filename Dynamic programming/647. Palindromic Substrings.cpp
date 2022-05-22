int countPali(int i,int j,string s){
    int count=0,n=s.length();
    while(i>=0 && j<n && s[i]==s[j]){
        i--;j++;count++;
    }  
    return count;
}
class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length(),count=0;
        // odd number's palindrome starts with same position
        for(int k=0;k<n;k++){
            int i=k,j=k;
            count+=countPali(i,j,s);        
        }
        //even length
        for(int k=0;k<n;k++){
            int i=k,j=k+1;
            count+=countPali(i,j,s);        
        }
        return count;
    }
};

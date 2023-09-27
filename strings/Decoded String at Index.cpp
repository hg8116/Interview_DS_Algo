/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=xK95Wlng_RA
    Company Tags                : National Instruments, Oracle, Google, TCS
    Leetcode Link               : https://leetcode.com/problems/decoded-string-at-index/
*/

/************************************************ C++ ************************************************/
class Solution {
public:
    string decodeAtIndex(string S, int K) {
        int n = S.length();
        long long size = 0;
        
        for(char ch:S) {
            if(isdigit(ch)) {
                size = size*(ch-'0');
            } else {
                size++;
            }
        }
        
        for(int i = n-1; i>=0; i--) {
            K = K%size;
            
            if(K == 0  && isalpha(S[i]))
                return string(1, S[i]);
            
            if(isalpha(S[i]))
                size--;
            else
                size = size/(S[i]-'0');
        }
        
        return "";
        
    }
};



/************************************************ JAVA ************************************************/
class Solution {
    public String decodeAtIndex(String s, int k) {
        long size = 0;
        for(int i=0; i<s.length(); i++){
            char x = s.charAt(i);
            if(Character.isDigit(x))
                size *= x - '0';
            else
                size++;
        }

        for(int i=s.length()-1; i>=0; i--){
            char x = s.charAt(i);
            if((k == 0 || k == size) && Character.isLetter(x))
                return String.valueOf(x);
            else if(Character.isLetter(x))
                size--;
            else{
                size /= x - '0';
                k %= size;
            }
        }

        return "";
    }
}

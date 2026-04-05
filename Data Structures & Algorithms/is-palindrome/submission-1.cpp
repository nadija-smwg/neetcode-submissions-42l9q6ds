class Solution {
public:
    bool isPalindrome(string s) {
        //transform(s.begin(),s.end(),s.begin(),::tolower);
        
        
        string s1;
        for (char c : s) {
            if (isalnum((unsigned char)c)) {
                s1 += tolower(c);
            }
        }
        int len = s1.length();
        cout << s1 <<endl;
        for(int i=0; i<len/2 ; i++){
            int j = len-1-i;
            if(s1[i] != s1[len-1-i]){
                cout<<s1[i] << s1[len-1-i];
                return false;
            }
        }
        return true;
    }
};

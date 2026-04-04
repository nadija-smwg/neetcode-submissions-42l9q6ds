class Solution {
public:

    string encode(vector<string>& strs) {
        string s="";
        for(string str : strs){
            s += (str + "`");
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> v;
        string str;
        for(char c : s){
            if (c=='`'){
                v.push_back(str);
                str = "";
                continue;
            }else if (c==s.back()){
                str += c;
                v.push_back(str);
                continue;
            }
            str += c;
        }
        return v;
    }
};

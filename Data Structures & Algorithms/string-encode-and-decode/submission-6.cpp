// class Solution {
// public:

//     string encode(vector<string>& strs) {
//         string s="";
//         for(string str : strs){
//             s += (str + "`");
//         }
//         return s;
//     }

//     vector<string> decode(string s) {
//         vector<string> v;
//         string str;
//         for(char c : s){
//             if (c=='`'){
//                 v.push_back(str);
//                 str = "";
//                 continue;
//             }else if (c==s.back()){
//                 str += c;
//                 v.push_back(str);
//                 continue;
//             }
//             str += c;
//         }
//         return v;
//     }
// };



class Solution {
public:
    string encode(vector<string>& strs) {
        string res;
        for (const string& s : strs) {
            res += to_string(s.size()) + "#" + s;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while (i < s.size()) {
            int j = i;
            while (s[j] != '#') {
                j++;
            }
            int length = stoi(s.substr(i, j - i));
            i = j + 1;
            j = i + length;
            res.push_back(s.substr(i, length));
            i = j;
        }
        return res;
    }
};
    




// 1047. Remove All Adjacent Duplicates In String
// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

class Solution {
public:
    string removeDuplicates(string s) {
        string st = "";
        st += s[0];
        for(int i=1;i<s.size();i++){
            if(s[i] == st.back()){
                st.pop_back();
            }
            else{
                st += s[i];
            }
        }
        return st;
    }
};

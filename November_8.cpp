// 1544. Make The String Great
// https://leetcode.com/problems/make-the-string-great/


class Solution {
public:
    string makeGood(string s) {
        string ans = "";
        for(int i=0;i<s.size();i++){
            if(!ans.empty() and abs(ans.back() - s[i]) == 32){
                ans.pop_back();
            }
            else{
                ans += s[i];
            }
        }
        return ans;
    }
};

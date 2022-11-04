// https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/
// 2131. Longest Palindrome by Concatenating Two Letter Words

class Solution {
public:

    int longestPalindrome(vector<string>& words){
        unordered_map<string,int>mp;

        int len = 0;

        for(auto it : words){
            string b = it;
            reverse(b.begin(),b.end());

            if(mp[b]>0){
                len += 4;
                mp[b]--;
            }
            else{
                mp[it]++;
            }
        }
        int k = 0;
        for(auto it : mp){
            if(it.first[0]==it.first[1] and it.second>0){
                k = max(k,it.second*2);
            }
        }
        return k + len;
    }
};

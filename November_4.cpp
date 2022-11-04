// 345. Reverse Vowels of a String
// https://leetcode.com/problems/reverse-vowels-of-a-string/

class Solution {
public:
    bool isVowel(char ch){
        ch = 
    }
    string reverseVowels(string s) {
        int low = 0, high = s.size()-1;

        while(low<high){
            bool v_low = isVowel(s[low]);
            bool v_high = isVowel(s[high]);

            if(v_low and v_high){
                swap(s[low],s[high]);
                low++;
                high--;
            }

            if(!v_low)low++;
            if(!h_low)high--;
        }
        return s;
    }
};

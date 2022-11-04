// 345. Reverse Vowels of a String
// https://leetcode.com/problems/reverse-vowels-of-a-string/
class Solution {
public:
    string reverseVowels(string s) {
        int n = s.size();
        int st = 0, en = n-1;
        while(st<en){
            while(st<en and (s[st]!='a' && s[st]!='e' && s[st]!='i' && s[st]!='o' && s[st]!='u') and (s[st]!='A' && s[st]!='E' && s[st]!='I' && s[st]!='O' && s[st]!='U')){
                st++;
            }
            while(st<en and (s[en]!='a' && s[en]!='e' && s[en]!='i' && s[en]!='o' && s[en]!='u') and (s[en]!='A' && s[en]!='E' && s[en]!='I' && s[en]!='O' && s[en]!='U')){
                en--;
            }
            if(st>=en){
                break;
            }
            swap(s[st],s[en]);
            st++;
            en--;
        }
        return s;
    }
};

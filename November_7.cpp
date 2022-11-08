// 1323. Maximum 69 Number
// https://leetcode.com/problems/maximum-69-number/

class Solution {
public:
    int maximum69Number(int num){
        int ans = num;

        int pos = 1;
        int max_six = 0;

        while(num>0){
            int digit = num%10;
            if(digit == 6){
                max_six = pos;
            }
            pos = pos*10;
            num /= 10;
        }
        
        ans += 3*max_six;
        return ans;        
    }
};

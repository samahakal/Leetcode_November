// 899. Orderly Queue
// https://leetcode.com/problems/orderly-queue/description/
class Solution {
public:
    string orderlyQueue(string s, int k) {
        
        if(k == 1){
            int n = s.size();
            string ans = s;
            s += s;
            for(int i=1;i<n;i++){
                ans = min(ans,s.substr(i,n));
            }
            return ans;
        }
        sort(s.begin(),s.end());
        return s;            
    }
};

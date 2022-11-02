// 433. Minimum Genetic Mutation
// https://leetcode.com/problems/minimum-genetic-mutation/description/


class Solution {
public:

    int diff(string a,string b){
        int cnt = 0;
        for(int i=0;i<8;i++){
            if(a[i]!=b[i]){
                cnt++;
            }
            if(cnt>1){
                return cnt;
            }
        }
        return cnt;
    }

    int solve(unordered_map<string,int>&mp,string st,string en){
        if(st == en){
            return 0;
        }

        string temp = st;
        int ans = 100;

        for(auto it : mp){
            if(it.second==0){
                continue;
            }
            if(diff(it.first,st) == 1){
                mp[it.first]--;
                ans = min(ans,1 + solve(mp,it.first,en));
                mp[it.first]++;
            }
        }
        return ans;
    }

    int minMutation(string start, string end, vector<string>& bank) {

        unordered_map<string,int>mp;
        for(auto st : bank){
            mp[st]++;
        }

        int mut = solve(mp,start,end);
        if(mut >= 100){
            return -1;
        }
        
        return mut;
    }
};

// 433. Minimum Genetic Mutation
// https://leetcode.com/problems/minimum-genetic-mutation/description/


Code : DFS
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

    int solve(unordered_map<string,int>mp,string st,string en){
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


Code : BFS 
class Solution {
public:

   

    int minMutation(string start, string end, vector<string>& bank) {

        
        unordered_set<string> dict(bank.begin(),bank.end());

        // base case
        if(dict.count(end) == 0){
            return -1;
        }

        int cnt = 0;
        queue<string>q;
        q.push(start);
        while(!q.empty()){
            int n = q.size();
            while(n--){
                string temp = q.front();
                q.pop();

                if(temp == end){
                    return cnt;
                }
                dict.erase(temp);

                for(int i=0;i<8;i++){
                    char ch = temp[i];
                    for(char c : "ACGT"){
                        temp[i] = c;
                        if(dict.count(temp)){
                            q.push(temp);
                        }
                    }
                    temp[i] = ch;
                }                

            }
            cnt++;
        }
        
        return -1;
    }
};

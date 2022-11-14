// 947. Most Stones Removed with Same Row or Column

class Solution {
public:
    int n;
    void dfs(vector<vector<int>>&stones,vector<bool>&visited,int ind){
        visited[ind] = true;
        for(int i=0;i<n;i++){
            if(visited[i]) continue;
            if(stones[ind][0] == stones[i][0] || stones[ind][1] == stones[i][1]) dfs(stones,visited,i);
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        n = stones.size();
        vector<bool>visited(n,false);
        int cnt = n;
        for(int i = 0 ;i<n;i++){
            if(visited[i]) continue;
            cnt--;
            dfs(stones,visited,i);
        }
        return cnt;
    }
};

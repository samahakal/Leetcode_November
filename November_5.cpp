// 212. Word Search II
// https://leetcode.com/problems/word-search-ii/description/
class node{
    public:
    vector<node*>arr;
    bool isEnd;
    string word;

    node():arr(26,NULL){
        // arr = vector<node*>(26,nullptr);
        isEnd = false;
        // word = "";
    }

};




class Solution {
private:

    void put(string  &s,int ind,node* t){
        node* root = t;
        for(int i=0;i<s.size();i++){
            char it = s[i];
            if(root->arr[it-'a'] == NULL){
                root->arr[it-'a'] = new node();
            }
            root = root->arr[it-'a'];
        }
        root->isEnd = true;
        root->word = s;
    }

    // void put(string &s,int si, node* cur){ //** adds a word to the trie 
    //         int a = s[si]-'a';    //*********** also stores the word at the terminal node
    //         if(!cur->arr[a]){
    //         node* newnode = new node();
    //         cur->arr[a] = newnode;
    //         }

    //         if(si != s.size()-1){
    //         put(s,si+1,cur->arr[a]); }
    //         else
    //          { cur->arr[a]->isEnd = true;
    //            cur->arr[a]->word = s;
    //           }
    //   }

    void dfs(vector<vector<char>>&board,int i,int j,set<string>&res,node *t,vector<vector<bool>>&vis){
        if(i<0 || j<0 ||i>=board.size()||j>=board[0].size() ||board[i][j] == '#'){
            return;         
        }

        t = t->arr[board[i][j]-'a'];
        if(t==NULL) return;

        if(t->isEnd) res.insert(t->word);

        char ch = board[i][j];
        board[i][j] = '#';
        // vis[i][j] = 1;
        dfs(board,i+1,j,res,t,vis);
        dfs(board,i-1,j,res,t,vis);
        dfs(board,i,j+1,res,t,vis);
        dfs(board,i,j-1,res,t,vis);
        board[i][j] = ch;
        // vis[i][j] = 0;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        node* t = new node();
        for(auto it : words){
            put(it,0,t);
        }

        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,0));

        set<string>res;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dfs(board,i,j,res,t,vis);
            }
        }

        vector<string>ans(res.begin(),res.end());
        return ans;
    }
};

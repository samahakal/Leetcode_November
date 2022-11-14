// 151. Reverse Words in a String


class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        stack<string>st;
        int n = s.size();
        int i = 0;
        while(i<n){
            while(i<n and s[i] == ' '){
                i++;
            }
            if(i==n) break;
            string temp = "";
            while(i<n and s[i] != ' '){
                temp += s[i];
                i++;
            }
            i++;
            st.push(temp);
        }

        while(!st.empty()){
            res += st.top() + " ";
            st.pop();
        }
        res.pop_back();

        return res;
    }
};

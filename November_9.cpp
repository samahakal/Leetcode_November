// 901. Online Stock Span
// https://leetcode.com/problems/online-stock-span/

class StockSpanner {
public:
    // to store prices and span
    stack<pair<int,int>>st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        // minimum span is 1 for every price
        int val = 1;

        // if it is a starting price then simply add it into our stack
        if(st.empty()){
            st.push({price,1});
        }
        else{
            // until stack top element is lest or equal to curr_price and add there span in val
            while(!st.empty() && st.top().first<=price){
                val += st.top().second;
                st.pop();
            }
            st.push({price,val});
        }
        return val;
    }
    
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

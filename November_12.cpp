// 295. Find Median from Data Stream

class MedianFinder {
public:
    priority_queue<int>mx;
    priority_queue<int,vector<int>,greater<int>>mn;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(mx.empty() || mx.top() > num){
            mx.push(num);
        }
        else{
            mn.push(num);
        }

        // maintain mx is alway greater or equal to mn
        if(mx.size() > mn.size() + 1){
            mn.push(mx.top());
            mx.pop();
        }
        else if(mn.size() >= mx.size()+1){
            mx.push(mn.top());
            mn.pop();
        }
    }
    
    double findMedian() {
        if(mx.size() == mn.size()){
            double ans = mx.top() + mn.top();
            return ans/2;
        }
        else{
            return mx.top();
        }
        return 1;
    }
};

// class MedianFinder {
// public:
//     priority_queue<int>mx;
//     priority_queue<int,vector<int>,greater<int>>mn;
//     MedianFinder() {
        
        
//     }
    
//     void addNum(int num) {
//         if(mx.empty() || mx.top()>num){
//             mx.push(num);
//         }
//         else{
//             mn.push(num);
//         }
//         if(mx.size()>mn.size()+1){
//             mn.push(mx.top());
//             mx.pop();
//         }
//         else if(mn.size()>mx.size()+1){
//             mx.push(mn.top());
//             mn.pop();
//         }        
//     }
    
    
//     double findMedian() {
//         if((mn.size()+mx.size())%2 == 0){
//             double ans = mx.top()+mn.top();
//             ans = ans/2;
//             return ans;
//         }
//         else{
//             return mn.size()>mx.size() ? mn.top() : mx.top();
//         }
        
//     }
// };

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

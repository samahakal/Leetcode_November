// 26. Remove Duplicates from Sorted Array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        // using two pointer 'a' and 'i'
        // 'a' using to check it dublicate or not
        // 'i' points to curr index

        int k = 0;
        int i = 0;
        int j = 0;

        for(int i=1;i<n;i++){
            if(nums[i] != nums[i-1]){
                nums[++j] = nums[i];
            }
        }
        return j+1;
        
        // int a = 0;
        // for(int i=1;i<n;i++){
        //     if(nums[a]!=nums[i]){
        //         nums[a+1] = nums[i];
        //         a++;
        //     }
        // }
        // return a+1;
    }
};
 

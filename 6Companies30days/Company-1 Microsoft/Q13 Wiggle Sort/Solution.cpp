class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(n);
        sort(nums.begin(),nums.end());
        int i = 1;
        int j = n-1;
        while(i<n && j>=0){
            temp[i] = nums[j];
            j--;
            i = i+2; 
        }
        i = 0;
        while(i<n && j>=0){
            temp[i] = nums[j];
            i = i+2;
            j--;
        }
        for(int i=0;i<n;i++){
            nums[i] = temp[i];
        }
    }
};
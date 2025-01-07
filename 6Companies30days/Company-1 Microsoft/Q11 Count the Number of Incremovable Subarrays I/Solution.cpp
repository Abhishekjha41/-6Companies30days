class Solution {
public:
    bool isValid(vector<int>& arr,int l,int r){
        int i = 1;
        int j = r+1;
        int n = arr.size();
        while(i<l){
            if(arr[i]<=arr[i-1]) return false;
            i++;
        }
        if(j<n && l>=1 && arr[j]<=arr[l-1]) return false;
        j++;
        while(j<n){
            if(arr[j]<=arr[j-1]) return false;
            j++;
        }
        return true;

    }
    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();
        int cntans = 0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isValid(nums,i,j)){
                    cntans = cntans+1;
                }
            }
        }
        return cntans;
    }
};
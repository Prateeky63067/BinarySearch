

class Solution {
public:
    int RotionCount(vector<int>& nums) {
       int low=0,high=nums.size()-1;
       int mid;
       while(low<=high)
       {
        if(nums[low]<=nums[high])
        return low;
        int mid=(low+high)/2;

        if(nums[mid]>=nums[high])
        low=mid+1;
        else
        high=mid;
       }
       return low;
    }
};
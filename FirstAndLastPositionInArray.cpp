class Solution {
public:
     int firstOcc(vector<int>& nums, int target)
     {
        int ans=-1;
        int low=0,high=nums.size()-1;
        int mid;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(nums[mid]==target)
            {
                ans=mid;
                high=mid-1;
            }
            else if(nums[mid]>target)
            {
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
     }
     int lastOcc(vector<int>& nums, int target)
     {
        int ans=-1;
        int low=0,high=nums.size()-1;
        int mid;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(nums[mid]==target)
            {
                ans=mid;
                low=mid+1;
            }
            else if(nums[mid]>target)
            {
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
     }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans;
        int ans1=firstOcc(nums,target);
        int ans2=lastOcc(nums,target);
        ans.push_back(ans1);
        ans.push_back(ans2);
        return ans;
    }
};
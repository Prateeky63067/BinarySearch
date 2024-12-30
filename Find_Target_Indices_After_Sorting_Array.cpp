//  Find Target Indices After Sorting Array
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

    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int>ans;
        sort(nums.begin(),nums.end());
        int ans1=firstOcc(nums,target);
        int ans2=lastOcc(nums,target);
        if(ans1==-1||ans2==-1)
        return ans;
        for(int i=ans1;i<=ans2;i++)
        {
            ans.push_back(i);
        }
        return ans;
    }
};
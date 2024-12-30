class Solution {
public:
  int helper(vector<int>& nums,int target)
  {
    int low=0, n=nums.size();
    int high=n-1;
    while(low<=high)
    {
      int mid=(low+high)/2;
      if(nums[mid]==target)
      return true;
      else if(nums[mid]>target)
      high=mid-1;
      else
      low=mid+1;
    }
    return -1;
  }
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int ans=-1;
        for(int i=0;i<n;i++)
        {
          if(helper(nums2,nums1[i])!=-1)
          {
            ans=nums1[i];
            break;
          }
        }
        return ans;
    }
};
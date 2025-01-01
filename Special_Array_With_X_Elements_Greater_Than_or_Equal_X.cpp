class Solution {
public:
    int helper(vector<int>& nums,int tar)
    {
        int n=nums.size();
        int low=0,high=n-1;
        int ans=n;
        while(low<=high)
        {
            int x=-1;
            
            int mid=(low+high)/2;
            if(nums[mid]>=tar)
            {
               ans=mid;
               high=mid-1;
            }else{
                low=mid+1;
               
            }

        }
        return ans;
    }
    int specialArray(vector<int>& nums) {
        int N=nums.size();
        sort(nums.begin(),nums.end());
             for (int i = 1; i <= N; i++) {
            int k = helper(nums, i);
            
            if (N - k == i) {
                return i;
            }
        }
        
        return -1;
    }
};
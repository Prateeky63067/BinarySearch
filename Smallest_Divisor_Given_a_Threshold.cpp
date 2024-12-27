class Solution {
public:
    int helper(vector<int>& nums,int div){
        int  sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            sum+=(nums[i]+div-1)/div;
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1,n=nums.size();
        int high=-1;
        for(int i=0;i<n;i++)
        {
            high=max(high,nums[i]);
        }
        int ans=0;
        while(low<=high)
        {
           int mid=(low+high)/2;
           if(helper(nums,mid)>threshold)
           {
            low=mid+1;
           }else{
            ans=mid;
            high=mid-1;
           }
        }
        return ans;
    }
};
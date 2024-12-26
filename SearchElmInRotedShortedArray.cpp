class Solution {
public:
    int binarySearch(vector<int>&nums,int low,int high,int target)
    {
        int mid;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(nums[mid]==target)
            {
                return mid;
            }else if(nums[mid]>target)
            {
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return -1;
    }
    int minElmIndex(vector<int>&nums)
    {
        int low=0;
        int high=nums.size()-1;
        int mid;
        while(low<=high)
        {
            if(nums[low]<=nums[high])
            return low;

            mid=(low+high)/2;

            if(nums[mid]>=nums[high])
            low=mid+1;
            else
            high=mid;
            
        }
        return low;
    }
    int search(vector<int>& nums, int target) {
        int minIndex=minElmIndex(nums);
        cout<<minIndex<<endl;
        int n=nums.size();
        int ans1=binarySearch(nums,minIndex,n-1,target);
        int ans2=binarySearch(nums,0,minIndex-1,target);
        if(ans1!=-1)
        return ans1;
        return ans2;
    }
};
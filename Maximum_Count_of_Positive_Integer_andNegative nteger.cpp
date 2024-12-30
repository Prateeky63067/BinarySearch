class Solution {
public:
    
    int maximumCount(vector<int>& nums) {
        int n=nums.size();
        int low=0,high=n-1;
        int posindex=-1;

        while(low<=high)
        {
            int mid=(low+high)/2;

            if(nums[mid]>0)
            {
                 posindex=mid;
                 high=mid-1;
            }else{
                low=mid+1;
            }
        }
        low=0,high=n-1;
        int negIndex=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;

            if(nums[mid]<0)
            {
                 negIndex=mid;
                 low=mid+1;
            }else{
                high=mid-1;
            }
        }
       
        int posval=0;
        if(posindex!=-1)
        posval=n-posindex;

        int negval=0;
        if(negIndex!=-1)
        negval=negIndex+1;
        
        return max(negval,posval);
    }
};
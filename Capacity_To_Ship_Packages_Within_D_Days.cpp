class Solution {
public:
    int helper(vector<int>& weights,int mid)
    {
         int n=weights.size();
         int currsum=0;
         int ans=0;
         for(int i=0;i<n;i++)
         {
            currsum+=weights[i];
            if(currsum==mid)
            {
             currsum=0;
             ans++;
            }
            else if(currsum>mid)
            {
             currsum=weights[i];
             ans++;
            }
         }
         if(currsum!=0)
         ans++;
         return ans;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=0;
        int n=weights.size();
        int high=0;
        for(int i=0;i<n;i++)
        {
          low=max(low,weights[i]);
          high+=weights[i];
        }
        int ans=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(helper(weights,mid)>days)
            {
                low=mid+1;
            }else{
                ans=mid;
                high=mid-1;
            }
        }
        return ans;
        // return helper(weights,15);
    }
};
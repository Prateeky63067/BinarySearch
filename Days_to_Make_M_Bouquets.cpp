class Solution {
public:
    int helper(vector<int>& bloomDay, int mid, int k)
    {
      int m=0;
      int count=0;
      int n=bloomDay.size();
      for(int i=0;i<n;i++)
      {
        if(mid>=bloomDay[i])
        {
          count++;
        }else{
             count=0;
        }
        if(count==k)
        {
            count=0;
            m++;
        }
      }
      return m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        int low=1;
        int high=-1;
        for(int i=0;i<n;i++)
        {
            high=max(high,bloomDay[i]);
        }
        int ans=-1;
        while(low<=high){

            int mid=(low+high)/2;
            if(helper(bloomDay,mid,k)<m)
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
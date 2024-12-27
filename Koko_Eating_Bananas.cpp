class Solution {
public:
    long possibleHours(vector<int>& piles,int possibleK)
    {
        long hour=0;
        int n=piles.size();
        for(int i=0;i<n;i++)
        {
            hour+=(piles[i]+possibleK-1)/possibleK;
       
        }
        return hour;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int n=piles.size();
        int high=-1;
        for(int i=0;i<n;i++)
        {
          high=max(high,piles[i]);
        }
        int ans=0;
        while(low<=high)
        {
          int mid=(low+high)/2;
          if(possibleHours(piles,mid)<=h)
          {
            ans=mid;
            high=mid-1;
          }else{
            low=mid+1;
          }
        }
        return ans;
    }
};
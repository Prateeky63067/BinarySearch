class Solution {
  public:
  
  
     bool helper(vector<int> &stalls,int mid,int cow)
     {
         int currCo=1;
         int n=stalls.size();
         int last=stalls[0];
         for(int i=0;i<n;i++)
         {
             if((stalls[i]-last)>=mid)
             {
                 last=stalls[i];
                 currCo++;
                 if(currCo>=cow)
                 return true;
             }
         }
         return false;
     }
     
     
    int aggressiveCows(vector<int> &stalls, int k) {

        int low=1;
        int high=0;
        int n=stalls.size();
        sort(stalls.begin(),stalls.end());
        high=stalls[n-1]-stalls[0];
        int ans=0;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(helper(stalls,mid,k))
            {
                ans=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return ans;
    }
};

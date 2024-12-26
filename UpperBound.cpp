class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        int low=0;
        int high=arr.size()-1;
        int mid;
        int ans=arr.size();
        
        while(low<=high)
        {
            mid=(low+high)/2;
            if(arr[mid]<=target)
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
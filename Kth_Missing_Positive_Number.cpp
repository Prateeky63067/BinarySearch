class Solution {
public:
    bool helper(vector<int>& arr, int target)
    {
          int n=arr.size();
          int low=0,high=n-1;
          while(low<=high)
          {
            int mid=(low+high)/2;
            if(arr[mid]==target)
            return true;
            else if(arr[mid]>target)
            {
                high=mid-1;
            }else{
                low=mid+1;
            }
          }
          return false;
    }
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int start=1,end=arr[n-1];
        if(n<=end)
        end=end+(k-(arr[0]-1));

        for(int i=start;i<=end;i++)
        {
          if(helper(arr,i)==false)
          {
            k--;
            if(k==0)
            return i;
          }
        }
        return 0;
    }
};
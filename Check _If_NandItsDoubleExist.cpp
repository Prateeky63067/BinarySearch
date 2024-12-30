class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==0)
            cnt++;
        }
        if(cnt>1||(cnt>0&&cnt%2==0))
        return true;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==0)
            continue;
         int target=2*arr[i];
         int low=0,high=n-1;
        while(low<=high)
        {
          int mid=(low+high)/2;
          if(arr[mid]==target)
          return true;
          else if(arr[mid]>target)
          high=mid-1;
          else
          low=mid+1;
        }
        }
        return false;
    }
};
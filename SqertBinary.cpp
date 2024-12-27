class Solution {
public:
    int mySqrt(int x) {
        long low=1,high=x;
        long ans=0;
        while(low<=high)
        {
            long mid=(low+high)/2;
            long mids=mid*mid;
            if((mids)>x)
            {
                high=mid-1;
            }else{
                ans=mid;
                low=mid+1;
            }
        }
        return ans;
    }
};
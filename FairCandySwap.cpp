// Fair Candy Swap

class Solution {
public:


    int helper(vector<int>& aliceSizes,int bob,int diff)
    {
        int target=bob-diff;
        // cout<<target<<" ";

        int low=0, high=aliceSizes.size()-1;

        while(low<=high)
        {
            int mid=(low+high)/2;
            if(aliceSizes[mid]==target)
            return aliceSizes[mid];
            else if(aliceSizes[mid]>target)
            {
               high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return 0;
    }
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        vector<int>ans;
        int sum1=0,sum2=0;
        sort(aliceSizes.begin(),aliceSizes.end());
        for(int i=0;i<aliceSizes.size();i++)
        {
            sum1+=aliceSizes[i];
        }

        for(int i=0;i<bobSizes.size();i++)
        {
            sum2+=bobSizes[i];
        }
        
        int totalsum=sum1+sum2;

        int reqsum=totalsum/2;

        int diff=reqsum-sum1;
         cout<<diff;
        for(int i=0;i<bobSizes.size();i++)
        {
            int x=helper(aliceSizes,bobSizes[i],diff);
            // cout<<x<<endl;
            if(x)
            {
              ans.push_back(x);
              ans.push_back(bobSizes[i]);
              break;
            }
            
        }
        return ans;

    }
};
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int>ans;
        int n=mat.size();
        int m=mat[0].size();
        vector<pair<int,int>>vp;
        for(int i=0;i<n;i++)
        {
            int cnt=0;
            for(int j=0;j<m;j++)
            {
              if(mat[i][j]==1)
              cnt++;
            }
            vp.push_back({cnt,i});
        }
        sort(vp.begin(),vp.end());
        for(int i=0;i<k;i++)
        {
          ans.push_back(vp[i].second);
        }
        return ans;
    }
};
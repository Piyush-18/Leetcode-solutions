class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        vector<int> lmax(n,0);
        vector<int> rmin(n,0);
        int maxx=INT_MIN, minn=INT_MAX;
        for(int i=0;i<n;i++)
        {
            lmax[i]=max(maxx,arr[i]);
            maxx=lmax[i];
            rmin[n-1-i]=min(minn,arr[n-1-i]);
            minn=rmin[n-1-i];
        }
        int chunks=0;
        for(int i=0;i<n-1;i++)
        {
            if(lmax[i]<=rmin[i+1]) chunks++;
        }
        return chunks+1;
    }
};
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int maxx=0, chunks=0;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            maxx=max(maxx,arr[i]);
            if(maxx==i) chunks++;
        }
        return chunks;
    }
};
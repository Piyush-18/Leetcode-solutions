class Solution {
public:

    int findDays(vector<int> weights, int cap)
    {
        int n=weights.size();
        int days=1;
        int load=0;
        for(int i=0;i<n;i++)
        {
            
            if(load+weights[i]>cap)
            {
                days++;
                load=weights[i];
            }
            else
            {
                load+=weights[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);
        while(low<=high)
        {
            int mid=(high+low)/2;
            int no_days=findDays(weights, mid);
            if(no_days<=days)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return low;
    }
};
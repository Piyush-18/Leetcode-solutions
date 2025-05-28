class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int count=0, ele=nums[0];
        for(int i=0;i<n;i++)
        {
            if(count==0)
                {
                    ele=nums[i];
                }
            if(nums[i]==ele)
            {
                count++;
            }
            else
            {
                count--;
                
            }
        }
        count=0;
        for(int i=0;i<n;i++)
        {
            if(ele==nums[i]) count++;
        }
        if(count>(n/2)) return ele;
        return 0;
    }
};
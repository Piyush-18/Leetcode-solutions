class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> ans;
        unordered_map<int,int> map;
        for(int i=0;i<n;i++)
        {
            int search=target-nums[i];
            if(map.find(search)!=map.end())
            {
                ans.push_back(i);
                ans.push_back(map[search]);
            }
            map[nums[i]]=i;
        }
        return ans;

    }
};
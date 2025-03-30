class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        for (int num : nums) {
            freqMap[num]++;
        }

        int maxFreq = 0;
        for (auto& it : freqMap) {
            maxFreq = max(maxFreq, it.second);
        }

        vector<vector<int>> buckets(maxFreq + 1);
        for (auto& it : freqMap) {
            buckets[it.second].push_back(it.first);
        }

        vector<int> ans;
        for (int i = maxFreq; i >= 0 && ans.size() < k; i--) {
            for (int num : buckets[i]) {
                ans.push_back(num);
                if (ans.size() == k) break;
            }
        }

        return ans;
    }
};

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // Handle cases where k > n
        if (k == 0) return; // No need to rotate

        // Reverse the first part
        reverse(nums.begin(), nums.end() - k);
        // Reverse the second part
        reverse(nums.end() - k, nums.end());
        // Reverse the whole array
        reverse(nums.begin(), nums.end());
    }
};

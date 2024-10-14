class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
    priority_queue<int> pq;

    // Add all elements to the priority queue
    for (int num : nums) {
        pq.push(num);
    }

    long long score = 0;

    while (k > 0) {
        int ele = pq.top();
        pq.pop();
        score += ele;
        pq.push(ceil(ele / 3.0));
        k--;
    }

    return score;
    }
};
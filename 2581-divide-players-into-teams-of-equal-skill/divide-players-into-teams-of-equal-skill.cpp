class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int total = accumulate(skill.begin(), skill.end(), 0);
        int n = skill.size();
        if (n % 2 != 0) return -1;  // Can't divide if odd number of players
        int teams = n / 2;
        if (total % teams != 0) return -1;  // Chemistry not divisible evenly
        int chemistry = total / teams;
        
        unordered_map<int, int> hash;
        int count=0;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            int rem = chemistry - skill[i];
            if (hash[rem] > 0) {
                sum += (long long)(skill[i]*rem);
                count++;
                hash[rem]--;
            } else {
                hash[skill[i]]++;
            }
        }
        
        // If not enough valid pairs are formed, return -1
        if (count != teams) return -1;
        return sum;
    }
};

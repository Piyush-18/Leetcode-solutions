class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1hash(26, 0);
        vector<int> s2hash(26, 0);
        
        int s1len = s1.length();
        int s2len = s2.length();
        
        if (s1len > s2len) return false;
        
        // Build the frequency map for s1
        for (int i = 0; i < s1len; i++) {
            s1hash[s1[i] - 'a']++;
            s2hash[s2[i] - 'a']++;  // Build initial window for s2
        }
        
        // Sliding window over s2
        for (int i = s1len; i < s2len; i++) {
            if (s1hash == s2hash) return true;  // Compare maps
            s2hash[s2[i] - 'a']++;              // Include next character in the window
            s2hash[s2[i - s1len] - 'a']--;      // Remove the character that's out of the window
        }
        
        // Final comparison for the last window
        return s1hash == s2hash;
    }
};

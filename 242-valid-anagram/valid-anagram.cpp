class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        unordered_map<char,int> count;
        for(auto ch : s)
        {
            count[ch]++;
        }
        for(auto ch : t)
        {
            if(count.find(ch)==count.end() || count[ch]==0)
            return false;
            count[ch]--;
         }
         return true;
    }
};
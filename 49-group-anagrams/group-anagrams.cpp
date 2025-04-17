class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> umap;
        for(auto x: strs)
        {
            string temp=x;
            sort(temp.begin(),temp.end());
            umap[temp].push_back(x);
        }
        for(auto x : umap)
        {
            ans.push_back(x.second);
        }
        return ans;
    }
};
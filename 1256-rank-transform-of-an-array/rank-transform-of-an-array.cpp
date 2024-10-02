class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n,0);
        vector<pair<int,int>> sorted;
        for(int i =0 ; i < n ; i++){
            sorted.push_back({arr[i] ,i});
        }
        
        sort(sorted.begin(), sorted.end(), [](pair<int,int> a, pair<int,int>b){
            return a.first < b.first;
        });
        
        int rank  = 1;
        for(int i = 0 ; i < n ; i++){ 
            // are the values same 
            if(i != 0 and sorted[i].first == sorted[i-1].first){
                ans[sorted[i].second]= rank-1;    
            }
            else{
                ans[sorted[i].second]= rank;
                rank+=1;
            }
            
            
        }
        return ans;
    }
};
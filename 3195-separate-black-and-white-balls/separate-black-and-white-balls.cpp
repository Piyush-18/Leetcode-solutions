class Solution {
public:
    long long minimumSteps(string s) {
        long long swaps=0, black=0;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')
            black++;
            else
            swaps+=black;
        }
        return swaps;
    }
};
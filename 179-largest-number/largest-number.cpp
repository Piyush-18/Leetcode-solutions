class Solution {
public:
    static bool comp(const string &str1, const string &str2)
    {
        return (str1+str2)>(str2+str1);
    }
    string largestNumber(vector<int>& nums) {
        vector<string> arr;
        for(int num : nums)//O(n)
        {
            arr.push_back(to_string(num));
        }
        sort(arr.begin(),arr.end(),comp);//O(nlogn)
        if(arr[0]=="0") return "0";
        string largest="";
        for(const string &num : arr)
        {
            largest+=num;

        }
        return largest;
    }
};
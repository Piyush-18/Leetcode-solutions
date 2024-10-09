class Solution {
public:
    int minAddToMakeValid(string s) {
        int count1=0, count2=0;
        
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(') count1++;
            else
            {
                if(count1)
                {
                    count1--;
                }
                else
                count2++;
            }
        }
        return count1+count2;
    }
};
class Solution {
public:
    int nextGreaterElement(int n) {
        string str = to_string(n);
        int len = str.length();
        int dip=-1;
        for (int i = len - 1; i >= 1; i--)
        {
            if(str[i]>str[i-1])
            {
                dip=i-1;
                break;
            }
        }
        if(dip==-1) return -1;
        int index, maxx=INT_MAX;
        for(int i=dip+1;i<len;i++)
        {
            if(str[i]>str[dip] && str[i]<maxx)
            {
                maxx=(int)(str[i]);
                index=i;
            }
        }
        swap(str[index],str[dip]);
        sort(str.begin()+dip+1,str.end());
        long long s=stoll(str);
        if(s>INT_MAX) return -1;
        return (int)s;
    }
};
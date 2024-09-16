class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
       
       int n=timePoints.size();
       vector<int> minutes(n,0);
       //calculating total minutes from each time point
       for(int i=0;i<n;i++)
       {
          int hrs=stoi(timePoints[i].substr(0,2));
          int mins=stoi(timePoints[i].substr(3));
          minutes[i]=hrs*60+mins;
       } 
       sort(minutes.begin(),minutes.end());
       //calculating differences in adjacent timepoints
       int mini_diff=INT_MAX;
       for(int i=0;i<n-1;i++)
       {
          mini_diff=min(mini_diff,minutes[i+1]-minutes[i]);
       }
       //calculating lower between already evaluated mini_diff and the circular difference between the first and the last element
       return min(mini_diff,(24*60-minutes[n-1])+minutes[0]);
    }
};
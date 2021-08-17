class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        
        vector<vector<int>> v;
        int l=intervals[0][0],h=intervals[0][1];
        int len=intervals.size();
        if(len==1)
        return intervals;
        for(int i=1;i<len;i++)
        {
            if(h>=intervals[i][0])
            {
                if(h<intervals[i][1])
                  h=intervals[i][1];    
            }
            else
            {
                v.push_back({l,h});
                l=intervals[i][0];
                h=intervals[i][1];
            }
            
        }
         v.push_back({l,h});
        return v;
    }
};

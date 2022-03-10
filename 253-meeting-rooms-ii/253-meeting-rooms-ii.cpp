class Solution {
public:
    struct cmp{
      bool operator()(pair<int,int>& a, pair<int,int>& b){
          return (a.first == b.first) ? (a.second < b.second) : (a.first < b.first);
      }  
    };
    int minMeetingRooms(vector<vector<int>>& intervals){
        vector<pair<int,int>> values;
        for(auto & v: intervals){
            values.push_back({v[0],1});
            values.push_back({v[1],-1});
        }
        sort(begin(values),end(values),cmp());
        int currentRooms = 0, maxRooms = 0;
        for(auto & v: values){
            currentRooms += v.second;
            maxRooms = max(maxRooms, currentRooms);
        }
        return maxRooms;
    }
};
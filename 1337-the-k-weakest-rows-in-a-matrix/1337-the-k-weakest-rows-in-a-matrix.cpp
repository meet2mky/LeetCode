class Solution {
public:
    struct cmp{
      bool operator()(const pair<int,int>& a, const pair<int,int>& b) const{
          return a.first == b.first ? a.second < b.second : a.first < b.first;
      }  
    };
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = 0; j < m; j++){
                sum += mat[i][j];
            }
            pq.push({sum,i});
            if(pq.size() > k) pq.pop();
        }
        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(begin(res),end(res));
        return res;
    }
};
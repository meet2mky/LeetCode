class Solution {
public:
    struct ComparePointsBasedOnDistanceFromOrigin{
        bool operator()(const vector<int> & a, const vector<int>& b){
            return a[0]*a[0] + a[1]*a[1] < b[0]*b[0] + b[1]*b[1];   
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>> , ComparePointsBasedOnDistanceFromOrigin> pq;
        for(vector<int> & v: points){
            pq.push(v);
            if(pq.size() > k) pq.pop();
        }
        vector<vector<int> > kCloset;
        while(!pq.empty()){
            kCloset.push_back(pq.top());
            pq.pop();
        }
        return kCloset;
    }
};
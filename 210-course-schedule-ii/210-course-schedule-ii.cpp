class Solution {
    vector<char> color;
    vector<int> order;
    vector<vector<int>> graph;
    int n;
    void makeGraph(int n, vector<vector<int>>& edges){
        this->n = n;
        graph = vector<vector<int>>(n, vector<int>());
        for(auto & e: edges){
            graph[e[1]].push_back(e[0]);
        }
        color = vector<char>(n, 'W');
    }
    bool dfs(int now){
        color[now] = 'R';
        bool res = false;
        for(auto & nv: graph[now]){
            if(color[nv] == 'R'){
                return true;
            }else if(color[nv] == 'W'){
                res = res | dfs(nv);
            }
        }
        color[now] = 'B';
        order.push_back(now);
        return res;
    }
public:
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        makeGraph(n, edges);
        for(int i = 0; i < n; i++){
            if(color[i] == 'W'){
                if(dfs(i)) return vector<int>();
            }
        }
        reverse(begin(order), end(order));
        return order;
    }
};
class Solution {
private:
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n,vector<int>(n,0));
        vector<bool> vis(n, false);
        for(auto it:edges){
            int u = it[0], v= it[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        // vector<bool> vis(n,false);
        int count = 0;
        for(int i=0;i<n;i++){
            if(vis[i]==false){
                dfs(i,graph,vis);
                count+=1;
            }
        }
        return count;
    }
    void dfs(int index,vector<vector<int>>& graph, vector<bool>& vis){
        vis[index]=true;
        for(auto it:graph[index]){
            if(vis[it]==false){
                dfs(it, graph, vis);
            }
        }
    }
};

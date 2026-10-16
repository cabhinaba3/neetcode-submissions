class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        return std::min(dfs(cost, 0), dfs(cost, 1));
    }
    int dfs(vector<int>& cost, int index){
        if(index >= cost.size()){ return 0; }
        return cost[index]+std::min(dfs(cost, index+1), dfs(cost,index+2));
    }
};

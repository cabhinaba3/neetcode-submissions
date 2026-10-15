class Solution {
private:
    vector<vector<int>> dp;
    int dfs(vector<vector<int>>& costs, int index, int preColourIndex){
        if(index == costs.size()){ return 0; }
        if(preColourIndex != -1 && dp[index][preColourIndex] != -1){
            return dp[index][preColourIndex];
        }
        int totalCost = INT_MAX;
        for(int i=0;i<costs[index].size();i++){
            if(i == preColourIndex){ continue; }
            totalCost = min(totalCost, costs[index][i]+dfs(costs, index+1, i));
        }
        if(preColourIndex != -1){
            return dp[index][preColourIndex] = totalCost;
        }
        return totalCost;
    }
public:
    int minCostII(vector<vector<int>>& costs) {
        dp.assign(costs.size()+1, vector<int>(costs[0].size()+1, -1));
        return dfs(costs, 0, -1);
    }
};

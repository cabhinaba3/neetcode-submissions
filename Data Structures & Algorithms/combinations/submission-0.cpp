class Solution {
private:
    vector<vector<int>> ans;
    void dfs(int n, int k, int index, vector<int>& comb){
        if(comb.size() == k){ ans.push_back(comb); }
        else{
            for(int i=index;i<=n;i++){
                comb.push_back(i);
                dfs(n,k,i+1, comb);
                comb.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> comb;
        dfs(n,k,1,comb);
        return ans;
    }
};
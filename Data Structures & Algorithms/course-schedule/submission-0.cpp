class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> degrees(numCourses, 0);
        vector<vector<int>> list(numCourses);
        for(auto it: prerequisites){
            degrees[it[1]]++;
            list[it[0]].push_back(it[1]);
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(degrees[i] == 0){
                q.push(i);
            }
        }
        int finish = 0;
        while(q.size()!=0){
            int node = q.front();
            q.pop();
            finish+=1;
            for(int cls:list[node]){
                degrees[cls]-=1;
                if(degrees[cls] == 0){
                    q.push(cls);
                }
            }
        }
        return finish == numCourses;
    }
};

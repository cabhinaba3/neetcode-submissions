class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int count_w = 0;
        for(int i=0;i<k;i++){
            if(blocks[i] == 'W'){ count_w++; }
        }
        int res = count_w;
        for(int i=k;i<blocks.size();i++){
            if(blocks[i-k] == 'W'){ count_w--; }
            if(blocks[i] == 'W'){ count_w++; }
            res = min(res, count_w);
        }
        return res;
    }
};
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>count;
        for(char task:tasks){
            count[task]++;
        }
        int maxm=0;
        int num=0;
        for(auto& pair:count){
            if(pair.second>maxm){
                maxm = pair.second;
                num=0;
            }
            if(pair.second==maxm)num++;
        }
        int maxmlen= (n+1)*(maxm-1)+num;
        int ans = max(maxmlen,(int)tasks.size());
        return ans;

    }
};
class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<pair<int,int>>items;
        for(int i =0; i<capacity.size();i++){
            items.push_back({capacity[i],rocks[i]});
        }

        sort(items.begin(),items.end(),[](auto &a,auto &b){
            return (a.first-a.second)<(b.first-b.second);
        });
        int maxbag=0;
        int left = additionalRocks;
        for (int i=0;i<capacity.size();i++){
            if(items[i].first-items[i].second!=0 &&items[i].first-items[i].second<=left){
                left = left - (items[i].first-items[i].second);
                maxbag++;
            }
            else if (items[i].first-items[i].second==0){
                maxbag++;
            }
        }
        return maxbag;

    }
};
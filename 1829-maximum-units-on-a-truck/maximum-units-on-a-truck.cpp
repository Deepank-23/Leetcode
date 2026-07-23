class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {

        sort(boxTypes.begin(),boxTypes.end(),[](auto &a,auto&b){
            return (double)a[1]>(double)b[1];
        });
        int units=0;
        int boxes=truckSize;
        for(int i=0;i<boxTypes.size();i++){
            if(boxTypes[i][0]<=boxes){
                units+=boxTypes[i][1]*boxTypes[i][0];
                boxes-=boxTypes[i][0];
            }
            else if(boxes!=0){
                units+=boxTypes[i][1]*boxes;
                boxes=0;
            }
        }
        return units;
        
    }
};
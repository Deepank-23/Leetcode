class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end(),[](int a ,int b){
            return a<b;
        });

        int sum = coins;
        int max=0;
        for(int i =0;i<costs.size();i++){
            if(sum>=costs[i]){
                sum=sum-costs[i];
                max++;
            }
            else break;
   
        }
        return max;

        
    
    }
};
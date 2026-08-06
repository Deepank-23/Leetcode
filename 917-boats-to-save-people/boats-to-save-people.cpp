class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int boats=0;
        int sum=limit;
        int n = people.size();
        int left =0;
        int right =n-1;
        sort(people.begin(),people.end(),[](int a,int b){
            return abs(a)>abs(b);
        });
        while(left<=right){
            if(left==right){
                boats++;
                break;
            }
            else if(people[left] + people[right]==sum){
                boats++;
                left++;
                right--;
                continue;
            }
            else if(people[left]+people[right]>sum){
                boats++;
                left++;
            }
            else{
                boats++;
                right--;
                left++;
            }
        }
        return boats;


    }
};
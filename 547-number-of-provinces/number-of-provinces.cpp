class Solution {
    void bfs(vector<vector<int>>&isconnected,vector<int>&isvisited,int node){
        isvisited[node]= true;
        queue<int> q;
        q.push(node);
        while(!q.empty()){
            int curr =  q.front();
            q.pop();
            

            for(int i=0 ; i<isconnected.size();i++){

                if (isconnected[curr][i]==1 && !isvisited[i]){
                isvisited[i]=true;
                q.push(i);
                }
            }
        }
           
       


    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> isvisited(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            if(!isvisited[i]){
                
                bfs(isConnected,isvisited,i);
                count++;
            }
            

        }
        return count;
    }
};
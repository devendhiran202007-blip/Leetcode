class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
            int n=mat.size();
            int m=mat[0].size();
            vector<vector<int>>dp(n,vector<int>(m,-1));
            queue<pair<int,int>>q;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(mat[i][j]==0){
                         dp[i][j]=0;
                         q.push({i,j});
                    }
                }
            }
            vector<vector<int>>dir={{-1,0},{0,-1},{1,0},{0,1}};
            while(!q.empty()){
                  pair<int,int>p=q.front();
                  q.pop();
                  for(int k=0;k<4;k++){
                      int np=p.first+dir[k][0];
                      int nx=p.second+dir[k][1];
                      if(np>=0&&np<n&&nx>=0&&nx<m&&dp[np][nx]==-1){
                          dp[np][nx]=dp[p.first][p.second]+1;
                          q.push({np,nx});
                      }
                  }
            }
            return dp;
    }
};
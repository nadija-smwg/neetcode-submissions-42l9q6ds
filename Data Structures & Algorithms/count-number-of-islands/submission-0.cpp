class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size(), m = grid[0].size();
        int count = 0;
        vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                if (grid[i][j] == '1'){
                    count++;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    grid[i][j] = '0';
            
                    while(!q.empty()) {
                        auto [x,y] = q.front(); q.pop();

                        for(auto d:dir){
                            int H=x+d.first, V=y+d.second;
                            if(H>=0 && V>=0 && H<n && V<m && grid[H][V] == '1'){
                                grid[H][V]='0';
                                q.push({H,V});
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};

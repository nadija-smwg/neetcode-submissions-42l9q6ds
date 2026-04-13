class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int,int>> q;

        // Step 1: push all treasure cells (0)
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0) {
                    q.push({i,j});
                }
            }
        }
        vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        // Step 2: BFS
        while(!q.empty()) {
            auto [x,y] = q.front(); 
            q.pop();

            for(auto d : dir) {
                int nx = x + d.first;
                int ny = y + d.second;

                if(nx >= 0 && ny >= 0 && nx < n && ny < m 
                   && grid[nx][ny] > grid[x][y] + 1) {

                    grid[nx][ny] = grid[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
};
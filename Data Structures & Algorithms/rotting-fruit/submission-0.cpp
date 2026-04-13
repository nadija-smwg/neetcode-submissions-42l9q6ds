class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        queue<pair<int,int>> q;
        int fresh = 0;

        // collect data
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 2) q.push({i,j});
                else if (grid[i][j] == 1) fresh++;
            }
        }

        int time = 0;
        vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

        while (!q.empty()) {
            int size = q.size();
            bool rotted = false;

            for (int i = 0; i < size; i++) {
                auto [x,y] = q.front(); 
                q.pop();

                for (auto d : dir) {
                    int nx = x + d.first;
                    int ny = y + d.second;

                    if (nx < 0 || ny < 0 || nx >= r || ny >= c || grid[nx][ny] != 1)
                        continue;

                    grid[nx][ny] = 2;
                    q.push({nx, ny});
                    fresh--;
                    rotted = true;
                }
            }

            if (rotted) time++;
        }

        return fresh == 0 ? time : -1;
    }
};
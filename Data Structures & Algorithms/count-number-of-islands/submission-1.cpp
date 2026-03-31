// class Solution {
// public:
    // int numIslands(vector<vector<char>>& grid) {

    //     int n = grid.size(), m = grid[0].size();
    //     int count = 0;
    //     vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

    //     for (int i=0;i<n;i++) {
    //         for (int j=0;j<m;j++) {
    //             if (grid[i][j] == '1'){
    //                 count++;
    //                 queue<pair<int,int>> q;
    //                 q.push({i,j});
    //                 grid[i][j] = '0';
            
    //                 while(!q.empty()) {
    //                     auto [x,y] = q.front(); q.pop();

    //                     for(auto d:dir){
    //                         int H=x+d.first, V=y+d.second;
    //                         if(H>=0 && V>=0 && H<n && V<m && grid[H][V] == '1'){
    //                             grid[H][V]='0';
    //                             q.push({H,V});
    //                         }
    //                     }
    //                 }
    //             }
    //         }
    //     }
    //     return count;
    // }


class Solution {
public:
    int n, m;

    void dfs(int i, int j, vector<vector<char>>& grid) {
        stack<pair<int,int>> st;
        st.push({i,j});

        while(!st.empty()) {
            auto [x,y] = st.top(); 
            st.pop();

            // boundary + water check
            if(x < 0 || y < 0 || x >= n || y >= m || grid[x][y] == '0')
                continue;

            grid[x][y] = '0'; // mark visited

            // push neighbors
            st.push({x+1, y});
            st.push({x-1, y});
            st.push({x, y+1});
            st.push({x, y-1});
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();

        int count = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '1') {
                    count++;        // new island
                    dfs(i, j, grid); // remove island
                }
            }
        }

        return count;
    }
};



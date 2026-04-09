class Solution {
public:
    int n,m,max_area=0;

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        for (int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    max_area = max(max_area,dfs(grid,i,j));
                }
            }
        }
        return max_area;
    }
    int dfs(vector<vector<int>>& grid, int i, int j) {
        stack<pair<int, int>> st;
        st.push({i,j});
        int size = 0;
        while(!st.empty()){
            auto [x,y] = st.top();
            st.pop();
            
            if (x<0 || y<0 || x >= n || y>=m || grid[x][y] == 0)
                continue;
            
            grid[x][y] = 0;
            size++;

            st.push({x+1,y});
            st.push({x-1,y});
            st.push({x,y+1});
            st.push({x,y-1});
        }
        return size;
    }
};

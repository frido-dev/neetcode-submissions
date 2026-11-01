class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<int, int>> q;

        for (int j = 0; j<m; j++) {
            if (board[0][j] == 'O') {
                q.push({0, j});
                vis[0][j] = true;
            }
        }

        for (int j = 0; j<m; j++) {
            if(board[n-1][j] == 'O') {
                q.push({n-1, j});
                vis[n-1][j] = true;
            }
        }

        for (int i = 1; i<n-1; i++) {
            if(board[i][0] == 'O') {
                q.push({i, 0});
                vis[i][0] = true;
            }
        }

        for (int i = 1; i<n-1; i++) {
            if (board[i][m-1] == 'O') {
                q.push({i, m-1});
                vis[i][m-1] = true;
            }
        }

        while(q.size() > 0) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            if (i-1 >= 0 && board[i-1][j] == 'O' && !vis[i-1][j]) {
                q.push({i-1, j});
                vis[i-1][j] = true;
            }

            if (i+1 < n && board[i+1][j] == 'O' && !vis[i+1][j]) {
                q.push({i+1, j});
                vis[i+1][j] = true;
            }

            if (j-1 >= 0 && board[i][j-1] == 'O' && !vis[i][j-1]) {
                q.push({i, j-1});
                vis[i][j-1] = true;
            }

            if (j+1 < m && board[i][j+1] == 'O' && !vis[i][j+1]) {
                q.push({i, j+1});
                vis[i][j+1] = true;
            }
        }

        for (int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if (vis[i][j]) {
                    board[i][j] = 'O';
                } else {
                    board[i][j] = 'X';
                }
            }
        }
    }
};

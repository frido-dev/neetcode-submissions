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
            }
        }

        for (int j = 0; j<m; j++) {
            if(board[n-1][j] == 'O') {
                q.push({n-1, j});
            }
        }

        for (int i = 1; i<n-1; i++) {
            if(board[i][0] == 'O') {
                q.push({i, 0});
            }
        }

        for (int i = 1; i<n-1; i++) {
            if (board[i][m-1] == 'O') {
                q.push({i, m-1});
            }
        }

        while(q.size() > 0) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            vis[i][j] = true;

            if (i-1 >= 0 && board[i-1][j] == 'O' && !vis[i-1][j]) {
                q.push({i-1, j});
            }

            if (i+1 < n && board[i+1][j] == 'O' && !vis[i+1][j]) {
                q.push({i+1, j});
            }

            if (j-1 >= 0 && board[i][j-1] == 'O' && !vis[i][j-1]) {
                q.push({i, j-1});
            }

            if (j+1 < m && board[i][j+1] == 'O' && !vis[i][j+1]) {
                q.push({i, j+1});
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

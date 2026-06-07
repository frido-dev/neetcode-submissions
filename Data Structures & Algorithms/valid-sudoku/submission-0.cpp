class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // each rows
        for (int i = 0; i < 9; i++) {
            unordered_set<char> st;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;

                if (st.find(board[i][j]) != st.end()) {
                    return false;
                } else {
                    st.insert(board[i][j]);
                }
            }
        }

        // each col
          for (int i = 0; i < 9; i++) {
            unordered_set<char> st;
            for (int j = 0; j < 9; j++) {
                if (board[j][i] == '.') continue;

                if (st.find(board[j][i]) != st.end()) {
                    return false;
                } else {
                    st.insert(board[j][i]);
                }
            }
        }

        // each box
        for (int row = 0; row < 9; row+= 3) {
            for (int col = 0; col < 9; col+= 3) {
                unordered_set<char> st;

                for (int i = row; i < row + 3; i++) {
                    for (int j = col; j < col + 3; j++) {
                        if (board[i][j] == '.') continue;

                        if (st.find(board[i][j]) != st.end()) {
                            return false;
                        } else {
                            st.insert(board[i][j]);
                        }
                    }
                }
            }
        }

        return true;
    }
};

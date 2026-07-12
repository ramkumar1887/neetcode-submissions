class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<char> r, c, b;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    for(int k=0;k<r.size();k++){
                        if(board[i][j]==r[k]){
                            return false;
                        }
                    }
                    r.push_back(board[i][j]);
                }
                if(board[j][i]!='.'){
                    for(int k=0;k<c.size();k++){
                        if(board[j][i]==c[k]){
                            return false;
                        }
                    }
                    c.push_back(board[j][i]);
                }
            }
            r.clear();
            c.clear();
        }
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                for(int l=0;l<3;l++){
                    for(int m=0;m<3;m++){
                        if(board[i+l][j+m]!='.'){
                            for(int k=0;k<r.size();k++){
                                if(board[i+l][j+m]==r[k]){
                                    return false;
                                }
                            }
                            r.push_back(board[i+l][j+m]);
                        }
                    }
                }
                r.clear();
            }
        }
        return true;
    }
};

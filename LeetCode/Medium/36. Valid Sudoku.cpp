class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //check boxes
        char c='.';
        for(int i=0;i<board.size()-2;i+=3){
            for(int j=0;j<board[0].size()-2;j+=3){
                vector<bool> nums(10);
                for(int z=0;z<3;z++){
                    for(int w=0;w<3;w++){
                        if(board[i+z][j+w]==c)continue;
                        if(nums[board[i+z][j+w]-'0'])return false;
                        nums[board[i+z][j+w]-'0']=true;
                    }
                }
            }
        }
        //check rows
        for(int i=0;i<board.size();i++){
            vector<bool> nums(10);
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==c)continue;
                if(nums[board[i][j]-'0'])return false;
                nums[board[i][j]-'0']=true;
            }
        }
        for(int i=0;i<board.size();i++){
            vector<bool> nums(10);
            for(int j=0;j<board[0].size();j++){
                if(board[j][i]==c)continue;
                if(nums[board[j][i]-'0'])return false;
                nums[board[j][i]-'0']=true;
            }
        }
        return true;
    }
};
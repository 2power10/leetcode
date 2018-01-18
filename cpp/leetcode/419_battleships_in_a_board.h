#ifndef battleships_in_a_board_h
#define battleships_in_a_board_h

#include <vector>

using namespace std;

class Solution {
public:
    int countBattleships(vector<vector<char> >& board) {
        if (board.empty()) return 0;
        int row = board.size();
        int column = board[0].size();

        int ver_battle = 0, hor_battle = 0;
        for (int i = 0 ; i < row ; ++i) {
            bool onBattle = false;
            for (int j = 0 ; j < column ; ++j) {
                if (board[i][j] == 'X') {
                    if (!onBattle) {
                         hor_battle++;
                         onBattle = true;
                    }
                }
                else    onBattle = false;
            }
        }

        for (int i = 0 ; i < column ; ++i) {
            bool onBattle = false;
            for (int j = 0 ; j < row; ++j) {
                if (board[j][i] == 'X') {
                    hor_battle--;
                    if (!onBattle) {
                        ver_battle++;
                        onBattle = true;
                    }
                }
                else    onBattle = false;
            }
        }
        return ver_battle + hor_battle;
    }
};

void Test()
{
    Solution s;
    vector<vector<char> > board = {
        vector<char>{'X', '.', '.', '.', 'X'},
        vector<char>{'.', 'X', '.', '.', 'X'},
        vector<char>{'.', '.', 'X', '.', 'X'},
        vector<char>{'.', '.', 'X', '.', 'X'},
    };
    int sc = s.countBattleships(board);
    cout << sc << " == 4\n";
    
    vector<vector<char> > board2 = {
        vector<char>{'.', '.', '.', '.', '.'},
        vector<char>{'.', '.', '.', '.', '.'},
        vector<char>{'.', '.', '.', '.', '.'},
        vector<char>{'.', '.', '.', '.', '.'},
    };
    sc = s.countBattleships(board2);
    cout << sc << " == 0\n";
    
    vector<vector<char> > board3 = {
        vector<char>{'.', 'X', '.', '.', '.'},
        vector<char>{'X', '.', 'X', 'X', 'X'},
        vector<char>{'X', '.', '.', '.', '.'},
        vector<char>{'.', 'X', 'X', '.', 'X'},
    };
    sc = s.countBattleships(board3);
    cout << sc << " == 5\n";
}

#endif

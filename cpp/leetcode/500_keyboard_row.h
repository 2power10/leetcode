
constexpr const int ROW1 = 1;
constexpr const int ROW2 = 2;
constexpr const int ROW3 = 4;

map<char, int> row_map = {
    {'q',ROW1}, {'w',ROW1}, {'e',ROW1}, {'r',ROW1}, {'t',ROW1}, {'y',ROW1}, {'u', ROW1}, {'i',ROW1}, {'o',ROW1}, {'p',ROW1},
    {'Q',ROW1}, {'W',ROW1}, {'E',ROW1}, {'R',ROW1}, {'T',ROW1}, {'Y',ROW1}, {'U', ROW1}, {'I',ROW1}, {'O',ROW1}, {'P',ROW1},
    {'a',ROW2}, {'s',ROW2}, {'d',ROW2}, {'f',ROW2}, {'g',ROW2}, {'h',ROW2}, {'j', ROW2}, {'k',ROW2}, {'l',ROW2},
    {'A',ROW2}, {'S',ROW2}, {'D',ROW2}, {'F',ROW2}, {'G',ROW2}, {'H',ROW2}, {'J', ROW2}, {'K',ROW2}, {'L',ROW2},
    {'z',ROW3}, {'x',ROW3}, {'c',ROW3}, {'v',ROW3}, {'b',ROW3}, {'n',ROW3}, {'m', ROW3},
    {'Z',ROW3}, {'X',ROW3}, {'C',ROW3}, {'V',ROW3}, {'B',ROW3}, {'N',ROW3}, {'M', ROW3}
};

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> result;
        for (const auto &word : words)
        {
            int row = 0;
            for (int i = 0 ; i < word.size(); ++i)
            {
                int rowOfChar = row_map[word[i]];
                row = row | rowOfChar;
                if ((row ^ rowOfChar) != 0)
                {
                    row = -1;
                    break;
                }
            }
            if (row != -1)  result.push_back(word);
        }
        return result;
    }
};

void Test()
{
    Solution s;
    vector<string> input = {"Hello", "Alaska", "Dad", "Peace"};
    auto result = s.findWords(input);
}

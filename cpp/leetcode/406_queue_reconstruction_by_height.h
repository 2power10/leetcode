
class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        list<pair<int, int>> result;
        sort(people.begin(), people.end(), [](const pair<int, int> &lhs, const pair<int, int> &rhs){
            return lhs.second < rhs.second || (lhs.second == rhs.second && lhs.first < rhs.first);
        });
        for (int i = 0 ; i < people.size() ; i ++)
        {
            if (people[i].second == 0)
            {
                result.push_back(people[i]);
            }
            else break;
        }
        
        sort(people.begin(), people.end(), [](const pair<int, int> &lhs, const pair<int, int> &rhs){
            return lhs.first > rhs.first || (lhs.first == rhs.first && lhs.second < rhs.second);
        });
        
        for (int i = 0 ; i < people.size() ; i ++)
        {
            if (people[i].second != 0)
            {
                insertItem(result, people[i]);
            }
        }
        return vector<pair<int, int>>(result.begin(), result.end());
    }
    void insertItem(list<pair<int, int>> & result, pair<int, int> &insertItem)
    {
        list<pair<int, int>>::iterator it = result.begin();
        int count = 0;
        for(; it != result.end(); it++)
        {
            if (count == insertItem.second)
            {
                break;
            }
            if (it->first >= insertItem.first)  count++;
        }
        if (count == insertItem.second)
        {
            result.insert(it, insertItem);
        }
    }
};



void Test()
{
    Solution s;
    vector<vector<pair<int, int>>> testCases =
    {
        {{7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2}},
        {},
        {{40,11},{81,12},{32,60},{36,39},{76,19},{11,37},{67,13},{45,39},{99,0},{35,20},{15,3},{62,13},{90,2},{86,0},{26,13},{68,32},{91,4},{23,24},{73,14},{86,13},{62,6},{36,13},{67,9},{39,57},{15,45},{37,26},{12,88},{30,18},{39,60},{77,2},{24,38},{72,7},{96,1},{29,47},{92,1},{67,28},{54,44},{46,35},{3,85},{27,9},{82,14},{29,17},{80,11},{84,10},{5,59},{82,6},{62,25},{64,29},{88,8},{11,20},{83,0},{94,4},{43,42},{73,9},{57,32},{76,24},{14,67},{86,2},{13,47},{93,1},{95,2},{87,8},{8,78},{58,16},{26,75},{26,15},{24,56},{69,9},{42,22},{70,17},{34,48},{26,39},{22,28},{21,8},{51,44},{35,4},{25,48},{78,18},{29,30},{13,63},{68,8},{21,38},{56,20},{84,14},{56,27},{60,40},{98,0},{63,7},{27,46},{70,13},{29,23},{49,6},{5,64},{67,11},{2,31},{59,8},{93,0},{50,39},{84,6},{19,39}}
    };
    
    for (auto tc : testCases)
    {
//        print(tc);
        auto result = s.reconstructQueue(tc);
//        print(result);
    }
    
    auto emptyVec = vector<pair<int, int>>();
    s.reconstructQueue(emptyVec);
}

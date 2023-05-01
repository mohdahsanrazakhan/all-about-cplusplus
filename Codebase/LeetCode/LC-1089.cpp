// Duplicate Zeros

class Solution
{
public:
    void duplicateZeros(vector<int> &arr)
    {
        vector<int> cpyArr;
        for (auto num : arr)
        {
            if (num == 0)
            {
                if (cpyArr.size() == arr.size())
                    break;
                cpyArr.push_back(num);
                if (cpyArr.size() == arr.size())
                    break;
                cpyArr.push_back(0);
            }
            else
            {
                if (cpyArr.size() == arr.size())
                    break;
                cpyArr.push_back(num);
            }
        }
        arr = cpyArr;
    }
};
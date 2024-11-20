#include <iostream>
#include <vector>
#include <string>
using namespace std;

//class Solution
//{
//public:
//    vector<vector<int>> generate(int numRows)
//    {
//        vector<vector<int>> vv;
//        vv.resize(numRows);
//
//        for (size_t i = 0; i < numRows; ++i)
//        {
//            vv[i].resize(i + 1);
//            vv[i][0] = vv[i][vv[i].size() - 1] = 1;
//        }
//
//        for (size_t i = 0; i < vv.size(); ++i)
//        {
//            for (size_t j = 0; j < vv[i].size(); ++j)
//            {
//                if (vv[i][j] == 0)
//                    vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
//            }
//        }
//
//        return vv;
//    }
//};
//
//int main()  // 杨辉三角
//{
//    vector<vector<int>> retV = Solution().generate(10);
//    for (size_t i = 0; i < retV.size(); ++i)
//    {
//        for (size_t j = 0; j < retV[i].size(); ++j)
//        {
//            cout << retV[i][j] << " ";
//        }
//        cout << endl;
//    }
//
//    return 0;
//}

class Solution
{
    string DigitToLetterArr[10] = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
public:
    void _letterCombinations(const string& digits, size_t i, vector<string>& vs, string tmp)
    {
        if (i == digits.size())
        {
            vs.push_back(tmp);
            return;
        }
        string letter = DigitToLetterArr[digits[i] - '0'];
        for (size_t j = 0; j < letter.size(); ++j)
        {
            _letterCombinations(digits, i + 1, vs, tmp + letter[j]);
        }
    }

    vector<string> letterCombinations(string digits)
    {
        vector<string> vs;
        if (digits.empty())
            return vs;
        _letterCombinations(digits, 0, vs, "");
        return vs;
    }
};

int main()  // 电话号码字母组合
{
    vector<string> retV = Solution().letterCombinations("975");
    for (auto e : retV)
    {
        cout << e << endl;
    }

    return 0;
}
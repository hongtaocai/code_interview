class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
        if (0 == strs.size())
            return "";
            
        string result = strs[0];
        for (int strs_index = 1; strs_index < strs.size(); ++strs_index)
        {
            result = result.substr(0, strs[strs_index].size());
            for (int i = 0; i < result.size(); ++i)
            {
                if (result[i] != strs[strs_index][i])
                {
                    result = result.substr(0, i);
                }
            }
        }
        
        return result;
    }
};
// Leetcode does not provide #include <regex>
class Solution {
public:
    bool isNumber(const char *s) {
        string str(s);
        regex number("^\\s*[+-]?((\\d+(\\.\\d*)?)|(\\.\\d+))([eE][+-]?\\d+)?\\s*$");
        return regex_match(str,number);
    }
};

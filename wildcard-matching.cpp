class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0, j_recall = 0, i_recall = 0;
        while (s[i]){
            if (p[j] == '?' || s[i] == p[j])
            {
                ++i,++j; 
            }
            else if(p[j] == '*') 
            {
                i_recall = i;
                j_recall = ++j;
            }
            else if(j_recall)
            {
                i = ++i_recall; 
                j = j_recall;
            }
            else
            {
                return false;
            }
        }
        while (p[j] == '*') ++j;
        return !p[j];
    }
};
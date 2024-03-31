class Solution {
public:
    int sl, pl; 

    bool isMatch(int si, int pi, string& s, string& p, vector<vector<int>>& dp) {
        if (si >= sl && pi >= pl)
            return true;
        
        if (si < sl && pi >= pl)
            return false;
        
        if (si >= sl && pi < pl) {
            pi++;
            while (pi < pl) {
                if (p[pi] != '*') return false;
                pi += 2;
            }
            if (p[pl - 1] != '*') return false;
            return true;
        }

        if (dp[si][pi] != -1)
            return dp[si][pi];

        if (pi < pl - 1 && p[pi + 1] == '*') {
            bool notUse = isMatch(si, pi + 2, s, p, dp);
            bool use = (s[si] == p[pi] || p[pi] == '.') && isMatch(si + 1, pi, s, p, dp);
            return dp[si][pi] = (notUse || use);
        }
        else if (p[pi] == '.' || s[si] == p[pi]) {
            return dp[si][pi] = isMatch(si + 1, pi + 1, s, p, dp);
        }
        return dp[si][pi] = false;
    }

    bool isMatch(string s, string p) {
        sl = s.length(), pl = p.length();
        vector<vector<int>> dp(sl, vector<int>(pl, -1)); 
        return isMatch(0, 0, s, p, dp); 
    }
};
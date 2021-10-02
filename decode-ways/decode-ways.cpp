class Solution
{
public:
    int numDecodings(string s)
    {
        int n = s.size();
        vector<int> mem(n + 1, -1);
        mem[n] = 1;
        return s.empty() ? 0 : num(0, s, mem);
    }
    int num(int i, string &s, vector<int> &mem)
    {
        if (mem[i] > -1)
            return mem[i];
        if (s[i] == '0')
            return mem[i] = 0;
        int res = num(i + 1, s, mem);
        if (i < s.size() - 1 && (s[i] == '1' || s[i] == '2' && s[i + 1] < '7'))
            res += num(i + 2, s, mem);
        return mem[i] = res;
    }
};
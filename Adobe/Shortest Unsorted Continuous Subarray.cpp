class Solution {
public:
    int findUnsortedSubarray(vector<int>& N) {
        int len = N.size() - 1, left = -1, right = -1,
            maxN = N[0], minN = N[len];
        for (int i = 1; i <= len; i++) {
            int a = N[i], b = N[len-i];
            if (a < maxN) right = i;
            else maxN = a;
            if (b > minN) left = i;
            else minN = b;
        }
        return max(0, left + right - len + 1);
    }
};

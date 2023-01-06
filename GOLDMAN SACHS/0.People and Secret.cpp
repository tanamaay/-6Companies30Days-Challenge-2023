class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        long long sharing = 0, mod = 1000000007;
    deque<int> d{1}, f{1};
    while (--n > 0) {
        if (d.size() >= delay) {
            sharing = (sharing + d.front()) % mod;
            d.pop_front();
        }
        if (f.size() >= forget) {
            sharing = (mod + sharing - f.front()) % mod;
            f.pop_front();
        }
        d.push_back(sharing);
        f.push_back(sharing);
    }
    return accumulate(begin(f), end(f), 0LL) % mod;
    }
};

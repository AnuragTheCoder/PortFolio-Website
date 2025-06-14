#include <bits/stdc++.h>
using namespace std;
class segT
{
    vector<int> seg;

public:
    segT(int n)
    {
        seg.resize(4 * n + 1);
    }
    void build1(int ind, int low, int high, vector<int> arr)
    {
        if (low == high)
        {
            seg[ind] = arr[low];
            return;
        }
        int mid = (low + high) >> 1;
        build1(2 * ind + 1, low, mid, arr);
        build1(2 * ind + 2, mid + 1, high, arr);
        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
    void build2(int ind, int low, int high, vector<int> arr)
    {
        if (low == high)
        {
            seg[ind] = arr[low];
            return;
        }
        int mid = (low + high) >> 1;
        build2(2 * ind + 1, low, mid, arr);
        build2(2 * ind + 2, mid + 1, high, arr);
        seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
    int getMin(int ind, int low, int high, int l, int r)
    {
        if (r < low || high < l)
        {
            return 1e9;
        }
        if (low >= l && high <= r)
        {
            return seg[ind];
        }
        int mid = (low + high) >> 1;
        int left = getMin(2 * ind + 1, low, mid, l, r);
        int right = getMin(2 * ind + 2, mid + 1, high, l, r);
        return min(left, right);
    }
    int getMax(int ind, int low, int high, int l, int r)
    {
        if (r < low || high < l)
        {
            return -1e9;
        }
        if (low >= l && high <= r)
        {
            return seg[ind];
        }
        int mid = (low + high) >> 1;
        int left = getMax(2 * ind + 1, low, mid, l, r);
        int right = getMax(2 * ind + 2, mid + 1, high, l, r);
        return max(left, right);
    }
    void update(int ind, int low, int high, int i, int val, vector<int> arr)
    {
        if (low == high)
        {
            seg[ind] = val;
            return;
        }
        int mid = (low + high) >> 1;
        if (i <= mid)
        {
            update(2 * ind + 1, low, mid, i, val, arr);
        }
        else
        {
            update(2 * ind + 2, mid + 1, high, i, val, arr);
        }
        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
};

class SegT
{
    vector<int> seg;

public:
    SegT(int n)
    {
        seg.resize(4 * n + 1);
    }
    int giveRoot()
    {
        return seg[0];
    }
    void build(int ind, int low, int high, vector<int> &arr, bool flag)
    {
        if (low == high)
        {
            seg[ind] = arr[low];
            return;
        }
        int mid = (low + high) >> 1;
        build(2 * ind + 1, low, mid, arr, !flag);
        build(2 * ind + 2, mid + 1, high, arr, !flag);
        if (flag)
        {
            seg[ind] = seg[2 * ind + 1] ^ seg[2 * ind + 2];
        }
        else
        {
            seg[ind] = seg[2 * ind + 1] | seg[2 * ind + 2];
        }
    }
    void update(int ind, int low, int high, int i, bool flag, int b)
    {
        if (low == high)
        {
            seg[ind] = b;
            return;
        }
        int mid = (low + high) >> 1;
        if (i <= mid)
        {
            update(2 * ind + 1, low, mid, i, !flag, b);
        }
        else
        {
            update(2 * ind + 2, mid + 1, high, i, !flag, b);
        }
        if (flag)
        {
            seg[ind] = seg[2 * ind + 1] ^ seg[2 * ind + 2];
        }
        else
        {
            seg[ind] = seg[2 * ind + 1] | seg[2 * ind + 2];
        }
    }
};

// Main solution function

class Seg1T
{
    vector<int> seg;

public:
    Seg1T(int n)
    {
        seg.resize(4 * n + 1, 0);
    }
    void update1(int ind, int low, int high, int i)
    {
        if (low == high)
        {
            seg[ind] = 1;
            return;
        }
        int mid = (low + high) >> 1;
        if (i <= mid)
        {
            update1(2 * ind + 1, low, mid, i);
        }
        else
        {
            update1(2 * ind + 2, mid + 1, high, i);
        }
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }
    int getQsum1(int ind, int low, int high, int l, int r)
    {
        if (high < l || r < low)
        {
            return 0;
        }
        if (low >= l && high <= r)
        {
            return seg[ind];
        }
        int mid = (low + high) >> 1;
        return getQsum1(2 * ind + 1, low, mid, l, r) + getQsum1(2 * ind + 2, mid + 1, high, l, r);
    }
};

int bs(vector<pair<int, int>> &sv, int el)
{
    int low = 0;
    int high = sv.size() - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        if (sv[mid].first > el)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}
void solvePashMak()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    Seg1T st(n);
    vector<int> fi(n);
    vector<int> fj(n);
    unordered_map<int, int> fi1;
    unordered_map<int, int> fj2;
    vector<pair<int, int>> sv(n);
    for (int i = 0; i < n; i++)
    {
        sv[i] = {v[i], i};
        fi1[v[i]]++;
        fi[i] = fi1[v[i]];
        sv[i] = {fi[i], i};
    }
    unordered_map<int, int> mpp;

    for (int i = n - 1; i >= 0; i--)
    {
        fj2[v[i]]++;
        fj[i] = fj2[v[i]];
    }
    fi1.clear();
    fj2.clear();
    long long cnt = 0;
    sort(sv.begin(), sv.end());
    for (int i = 0; i < n; i++)
    {
        mpp[sv[i].second] = i;
    }
    for (int i = 0; i < n; i++)
    {
        int el = fj[i];
        int idx = bs(sv, el);

        if (idx == -1)
        {
            st.update1(0, 0, n - 1, mpp[i]);
            continue;
        }
        else
        {
            int num = st.getQsum1(0, 0, n - 1, idx, n - 1);
            cnt += num;
        }
        st.update1(0, 0, n - 1, mpp[i]);
    }
    cout << cnt;
}

class ST
{
    vector<int> seg, lazy;

public:
    ST(int n)
    {
        seg.resize(4 * n + 1);
        lazy.resize(4 * n + 1, 0);
    }

    void build(int ind, int low, int high, vector<int> &arr)
    {
        if (low == high)
        {
            seg[ind] = arr[low];
            return;
        }
        int mid = (low + high) >> 1;
        build(2 * ind + 1, low, mid, arr);
        build(2 * +ind + 2, mid + 1, high, arr);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }
    void update(int ind, int low, int high, int l, int r, int val, vector<int> &arr)
    {
        if (lazy[ind] != 0)
        {
            seg[ind] += (high - low + 1) * lazy[ind];
            if (low != high)
            {
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }
            lazy[ind] = 0;
        }
        if (r < low || l > high)
        {
            return;
        }

        if (low >= l && high <= r)
        {
            seg[ind] += (high - low + 1) * val;
            if (low != high)
            {
                lazy[2 * ind + 1] += val;
                lazy[2 * ind + 2] += val;
            }
            return;
        }
        int mid = (low + high) >> 1;
        update(2 * ind + 1, low, mid, l, r, val, arr);
        update(2 * ind + 2, mid + 1, high, l, r, val, arr);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }
    int query(int ind, int low, int high, int l, int r)
    {
        if (lazy[ind] != 0)
        {
            seg[ind] += (high - low + 1) * lazy[ind];
            if (low != high)
            {
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }
            lazy[ind] = 0;
        }
        if (high < l || r < low)
        {
            return 0;
        }
        if (low >= l && high <= r)
        {
            return seg[ind];
        }
        int mid = (low + high) >> 1;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);
        return left + right;
    }
};

class ST1
{
    vector<int> seg, lazy;

public:
    ST1(int n)
    {
        seg.resize(4 * n + 1);
        lazy.resize(4 * n + 1, 0);
    }

    void build(int ind, int low, int high, vector<int> &arr)
    {
        if (low == high)
        {
            seg[ind] = arr[low];
            return;
        }
        int mid = (low + high) >> 1;
        build(2 * ind + 1, low, mid, arr);
        build(2 * +ind + 2, mid + 1, high, arr);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }
    void update(int ind, int low, int high, int l, int r, int val, vector<int> &arr)
    {
        if (lazy[ind] != 0)
        {
            seg[ind] = (high - low + 1) - seg[ind];
            if (low != high)
            {
                lazy[2 * ind + 1] = !lazy[ind];
                lazy[2 * ind + 2] = !lazy[ind];
            }
            lazy[ind] = 0;
        }
        if (r < low || l > high)
        {
            return;
        }

        if (low >= l && high <= r)
        {
            seg[ind] = (high - low + 1) - seg[ind];
            if (low != high)
            {
                lazy[2 * ind + 1] = !lazy[ind];
                lazy[2 * ind + 2] = !lazy[ind];
            }
            return;
        }
        int mid = (low + high) >> 1;
        update(2 * ind + 1, low, mid, l, r, val, arr);
        update(2 * ind + 2, mid + 1, high, l, r, val, arr);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }
    int query(int ind, int low, int high, int l, int r)
    {
        if (lazy[ind] != 0)
        {
            seg[ind] = (high - low + 1) - seg[ind];
            if (low != high)
            {
                lazy[2 * ind + 1] = !lazy[ind];
                lazy[2 * ind + 2] = !lazy[ind];
            }
            lazy[ind] = 0;
        }
        if (high < l || r < low)
        {
            return 0;
        }
        if (low >= l && high <= r)
        {
            return seg[ind];
        }
        int mid = (low + high) >> 1;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);
        return left + right;
    }
};

void solve3()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ST st(n);
    st.build(0, 0, n - 1, arr);
    int q;
    cin >> q;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int l, r;
            cin >> l >> r;
            cout << st.query(0, 0, n - 1, l, r) << endl;
        }
        else
        {
            int l, r, val;
            cin >> l >> r >> val;
            st.update(0, 0, n - 1, l, r, val, arr);
        }
    }
}

void solve2()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<int> sv(v.begin(), v.end());

    sort(sv.begin(), sv.end());
    vector<int> newsv(sv.begin(), sv.end());

    reverse(sv.begin(), sv.end());
    unordered_map<int, int> mp1;
    for (int i = 0; i < sv.size(); i++)
    {
        mp1[sv[i]] = i;
    }
    vector<int> newvec(v.begin(), v.end());
    reverse(newvec.begin(), newvec.end());
    unordered_map<int, int> mp2;
    for (int i = 0; i < newsv.size(); i++)
    {
        mp2[newsv[i]] = i;
    }
    Seg1T seg1(n);
    Seg1T seg2(n);
    unordered_map<int, int> mp3;
    for (int i = 0; i < newvec.size(); i++)
    {
        int l1 = 0;
        int r1 = mp2[newvec[i]];
        int big = seg2.getQsum1(0, 0, n - 1, l1, r1 - 1);
        seg2.update1(0, 0, n - 1, mp2[newvec[i]]);
        mp3[newvec[i]] = big;
    }
    long long cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int l1 = 0;
        int r1 = mp1[v[i]];
        int getSmaller = seg1.getQsum1(0, 0, n - 1, l1, r1 - 1);
        // cout << " this is " << getSmaller << endl;

        seg1.update1(0, 0, n - 1, mp1[v[i]]);

        cnt += (long long)(getSmaller)*mp3[v[i]];
    }
    cout << cnt << endl;
}

int getCount(int num)
{
    for (int i = 31; i >= 0; i--)
    {
        if (num & (1 << i))
        {
            return (i + 1);
        }
    }
    return 0;
}
const int mod = 1000000007;
void solveInfiniteSet()
{
    int n, p;
    cin >> n >> p;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    map<int, int> present;

    vector<int> v;

    // removing useless elements

    for (int i = 0; i < n; i++)
    {
        bool useless = false;
        int temp = a[i];

        while (temp > 0)
        {
            if (temp % 2 == 1)
            {
                // if temp is odd , it means it is 2*x + 1 case
                temp /= 2;
            }
            else
            {
                // now if temp has been generated from someone then it has to be multiple of 4

                if (temp % 4)
                    break;
                temp /= 4;
            }

            // if curr temp is already present then it means a[i] is useless

            if (present[temp])
            {
                useless = true;
                break;
            }
        }

        if (!useless)
        {
            v.push_back(a[i]);
            present[a[i]] = 1;
        }
    }

    vector<int> dp(p + 5);

    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i < p + 5; i++)
        dp[i] = (dp[i - 1] + dp[i - 2]) % mod;

    vector<int> pref(p + 5);

    pref[0] = dp[0];

    for (int i = 1; i < p + 5; i++)
        pref[i] = (pref[i - 1] + dp[i]) % mod;

    /*
    for(int i = 0 ; i < p + 5 ; i++)
        dbg(i , dp[i]);
        */

    int ans = 0;

    for (auto x : v)
    {
        int bits = 0;

        while (x > 0)
        {
            bits++;
            x /= 2;
        }

        int rem = p - bits;

        if (rem < 0)
            continue;

        ans = (ans + pref[rem]) % mod;
    }

    cout << ans << endl;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr;
    for (int i = 0; i < (1 << n); i++)
    {
        int el;
        cin >> el;
        arr.push_back(el);
    }
    bool flag = false;
    if (n % 2 == 0)
    {
        flag = true;
    }
    int k = arr.size();
    SegT seg(k);
    seg.build(0, 0, k - 1, arr, flag);

    while (m--)
    {
        int p, b;
        cin >> p >> b;
        seg.update(0, 0, k - 1, p - 1, flag, b);

        cout << seg.giveRoot() << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solveInfiniteSet();
    return 0;
}
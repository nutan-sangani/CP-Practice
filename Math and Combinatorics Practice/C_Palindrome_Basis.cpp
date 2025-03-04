#include <iostream>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define ll long long
#define forLoop for (int i = 0; i < n; i++)
#define pii pair<int, int>
#define pb push_back
#define pll pair<ll, ll>
#define mp make_pair
#define um unordered_map
#define us unordered_set
#define umll unordered_map<ll, ll, custom_hash>
#define omll map<ll, ll>
#define vecll vector<ll>
#define FASTIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define forn(begin, end) for (int i = begin; i < end; ++i)
#define itr(a) a.begin(), a.end()
#define mod 1000000007

using namespace std;
using namespace __gnu_pbds;

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

vector<vector<int>> dp(40001, vector<int>(1099, -1));
vector<int> palindromes;

void buildAllPalindromes()
{
    forn(1, 10)
    { // one & two digit wale
        palindromes.pb(i);
        palindromes.pb(11 * i);
    }
    string s = "000";
    string s1 = "0000";
    forn(1, 10)
    {
        for (int j = 0; j <= 9; j++)
        {
            s[0] = s[2] = ('0' + i);
            s[1] = ('0' + j);
            ll num = stoi(s);
            palindromes.pb(num);
            s1[0] = s1[3] = ('0' + i);
            s1[1] = s1[2] = ('0' + j);
            num = stoi(s1);
            palindromes.pb(num);
        }
    }
    s = "00000";
    forn(1, 10)
    {
        for (int j = 0; j <= 9; j++)
        {
            for (int k = 0; k <= 9; k++)
            {
                s[0] = s[4] = ('0' + i);
                s[1] = s[3] = ('0' + j);
                s[2] = ('0' + k);
                ll num = stoi(s);
                palindromes.pb(num);
            }
        }
    }
}

ll recurse(ll rem, ll index, ll n)
{
    if (rem == 0)
        return 1;
    else if (index >= n)
        return 0;
    else if (rem < 0)
        return 0;
    else if (rem < palindromes[index])
        return 0;
    else if (dp[rem][index] != -1)
        return dp[rem][index];
    ll ways = 0;
    ways = recurse(rem, index + 1, n);
    ways %= mod;
    ways += recurse(rem - palindromes[index], index, n);
    ways %= mod;
    return dp[rem][index] = ways;
}

void solve()
{
    ll n;
    cin >> n;
    cout << recurse(n, 1, 1099) << endl;
}

int main()
{
    FASTIO

    int t;
    cin >> t;
    palindromes.pb(-1);
    buildAllPalindromes();
    sort(itr(palindromes));
    // dp[0]=1;
    // // forn(1,1099) dp[palindromes[i]]=1;
    // for(ll sum = 1;sum<=40000;sum++){
    //     forn(1,1099){ //ye sum banane ke liye sab palin ka use kr
    //         ll needed = sum - palindromes[i];
    //         if(needed<0) break;
    //         dp[sum]+=dp[needed];
    //     }
    // }
    while (t--)
    {
        solve();
    }
    return 0;
}
#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define forLoop for (int i = 0; i < n; i++)
#define pii pair<int, int>
#define pb push_back
#define pll pair<ll, ll>
#define mp make_pair
#define um unordered_map
#define us unordered_set
#define umll unordered_map<ll, ll>
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

// use 1LL always while doing bit operations.

void solve()
{
    ll firstSetBitInR = -1;
    ll firstSetBitInB = -1;
    ll a, b, r;
    cin >> a >> b >> r;
    if (a > b)
    {
        ll temp = a;
        a = b;
        b = temp;
    }
    if (a == b)
    {
        cout << 0 << endl;
        return;
    }
    forn(0, 63)
    {
        if (r & 1LL << i)
        {
            firstSetBitInR = i;
        }
        if ((b & 1LL << i) != (a & 1LL<<i))
        {
            firstSetBitInB = i;
        }
    }
    ll i = min<ll>(firstSetBitInB-1,firstSetBitInR);
    bool canDoAnything = false;
    ll ans = 0;
    if(i<firstSetBitInR){
        canDoAnything = true;
    }
    while (i >= 0)
    {
        bool isASet = a & 1LL << i;
        bool isBSet = b & 1LL << i;
        bool isRSet = r & 1LL << i;
        if(isASet==isBSet){
            if(isRSet){
                canDoAnything=true;
            }
        }
        else{
            if(isASet && !isBSet){ //(1,0)
                if(isRSet){
                    canDoAnything=true;
                }
            }
            else{
                if(isRSet || canDoAnything){
                    ans = ans | 1LL<<i;
                }
            }
        }
        i--;
    }
    cout<<abs((a ^ ans) - (b^ans))<<endl;
}

int main()
{
    FASTIO

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
//101000110100001100101110001100110010101101010101010010111100
//110010111000110110011001001100000111001110101010101000010011
//r
//110001101100001101101001000001111011110101011101111000000111
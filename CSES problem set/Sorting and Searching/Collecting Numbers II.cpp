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
class MyComp
{
public:
    bool operator()(const pll &a, const pll &b)
    {
        if (a.first != b.first)
            return a.first < b.first;
        else
            return a.second < b.second;
    }
};
ll calculatePenaltyForBeingUnordered(ll num, vector<pll> &data)
{
    int n = data.size();
    ll prev = (num - 1) >= 0 ? data[num - 1].second : -1;
    ll next = (num + 1) < n ? data[num + 1].second : LLONG_MAX;
    ll curr = data[num].second;
    return ((prev < curr ? 0 : 1) + (next > curr ? 0 : 1));
}
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<pll> a;
    a.pb(mp(-1, -1));
    umll numberAtIndex;
    forn(0, n)
    {
        ll k;
        cin >> k;
        a.pb(mp(k, (i + 1)));
        numberAtIndex[i + 1] = k;
    }
    sort(itr(a), MyComp());
    ll prev = -1;
    ll count = 1;
    forn(1, n + 1)
    {
        if (prev > a[i].second)
        {
            ++count;
        }
        prev = a[i].second;
    }
    forn(0, m)
    {
        ll index1, index2;
        cin >> index1 >> index2;
        if (index1 == index2)
        { // nothing swapped
            cout << count << endl;
            continue;
        }
        if (index1 > index2)
        { // index should only be increasing
            ll temp = index1;
            index1 = index2;
            index2 = temp;
        }
        ll num1, num2;
        num1 = numberAtIndex[index1];
        num2 = numberAtIndex[index2];

        numberAtIndex[index1] = num2;
        numberAtIndex[index2] = num1;
        ll penaltyBeforeSwapOfNum1, penaltyBeforeSwapOfNum2;
        penaltyBeforeSwapOfNum1 = calculatePenaltyForBeingUnordered(num1, a);
        penaltyBeforeSwapOfNum2 = calculatePenaltyForBeingUnordered(num2, a);
        if ((num2 + 1) == num1)
        { // decreasing 1 penalty if both are neighbors since wo 2 bar count hua
            penaltyBeforeSwapOfNum1 -= 1;
        }
        a[num1].second = index2;
        a[num2].second = index1;

        ll penaltyAfterSwapOfNum1, penaltyAfterSwapofNum2;
        penaltyAfterSwapOfNum1 = calculatePenaltyForBeingUnordered(num1, a);
        penaltyAfterSwapofNum2 = calculatePenaltyForBeingUnordered(num2, a);
        if ((num1 + 1) == num2)
        { // decreasing 1 penalty if both are neighbors since wo 2 bar count hua
            penaltyAfterSwapOfNum1 -= 1;
        }
        ll d1, d2;
        d1 = penaltyAfterSwapOfNum1 - penaltyBeforeSwapOfNum1;
        d2 = penaltyAfterSwapofNum2 - penaltyBeforeSwapOfNum2;
        count += (d1 + d2);
        cout << count << endl;
    }
}
int main()
{
    FASTIO
    {
        solve();
    }
    return 0;
}
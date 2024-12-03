#include <iostream>
#include<bits/stdc++.h>
#define ll long long
#define forLoop for(int i=0;i<n;i++)
#define pii pair<int,int>
#define pb push_back
#define pll pair<ll,ll>
#define mp make_pair
#define um unordered_map
#define us unordered_set
#define umll unordered_map<ll,ll>
#define omll map<ll,ll>
#define vecll vector<ll>
#define FASTIO  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mod 998244353

using namespace std;

ll binarySearch(ll low,ll high,ll multiple,ll a,ll b){
    while(low<=high){
        ll mid = (high+low)/2;
        ll end = (a+mid)*multiple;
        if(end==b){
            return mid;
        }
        else if(end<b){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return high;
}

void helper(ll a,ll b)
{
    ll length=0;
    ll count=0;
    ll factorPossible = b/a;
    ll closestPowerOf2 = log2(factorPossible);
    length=closestPowerOf2+1;
    if(length==1){
        cout<<length<<" "<<b-a+1<<endl;
        return;
    }
    ll targetMultipleOf2 = pow(2,closestPowerOf2);
    count=1;
    count+=binarySearch(0,b,targetMultipleOf2,a,b);  
    count%=mod;
    ll targetMultipleWith3 = (targetMultipleOf2/2)*3;
    ll temp = binarySearch(0,b,targetMultipleWith3,a,b);
    // cout<<temp<<endl;
    if(temp>=0){
        temp++;
        count+=(temp*(length-1)*1LL);
        count%=mod;
    }
    cout<<length<<" "<<count<<endl;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        ll a,b;
        cin>>a>>b;
        helper(a,b);
    }
    return 0;
}

























// 1 1
// 2 1
// 1 1
// 2 2
// 1 2
// 1 1
// 3 1
// 2 1
// 1 2
// 1 1
// 3 1
// 2 1
// 1 3
// 1 2
// 1 1
// 3 3
// 2 3
// 2 1
// 1 3
// 1 2
// 1 1
// 3 3
// 2 3
// 2 1
// 1 4
// 1 3
// 1 2
// 1 1
// 4 1
// 3 1
// 2 2
// 2 1
// 1 4
// 1 3
// 1 2
// 1 1
// 4 1
// 3 1
// 2 3
// 2 1
// 1 5
// 1 4
// 1 3
// 1 2
// 1 1
// 4 1
// 3 1
// 2 4
// 2 2
// 2 1
// 1 5
// 1 4
// 1 3
// 1 2
// 1 1
// 4 1
// 3 1
// 2 4
// 2 2
// 2 1
// 1 6
// 1 5
// 1 4
// 1 3
// 1 2
// 1 1
// 4 4
// 3 4
// 3 1
// 2 4
// 2 2
// 2 1
// 1 6
// 1 5
// 1 4
// 1 3
// 1 2
// 1 1
// 4 4
// 3 4
// 3 1
// 2 4
// 2 2
// 2 1
// 1 7
// 1 6
// 1 5
// 1 4
// 1 3
// 1 2

// 1 1
// 1 2
// 2 2
// 1 3
// 2 3
// 3 3
// 1 4
// 2 4
// 3 4
// 4 4
// 1 5
// 2 5
// 3 5
// 4 5
// 5 5
// 1 6
// 2 6
// 3 6
// 4 6
// 5 6
// 6 6
// 1 7
// 2 7
// 3 7
// 4 7
// 5 7
// 6 7
// 7 7
// 1 8
// 2 8
// 3 8
// 4 8
// 5 8
// 6 8
// 7 8
// 8 8
// 1 9
// 2 9
// 3 9
// 4 9
// 5 9
// 6 9
// 7 9
// 8 9
// 9 9
// 1 10
// 2 10
// 3 10
// 4 10
// 5 10
// 6 10
// 7 10
// 8 10
// 9 10
// 10 10
// 1 11
// 2 11
// 3 11
// 4 11
// 5 11
// 6 11
// 7 11
// 8 11
// 9 11
// 10 11
// 11 11
// 1 12
// 2 12
// 3 12
// 4 12
// 5 12
// 6 12
// 7 12
// 8 12
// 9 12
// 10 12
// 11 12
// 12 12
// 1 13
// 2 13
// 3 13
// 4 13
// 5 13
// 6 13
// 7 13
// 8 13
// 9 13
// 10 13
// 11 13
// 12 13
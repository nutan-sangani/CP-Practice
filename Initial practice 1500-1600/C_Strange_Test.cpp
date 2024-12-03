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

using namespace std;

ll findBDash(ll aDash,ll b){
    ll bDash=0;
    for(int i=35;i>=0;i--){
        bool aBit = (aDash & 1LL<<i) > 0 ? true : false;
        bool bBit = (b & 1LL<<i) > 0 ? true : false;
        if(aBit && !bBit){
            bDash = bDash | 1LL<<i;
            return bDash;
        }
        bDash = bDash | (b & 1LL<<i);
    }
    return bDash;
}

void helper(ll a,ll b)
{
    ll mini = b-a;
    mini = min<ll>((a|b)-b+1,mini);
    //find a' such that a'+(a'|b') +(1-a-b) is maximized
    //a' = a+something, isme atmost b tak add krsakte h
    //b' can be made with zero addition or a' me highest position jaha 1,0 h in a',b.
    for(int additive=0;(a+additive)<=b;additive++){
        ll aDash = a+additive;
        ll bDash = findBDash(aDash,b);
        mini=min<ll>(mini,(aDash+(aDash | bDash)+(1-a-b)));
    }
    cout<<mini<<endl;
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
//2,5
//a = 010
//b = 101 -> 110
//110



//0001101110101100110 -- a = 56678
//0101000001001000110 -- b = 164422
//6,9,11,12,13,15


//0101101111101100110 -- or= 188262
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
#define forn(begin,end) for(int i=begin;i<end;++i)
#define itr(a) a.begin(),a.end()
#define mod 1000000007

using namespace std;

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll total = (n*(n+1)*1LL)/2LL;
        vecll map(2*n,0); //iske badle umll or omll use kiya toh tle, thus ye bhi ek soln hosakta if tle arha toh
        int limit = sqrt(2*n);
        //this is the limit since maximum xor for no. btw 1 to n can be leftmost digit jo n me active h, waha se sab digits
        //thus 2 se multiply kiya, to leftmost 1 position shift hojata, thus wo iss max se bada hi hojata.

        //yaad rakh, 1 to n ka max xor is not n, but <2*n.
        int runningXor = 0;
        map[0]=1;
        forn(0,n){
            ll a;
            cin>>a;
            runningXor^=a;
            for(int j=0;j<=limit;j++){
                int target = j*j;
                target^=runningXor;
                if(target<2*n)
                    total -= map[target];
            }
            map[runningXor]++;
        }
        cout<<total<<endl;
    }
    return 0;
}
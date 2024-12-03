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
#define mod 998244353


using namespace std;

class Node{
    public:
    ll zeroCount;
    ll count;
    ll index;

    Node(ll zero,ll count,ll index){
        this->zeroCount=zero;
        this->index=index;
        this->count=count;
    }
};

ll getSum(ll n){
    if(n%2==0) return ((n/2)*(n+1))%mod;
    return  (((n+1)/2)*n)%mod;
}

void solve()
{
    int n;
    cin>>n;
    vecll a(n,0);
    forn(0,n){
        cin>>a[i];
    }
    ll ans=0;
    forn(0,35){
        vector<Node> temp;
        ll sum=0;
        for(int j=0;j<n;j++){ //looping through a_j
            bool isPresent = a[j] & 1LL<<i;
            if(isPresent){
                ll prev = -1;
                if(temp.size()>=1){
                    prev=temp[temp.size()-1].index;
                }
                ll length = j - prev;
                if(temp.size()<=1){
                    ll count = getSum(length);
                    count%=mod;
                    ll zeroCount = length;
                    Node nn(zeroCount,count,j);
                    temp.pb(nn);
                    sum+=count;
                    sum%=mod;
                    continue;
                }
                //else wo 3rd ya uske baad wala elem h.
                int pIdx = temp.size()-1;
                ll nLength = j - temp[pIdx-1].index;
                ll count = getSum(length) + 1LL*nLength*temp[pIdx-1].zeroCount + temp[pIdx-1].count;
                count%=mod;
                ll zeroCount = length+temp[pIdx-1].zeroCount;
                sum+=count;
                sum%=mod;
                Node nn(zeroCount,count,j);
                temp.pb(nn);
            }
            else{
                if(temp.size()==0) continue;
                else{
                    int prevIndex = temp.size()-1;
                    Node top = temp[prevIndex];
                    ll count = top.count;
                    ll length = j - top.index;
                    count+=length*top.zeroCount;
                    count%=mod;
                    sum+=count;
                    sum%=mod;
                }
            }
        }
        sum%=mod;
        ll power = pow(2,i);
        power%=mod;
        sum*=power;
        sum%=mod;
        ans+=sum;
        ans%=mod;
        // if(i==2){
        //     for(Node n : temp){
        //         cout<<n.count<<" "<<n.zeroCount<<" "<<n.index<<endl;
        //     }
        // }
        // if(sum!=0){
        //     cout<<sum<<endl;
        // }

    }
    cout<<ans<<endl;
}

int main()
{
    FASTIO
    
    // int t;
    // cin>>t;
    // while(t--)
    {
        solve();
    }
    return 0;
}
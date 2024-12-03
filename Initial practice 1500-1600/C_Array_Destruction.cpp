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

vector<pll> finalAns;

void decrement(map<ll,ll,greater<ll>>& count,ll key){
    count[key]--;
    if(count[key]==0)
        count.erase(key);
    return;
}

bool helper(ll x,map<ll,ll,greater<ll>>& count,bool removed,int rem,vector<pll>& ans)
{
    if(rem<=1){
        if(rem==1){
            ans[0].second = (*(count.begin())).first;
        }
        finalAns=ans;
        return true;
    } 
    //else 2 choices h, ki max ko le, ya fhir remove krde aise hi.
    bool choice1,choice2;
    choice1=choice2=false;
    pll pair = (*(count.begin()));
    ll target = x - pair.first;
    decrement(count,pair.first);
    if(count[target]>0){
        decrement(count,target);
        ans.pb(mp(pair.first,target));
        choice1 = helper(pair.first,count,removed,rem-2,ans);
        ans.pop_back();
        count[target]++;
    }
    if(count[target]==0){
        count.erase(target);
    }
    if(choice1) return true;
    if(removed==false){
        ans[0].second=pair.first;
        choice2 = helper(x,count,true,rem-1,ans);
    }
    count[pair.first]++;
    return choice1 | choice2;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    vector<pll> ans1;
    while(t--)
    {
        map<ll,ll,greater<ll>> count;
        int n;
        ans1.resize(0);
        cin>>n;
        vecll a(2*n,0);
        forn(0,2*n){
            cin>>a[i];
            ++count[a[i]];
        }
        pll pairi = *(count.begin());
        decrement(count,pairi.first);
        // cout<<(*(count.begin())).first<<endl;
        // cout<<pairi.first<<endl;
        // cout<<count[2]<<endl;
        ans1.pb(mp(pairi.first,-1));
        bool ans = helper(pairi.first,count,false,2*n-1,ans1);
        if(ans==true){
            cout<<"YES"<<endl;
            cout<<finalAns[0].first+finalAns[0].second<<endl;
            for(pll z : finalAns){
                cout<<z.first<<" "<<z.second<<endl;
            }
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}
//1 1 1
//
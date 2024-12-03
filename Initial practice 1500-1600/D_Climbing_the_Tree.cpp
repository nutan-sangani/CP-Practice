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

bool inRange(ll rangeL,ll rangeR,ll subRangeL,ll subRangeR){
    if(rangeL<=subRangeL && rangeR>=subRangeR) return true;
    return false;
}

ll findTimeToReach(ll height,ll a,ll b){
    ll temp = height - a;
    if(temp<=0) return 1;
    ll diff = a-b;
    ll time = temp/diff;
    ll rem = temp%diff;
    if(rem>0) ++time;
    return time+1;
}

void solve(){
    int q;
    cin>>q;
    ll lowerRange=-1;
    ll upperRange=-1;
    forn(0,q){
        int type;
        cin>>type;
        if(type==1){
            ll a,b,time;
            cin>>a>>b>>time;
            ll lower;
            if(time==1){
                lower=1;
            }
            else lower = (a-b)*(time-2)+a+1; //0+4+1 = 5
            ll upper = (a-b)*(time-1)+a; //2+4 = 6
            if(lowerRange==-1 && upperRange==-1){
                lowerRange=lower;
                upperRange=upper;
                cout<<1<<" ";
            }
            else{
                ll lMax,rMin;
                lMax = max<ll>(lower,lowerRange);
                rMin = min<ll>(upper,upperRange);
                if(inRange(lowerRange,upperRange,lMax,rMin) && inRange(lower,upper,lMax,rMin) && lMax<=rMin){
                    lowerRange=lMax;
                    upperRange=rMin;
                    cout<<1<<" ";
                }
                else{
                    cout<<0<<" ";
                }
            }
        }
        else{
            ll a,b;
            cin>>a>>b;
            if(lowerRange==-1 && upperRange==-1){
                cout<<-1<<" ";
                continue;
            }
            ll time1 = findTimeToReach(lowerRange,a,b);
            ll time2 = findTimeToReach(upperRange,a,b);
            if(time1!=time2){
                cout<<-1<<" ";
            }
            else{
                cout<<time1<<" ";
            }
        }
    }
    cout<<endl;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
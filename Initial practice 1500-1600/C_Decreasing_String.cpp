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

class MyComp{
    public:
    bool operator()(pair<ll,ll> a,pair<ll,ll>b){
        if(a.first!=b.first)
            return a.first < b.first;
        return a.second > b.second;
    }
};

void helper(string s,ll pos)
{
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,MyComp> pq;
    vecll isDeleted(s.size());
    int n=s.size();
    int count=0;
    for(int i=n;i>1;i--){
        if(pos>(i*1LL)){
            pos-=(i*1LL);
            count++;
        }
        else break;
    }
    stack<int> st;
    int i=0;
    while(count>0 && i<n){
        if(!st.empty() && s[st.top()]>s[i]){
            isDeleted[st.top()]=1;
            count--;
            st.pop();
        }
        else{
            st.push(i);
            i++;
        } 
    }
    for(i=0;i<n;i++){
        if(isDeleted[i]==0)
            pq.push(mp(s[i],i));
    }
    while(count>0){
        count--;
        isDeleted[pq.top().second]=1;
        pq.pop();
        count--;
    }
    i=0;
    while(i<n && pos>0LL){
        if(isDeleted[i]==1){
            i++;
            continue;
        }
        else{
            pos-=1LL;
            if(pos<=(0LL)){
                cout<<s[i];
                return;
            }
            i++;
        }
    }
    return;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        ll pos;
        cin>>pos;
        helper(s,pos);
    }
    return 0;
}
//pbdm
//bdtm
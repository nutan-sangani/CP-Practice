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

void helper(string s,int n)
{
    stack<pii> st;
    vecll nums(n);
    forLoop
        nums[i]=(s[i]-'a'+1);
    for(int i=0;i<n;i++){
        if(st.empty()){
            st.push(mp(nums[i],nums[i]));
            continue;
        }
        if(st.top().first==nums[i]+1){
            while(!st.empty() && st.top().first==nums[i]+1) st.pop();
        }
        if(!st.empty() && st.top().second+1==nums[i]){
            int first,second;
            first = st.top().first;
            second = st.top().second;
            st.pop();
            st.push(mp(first,nums[i]));
            continue;
        }
        if(!st.empty() && st.top().first<nums[i] && st.top().second>=nums[i]){
            int first,second;
            first = st.top().first;
            second = st.top().second;
            st.pop();
            st.push(mp(first,nums[i]));
            continue;
        }
        st.push(mp(nums[i],nums[i]));
    }
    cout<<n-st.size()<<endl;
}
//a,c,i,m,r,w,x - problem, since ye x will not be deleted by w
//a
//wzzzzzyzzzzzzyzzzzzzzyzzzzzyzzzzzzyx zzzyzzzzzyzzzzzyzzyzzzzv utqp lkhgeb
int main()
{
    FASTIO
    
    int n;
    cin>>n;
    string s;
    cin>>s;
    helper(s,n);
    return 0;
}
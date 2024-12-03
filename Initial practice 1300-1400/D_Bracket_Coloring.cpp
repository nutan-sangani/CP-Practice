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

bool isUnbalanced(string s,int n){
    int a,b;
    a=b=0;
    forLoop
    {
        if(s[i]=='(') a++;
        else b++;
    }
    return (a!=b);
}

bool isRegular(string s,int n){
    stack<int> st;
    for(int i=0;i<n;i++){
         if(s[i]=='('){
            st.push(i);
        }
        else if(s[i]==')' && !st.empty()){
            st.pop();
        }
        else if(s[i]==')' && st.empty()){
            return false;
        }
    }
    if(!st.empty()) return false;
    return true;
}

void helper(string s,int n)
{
    if(n%2!=0 || isUnbalanced(s,n)){
        cout<<-1<<endl;
        return;
    }
    string copy = s;
    reverse(copy.begin(),copy.end());
    if(isRegular(s,n) || isRegular(copy,n)){
        cout<<1<<endl;
        for(int i=0;i<n;i++){
            cout<<1<<" ";
        }
        cout<<endl;
        return;
    }
    vecll color(n);
    stack<int> st;
    for(int i=0;i<n;i++){
        if(s[i]=='('){
            color[i]=1;
            st.push(i);
        }
        else if(s[i]==')' && !st.empty()){
            st.pop();
            color[i]=1;
        }
    }
    if(!st.empty()){
        while(!st.empty()){
            color[st.top()]=0;
            st.pop();
        }
    }
    for(int i=0;i<n;i++){
        if(color[i]==0){
            color[i]=2;
        }
    }
    int allTwo=1;
    int allOne=1;
    for(int i=0;i<n;i++){
        if(color[i]==1){
            allTwo=0;
            break;
        }
    }
    for(int i=0;i<n;i++){
        if(color[i]==2){
            allOne=0;
            break;
        }
    }
    if(allOne || allTwo){
        cout<<1<<endl;
        for(int i=0;i<n;i++){
            cout<<1<<" ";
        }
        cout<<endl;
    }
    else{
        cout<<2<<endl;
        for(int i=0;i<n;i++){
            cout<<color[i]<<" ";
        }
        cout<<endl;
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
        int n;
        cin>>n;
        string s;
        cin>>s;
        helper(s,n);
    }
    return 0;
}
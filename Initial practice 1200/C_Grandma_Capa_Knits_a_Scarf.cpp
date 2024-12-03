#include <iostream>
#include<bits/stdc++.h>
#define ll long long

using namespace std;

bool isPalindrome(string s,vector<int>& indexes){
    int j = indexes.size()-1;
    int i=0;
    while(i<j){
        if(s[indexes[i]]!=s[indexes[j]]) return 0;
        i++;
        j--;
    }
    return 1;
}

vector<int> getIndexes(string s,char toRemove,int n){
    vector<int> indexes;
    for(int i=0;i<n;i++){
        if(s[i]!=toRemove){
            indexes.push_back(i);
        }
    }
    return indexes;
}

int findNeededRemoval(string s,vector<int>& idx,int n,char toRemove,ll prefixSum[][26]){
    int i,j;
    i=0;
    j=idx.size()-1;
    int sum=0;
    int start,end;
    start=end=0;
    int z=0;
    while(z<n && s[z]==toRemove){
        start++;
        z++;
    }
    z=n-1;
    while(z>=0 && s[z]==toRemove){
        end++;
        z--;
    }
    if(min(start,end)!=n)
        sum+=(min(start,end)*2);
    else sum+=(min(start,end));
    while(i<j){
        ll diffLeft = prefixSum[idx[i+1]][toRemove-'a'] - prefixSum[idx[i]][toRemove-'a'];
        ll diffRight = prefixSum[idx[j]][toRemove-'a'] - prefixSum[idx[j-1]][toRemove-'a'];
        if(i+1==j){
           sum += ((min(diffLeft,diffRight))); 
        }
        else sum += ((min(diffLeft,diffRight))*2);
        i++;
        j--;
    }
    int removed = n - idx.size();
    int updatedRemoved = removed - sum;
    return updatedRemoved;
}

void helper(string s,int n)
{
    if(n==1){
        cout<<0<<endl;
        return;
    }
    int i,j;
    i=0;
    j=n-1;
    int isPalin = 1;
    while(i<j){
        if(s[i]!=s[j]){
            isPalin=0;
            break;
        }
        i++;
        j--;
    }
    if(isPalin){
        cout<<0<<endl;
        return;
    }
    int start,end;
    start=0;
    end=0;
    ll prefixSum[n][26];
    for(i=0;i<n;i++){
        for(j=0;j<26;j++){
            if(s[i]==('a'+j)){
                ll prev = i>0 ? prefixSum[i-1][j] : 0;
                prefixSum[i][j]=prev+1;
            }
            else{
                prefixSum[i][j]= i>0 ? prefixSum[i-1][j] : 0;
            }
        }
    } //now we have prefixsum also
    int mini=INT_MAX; //find mini deletion here
    for(i=0;i<26;i++){ //delete ith alphabet
        vector<int> temp = getIndexes(s,('a'+i),n);
        if(isPalindrome(s,temp)){
            int removals = findNeededRemoval(s,temp,n,('a'+i),prefixSum);
            mini = min(removals,mini);
            // cout<<mini<<" "<<char('a'+i)<<endl;
        }
    }
    if(mini!=INT_MAX)
        cout<<mini<<endl;
    else cout<<-1<<endl;
    return;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        int n;
        cin>>n;
        cin>>s;
        helper(s,n);
    }
    return 0;
}
//20:09

//this is a bad solution, since complex logic, thus bug jyada honge and code krne me time me jyada lagega
//editorial me mast soln diya h, wo dekh.
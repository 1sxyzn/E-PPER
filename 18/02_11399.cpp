#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int solution(int n, vector<int> waiting){
    sort(waiting.begin(), waiting.end());
    int ans=waiting[0];
    for(int i=1; i<n; i++){
        for(int j=0; j<=i; j++){
            ans+=waiting[j];
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> waiting(n,0);
    for(int i=0; i<n; i++)
        cin>>waiting[i];

    cout<<solution(n, waiting);
}

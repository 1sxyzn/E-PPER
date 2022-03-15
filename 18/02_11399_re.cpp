#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//이중 반복문을 쓰지 않고 구현
//시간 복잡도 O(n^2) -> O(n) 
int solution(int n, vector<int> waiting){
    sort(waiting.begin(), waiting.end());
    int ans=0;
    for(int i=0; i<n; i++){
        ans += waiting[i] * (n-i);
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

#include<iostream>

using namespace std;

int solution (int n){
    for(int i=1; i<n; i++){
        int ans = 0;
        int k=i;
        while(k!=0){
            ans +=k%10;
            k/=10;
        }
        ans+=i;
        if(ans==n)
            return i;
    }
    return 0;
}

int main(){
    int n;
    cin>>n;

    cout<<solution(n);
}

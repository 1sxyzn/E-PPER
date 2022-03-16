#include <iostream>
#include <vector>

using namespace std;
const int MOD = 1e6; //모듈러 연산 상수

int solution(string code, int n) {
    int answer;
    vector<long long> dp(n+1,0); //암호가 되는 경우의 수가 아주 클 수 있다고 문제에 명시됨
    if(code[0]=='0') //첫 시작이 0이면 암호가 잘못된 것
        return 0;
    dp[0]=dp[1]=1; //dp[1]이 맨 앞자리 암호이고, 해석할 수 있는 경우의 수는 1개

    for(int i=2; i<=n; i++){
        //code 의 자릿수는 code[0] 부터 시작하지만, dp는 dp[1]부터 시작하므로 code는 i-1(=num)으로, dp는 i로 접근
        int num = i-1;
        if((code[num-1]<'1' || code[num-1]>'2') && code[num]=='0') //10, 20은 가능하지만 00, 30, 40... 등은 불가능
            return 0;
        if(code[num]!='0') // 1~9의 경우 단독으로 A~J 로 해석 가능
            dp[i]+=dp[i-1]; // 한자리 전까지 문장의, 경우의 수를 그대로 이어서
        if(code[num-1] == '1' || (code[num-1]=='2' && code[num]<='6')) //10~26은, 두자리 합친 것을 하나로 해독 가능
                dp[i]+=dp[i-2]; // 두자리 전까지 문장의, 경우의 수를 그대로 이어서

        dp[i]%=MOD; //아주 클 수 있으니 MOD로 나누기
    }
    answer = dp[n];
    return answer;
}

int main() {
    string str;
    cin >> str;
    int answer = solution(str, str.length());
    cout << answer;
}

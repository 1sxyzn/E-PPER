#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<int>& score) {
    int answer=0;
    vector<int>dp(n+1,0);
    dp[1] = score[1];
    dp[2] = score[2] + score[1]; // +score[1]하는 것 까먹지 말기, 첫 계단은 반드시 밟아야함 + 첫 계단은 연속된 것에 포함 X

    for(int i=3; i<=n; i++){
        //두칸 건너뛰기, 세칸전 것 밟고 한칸전 칸 밟고 현재칸 밟기
        dp[i] = max(dp[i-2], dp[i-3]+score[i-1])+score[i];
        // dp[i-3]+dp[i-1] 가 아님. 주의하기!
    }
    answer = dp[n];
    return answer; // 최대점수가 저장되어 있는 마지막 계단의 점수값 리턴
}

int main() {
    int n; // 계단의 개수 n
    cin >> n;
    int answer;
    vector<int> score(301, 0); // 계단의 점수를 저장할 변수 선언, 동시에 초기화
    // -> 1번째 index부터 저장하기 위해, 계단의 개수 + 1 만큼 크기 할당
    for (int i = 1; i <= n; i++)
        cin >> score[i];

    answer = solution(n, score);
    cout << answer;
}

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<string> inputs){
    vector<string> answer;
    for(int i=0; i<n; i++){
        stack<char> vps; //string이 아니라 char형의 stack 선언
        bool flag = true; // ')' 와 매칭되는게 stack에 없으면 false로 바꾸고 반복 종료 -> NO 출력
        for(int j=0; j<inputs[i].size(); j++){
            if(inputs[i][j] == '(')
                vps.push('(');
            else {
                if(vps.empty()) { //비어있으면 NO 출력해야함
                    flag = false;
                    break;
                }
                else
                    vps.pop(); // ')'와 매칭되는게 있으면 pop하고 다음 괄호 확인
            }
        }
        if(vps.empty() && flag==true)
            answer.push_back("YES");
        else
            answer.push_back("NO");
    }
    return answer;
}

void show(int n, vector<string>answer){
    int i;
    for(i=0; i<n;i++)
        cout << answer[i] << '\n';
}

int main(){
    int n;
    cin >> n;
    vector<string> inputs(n);
    for (int i=0; i<n; i++)
        cin >> inputs[i];
    vector<string> answer = solution(n, inputs);
    show(n,answer);
    return 0;
}

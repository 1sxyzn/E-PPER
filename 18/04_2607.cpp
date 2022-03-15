#include <iostream>
#include <vector>

using namespace std;

void frequency(string words, int al[26]){
    for(int i=0; i<words.size(); i++){
        al[words[i]-'A']++; // DOG의 경우 al[D]=1, al[O]=1, al[G]=1
    }
}

int solution(int n, vector<string>words){
    int answer=0;
    int al[26]={0}; //기준 단어의 빈도수 저장
    frequency(words[0], al); //기준 단어의 빈도수 계산

    for(int i=1; i<n; i++){ //나머지 비교할 단어들
        int diff = 0; //차이 계산할 변수, 단어마다 초기화 해야하므로 for문 안에
        int al_cmp[26]={0}; //비교할 단어의 빈도수 저장, 단어마다 초기화 해야하므로 for문 안에
        frequency(words[i], al_cmp);
        for(int j=0; j<26; j++){ //i번째 단어와 기준 단어의 차이 계산
            diff+=abs(al[j] - al_cmp[j]);
        }
        //diff ==0 이면 조합만 다르고 같은 것
        //diff ==1 이면 하나만 다르거나 한 단어를 더하거나 뺀 것
        //diff ==2 이면 ABC ABD 처럼 단어를 바꾼 것. ABC와 ABCDD는 diff==2인데 비슷한 단어가 아니므로 예외처리
        if(diff == 0 || diff == 1 || (diff == 2 && words[0].size() == words[i].size()))
            answer++;
    }
    return answer;
}

int main() {
    int n,i;
    int answer;
    cin >> n;
    vector<string> words(n);
    for (i = 0; i < n; i++)
        cin >> words[i];

    answer = solution(n,words);
    cout << answer;
}

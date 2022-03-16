#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//상하좌우 이동을 위한 좌표
int x[4]={0,0,-1,1};
int y[4]={1,-1,0,0};

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    vector<int> answer(2); //영역의 갯수, 가장 넓은 영역의 넓이
    queue<pair<int,int>> q; //좌표 저장할 큐
    int number_of_area = 0; //서로 다른 영역의 갯수
    int max_size_of_one_area = 0;  //가장 넓은 영역의 넓이

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(!picture[i][j]) //색칠하지 않은 칸이면 넘어가기
                continue;
            int current_area=0; //현재 있는 영역의 넓이
            int current_color = picture[i][j]; //현재 영역의 색상 저장
            picture[i][j]=0; //방문한걸 표시하기 위해 0으로 변경 (재방문 방지)
            q.push({i,j}); //색칠됐는데 방문 안했으면 큐에 저장

            number_of_area++; //새 영역 추가
            //인접한 주변 둘러보면서 같은 영역인 것들 확인
            while(!q.empty()){
                current_area++;
                int cx = q.front().first; // current x
                int cy = q.front().second; //current y
                q.pop();
                // cx와 cy의 상하좌우 봐야하므로 4번 반복
                for(int k=0; k<4; k++){
                    //상하좌우 탐색중인 좌표가 범위 이내이고, 같은 색이라면 영역 확장
                    if(cx+x[k]<m && cy+y[k]<n && cx+x[k]>=0 && cy+y[k]>=0 && picture[cx+x[k]][cy+y[k]]==current_color){
                        q.push({cx+x[k], cy+y[k]});
                        picture[cx+x[k]][cy+y[k]]=0;
                    }
                }
            }
            max_size_of_one_area=max(max_size_of_one_area, current_area);
        }
    }
    answer[0]=number_of_area;
    answer[1]=max_size_of_one_area;
    return answer;
}

int main(){
    int m, n;
    cin >> m >> n;
    vector<vector<int>> picture(m, vector<int>(n));
    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++)
            cin >> picture[i][j];
    vector<int> answer = solution(m, n, picture);
    cout << answer[0] << ' ' << answer[1];
    return 0;
}

#include <iostream>
#include <vector>
#include <deque>
#include <map>

using namespace std;
typedef pair<int, int> ii;

int playGame(int n, vector<vector<int>> &board, map<int, string> &cmd){
    //뱀은 맨 처음에 오른쪽을 향해서 감 = 우
    //왼쪽 회전 시 = 상 (오른쪽 회전 시 = 하)
    //한번 더 왼쪽 회전 시 = 좌
    //한번 더 왼쪽 회전 시 = 하
    //따라서 우 상 좌 하 로 저장한 다음, 왼쪽 회전시 +1 을, 오른쪽 회전 시 +3 한뒤 4로 나눈 나머지
    int mx[4]={0,-1,0,1};
    int my[4]={1,0,-1,0};
    int time=0; //시간
    int head=0; //뱀 머리 방향

    deque<ii>snake;
    snake.push_front(ii(0,0));
    board[0][0]=1;

    while(true){
        time++;
        //뱀 머리가 이동할 새로운 좌표
        int nx=snake.front().first+mx[head];
        int ny=snake.front().second+my[head];

        //게임 종료 : 움직인 맴의 머리가 벽에 부딪히거나, 자기 몸과 부딪힐 때
        if(nx<0 || ny<0 || nx>=n || ny>=n || board[nx][ny]==1)
            break;
        if(board[nx][ny]!=2){ //이동한 곳에 사과가 없다면
            board[snake.back().first][snake.back().second]=0; //꼬리 부분 줄이기
            snake.pop_back(); //꼬리 부분 줄이기
        }

        //뱀의 몸 늘리기 : 머리를 다음칸에 위치
        snake.push_front(ii(nx,ny));
        board[nx][ny]=1;

        //방향 변환
        if(cmd[time] == "L") //왼쪽 화전
            head = (head+1)%4;

        if(cmd[time] == "D") //오른쪽 회전
            head = (head+3)%4;
    }
    return time;
}

int solution(int n, int k, int l, vector<vector<int>> &apple, vector<vector<string>> &rotation) {
    vector<vector<int>>board(n, vector<int>(n));
    map<int, string> cmd;
    for(int i=0; i<k; i++)
        board[apple[i][0]-1][apple[i][1]-1]=2; //사과는 1행 1열부터 시작, board는 0행 0열부터 시작
    for(int i=0; i<l; i++)
        cmd[stoi(rotation[i][0])]=rotation[i][1];

    int answer = playGame(n, board, cmd);
    return answer;
}

int main() {
    int n, k, l;

    cin >> n >> k;
    vector<vector<int>> apple(k, vector<int>(2));
    for (int i = 0; i < k; i++) //사과 위치
        cin >> apple[i][0] >> apple[i][1];
    cin >> l;
    vector<vector<string>> rotation(l, vector<string>(2));
    for (int i = 0; i < l; i++) //회전 정보
        cin >> rotation[i][0] >> rotation[i][1];
    //연산
    int answer = solution(n, k, l, apple, rotation);
    //출력
    cout << answer;
    return 0;
}

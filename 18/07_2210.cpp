#include <iostream>
#include <vector>

using namespace std;

vector<bool> dfs(vector<vector<int>> &board, vector<bool>visited, int x, int y, int sum, int cnt){
    int mx[4]={0,0,-1,1};
    int my[4]={1,-1,0,0};

    if(cnt==5){
        if(visited[sum]==false){
            visited[sum]=true;
        }
        return visited;
    }

    //만약 5번 이동한게 아니라면
    for(int i=0; i<4; i++){
        int nx = x+mx[i];
        int ny = y+my[i];

        if(nx>=0 && ny>=0 && nx<5 && ny<5)
            visited = dfs(board, visited, nx, ny, sum*10+board[nx][ny], cnt+1);
    }
    return visited;
}

int solution(vector<vector<int>> &board){
    int answer = 0; //다른 조합 개수
    vector<bool> visited(1000000,false);

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            visited = dfs(board, visited, i, j, board[i][j], 0);
        }
    }

    for(int i=0; i<1000000; i++)
        if(visited[i])
            answer++;

    return answer;

}

int main() {
    vector<vector<int>> board;
    int num, result;

    //숫자판 초기화
    board.assign(5, vector<int>(5,0));

    //숫자판 입력
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> num;
            board[i][j]=num;

        }
    }

    //만들 수 있는 서로 다른 여섯 자리의 수들의 개수 구하기
    result = solution(board);

    //출력
    cout << result;
}

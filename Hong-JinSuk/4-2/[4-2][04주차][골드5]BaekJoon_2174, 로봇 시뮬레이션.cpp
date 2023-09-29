#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int A, B, N, M;
char Move[] = { 'E','S','W','N' };
int map[101][101];
vector<pair<int, pair<int,int>>> Robot(101); // 방향 / x,y
queue<pair<char, pair<int, int>>> Order; // 명령 / 번호,반복

void input() {

	cin >> A >> B >> N >> M;
	for (int i = 1; i <= N; i++) {
		int x, y, Dir; char dir;
		cin >> x >> y >> dir;
		for(int j = 0; j < 4; j++)
			if (dir == Move[j]) {
				Dir = j;
			}
		Robot[i] = { Dir,{x,y} };
		map[y][x] = i;
	}
	for (int i = 0; i < M; i++) {
		int ro, ag; char ord;
		cin >> ro >> ord >> ag;
		Order.push({ ord,{ro,ag} });
	}
	return;
}

void turn_left(int robot_num, int re) {
	Robot[robot_num].first += (3 * re);
	Robot[robot_num].first %= 4;
	return;
}

void turn_right(int robot_num, int re) {
	Robot[robot_num].first += re;
	Robot[robot_num].first %= 4;
	return;
}

void move_move(int robot_num, int re) {
	char dir = Move[Robot[robot_num].first];
	int x = Robot[robot_num].second.first;
	int y = Robot[robot_num].second.second;
	map[y][x] = 0;
	if (dir == 'E') {
		for (int i = 0; i < re; i++) {
			x++;
			if (x > A) {
				cout << "Robot " << robot_num << " crashes into the wall\n";
				exit(0);
			}
			else if (map[y][x] != 0) {
				cout << "Robot " << robot_num << " crashes into robot " << map[y][x] << endl;
				exit(0);
			}
		}
		Robot[robot_num].second.first += re;
	}
	else if (dir == 'W') {
		for (int i = 0; i < re; i++) {
			x--;
			if (x < 1) {
				cout << "Robot " << robot_num << " crashes into the wall\n";
				exit(0);
			}
			else if (map[y][x] != 0) {
				cout << "Robot " << robot_num << " crashes into robot " << map[y][x] << endl;
				exit(0);
			}
		}
		Robot[robot_num].second.first -= re;
	}
	else if (dir == 'N') {
		for (int i = 0; i < re; i++) {
			y++;
			if (y > B) {
				cout << "Robot " << robot_num << " crashes into the wall\n";
				exit(0);
			}
			else if (map[y][x] != 0) {
				cout << "Robot " << robot_num << " crashes into robot " << map[y][x] << endl;
				exit(0);
			}
		}
		Robot[robot_num].second.second += re;
	}
	else if (dir == 'S') {
		for (int i = 0; i < re; i++) {
			y--;
			if (y < 1) {
				cout << "Robot " << robot_num << " crashes into the wall\n";
				exit(0);
			}
			else if (map[y][x] != 0) {
				cout << "Robot " << robot_num << " crashes into robot " << map[y][x] << endl;
				exit(0);
			}
		}
		Robot[robot_num].second.second -= re;
	}
	map[y][x] = robot_num;
	return;
}
void Play() {
	
	while (!Order.empty()) {
		auto play = Order.front(); Order.pop();
		char ord = play.first, robot_num = play.second.first, re = play.second.second;
		if (ord == 'L') {
			turn_left(robot_num, re);
		}
		else if (ord == 'R') {
			turn_right(robot_num, re);
		}
		else if (ord == 'F') {
			move_move(robot_num, re);
		}
	}
	cout << "OK\n";
	return;
}

int main() {

	input();
	Play();

	return 0;
}
#include <iostream>
using namespace std;


class Robot {
public:
    int x;
    int y;
    char 방향;
};

int mx, my, n, m, map[102][102];
Robot robot[101];

bool run(int, char);
bool run_L(int);
bool run_R(int);
bool run_F(int);

int main()
{
    cin >> mx >> my >> n >> m;
    for (int i = 0; i < n; i++) {
        int 로봇가로, 로봇세로;
        char 로봇방향;
        cin >> 로봇가로 >> 로봇세로 >> 로봇방향;
        if (map[로봇세로][로봇가로]) {
            cout << "Robot " << i + 1 << " crashes into robot " << map[로봇세로][로봇가로];
            return 0;
        }
        else {
            map[로봇세로][로봇가로] = i + 1;
            robot[i + 1].x = 로봇가로;
            robot[i + 1].y = 로봇세로;
            robot[i + 1].방향 = 로봇방향;
        }
    }
    for (int i = 0; i < m; i++) {
        int rnum, repeat;
        char command;
        cin >> rnum >> command >> repeat;
        for (int k = 0; k < repeat; k++) {
            if (run(rnum, command) == false) {
                return 0;
            }
        }
    }
    cout << "OK";
}

bool run(int rnum, char cmd) {
    switch (cmd) {
    case 'L':
        return run_L(rnum);
    case 'R':
        return run_R(rnum);
    case 'F':
        return run_F(rnum);
    default:
        return false;
    }
}

bool run_L(int rnum) {
    switch (robot[rnum].방향) {
    case 'N':
        robot[rnum].방향 = 'W';
        break;
    case 'W':
        robot[rnum].방향 = 'S';
        break;
    case 'S':
        robot[rnum].방향 = 'E';
        break;
    case 'E':
        robot[rnum].방향 = 'N';
        break;
    }
    return true;
}

bool run_R(int rnum) {
    switch (robot[rnum].방향) {
    case 'N':
        robot[rnum].방향 = 'E';
        break;
    case 'W':
        robot[rnum].방향 = 'N';
        break;
    case 'S':
        robot[rnum].방향 = 'W';
        break;
    case 'E':
        robot[rnum].방향 = 'S';
        break;
    }
    return true;
}

bool run_F(int rnum) {
    switch (robot[rnum].방향) {
    case 'S':
        if (map[robot[rnum].y - 1][robot[rnum].x] != 0) {
            cout << "Robot " << rnum << " crashes into robot " << map[robot[rnum].y - 1][robot[rnum].x];
            return false;
        }
        else if (robot[rnum].y <= 1) {
            cout << "Robot " << rnum << " crashes into the wall";
            return false;
        }
        map[robot[rnum].y - 1][robot[rnum].x] = rnum;
        map[robot[rnum].y][robot[rnum].x] = 0;
        robot[rnum].y--;
        return true;
    case 'W':
        if (map[robot[rnum].y][robot[rnum].x - 1] != 0) {
            cout << "Robot " << rnum << " crashes into robot " << map[robot[rnum].y][robot[rnum].x - 1];
            return false;
        }
        else if (robot[rnum].x <= 1) {
            cout << "Robot " << rnum << " crashes into the wall";
            return false;
        }
        map[robot[rnum].y][robot[rnum].x - 1] = rnum;
        map[robot[rnum].y][robot[rnum].x] = 0;
        robot[rnum].x--;
        return true;
    case 'N':
        if (map[robot[rnum].y + 1][robot[rnum].x] != 0) {
            cout << "Robot " << rnum << " crashes into robot " << map[robot[rnum].y + 1][robot[rnum].x];
            return false;
        }
        else if (robot[rnum].y >= my) {
            cout << "Robot " << rnum << " crashes into the wall";
            return false;
        }
        map[robot[rnum].y + 1][robot[rnum].x] = rnum;
        map[robot[rnum].y][robot[rnum].x] = 0;
        robot[rnum].y++;
        return true;
    case 'E':
        if (map[robot[rnum].y][robot[rnum].x + 1] != 0) {
            cout << "Robot " << rnum << " crashes into robot " << map[robot[rnum].y][robot[rnum].x + 1];
            return false;
        }
        else if (robot[rnum].x >= mx) {
            cout << "Robot " << rnum << " crashes into the wall";
            return false;
        }
        map[robot[rnum].y][robot[rnum].x + 1] = rnum;
        map[robot[rnum].y][robot[rnum].x] = 0;
        robot[rnum].x++;
        return true;
    }
}

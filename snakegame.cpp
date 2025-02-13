#include <iostream>
#include <conio.h>   
#include <windows.h>

using namespace std;

class SnakeGame {
private:
    const int w = 50;
    const int h = 25;
    int x, y, foodX, foodY;
    int tailX[100], tailY[100];
    int nTail;
    int speed;
    
    enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
    eDirection dir;

    void gotoxy(int x, int y) {
        COORD coord;
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }

    void HideCursor() {
        CONSOLE_CURSOR_INFO cursorInfo;
        cursorInfo.bVisible = FALSE; 
        cursorInfo.dwSize = 1;
        SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
    }

public:
    bool gameOver;
    int score,maxscore;

    SnakeGame() {
        gameOver = false;
        dir = RIGHT;
        x = w / 2;
        y = h / 2;
        foodX = rand() % w;
        foodY = rand() % h;
        score = 0;
        maxscore = 0;

        nTail = 2;
        for (int i = 0; i < nTail; i++) {
            tailX[i] = x - (i + 1);
            tailY[i] = y;
        }
        speed = 50;
        HideCursor();
    }

    void Draw() {
        gotoxy(0, 0);
        for (int i = 0; i < w + 2; i++) cout<<"*";
    
        cout << endl;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (j == 0) cout << "*"; 

                if (i == y && j == x)
                    cout << "O";
                else if (i == foodY && j == foodX)
                    cout << "F";
                else {
                    bool print = false;
                    for (int k = 0; k < nTail; k++) {
                        if (tailX[k] == j && tailY[k] == i) {
                            cout << "o";
                            print = true;
                        }
                    }
                    if (!print) cout << " ";
                }

                if (j == w - 1) cout << "*";
            }
            cout << endl;
        }

        for (int i = 0; i < w + 2; i++) cout<<"*";
        cout << endl;
        cout << "--> Score : " << score << endl;
    }

    void Input() {
        if (_kbhit()) {
            switch (_getch()) {
            case 'a': if (dir != RIGHT) dir = LEFT; break;
            case 'd': if (dir != LEFT) dir = RIGHT; break;
            case 'w': if (dir != DOWN) dir = UP; break;
            case 's': if (dir != UP) dir = DOWN; break;
            case 'q': gameOver = true; break;
            }
        }
    }

    void Logic() {
        int prevX = tailX[0];
        int prevY = tailY[0];
        int prev2X, prev2Y;
        tailX[0] = x;
        tailY[0] = y;
        for (int i = 1; i < nTail; i++) {
            prev2X = tailX[i];
            prev2Y = tailY[i];
            tailX[i] = prevX;
            tailY[i] = prevY;
            prevX = prev2X;
            prevY = prev2Y;
        }

        switch (dir) {
        case LEFT: x--; break;
        case RIGHT: x++; break;
        case UP: y--; break;
        case DOWN: y++; break;
        default: break;
        }

        if (x >= w || x < 0 || y >= h || y < 0)
            gameOver = true;

        for (int i = 0; i < nTail; i++) {
            if (tailX[i] == x && tailY[i] == y)
                gameOver = true;
        }

        if (x == foodX && y == foodY) {
            score += 10;
            foodX = rand() % w;
            foodY = rand() % h;
            nTail++;

            if (score % 50 == 0 && speed > 10) 
                speed -= 5;
        }
    }

    void Reset() {
        x = w / 2;
        y = h / 2;
        foodX = rand() % w;
        foodY = rand() % h;
        score = 0;
        dir = RIGHT;
        nTail = 2;
        for (int i = 0; i < nTail; i++) {
            tailX[i] = x - (i + 1);
            tailY[i] = y;
        }
        gameOver = false;
    }

    void Run() {
        while (!gameOver) {
            Draw();
            Input();
            Logic();
            Sleep(speed);
        }
    }
};

int main() {
    SnakeGame game;
    game.Run();
    while(game.gameOver){
        if(game.score > game.maxscore){
            game.maxscore = game.score;
        }

        cout<<"You Want To Restart The Game(Yes[y]/No[n])? : ";
        char choice;
        cin>>choice;
        if(choice == 'Y' || choice == 'y'){
            game.Reset();
            game.Run();
        }
        else{
            cout<<endl<<"(^_^) Thank You For Playing (^_^) !!" <<endl<< "--> Highest Score : "<<game.maxscore <<endl;
            return 0;
        }
    }
}

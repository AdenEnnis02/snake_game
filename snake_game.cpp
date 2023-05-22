#include <iostream>
#include <conio.h>
using namespace std;
bool game_over;
const int screen_width = 20;
const int screen_height = 20;
int x, y, fruitX, fruitY, player_score;
enum Direction
{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};
Direction dir;
void Startgame()
{
    game_over = false;
    dir = STOP;
    x = screen_width / 2;
    y = screen_height / 2;
    fruitX = rand() % screen_width;
    fruitY = rand() % screen_width;
    player_score = 0;
}
void Draw()
{
    system("clear");
    for (int i = 0; i < screen_width; i++)
        cout << "#";
    cout << endl;
    for (int i = 0; i < screen_height; i++)
    {
        for (int j = 0; j < screen_width; j++)
        {
            if (j == 0)
                cout << "#";
            if (i == y && j == x)
                cout << "O";
            else if (i == fruitY && j == fruitX)
                cout << "F";
            else
                cout << " ";
            if (j == screen_width - 1)
                cout << "#";
        }
        cout << endl;
    }
    for (int i = 0; i < screen_width; i++)
        cout << "#";
    cout << endl;
}
void Input()
{
    if (_khbit())
    {
        switch (_getch())
        {
            case 'a':
                dir = LEFT;
                break;
            case 's':
                dir = DOWN;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 'w':
                dir = UP;
                break;
            case 'x':
                game_over = true;
                break;
        }
    }
}
void Logic()
{
    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case DOWN:
        y++;
        break;
    case UP:
        x--;
        break;
    default
        break;
    
    }
}

int main()
{
    Startgame();
    while (!game_over)
    {
        Draw();
        Input();
        Logic();
    }
    return 0;
}

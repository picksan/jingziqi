#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;

//电脑 玩家 平局 无
enum players {Computer,Human,Draw,None};
//可能赢的情况，一行一列或者对角
const int iWin[8][3] = { {0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{3,5,8},{0,4,8},{2,4,6} };

//＃字棋类
class TickTackToe
{
public:
    //构造方法
    TickTackToe()
    {

    }
    //游戏函数
    void play()
    {

    }
private:
    //棋局开始状态
    void reset()
    {

    }
    //画格子
    void drawGrid()
    {

    }
    //判断输赢
    int checkVictory()
    {

    }
    //人下棋
    void getHumanMove()
    {

    }
    //电脑下棋
    void getComputerMove()
    {

    }
    //计数器，用来记录当前玩家是谁
    int _p;
    //格子状态
    int _field[9];

};



int main()
{
    srand(GetTickCount());
    TickTackToe tic;
    tic.play();
    return 0;
}
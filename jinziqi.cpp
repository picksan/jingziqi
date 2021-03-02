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
        _p = rand() % 2;
        reset();
    }
    //游戏函数
    void play()
    {
        //res表示最终结果，初始为平局
        int res = Draw;
        while (true)
        {
            //画棋盘
            drawGrid();
            while (true)
            {
                
                //落子
                if (_p) getHumanMove();
                else getComputerMove();
                drawGrid();
                //判断输赢
                res = checkVictory();
                if (res != None)
                    break;
                //计数器+1
                ++_p;
                _p %= 2;
            }
            if (res == Human)
                cout << "Human win!" << endl;
            else if (res == Computer)
                cout << "Computer win!" << endl;
            else
                cout << "It is a draw." << endl;
            cout << endl << endl;

            string r;
            cout << "Play again( Y / N )? ";
            cin >> r;
            //不输入y，直接返回，退出游戏
            if (r != "Y" && r != "y")
                return;
            //计数器+1
            ++_p %= 2;
            //重置棋盘
            reset();

        }
      
    }
private:
    //棋局开始状态
    void reset()
    {
        for (int x = 0;x < 9;x++)
        {
            _field[x] = None;
        }
    }
    //画格子
    void drawGrid()
    {
        //清屏
        system("cls");
        //定义控制台屏幕初始坐标
        /*坐标系统
        o ----->x
        |
        |
        |
        y
        */
        COORD c = { 0,2 };
        //设置控制台光标
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
        //棋局初始状态
        cout << " 1 | 2 | 3 " << endl;
        cout << "---|---|---" << endl;
        cout << " 4 | 5 | 6 " << endl;
        cout << "---|---|---" << endl;
        cout << " 7 | 8 | 9 " << endl;
        //棋子计数器
        int f = 0;
        for (int y = 0;y < 5;y += 2)
        {
            for (int x = 1;x < 10;x += 4)
            {
                //如果这颗棋子没有使用过
                if (_field[f] != None)
                {
                    //刚开始光标从02开始，所以这里y整体坐标要下移2
                    COORD c = { x,y + 2 };
                    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
                    //判断棋子，电脑x，人o
                    string o = _field[f] == Computer ? "X" : "O";
                    cout << o;
                }
                f++;
            }
        }
        c.Y = 9;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
    }
    //判断输赢
    int checkVictory()
    {
        //判断赢的情况
        for (int i = 0;i < 8;i++)
        {
            if (_field[iWin[i][0]] != None &&
                _field[iWin[i][0]] == _field[iWin[i][1]] && 
                _field[iWin[i][1]] == _field[iWin[i][2]])
            {
                return _field[iWin[i][0]];
            }
        }
        //i表示棋子数量
        int i = 0;
        for (int f = 0;f < 9;f++)
        {
            if (_field[f] != None)
                i++;
        }
        //如果有9颗棋子，就是平局
        if (i == 9)
            return Draw;
        //None 表示还未分出胜负，继续下棋
        return None;
    }
    //人下棋
    void getHumanMove()
    {
        int m;
        cout << "Enter your move(1-9):";
        //开始死循环
        while (true)
        {
            m = 0;
            cin >> m;
            if (_field[m-1] != None)
                cout << "Invid move. Try again!" << endl;
            else
                break;
        }
        _field[m - 1] = Human;
    }
    //电脑下棋
    void getComputerMove()
    {
        int move=0;
        //随机下一步
        do
        {
            move = rand() % 9;
        } while (_field[move]!=None);

        //对赢的情况进行枚举
        for (int i = 0;i < 8;i++)
        {
            int try1 = iWin[i][0], try2 = iWin[i][1], try3 = iWin[i][2];
            //12有相同的，下3，相同的是自己，电脑赢了
            if (_field[try1] != None && _field[try1] == _field[try2] && _field[try3] == None)
            {
                move = try3;
                if (_field[try1] == Computer)
                    break;
            }
            //23有相同的，下1
            if (_field[try2] != None && _field[try2] == _field[try3] && _field[try1] == None)
            {
                move = try1;
                if (_field[try2] == Computer)
                    break;
            }
            //13有相同的，下2
            if (_field[try3] != None && _field[try1] == _field[try3] && _field[try2] == None)
            {
                move = try2;
                if (_field[try3] == Computer)
                    break;
            }
        }
        //电脑下
        _field[move] = Computer;

    }
    //计数器，用来记录当前玩家是谁
    int _p;
    //格子状态
    int _field[9];

};



int main()
{
    srand(GetTickCount64());
    TickTackToe tic;
    tic.play();
    return 0;
}
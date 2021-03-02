#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;

//���� ��� ƽ�� ��
enum players {Computer,Human,Draw,None};
//����Ӯ�������һ��һ�л��߶Խ�
const int iWin[8][3] = { {0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{3,5,8},{0,4,8},{2,4,6} };

//��������
class TickTackToe
{
public:
    //���췽��
    TickTackToe()
    {
        _p = rand() % 2;
        reset();
    }
    //��Ϸ����
    void play()
    {
        //res��ʾ���ս������ʼΪƽ��
        int res = Draw;
        while (true)
        {
            //������
            drawGrid();
            while (true)
            {
                
                //����
                if (_p) getHumanMove();
                else getComputerMove();
                drawGrid();
                //�ж���Ӯ
                res = checkVictory();
                if (res != None)
                    break;
                //������+1
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
            //������y��ֱ�ӷ��أ��˳���Ϸ
            if (r != "Y" && r != "y")
                return;
            //������+1
            ++_p %= 2;
            //��������
            reset();

        }
      
    }
private:
    //��ֿ�ʼ״̬
    void reset()
    {
        for (int x = 0;x < 9;x++)
        {
            _field[x] = None;
        }
    }
    //������
    void drawGrid()
    {
        //����
        system("cls");
        //�������̨��Ļ��ʼ����
        /*����ϵͳ
        o ----->x
        |
        |
        |
        y
        */
        COORD c = { 0,2 };
        //���ÿ���̨���
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
        //��ֳ�ʼ״̬
        cout << " 1 | 2 | 3 " << endl;
        cout << "---|---|---" << endl;
        cout << " 4 | 5 | 6 " << endl;
        cout << "---|---|---" << endl;
        cout << " 7 | 8 | 9 " << endl;
        //���Ӽ�����
        int f = 0;
        for (int y = 0;y < 5;y += 2)
        {
            for (int x = 1;x < 10;x += 4)
            {
                //����������û��ʹ�ù�
                if (_field[f] != None)
                {
                    //�տ�ʼ����02��ʼ����������y��������Ҫ����2
                    COORD c = { x,y + 2 };
                    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
                    //�ж����ӣ�����x����o
                    string o = _field[f] == Computer ? "X" : "O";
                    cout << o;
                }
                f++;
            }
        }
        c.Y = 9;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
    }
    //�ж���Ӯ
    int checkVictory()
    {
        //�ж�Ӯ�����
        for (int i = 0;i < 8;i++)
        {
            if (_field[iWin[i][0]] != None &&
                _field[iWin[i][0]] == _field[iWin[i][1]] && 
                _field[iWin[i][1]] == _field[iWin[i][2]])
            {
                return _field[iWin[i][0]];
            }
        }
        //i��ʾ��������
        int i = 0;
        for (int f = 0;f < 9;f++)
        {
            if (_field[f] != None)
                i++;
        }
        //�����9�����ӣ�����ƽ��
        if (i == 9)
            return Draw;
        //None ��ʾ��δ�ֳ�ʤ������������
        return None;
    }
    //������
    void getHumanMove()
    {
        int m;
        cout << "Enter your move(1-9):";
        //��ʼ��ѭ��
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
    //��������
    void getComputerMove()
    {
        int move=0;
        //�����һ��
        do
        {
            move = rand() % 9;
        } while (_field[move]!=None);

        //��Ӯ���������ö��
        for (int i = 0;i < 8;i++)
        {
            int try1 = iWin[i][0], try2 = iWin[i][1], try3 = iWin[i][2];
            //12����ͬ�ģ���3����ͬ�����Լ�������Ӯ��
            if (_field[try1] != None && _field[try1] == _field[try2] && _field[try3] == None)
            {
                move = try3;
                if (_field[try1] == Computer)
                    break;
            }
            //23����ͬ�ģ���1
            if (_field[try2] != None && _field[try2] == _field[try3] && _field[try1] == None)
            {
                move = try1;
                if (_field[try2] == Computer)
                    break;
            }
            //13����ͬ�ģ���2
            if (_field[try3] != None && _field[try1] == _field[try3] && _field[try2] == None)
            {
                move = try2;
                if (_field[try3] == Computer)
                    break;
            }
        }
        //������
        _field[move] = Computer;

    }
    //��������������¼��ǰ�����˭
    int _p;
    //����״̬
    int _field[9];

};



int main()
{
    srand(GetTickCount64());
    TickTackToe tic;
    tic.play();
    return 0;
}
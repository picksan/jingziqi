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

    }
    //��Ϸ����
    void play()
    {

    }
private:
    //��ֿ�ʼ״̬
    void reset()
    {

    }
    //������
    void drawGrid()
    {

    }
    //�ж���Ӯ
    int checkVictory()
    {

    }
    //������
    void getHumanMove()
    {

    }
    //��������
    void getComputerMove()
    {

    }
    //��������������¼��ǰ�����˭
    int _p;
    //����״̬
    int _field[9];

};



int main()
{
    srand(GetTickCount());
    TickTackToe tic;
    tic.play();
    return 0;
}
#include <iostream>
#include <ctime>

#include "NeuronNet.h"

int main()
{
    srand(time(NULL));

    //���������� ���� � ��������� ����
    int NLA = 4;
    //���������� �������� � ������ ����
    int LNA[4];
    LNA[0] = 36;
    LNA[1] = 26;
    LNA[2] = 16;
    LNA[3] = 10;
    //���������� ������ ����� ������
    int CA[4];
    CA[0] = 900;
    CA[1] = 390;
    CA[2] = 160;
    CA[3] = 0;
    //��������� � � �������� �����������
    int a = 1;
    float speed = 0.8;
    //�����, ����������� � ���� ��������� �������� (�� 0 �� 1)
    bool Number[11][7][5] = { {
       {0,1,1,1,0},
       {1,0,0,0,1},
       {1,0,0,0,1},
       {1,0,0,0,1}, //0
       {1,0,0,0,1},
       {1,0,0,0,1},
       {0,1,1,1,0}
    },{
       {0,1,1,1,0},
       {1,0,0,0,1},
       {1,0,0,0,1},
       {0,1,1,1,1}, //9
       {0,0,0,0,1},
       {1,0,0,0,1},
       {0,1,1,1,0} }
    ,{
       {0,1,1,1,0},
       {1,0,0,0,1},
       {1,0,0,0,1},
       {0,1,1,1,0}, //8
       {1,0,0,0,1},
       {1,0,0,0,1},
       {0,1,1,1,0} } 
    ,{
       {1,1,1,1,1},
       {0,0,0,0,1},
       {0,0,0,1,0},
       {0,0,1,0,0}, //7
       {0,1,0,0,0},
       {0,1,0,0,0},
       {0,1,0,0,0} } 
    ,{
       {0,1,1,1,0},
       {1,0,0,0,1},
       {1,0,0,0,0},
       {1,1,1,1,0}, //6
       {1,0,0,0,1},
       {1,0,0,0,1},
       {0,1,1,1,0} } 
    ,{
       {1,1,1,1,1},
       {1,0,0,0,0},
       {1,1,1,1,0},
       {0,0,0,0,1}, //5
       {0,0,0,0,1},
       {1,0,0,0,1},
       {0,1,1,1,0} } 
    ,{
       {0,0,1,1,0},
       {0,1,0,1,0},
       {1,0,0,1,0},
       {1,0,0,1,0}, //4
       {1,1,1,1,1},
       {0,0,0,1,0},
       {0,0,0,1,0} } 
    ,{
       {0,1,1,1,0},
       {1,0,0,0,1},
       {0,0,0,0,1},
       {0,0,1,1,0}, //3
       {0,0,0,0,1},
       {1,0,0,0,1},
       {0,1,1,1,0} } 
    ,{
       {0,1,1,1,0},
       {1,0,0,0,1},
       {0,0,0,0,1},
       {0,0,0,1,0}, //2
       {0,1,1,0,0},
       {1,0,0,0,0},
       {1,1,1,1,1} } 
    ,{
       {0,0,1,0,0},
       {0,1,1,0,0},
       {0,0,1,0,0},
       {0,0,1,0,0}, //1
       {0,0,1,0,0},
       {0,0,1,0,0},
       {0,1,1,1,0} },
    {
       {1,1,1,1,0},
       {0,0,0,1,0},
       {0,0,0,1,0},
       {0,0,0,1,0}, //���� �����
       {0,0,1,0,0},
       {0,1,0,0,0},
       {0,1,1,1,1}
    } };
    
    //�������� ��������� ��� ������ �����, ������������ ��� ���������� ������
    bool NumberWant[10][10] = { 
    { 0,0,0,0,0,0,0,0,0,1 } ,
    { 0,0,0,0,0,0,0,0,1,0 } , 
    { 0,0,0,0,0,0,0,1,0,0 } , 
    { 0,0,0,0,0,0,1,0,0,0 } , 
    { 0,0,0,0,0,1,0,0,0,0 } , 
    { 0,0,0,0,1,0,0,0,0,0 } , 
    { 0,0,0,1,0,0,0,0,0,0 } , 
    { 0,0,1,0,0,0,0,0,0,0 } , 
    { 0,1,0,0,0,0,0,0,0,0 } , 
    { 1,0,0,0,0,0,0,0,0,0 } , };
    
    //������� ����
    NeuronNet MyNet(NLA, CA, a, speed, LNA);
    
    //�������� ����, ���� �������� ������ ����� � �������������� ������
    for (int i = 0; i < 1000; i++)
    {
        //������ ������ �� ������� ����
        MyNet.InputStartData(Number[i%10]);
        //������������� �������� ������� �������
        MyNet.CalcGeneration();
        //������� �������� ������ � ���������� ����
        MyNet.CalcErrorDelta(NumberWant[i%10]);
    }

    //����� ���� ��� ����������
    int jjj = 0;
    while (jjj < 7)
    {
        for (int i = 0; i < 11; i++)
        {
            for (int k = 0; k < 5; k++)
            {
                if (Number[i][jjj][k]) std::cout << "#";
                else std::cout << " ";
            }
            std::cout << "\t";
        }
        std::cout << "\n";
        jjj++;
    }
    //����� ����� �������������
    std::cout << "Select your number to recognize (index 1-11 from left to right):\n";
    int selectednumber;
    std::cin >> selectednumber;

    std::cout << "You picked:\n";

    for (int j = 0; j < 7; j++)
    {
        for (int k = 0; k < 5; k++)
        {
            if (Number[selectednumber-1][j][k]) std::cout << "#";
            else std::cout << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    //��� ����, ��������� �������������, �����
    MyNet.InputStartData(Number[selectednumber-1]);
    MyNet.CalcGeneration();
    //����� ����������
    MyNet.WriteData();
    MyNet.OutputResult();
    
    int maxindexresult = 0;
    float max = 0;
    for (int jj = 9; jj >= 0; jj--)
    {
        if (MyNet.GetResultAtIndex(jj) > max)
        {
            maxindexresult = jj;
            max = MyNet.GetResultAtIndex(jj);
        }
    }
    std::cout << "\n You result = " << 10-maxindexresult << " = " << max << std::endl << std::endl;

    for (int j = 0; j < 7; j++)
    {
        for (int k = 0; k < 5; k++)
        {
            if (Number[9-maxindexresult][j][k]) std::cout << "#";
            else std::cout << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;


    system("pause");

}

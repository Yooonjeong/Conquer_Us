#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <string.h>
#include "worldmap.h"
#include "data.h"
#include "makeTap.h"

#pragma warning(disable:4996)

#define WORLD_WIDTH 77      //���� ũ��
#define WORLD_HEIGHT 39      //���� ����

/*�Լ�*/
void SetCurrentCursorPos(int x, int y);      //���� Ŀ�� ��ġ ���� �Լ�
COORD GetCurrentCursorPos();   //Ŀ�� ��ġ �������� �Լ�
void MakeWorld();      //�� �����  
void RemoveCursor();      //Ŀ�� �����
void Colorset(int backColor, int textColor);      //��Ʈ�� ����(���ڹ���, ���ڻ�)
void ProcessKeyInput();       //Ű�Է�


/*��������*/
int totalSpeed = 5;                 //��ü �ӵ�


void main() {
    system("mode con cols=200 lines=60");      //�ܼ� ũ�� ����
    SetConsoleTitle(TEXT("Conqure Us"));        //�ܼ� �̸� ����
    initTap();
    RemoveCursor();
    MakeWorld();
    drawFirstTap();
    while (1) {
        ProcessKeyInput();
    }


}
void SetCurrentCursorPos(int x, int y) {         //Ŀ�� ��ġ ����
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

COORD GetCurrentCursorPos(void) {         //���� Ŀ�� ��ġ �θ���
    CONSOLE_SCREEN_BUFFER_INFO curInfo;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
    return curInfo.dwCursorPosition;
}


void MakeWorld() {                        //�� ����� �Լ�
    COORD curPos = { 0,0 };
    for (int i = 2; i < WORLD_HEIGHT - 1; i++) {
        for (int j = 1; j < WORLD_WIDTH - 1; j++) {
            SetCurrentCursorPos(curPos.X + j * 2, curPos.Y + i);
            if (World[i][j] == 6) {
                Colorset(green, green);
                printf("��");
            }
            else if (World[i][j] == 5) {
                Colorset(lightBlue, lightBlue);
                printf("��");
            }
            else if (World[i][j] == 7) {
                Colorset(Orange, Orange);
                printf("��");
            }
            else if (World[i][j] == 8) {
                Colorset(green, brightRed);
                printf("��");
            }
            else if (World[i][j] == 9) {
                Colorset(brightYellow, red);
                printf("��");
            }
        }
    }
}

void RemoveCursor(void) {            //Ŀ�� �����
    CONSOLE_CURSOR_INFO curInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
    curInfo.bVisible = 0;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}

void Colorset(int backColor, int textColor) {         //�� ��ȯ �Լ�
    HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(Handle, (backColor << 4) + textColor);
}

void ProcessKeyInput() {//Ű �Է¹޴� �Լ�
    int key;
    // QE �Է� ������ -> ���̷���/�������/�� ��ȭ/������ ��ư ���� �̵� (Q-����, E-������)
    // WASD �Է� ������ -> �� �ǿ��� ���� ���û��� ���� �̵� (W-����, A-����, S-�Ʒ���, D-������)
    // F �Է� ������ -> �� ��ư ����


    for (int i = 0; i < 5; i++) {

        if (_kbhit() != 0) {
            key = _getch();
            switch (key) {
            case Q:
                check = 0;
                currentst = 0;
                currentrt = 0;
                currentvt = 0;
                currentit = 0;
                if (currentTap == 0) break;
                currentTap = (currentTap + 3) % 4;
                if (currentTap == 0) {
                    removeTap();
                    selectedTap(0);
                    break;
                }
                else if (currentTap == 1) {
                    selectedTap(1);
                    removeTap();
                    break;
                }
                else if (currentTap == 2) {
                    selectedTap(2);
                    removeTap();
                    break;
                }
                else if (currentTap == 3) {
                    selectedTap(3);
                    removeTap();
                    break;
                }
                break;
            case E:
                check = 0;
                currentst = 0;
                currentrt = 0;
                currentvt = 0;
                currentit = 0;
                if (currentTap == 3) break;
                currentTap = (currentTap + 1) % 4;
                if (currentTap == 0) {
                    removeTap();
                    selectedTap(0);
                    break;
                }
                else if (currentTap == 1) {
                    removeTap();
                    selectedTap(1);
                    break;
                }
                else if (currentTap == 2) {
                    removeTap();
                    selectedTap(2);
                    break;
                }
                else if (currentTap == 3) {
                    removeTap();
                    selectedTap(3);
                    break;
                }
                break;
            case F:
                if (currentTap == 0) {      //���̷��� ��ȭ ���ϰ��
                    if (check == 0) {
                        removeTap();
                        colorChangeVirusTap(0, currentWaterLv);
                        check = 1;
                        break;
                    }
                    if (currentvt == 0) {           //���̷��� ��ȭ �� �� ���ķ��� ���
                        check = 1;
                        colorChangeVirusTap(0, currentWaterLv);
                        break;
                    }
                    else if (currentvt == 1) {      //���̷��� ��ȭ �� �� ġ������ ���
                        check = 1;
                        colorChangeVirusTap(1, currentWaterLv);
                        break;
                    }
                    else if (currentvt == 2) {
                        check = 1;
                        colorChangeVirusTap(2, currentWaterLv);
                        break;
                    }
                    break;
                }
                else if (currentTap == 1) {     //���� ��� ��ȭ���ϰ��
                    if (check == 0) {
                        removeTap();
                        colorChangeRouteTap(0);
                        check = 1;
                        break;
                    }
                    if (currentrt == 0) {       //������� ����
                        check = 1;
                        colorChangeRouteTap(0);
                        break;
                    }
                    else if (currentrt == 1) {  //������� ����
                        check = 1;
                        colorChangeRouteTap(1);
                        break;
                    }
                    else if (currentrt == 2) {      //������� ����
                        check = 1;
                        colorChangeRouteTap(2);
                        break;
                    }
                    else if (currentrt == 3) {      //������� ��
                        check = 1;
                        colorChangeRouteTap(3);
                        break;
                    }
                    else if (currentrt == 4) {      //������� ������
                        check = 1;
                        colorChangeRouteTap(4);
                        break;
                    }
                    break;
                }
                else if (currentTap == 2) { // �� ��ȭ
                    if (check == 0) {
                        colorChangeShipTap(0);
                        check = 1;
                        break;
                    }

                    if (currentst == 0) { // ���ݷ�
                        check = 1;
                        colorChangeShipTap(0);
                        break;
                    }

                    else if (currentst == 1) { // ������
                        check = 1;
                        colorChangeShipTap(1);
                        break;
                    }
                    else if (currentst == 2) { // �ӵ�
                        check = 1;
                        colorChangeShipTap(2);
                        break;
                    }
                    break;
                }
                else if (currentTap == 3) { //�������� ���� ��
                    if (check == 0) {
                        removeTap();
                        colorChangeItemTap(0);
                        check = 1;
                        break;
                    }
                    if (currentit == 0) { //��¥�⸧����(��� �� �ӵ� ����)
                        check = 1;
                        colorChangeItemTap(0);
                        break;
                    }
                    else if (currentit == 1) { //���ΰ� �� ü�� ȸ��
                        check = 1;
                        colorChangeItemTap(1);
                        break;
                    }
                    else if (currentit == 2) { // �Ͻ��� �ӵ� ���� �ִ��(1)
                        check = 1;
                        colorChangeItemTap(2);
                        break;
                    }
                    else if (currentit == 3) { // ��� ��� �� �νñ�
                        check = 1;
                        colorChangeItemTap(3);
                        break;
                    }
                    else if (currentit == 4) { // ��� ��� ȹ�淮 ������ ����
                        check = 1;
                        colorChangeItemTap(4);
                        break;
                    }
                    break;
                }
                break;
            case A:
                if (currentTap == 0) {
                    if (currentvt == 0) break;
                    currentvt = (currentvt + 2) % 3;
                    if (currentvt == 0) {
                        colorChangeVirusTap(0, currentWaterLv);
                        break;
                    }
                    else if (currentvt == 1) {
                        colorChangeVirusTap(1, currentWaterLv);
                        break;
                    }
                    else if (currentvt == 2) {
                        colorChangeVirusTap(2, currentWaterLv);
                    }
                }
                else if (currentTap == 1) {
                    if (currentrt == 0 || currentrt == 3) break;
                    currentrt = (currentrt + 4) % 5;
                    if (currentrt == 0) {
                        colorChangeRouteTap(0);
                        break;
                    }
                    else if (currentrt == 1) {
                        colorChangeRouteTap(1);
                        break;
                    }
                    else if (currentrt == 2) {
                        colorChangeRouteTap(2);
                        break;
                    }
                    else if (currentrt == 3) {
                        colorChangeRouteTap(3);
                        break;
                    }
                    else if (currentrt == 4) {
                        colorChangeRouteTap(4);
                        break;
                    }
                }
                else if (currentTap == 2) {
                    if (currentst == 0) break;
                    currentst = (currentst + 2) % 3;
                    if (currentst == 0) {
                        colorChangeShipTap(0);
                        break;
                    }
                    else if (currentst == 1) {
                        colorChangeShipTap(1);
                        break;
                    }
                    else if (currentst == 2) {
                        colorChangeShipTap(2);
                        break;
                    }
                }
                else if (currentTap == 3) {
                    if (currentit == 0 || currentrt == 3) break;
                    currentit = (currentit + 4) % 5;
                    if (currentit == 0) {
                        colorChangeItemTap(0);
                        break;
                    }
                    else if (currentit == 1) {
                        colorChangeItemTap(1);
                        break;
                    }
                    else if (currentit == 2) {
                        colorChangeItemTap(2);
                        break;
                    }
                    else if (currentit == 3) {
                        colorChangeItemTap(3);
                        break;
                    }
                    else if (currentit == 4) {
                        colorChangeItemTap(4);
                        break;
                    }
                }
                break;
            case D:
                if (currentTap == 0) {
                    if (currentvt == 2) break;
                    currentvt = (currentvt + 1) % 3;
                    if (currentvt == 0) {
                        colorChangeVirusTap(0, currentWaterLv);
                        break;
                    }
                    else if (currentvt == 1) {
                        colorChangeVirusTap(1, currentWaterLv);
                        break;
                    }
                    else if (currentvt == 2) {
                        colorChangeVirusTap(2, currentWaterLv);
                        break;
                    }
                }
                if (currentTap == 1) {
                    if (currentrt == 4 || currentrt == 2) break;
                    currentrt = (currentrt + 1) % 5;
                    if (currentrt == 0) {
                        colorChangeRouteTap(0);
                        break;
                    }
                    else if (currentrt == 1) {
                        colorChangeRouteTap(1);
                        break;
                    }
                    else if (currentrt == 2) {
                        colorChangeRouteTap(2);
                        break;
                    }
                    else if (currentrt == 3) {
                        colorChangeRouteTap(3);
                        break;
                    }
                    else if (currentrt == 4) {
                        colorChangeRouteTap(4);
                        break;
                    }
                }
                else if (currentTap == 2) {
                    if (currentst == 2) break;
                    currentst = (currentst + 1) % 3;
                    if (currentst == 0) {
                        colorChangeShipTap(0);
                        break;
                    }
                    else if (currentst == 1) {
                        colorChangeShipTap(1);
                        break;
                    }
                    else if (currentst == 2) {
                        colorChangeShipTap(2);
                        break;
                    }
                }
                else if (currentTap == 3) {
                    if (currentit == 4 || currentit == 2) break;
                    currentit = (currentit + 1) % 5;
                    if (currentit == 0) {
                        colorChangeItemTap(0);
                        break;
                    }
                    else if (currentit == 1) {
                        colorChangeItemTap(1);
                        break;
                    }
                    else if (currentit == 2) {
                        colorChangeItemTap(2);
                        break;
                    }
                    else if (currentit == 3) {
                        colorChangeItemTap(3);
                        break;
                    }
                    else if (currentit == 4) {
                        colorChangeItemTap(4);
                        break;
                    }
                }
                break;
            case W:
                if (currentTap == 1) {
                    if (currentrt == 0 || currentrt == 1 || currentrt == 2) {
                        break;
                    }
                    if (currentrt == 3) {
                        currentrt = 0;
                        colorChangeRouteTap(0);
                    }
                    else if (currentrt == 4) {
                        currentrt = 2;
                        colorChangeRouteTap(2);
                    }
                    break;
                }
                else if (currentTap == 3) {
                    if (currentit == 0 || currentit == 1 || currentit == 2) {
                        break;
                    }
                    if (currentit == 3) {
                        currentit = 0;
                        colorChangeItemTap(0);
                    }
                    else if (currentit == 4) {
                        currentit = 2;
                        colorChangeItemTap(2);
                    }
                    break;
                }
                break;
            case S:
                if (currentTap == 1) {
                    if (currentrt == 3 || currentrt == 4) {
                        break;
                    }
                    if (currentrt == 0) {
                        currentrt = 3;
                        colorChangeRouteTap(3);
                        break;
                    }
                    else if (currentrt == 1) {
                        currentrt = 3;
                        colorChangeRouteTap(3);
                        break;
                    }
                    else if (currentrt == 2) {
                        currentrt = 4;
                        colorChangeRouteTap(4);
                        break;
                    }
                }
                else if (currentTap == 3) {
                    if (currentit == 3 || currentit == 4) {
                        break;
                    }
                    if (currentit == 0) {
                        currentit = 3;
                        colorChangeItemTap(3);
                        break;
                    }
                    else if (currentit == 1) {
                        currentit = 3;
                        colorChangeItemTap(3);
                        break;
                    }
                    else if (currentit == 2) {
                        currentit = 4;
                        colorChangeItemTap(4);
                        break;
                    }
                }
                break;
            }
        }
        Sleep(totalSpeed);
    }
}
#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <string.h>
#include "worldmap.h"

#pragma warning(disable:4996)

#define WORLD_WIDTH 77      //���� ũ��
#define WORLD_HEIGHT 39      //���� ����

typedef enum ColorKinds {      //��������
    black, blue, green, skyBlue, red, pink, Orange, white, gray, lightBlue, brightGreen, sky, brightRed, brightPink, brightYellow, brightWhite
}ColorKinds;

/*�Լ�*/
void SetCurrentCursorPos(int x, int y);      //���� Ŀ�� ��ġ ���� �Լ�
COORD GetCurrentCursorPos();   //Ŀ�� ��ġ �������� �Լ�
void MakeWorld();      //�� �����  
void RemoveCursor();      //Ŀ�� �����
void Colorset(int backColor, int textColor);      //��Ʈ�� ����(���ڹ���, ���ڻ�)

void main() {
    system("mode con cols=200 lines=60");      //�ܼ� ũ�� ����
    SetConsoleTitle(TEXT("Conqure Us"));        //�ܼ� �̸� ����
    MakeWorld();
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
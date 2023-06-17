#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <string.h>
#include "worldmap.h"

#pragma warning(disable:4996)

#define WORLD_WIDTH 77      //맵의 크기
#define WORLD_HEIGHT 39      //맵의 높이

typedef enum ColorKinds {      //색깔지정
    black, blue, green, skyBlue, red, pink, Orange, white, gray, lightBlue, brightGreen, sky, brightRed, brightPink, brightYellow, brightWhite
}ColorKinds;

/*함수*/
void SetCurrentCursorPos(int x, int y);      //현재 커서 위치 변경 함수
COORD GetCurrentCursorPos();   //커서 위치 가져오는 함수
void MakeWorld();      //맵 만들기  
void RemoveCursor();      //커서 지우기
void Colorset(int backColor, int textColor);      //폰트색 변경(글자배경색, 글자색)

void main() {
    system("mode con cols=200 lines=60");      //콘솔 크기 조정
    SetConsoleTitle(TEXT("Conqure Us"));        //콘솔 이름 설정
    MakeWorld();
}
void SetCurrentCursorPos(int x, int y) {         //커서 위치 설정
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

COORD GetCurrentCursorPos(void) {         //현재 커서 위치 부르기
    CONSOLE_SCREEN_BUFFER_INFO curInfo;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
    return curInfo.dwCursorPosition;
}


void MakeWorld() {                        //맵 만들기 함수
    COORD curPos = { 0,0 };
    for (int i = 2; i < WORLD_HEIGHT - 1; i++) {
        for (int j = 1; j < WORLD_WIDTH - 1; j++) {
            SetCurrentCursorPos(curPos.X + j * 2, curPos.Y + i);
            if (World[i][j] == 6) {
                Colorset(green, green);
                printf("■");
            }
            else if (World[i][j] == 5) {
                Colorset(lightBlue, lightBlue);
                printf("■");
            }
            else if (World[i][j] == 7) {
                Colorset(Orange, Orange);
                printf("■");
            }
            else if (World[i][j] == 8) {
                Colorset(green, brightRed);
                printf("■");
            }
            else if (World[i][j] == 9) {
                Colorset(brightYellow, red);
                printf("♥");
            }
        }
    }
}

void RemoveCursor(void) {            //커서 지우기
    CONSOLE_CURSOR_INFO curInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
    curInfo.bVisible = 0;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}

void Colorset(int backColor, int textColor) {         //색 변환 함수
    HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(Handle, (backColor << 4) + textColor);
}
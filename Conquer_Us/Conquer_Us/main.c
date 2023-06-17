#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <string.h>
#include "worldmap.h"
#include "data.h"
#include "makeTap.h"

#pragma warning(disable:4996)

#define WORLD_WIDTH 77      //맵의 크기
#define WORLD_HEIGHT 39      //맵의 높이

/*함수*/
void SetCurrentCursorPos(int x, int y);      //현재 커서 위치 변경 함수
COORD GetCurrentCursorPos();   //커서 위치 가져오는 함수
void MakeWorld();      //맵 만들기  
void RemoveCursor();      //커서 지우기
void Colorset(int backColor, int textColor);      //폰트색 변경(글자배경색, 글자색)
void ProcessKeyInput();       //키입력


/*전역변수*/
int totalSpeed = 5;                 //전체 속도


void main() {
    system("mode con cols=200 lines=60");      //콘솔 크기 조정
    SetConsoleTitle(TEXT("Conqure Us"));        //콘솔 이름 설정
    initTap();
    RemoveCursor();
    MakeWorld();
    drawFirstTap();
    while (1) {
        ProcessKeyInput();
    }


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

void ProcessKeyInput() {//키 입력받는 함수
    int key;
    // QE 입력 받으면 -> 바이러스/감염경로/배 강화/아이템 버튼 사이 이동 (Q-왼쪽, E-오른쪽)
    // WASD 입력 받으면 -> 각 탭에서 여러 선택사항 사이 이동 (W-위쪽, A-왼쪽, S-아래쪽, D-오른쪽)
    // F 입력 받으면 -> 각 버튼 선택


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
                if (currentTap == 0) {      //바이러스 강화 탭일경우
                    if (check == 0) {
                        removeTap();
                        colorChangeVirusTap(0, currentWaterLv);
                        check = 1;
                        break;
                    }
                    if (currentvt == 0) {           //바이러스 강화 탭 중 전파력일 경우
                        check = 1;
                        colorChangeVirusTap(0, currentWaterLv);
                        break;
                    }
                    else if (currentvt == 1) {      //바이러스 강화 탭 중 치사율일 경우
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
                else if (currentTap == 1) {     //감염 경로 강화탭일경우
                    if (check == 0) {
                        removeTap();
                        colorChangeRouteTap(0);
                        check = 1;
                        break;
                    }
                    if (currentrt == 0) {       //감염경로 동물
                        check = 1;
                        colorChangeRouteTap(0);
                        break;
                    }
                    else if (currentrt == 1) {  //감염경로 혈액
                        check = 1;
                        colorChangeRouteTap(1);
                        break;
                    }
                    else if (currentrt == 2) {      //감염경로 공기
                        check = 1;
                        colorChangeRouteTap(2);
                        break;
                    }
                    else if (currentrt == 3) {      //감염경로 물
                        check = 1;
                        colorChangeRouteTap(3);
                        break;
                    }
                    else if (currentrt == 4) {      //감염경로 선착장
                        check = 1;
                        colorChangeRouteTap(4);
                        break;
                    }
                    break;
                }
                else if (currentTap == 2) { // 배 강화
                    if (check == 0) {
                        colorChangeShipTap(0);
                        check = 1;
                        break;
                    }

                    if (currentst == 0) { // 공격력
                        check = 1;
                        colorChangeShipTap(0);
                        break;
                    }

                    else if (currentst == 1) { // 내구력
                        check = 1;
                        colorChangeShipTap(1);
                        break;
                    }
                    else if (currentst == 2) { // 속도
                        check = 1;
                        colorChangeShipTap(2);
                        break;
                    }
                    break;
                }
                else if (currentTap == 3) { //아이템탭 선택 시
                    if (check == 0) {
                        removeTap();
                        colorChangeItemTap(0);
                        check = 1;
                        break;
                    }
                    if (currentit == 0) { //가짜기름유포(백신 배 속도 감소)
                        check = 1;
                        colorChangeItemTap(0);
                        break;
                    }
                    else if (currentit == 1) { //주인공 배 체력 회복
                        check = 1;
                        colorChangeItemTap(1);
                        break;
                    }
                    else if (currentit == 2) { // 일시적 속도 증가 최대로(1)
                        check = 1;
                        colorChangeItemTap(2);
                        break;
                    }
                    else if (currentit == 3) { // 모든 상대 배 부시기
                        check = 1;
                        colorChangeItemTap(3);
                        break;
                    }
                    else if (currentit == 4) { // 얻는 골드 획득량 영구적 증가
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
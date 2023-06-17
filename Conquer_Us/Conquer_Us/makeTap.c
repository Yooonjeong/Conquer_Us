#include "makeTap.h"
#include "data.h"

void removeTap() {      //�� �����
    SetCurrentCursorPos(5, 45);
    Colorset(black, white);
    for (int i = 0; i < 63; i++) {
        for (int j = 0; j < 14; j++) {
            SetCurrentCursorPos(5 + i, 45 + j);
            printf(" ");
        }
    }
}

void initTap() {    //�⺻ ���� �ʱ�ȭ
    for (int i = 0; i < 5; i++) { vt.fatality[i] = 0; }
    for (int i = 0; i < 5; i++) { vt.propagation[i] = 0; }
    st.power = 0;
    st.health = 0;
    st.speed = 0;
    rt.animal = 0;
    rt.blood = 0;
    rt.air = 0;
    rt.water = 0;
    rt.port = 0;
    it.oil = 0;
    it.jamming = 0;
    it.toground = 0;
    it.engine = 0;
    it.hostage = 0;
}
void drawBox(int fstPosX, int fstPosY, int width, int height) {     //�ǿ��� �簢�� �׸��� �Լ�
    SetCurrentCursorPos(fstPosX, fstPosY);
    for (int i = 0; i < width; i++) {
        SetCurrentCursorPos(fstPosX + i, fstPosY);
        if (i == 0) {
            printf("��");
        }
        else if (i == width - 1) {
            printf("��");
        }
        else {
            printf("��");
        }
    }
    for (int i = 0; i < height; i++) {
        SetCurrentCursorPos(fstPosX, fstPosY + i + 1);
        printf("��");
        SetCurrentCursorPos(fstPosX + width - 1, fstPosY + i + 1);
        printf("��");
    }
    for (int i = 0; i < width; i++) {
        SetCurrentCursorPos(fstPosX + i, fstPosY + height);
        if (i == 0) {
            printf("��");
        }
        else if (i == width - 1) {
            printf("��");
        }
        else {
            printf("��");
        }
    }
}
void colorChangeVirusTap(int i, int j) {        //���� ��ġ�� ���� �� ����-���̷��� ��
    removeTap();
    if (i == 0) {
        Colorset(black, sky);
        drawBox(10, 47, 16, 6);
        SetCurrentCursorPos(17, 48);
        if (currentPropagation < 2) {
            printf("%d G", goldPropagation[currentPropagation]);
        }
        else {
            printf("�Ұ�");
        }
        SetCurrentCursorPos(15, 50);
        printf("�� �� ��");
        SetCurrentCursorPos(16, 52);
        if (vt.propagation[j] - rt.animal < 2) {
            printf("Lv. %d", vt.propagation[j] - rt.animal);
        }
        else { printf("Lv. MAX"); }
        Colorset(black, white);
        drawBox(30, 47, 16, 6);
        SetCurrentCursorPos(37, 48);
        if (currentFatality < 2) {
            printf("%d G", goldFatality[currentFatality]);
        }
        else {
            printf("�Ұ�");
        }
        SetCurrentCursorPos(35, 50);
        printf("ġ �� ��");
        SetCurrentCursorPos(36, 52);
        if (currentBlood == 1 && vt.fatality[j] - rt.blood * 2 < 2) {
            printf("Lv. %d", vt.fatality[j] - rt.blood * 2);
        }
        else if (currentBlood != 1 && vt.fatality[j] < 2) {
            printf("Lv. %d", vt.fatality[j]);
        }
        else {
            printf("Lv. MAX");
        }
        drawBox(50, 47, 16, 6);
        SetCurrentCursorPos(57, 48);
        if (vt.goldup != 2)
            printf("%d G", goldGoldup[vt.goldup]);
        else
            printf("�Ұ�");
        SetCurrentCursorPos(53, 50);
        printf("��ȭ ȹ�淮");
        SetCurrentCursorPos(56, 52);
        if (vt.goldup != 2)       //�ְ� ������ �ƴϸ�
            printf("Lv. %d", vt.goldup);     //���ǵ� ����
        else {
            printf("Lv. MAX");
        }
    }
    else if (i == 1) {
        Colorset(black, white);
        drawBox(10, 47, 16, 6);
        SetCurrentCursorPos(17, 48);
        if (currentPropagation < 2) {
            printf("%d G", goldPropagation[currentPropagation]);
        }
        else {
            printf("�Ұ�");
        }
        SetCurrentCursorPos(15, 50);
        printf("�� �� ��");
        SetCurrentCursorPos(16, 52);
        if (vt.propagation[j] - rt.animal < 2) {
            printf("Lv. %d", vt.propagation[j] - rt.animal);
        }
        else { printf("Lv. MAX"); }
        Colorset(black, sky);
        drawBox(30, 47, 16, 6);
        SetCurrentCursorPos(37, 48);
        if (currentFatality < 2) {
            printf("%d G", goldFatality[currentFatality]);
        }
        else {
            printf("�Ұ�");
        }
        SetCurrentCursorPos(35, 50);
        printf("ġ �� ��");
        SetCurrentCursorPos(36, 52);
        if (currentBlood == 1 && vt.fatality[j] - rt.blood * 2 < 2) {
            printf("Lv. %d", vt.fatality[j] - rt.blood * 2);
        }
        else if (currentBlood != 1 && vt.fatality[j] < 2) {
            printf("Lv. %d", vt.fatality[j]);
        }
        else {
            printf("Lv. MAX");
        }
        Colorset(black, white);
        drawBox(50, 47, 16, 6);
        SetCurrentCursorPos(57, 48);
        if (vt.goldup != 2)
            printf("%d G", goldGoldup[vt.goldup]);
        else
            printf("�Ұ�");
        SetCurrentCursorPos(53, 50);
        printf("��ȭ ȹ�淮");
        SetCurrentCursorPos(56, 52);
        if (vt.goldup != 2)       //�ְ� ������ �ƴϸ�
            printf("Lv. %d", vt.goldup);     //���ǵ� ����
        else {
            printf("Lv. MAX");
        }
    }
    else if (i == 2) {
        Colorset(black, white);
        drawBox(10, 47, 16, 6);
        SetCurrentCursorPos(17, 48);
        if (currentPropagation < 2) {
            printf("%d G", goldPropagation[currentPropagation]);
        }
        else {
            printf("�Ұ�");
        }
        SetCurrentCursorPos(15, 50);
        printf("�� �� ��");
        SetCurrentCursorPos(16, 52);
        if (vt.propagation[j] - rt.animal < 2) {
            printf("Lv. %d", vt.propagation[j] - rt.animal);
        }
        else { printf("Lv. MAX"); }
        drawBox(30, 47, 16, 6);
        SetCurrentCursorPos(37, 48);
        if (currentFatality < 2) {
            printf("%d G", goldFatality[currentFatality]);
        }
        else {
            printf("�Ұ�");
        }
        SetCurrentCursorPos(35, 50);
        printf("ġ �� ��");
        SetCurrentCursorPos(36, 52);
        if (currentBlood == 1 && vt.fatality[j] - rt.blood * 2 < 2) {
            printf("Lv. %d", vt.fatality[j] - rt.blood * 2);
        }
        else if (currentBlood != 1 && vt.fatality[j] < 2) {
            printf("Lv. %d", vt.fatality[j]);
        }
        else {
            printf("Lv. MAX");
        }
        Colorset(black, sky);
        drawBox(50, 47, 16, 6);
        SetCurrentCursorPos(57, 48);
        if (vt.goldup != 2)
            printf("%d G", goldGoldup[vt.goldup]);
        else
            printf("�Ұ�");
        SetCurrentCursorPos(53, 50);
        printf("��ȭ ȹ�淮");
        SetCurrentCursorPos(56, 52);
        if (vt.goldup != 2)       //�ְ� ������ �ƴϸ�
            printf("Lv. %d", vt.goldup);     //���ǵ� ����
        else {
            printf("Lv. MAX");
        }
    }
    Colorset(black, white);

}
void colorChangeRouteTap(int i) {        //���� ��ġ�� ���� �� ����-������� ��
    removeTap();
    if (i == 0) {
        Colorset(black, sky);
        drawBox(10, 45, 16, 6);
        SetCurrentCursorPos(17, 46);
        if (rt.animal < 1) {
            printf("%d G", goldAnimal);
        }
        else {
            printf("�Ұ�");
        }
        SetCurrentCursorPos(16, 48);
        printf("�� ��");
        SetCurrentCursorPos(16, 50);
        if (rt.animal < 1) {
            printf("Lv. %d", rt.animal);
        }
        else {
            printf("Lv. MAX");
        }
        Colorset(black, white);
        drawBox(30, 45, 16, 6);
        SetCurrentCursorPos(37, 46);
        if (rt.blood < 1) {
            printf("%d G", goldBlood);
        }
        else {
            printf("�Ұ�");
        }
        SetCurrentCursorPos(36, 48);
        printf("�� ��");
        SetCurrentCursorPos(36, 50);
        if (rt.blood < 1) {
            printf("Lv. %d", rt.blood);
        }
        else {
            printf("Lv. MAX");
        }
        drawBox(50, 45, 16, 6);
        SetCurrentCursorPos(57, 46);
        if (rt.air < 1) {
            printf("%d G", goldAir);
        }
        else {
            printf("�Ұ�");
        }
        SetCurrentCursorPos(56, 48);
        printf("�� ��");
        SetCurrentCursorPos(56, 50);
        if (rt.air < 1) {
            printf("Lv. %d", rt.air);
        }
        else {
            printf("Lv. MAX");
        }
        drawBox(20, 52, 16, 6);
        SetCurrentCursorPos(26, 53);
        if (rt.water != 4)
            printf("%d G", goldWater[rt.water]);
        else
            printf("�Ұ�");
        SetCurrentCursorPos(27, 55);
        printf("��");
        SetCurrentCursorPos(25, 57);
        if (rt.water != 4)
            printf("Lv. %d", rt.water);
        else {
            printf("Lv. MAX");
        }
        drawBox(40, 52, 16, 6);
        SetCurrentCursorPos(47, 53);
        if (rt.port != 5)
            printf("%d G", goldHealing[rt.port]);
        else
            printf("�Ұ�");
        SetCurrentCursorPos(45, 55);
        printf("�� �� ��");
        SetCurrentCursorPos(46, 57);
        if (rt.port != 5)
            printf("Lv. %d", rt.port);
        else {
            printf("Lv. MAX");
        }
    }
    else if (i == 1) {
        Colorset(black, white);
        drawBox(10, 45, 16, 6);
        SetCurrentCursorPos(17, 46);
        if (rt.animal < 1) {
            printf("%d G", goldAnimal);
        }
        else {
            printf("�Ұ�");
        }
        SetCurrentCursorPos(16, 48);
        printf("�� ��");
        SetCurrentCursorPos(16, 50);
        if (rt.animal < 1) {
            printf("Lv. %d", rt.animal);
        }
        else {
            printf("Lv. MAX");
        }
        Colorset(black, sky);
        drawBox(30, 45, 16, 6);
        SetCurrentCursorPos(37, 46);
        if (rt.blood < 1) {
            printf("%d G", goldBlood);
        }
        else {
            printf("�Ұ�");
        }
        SetCurrentCursorPos(36, 48);
        printf("�� ��");
        SetCurrentCursorPos(36, 50);
        if (rt.blood < 1) {
            printf("Lv. %d", rt.blood);
        }
        else {
            printf("Lv. MAX");
        }
        Colorset(black, white);
        drawBox(50, 45, 16, 6);
        SetCurrentCursorPos(57, 46);
        if (rt.air < 1) {
            printf("%d G", goldAir);
        }
        else {
            printf("�Ұ�");
        }
        SetCurrentCursorPos(56, 48);
        printf("�� ��");
        SetCurrentCursorPos(56, 50);
        if (rt.air < 1) {
            printf("Lv. %d", rt.air);
        }
        else {
            printf("Lv. MAX");
        }
        drawBox(20, 52, 16, 6);
        SetCurrentCursorPos(26, 53);
        if (rt.water != 4)
            printf("%d G", goldWater[rt.water]);
        else
            printf("�Ұ�");
        SetCurrentCursorPos(27, 55);
        printf("��");
        SetCurrentCursorPos(25, 57);
        if (rt.water != 4)
            printf("Lv. %d", rt.water);
        else {
            printf("Lv. MAX");
        }
        drawBox(40, 52, 16, 6);
        SetCurrentCursorPos(47, 53);
        if (rt.port != 5)
            printf("%d G", goldHealing[rt.port]);
        else
            printf("�Ұ�");
        SetCurrentCursorPos(45, 55);
        printf("�� �� ��");
        SetCurrentCursorPos(46, 57);
        if (rt.port != 5)
            printf("Lv. %d", rt.port);
        else {
            printf("Lv. MAX");
        }
    }
    else if (i == 2) {
        Colorset(black, white);
        drawBox(10, 45, 16, 6);
        SetCurrentCursorPos(17, 46);
        if (rt.animal < 1) {
            printf("%d G", goldAnimal);
        }
        else {
            printf("�Ұ�");
        }
        SetCurrentCursorPos(16, 48);
        printf("�� ��");
        SetCurrentCursorPos(16, 50);
        if (rt.animal < 1) {
            printf("Lv. %d", rt.animal);
        }
        else {
            printf("Lv. MAX");
        }
        drawBox(30, 45, 16, 6);
        SetCurrentCursorPos(37, 46);
        if (rt.blood < 1) {
            printf("%d G", goldBlood);
        }
        else {
            printf("�Ұ�");
        }
        SetCurrentCursorPos(36, 48);
        printf("�� ��");
        SetCurrentCursorPos(36, 50);
        if (rt.blood < 1) {
            printf("Lv. %d", rt.blood);
        }
        else {
            printf("Lv. MAX");
        }
        Colorset(black, sky);
        drawBox(50, 45, 16, 6);
        SetCurrentCursorPos(57, 46);
        if (rt.air < 1) {
            printf("%d G", goldAir);
        }
        else {
            printf("�Ұ�");
        }
        SetCurrentCursorPos(56, 48);
        printf("�� ��");
        SetCurrentCursorPos(56, 50);
        if (rt.air < 1) {
            printf("Lv. %d", rt.air);
        }
        else {
            printf("Lv. MAX");
        }
        Colorset(black, white);
        drawBox(20, 52, 16, 6);
        SetCurrentCursorPos(26, 53);
        if (rt.water != 4)
            printf("%d G", goldWater[rt.water]);
        else
            printf("�Ұ�");
        SetCurrentCursorPos(27, 55);
        printf("��");
        SetCurrentCursorPos(25, 57);
        if (rt.water != 4)
            printf("Lv. %d", rt.water);
        else {
            printf("Lv. MAX");
        }
        drawBox(40, 52, 16, 6);
        SetCurrentCursorPos(47, 53);
        if (rt.port != 5)
            printf("%d G", goldHealing[rt.port]);
        else
            printf("�Ұ�");
        SetCurrentCursorPos(45, 55);
        printf("�� �� ��");
        SetCurrentCursorPos(46, 57);
        if (rt.port != 5)
            printf("Lv. %d", rt.port);
        else {
            printf("Lv. MAX");
        }
    }
    else if (i == 3) {
        Colorset(black, white);
        drawBox(10, 45, 16, 6);
        SetCurrentCursorPos(17, 46);
        if (rt.animal < 1) {
            printf("%d G", goldAnimal);
        }
        else {
            printf("�Ұ�");
        }
        SetCurrentCursorPos(16, 48);
        printf("�� ��");
        SetCurrentCursorPos(16, 50);
        if (rt.animal < 1) {
            printf("Lv. %d", rt.animal);
        }
        else {
            printf("Lv. MAX");
        }
        drawBox(30, 45, 16, 6);
        SetCurrentCursorPos(37, 46);
        if (rt.blood < 1) {
            printf("%d G", goldBlood);
        }
        else {
            printf("�Ұ�");
        }
        SetCurrentCursorPos(36, 48);
        printf("�� ��");
        SetCurrentCursorPos(36, 50);
        if (rt.blood < 1) {
            printf("Lv. %d", rt.blood);
        }
        else {
            printf("Lv. MAX");
        }
        drawBox(50, 45, 16, 6);
        SetCurrentCursorPos(57, 46);
        if (rt.air < 1) {
            printf("%d G", goldAir);
        }
        else {
            printf("�Ұ�");
        }
        SetCurrentCursorPos(56, 48);
        printf("�� ��");
        SetCurrentCursorPos(56, 50);
        if (rt.air < 1) {
            printf("Lv. %d", rt.air);
        }
        else {
            printf("Lv. MAX");
        }
        Colorset(black, sky);
        drawBox(20, 52, 16, 6);
        SetCurrentCursorPos(26, 53);
        if (rt.water != 4)
            printf("%d G", goldWater[rt.water]);
        else
            printf("�Ұ�");
        SetCurrentCursorPos(27, 55);
        printf("��");
        SetCurrentCursorPos(25, 57);
        if (rt.water != 4)
            printf("Lv. %d", rt.water);
        else {
            printf("Lv. MAX");
        }
        Colorset(black, white);
        drawBox(40, 52, 16, 6);
        SetCurrentCursorPos(47, 53);
        if (rt.port != 5)
            printf("%d G", goldHealing[rt.port]);
        else
            printf("�Ұ�");
        SetCurrentCursorPos(45, 55);
        printf("�� �� ��");
        SetCurrentCursorPos(46, 57);
        if (rt.port != 5)
            printf("Lv. %d", rt.port);
        else {
            printf("Lv. MAX");
        }
    }
    else if (i == 4) {
        Colorset(black, white);
        drawBox(10, 45, 16, 6);
        SetCurrentCursorPos(17, 46);
        if (rt.animal < 1) {
            printf("%d G", goldAnimal);
        }
        else {
            printf("�Ұ�");
        }
        SetCurrentCursorPos(16, 48);
        printf("�� ��");
        SetCurrentCursorPos(16, 50);
        if (rt.animal < 1) {
            printf("Lv. %d", rt.animal);
        }
        else {
            printf("Lv. MAX");
        }
        drawBox(30, 45, 16, 6);
        SetCurrentCursorPos(37, 46);
        if (rt.blood < 1) {
            printf("%d G", goldBlood);
        }
        else {
            printf("�Ұ�");
        }
        SetCurrentCursorPos(36, 48);
        printf("�� ��");
        SetCurrentCursorPos(36, 50);
        if (rt.blood < 1) {
            printf("Lv. %d", rt.blood);
        }
        else {
            printf("Lv. MAX");
        }
        drawBox(50, 45, 16, 6);
        SetCurrentCursorPos(57, 46);
        if (rt.air < 1) {
            printf("%d G", goldAir);
        }
        else {
            printf("�Ұ�");
        }
        SetCurrentCursorPos(56, 48);
        printf("�� ��");
        SetCurrentCursorPos(56, 50);
        if (rt.air < 1) {
            printf("Lv. %d", rt.air);
        }
        else {
            printf("Lv. MAX");
        }
        drawBox(20, 52, 16, 6);
        SetCurrentCursorPos(26, 53);
        if (rt.water != 4)
            printf("%d G", goldWater[rt.water]);
        else
            printf("�Ұ�");
        SetCurrentCursorPos(27, 55);
        printf("��");
        SetCurrentCursorPos(25, 57);
        if (rt.water != 4)
            printf("Lv. %d", rt.water);
        else {
            printf("Lv. MAX");
        }
        Colorset(black, sky);
        drawBox(40, 52, 16, 6);
        SetCurrentCursorPos(47, 53);
        if (rt.port != 5)
            printf("%d G", goldHealing[rt.port]);
        else
            printf("�Ұ�");
        SetCurrentCursorPos(45, 55);
        printf("�� �� ��");
        SetCurrentCursorPos(46, 57);
        if (rt.port != 5)
            printf("Lv. %d", rt.port);
        else {
            printf("Lv. MAX");
        }
    }
}

void colorChangeShipTap(int i) {        //���� ��ġ�� ���� �� ����-�� ��ȭ ��
    removeTap();
    if (i == 0) {
        Colorset(black, sky);
        drawBox(10, 47, 16, 6);
        SetCurrentCursorPos(17, 48);
        if (st.power != 10)
            printf("%d G", goldPower[st.power]);
        else
            printf("�Ұ�");
        SetCurrentCursorPos(15, 50);
        printf("�� �� ��");
        SetCurrentCursorPos(16, 52);
        if (st.power != 10)
            printf("Lv. %d", st.power);
        else
            printf("Lv. MAX");
        Colorset(black, white);
        drawBox(30, 47, 16, 6);
        SetCurrentCursorPos(37, 48);
        if (st.health != 10)
            printf("%d G", goldHealth[st.health]);
        else
            printf("�Ұ�");
        SetCurrentCursorPos(35, 50);
        printf("�� �� ��");
        SetCurrentCursorPos(36, 52);
        if (st.health != 10)
            printf("Lv. %d", st.health);
        else
            printf("Lv. MAX");
        drawBox(50, 47, 16, 6);
        SetCurrentCursorPos(57, 48);
        if (st.speed != 5)
            printf("%d G", goldSpeed[st.speed]);
        else
            printf("�Ұ�");
        SetCurrentCursorPos(56, 50);
        printf("�� ��");
        SetCurrentCursorPos(56, 52);
        if (st.speed != 5)       //�ְ� ������ �ƴϸ�
            printf("Lv. %d", st.speed);     //���ǵ� ����
        else {
            printf("Lv. MAX");
        }
    }
    else if (i == 1) {
        Colorset(black, white);
        drawBox(10, 47, 16, 6);
        SetCurrentCursorPos(17, 48);
        if (st.power != 10)
            printf("%d G", goldPower[st.power]);
        else
            printf("�Ұ�");
        SetCurrentCursorPos(15, 50);
        printf("�� �� ��");
        SetCurrentCursorPos(16, 52);
        if (st.power != 10)
            printf("Lv. %d", st.power);
        else
            printf("Lv. MAX");
        Colorset(black, sky);
        drawBox(30, 47, 16, 6);
        SetCurrentCursorPos(37, 48);
        if (st.health != 10)
            printf("%d G", goldHealth[st.health]);
        else
            printf("�Ұ�");
        SetCurrentCursorPos(35, 50);
        printf("�� �� ��");
        SetCurrentCursorPos(36, 52);
        if (st.health != 10)
            printf("Lv. %d", st.health);
        else
            printf("Lv. MAX");
        Colorset(black, white);
        drawBox(50, 47, 16, 6);
        SetCurrentCursorPos(57, 48);
        if (st.speed != 5)
            printf("%d G", goldSpeed[st.speed]);
        else
            printf("�Ұ�");
        SetCurrentCursorPos(56, 50);
        printf("�� ��");
        SetCurrentCursorPos(56, 52);
        if (st.speed != 5)       //�ְ� ������ �ƴϸ�
            printf("Lv. %d", st.speed);     //���ǵ� ����
        else {
            printf("Lv. MAX");
        }
    }
    else if (i == 2) {
        Colorset(black, white);
        drawBox(10, 47, 16, 6);
        SetCurrentCursorPos(17, 48);
        if (st.power != 10)
            printf("%d G", goldPower[st.power]);
        else
            printf("�Ұ�");
        SetCurrentCursorPos(15, 50);
        printf("�� �� ��");
        SetCurrentCursorPos(16, 52);
        if (st.power != 10)
            printf("Lv. %d", st.power);
        else
            printf("Lv. MAX");
        drawBox(30, 47, 16, 6);
        SetCurrentCursorPos(37, 48);
        if (st.health != 10)
            printf("%d G", goldHealth[st.health]);
        else
            printf("�Ұ�");
        SetCurrentCursorPos(35, 50);
        printf("�� �� ��");
        SetCurrentCursorPos(36, 52);
        if (st.health != 10)
            printf("Lv. %d", st.health);
        else
            printf("Lv. MAX");
        Colorset(black, sky);
        drawBox(50, 47, 16, 6);
        SetCurrentCursorPos(57, 48);
        if (st.speed != 5)
            printf("%d G", goldSpeed[st.speed]);
        else
            printf("�Ұ�");
        SetCurrentCursorPos(56, 50);
        printf("�� ��");
        SetCurrentCursorPos(56, 52);
        if (st.speed != 5)       //�ְ� ������ �ƴϸ�
            printf("Lv. %d", st.speed);     //���ǵ� ����
        else {
            printf("Lv. MAX");
        }
    }
    Colorset(black, white);

}
void colorChangeItemTap(int i) {        //���� ��ġ�� ���� �� ����-������ ��
    removeTap();
    if (i == 0) {
        Colorset(black, sky);
        drawBox(10, 45, 16, 6);
        SetCurrentCursorPos(13, 47);
        printf("��¥�⸧����");
        SetCurrentCursorPos(17, 49);
        printf("%d ��", itemList[0]);
        Colorset(black, white);
        drawBox(30, 45, 16, 6);
        SetCurrentCursorPos(35, 47);
        printf("���ȸ��");
        SetCurrentCursorPos(37, 49);
        printf("%d ��", itemList[1]);
        drawBox(50, 45, 16, 6);
        SetCurrentCursorPos(54, 47);
        printf("�ӵ� �ִ�");
        SetCurrentCursorPos(57, 49);
        printf("%d ��", itemList[2]);
        drawBox(20, 52, 16, 6);
        SetCurrentCursorPos(25, 54);
        printf("��    ��");
        SetCurrentCursorPos(27, 56);
        printf("%d ��", itemList[3]);
        drawBox(40, 52, 16, 6);
        SetCurrentCursorPos(45, 54);
        printf("�� �� ��");
        SetCurrentCursorPos(47, 56);
        printf("%d ��", itemList[4]);
    }
    else if (i == 1) {
        Colorset(black, white);
        drawBox(10, 45, 16, 6);
        SetCurrentCursorPos(13, 47);
        printf("��¥�⸧����");
        SetCurrentCursorPos(17, 49);
        printf("%d ��", itemList[0]);
        Colorset(black, sky);
        drawBox(30, 45, 16, 6);
        SetCurrentCursorPos(35, 47);
        printf("���ȸ��");
        SetCurrentCursorPos(37, 49);
        printf("%d ��", itemList[1]);
        Colorset(black, white);
        drawBox(50, 45, 16, 6);
        SetCurrentCursorPos(54, 47);
        printf("�ӵ� �ִ�");
        SetCurrentCursorPos(57, 49);
        printf("%d ��", itemList[2]);
        drawBox(20, 52, 16, 6);
        SetCurrentCursorPos(25, 54);
        printf("��    ��");
        SetCurrentCursorPos(27, 56);
        printf("%d ��", itemList[3]);
        drawBox(40, 52, 16, 6);
        SetCurrentCursorPos(45, 54);
        printf("�� �� ��");
        SetCurrentCursorPos(47, 56);
        printf("%d ��", itemList[4]);
    }
    else if (i == 2) {
        Colorset(black, white);
        drawBox(10, 45, 16, 6);
        SetCurrentCursorPos(13, 47);
        printf("��¥�⸧����");
        SetCurrentCursorPos(17, 49);
        printf("%d ��", itemList[0]);
        drawBox(30, 45, 16, 6);
        SetCurrentCursorPos(35, 47);
        printf("���ȸ��");
        SetCurrentCursorPos(37, 49);
        printf("%d ��", itemList[1]);
        Colorset(black, sky);
        drawBox(50, 45, 16, 6);
        SetCurrentCursorPos(54, 47);
        printf("�ӵ� �ִ�");
        SetCurrentCursorPos(57, 49);
        printf("%d ��", itemList[2]);
        Colorset(black, white);
        drawBox(20, 52, 16, 6);
        SetCurrentCursorPos(25, 54);
        printf("��    ��");
        SetCurrentCursorPos(27, 56);
        printf("%d ��", itemList[3]);
        drawBox(40, 52, 16, 6);
        SetCurrentCursorPos(45, 54);
        printf("�� �� ��");
        SetCurrentCursorPos(47, 56);
        printf("%d ��", itemList[4]);
    }
    else if (i == 3) {
        Colorset(black, white);
        drawBox(10, 45, 16, 6);
        SetCurrentCursorPos(13, 47);
        printf("��¥�⸧����");
        SetCurrentCursorPos(17, 49);
        printf("%d ��", itemList[0]);
        drawBox(30, 45, 16, 6);
        SetCurrentCursorPos(35, 47);
        printf("���ȸ��");
        SetCurrentCursorPos(37, 49);
        printf("%d ��", itemList[1]);
        drawBox(50, 45, 16, 6);
        SetCurrentCursorPos(54, 47);
        printf("�ӵ� �ִ�");
        SetCurrentCursorPos(57, 49);
        printf("%d ��", itemList[2]);
        Colorset(black, sky);
        drawBox(20, 52, 16, 6);
        SetCurrentCursorPos(25, 54);
        printf("��    ��");
        SetCurrentCursorPos(27, 56);
        printf("%d ��", itemList[3]);
        Colorset(black, white);
        drawBox(40, 52, 16, 6);
        SetCurrentCursorPos(45, 54);
        printf("�� �� ��");
        SetCurrentCursorPos(47, 56);
        printf("%d ��", itemList[4]);
    }
    else if (i == 4) {
        Colorset(black, white);
        drawBox(10, 45, 16, 6);
        SetCurrentCursorPos(13, 47);
        printf("��¥�⸧����");
        SetCurrentCursorPos(17, 49);
        printf("%d ��", itemList[0]);
        drawBox(30, 45, 16, 6);
        SetCurrentCursorPos(35, 47);
        printf("���ȸ��");
        SetCurrentCursorPos(37, 49);
        printf("%d ��", itemList[1]);
        drawBox(50, 45, 16, 6);
        SetCurrentCursorPos(54, 47);
        printf("�ӵ� �ִ�");
        SetCurrentCursorPos(57, 49);
        printf("%d ��", itemList[2]);
        drawBox(20, 52, 16, 6);
        SetCurrentCursorPos(25, 54);
        printf("��    ��");
        SetCurrentCursorPos(27, 56);
        printf("%d ��", itemList[3]);
        Colorset(black, sky);
        drawBox(40, 52, 16, 6);
        SetCurrentCursorPos(45, 54);
        printf("�� �� ��");
        SetCurrentCursorPos(47, 56);
        printf("%d ��", itemList[4]);
    }
    Colorset(black, white);
}

void selectedTap(int i) {       //���õ� �� ��Ÿ����
    if (i == 0) {
        removeTap();
        Colorset(black, brightYellow);
        drawBox(10, 42, 12, 2);
        SetCurrentCursorPos(13, 43);
        printf("���̷���");
        Colorset(black, white);
        drawBox(25, 42, 12, 2);
        SetCurrentCursorPos(28, 43);
        printf("�������");
        drawBox(40, 42, 12, 2);
        SetCurrentCursorPos(43, 43);
        printf("�� ��ȭ");
        drawBox(55, 42, 12, 2);
        SetCurrentCursorPos(59, 43);
        printf("������");
    }
    else if (i == 1) {
        removeTap();
        Colorset(black, white);
        drawBox(10, 42, 12, 2);
        SetCurrentCursorPos(13, 43);
        printf("���̷���");
        Colorset(black, brightYellow);
        drawBox(25, 42, 12, 2);
        SetCurrentCursorPos(28, 43);
        printf("�������");
        Colorset(black, white);
        drawBox(40, 42, 12, 2);
        SetCurrentCursorPos(43, 43);
        printf("�� ��ȭ");
        drawBox(55, 42, 12, 2);
        SetCurrentCursorPos(59, 43);
        printf("������");
    }
    else if (i == 2) {
        removeTap();
        Colorset(black, white);
        drawBox(10, 42, 12, 2);
        SetCurrentCursorPos(13, 43);
        printf("���̷���");
        drawBox(25, 42, 12, 2);
        SetCurrentCursorPos(28, 43);
        printf("�������");
        Colorset(black, brightYellow);
        drawBox(40, 42, 12, 2);
        SetCurrentCursorPos(43, 43);
        printf("�� ��ȭ");
        Colorset(black, white);
        drawBox(55, 42, 12, 2);
        SetCurrentCursorPos(59, 43);
        printf("������");
    }
    else if (i == 3) {
        removeTap();
        Colorset(black, white);
        drawBox(10, 42, 12, 2);
        SetCurrentCursorPos(13, 43);
        printf("���̷���");
        drawBox(25, 42, 12, 2);
        SetCurrentCursorPos(28, 43);
        printf("�������");
        drawBox(40, 42, 12, 2);
        SetCurrentCursorPos(43, 43);
        printf("�� ��ȭ");
        Colorset(black, brightYellow);
        drawBox(55, 42, 12, 2);
        SetCurrentCursorPos(59, 43);
        printf("������");
    }
    Colorset(black, white);
}

void drawFirstTap() {        //�ƹ� �͵� �����ϱ� �� ó�� �� ��Ÿ����
    Colorset(black, white);
    int key = 0;
    int check = 0;
    SetCurrentCursorPos(2, 40);
    int curPosX = 2;
    int curPosY = 40;
    for (int i = 0; i < TAP_WIDTH; i++) {
        SetCurrentCursorPos(curPosX + i * 2, curPosY);
        printf("��");
    }
    for (int i = 0; i < TAP_WIDTH; i++) {
        SetCurrentCursorPos(curPosX + i * 2, curPosY + TAP_HEIGHT - 1);
        printf("��");
    }
    for (int i = 0; i < TAP_HEIGHT; i++) {
        SetCurrentCursorPos(curPosX, curPosY + i);
        if (i == 0) {
            printf("��");
        }
        else if (i == TAP_HEIGHT - 1) {
            printf("��");
        }
        else printf("��");
    }
    for (int i = 1; i < TAP_HEIGHT - 1; i++) {
        SetCurrentCursorPos(curPosX + TAP_WIDTH - 1, curPosY + i);
        printf("��");
    }
    for (int i = 0; i < TAP_HEIGHT; i++) {
        SetCurrentCursorPos(curPosX + (TAP_WIDTH - 1) * 2, curPosY + i);
        if (i == 0) {
            printf("��");
        }
        else if (i == TAP_HEIGHT - 1) {
            printf("��");
        }
        else printf("��");
    }

    selectedTap(0);
}

/*Time ����*/
void printTime() {
    Colorset(black, white);
    SetCurrentCursorPos(126, 39);
    printf("                              ");
    SetCurrentCursorPos(126, 39);
    printf("����ð� : %d�� %d�ð� %d��", vt.min / 5760, vt.min % 5760 / 240, vt.min % 240 / 4);
}

/*Gold ����*/
void printGold() {
    Colorset(black, white);
    SetCurrentCursorPos(76, 39);
    printf("         ");
    SetCurrentCursorPos(76, 39);
    printf("%dG", vt.gold);
}

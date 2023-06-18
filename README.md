# ConquerUs

바이러스를 제작 및 확산시켜 백신의 확산을 막고 전세계 사람들을 감염시키는 게임


## 설치
프로젝트 개발 환경
* OS : Windows 11
* Language : C
* Tools : Visual Studio 2019

해당  저장소를 로컬 컴퓨터에 복제

  git clone https://github.com/Yooonjeong/Conquer_Us.git .

컴파일 후 실행


## 구현한 주요 기능 및 구현 기술
* 탭 선택
  * 사용자 입력 (Q/E/W/A/S/D/F)에 따라 탭 이동 및 선택
  * 사용자 전략을 위한 강화 선택 가능

* 플레이어 컨트롤
  * 방향키대로 상하좌우 바다를 이동

* 적 배의 랜덤 생성
  * 시간의 흐름에 따라 적배가 생성되어 랜덤으로 지정된 경로를 항해하고 도착지점에 도달 시 사라짐
  * 적 배의 도착지점 도달로 백신 운반에 성공 시 백신 완성도 5% 상승

* 난이도 조정 기능
  * 스테이지에 따른 적의 업그레이드
    * 시간의 흐름에 따라 1~4일차로 구성
    * 스테이지가 올라갈 수록 적 배의 생성이 많아지고 적을 침몰시키기 어려워짐

* 현재 진행 상황 제공
  * log판에서 플레이어 정보, 현재 상황, 강화 탭의 세부내용 확인 가능
  * 플레이어 배의 파손도 하단의 배 모형으로 확인 가능
  * 사망비율, 백신 완성도 그래프 표현

* 다양한 전략 기능
  * 바이러스 강화 / 감염 경로 강화 / 배 강화
  * 아이템
    * 적 배 침몰시킬 시 랜덤으로 아이템 생성 및 획득 가능
    * 아이템 탭에서 원하는 시점에 적용 가능

* 배경음악 재생
  * 긴장감을 고조시키는 bgm 적용

* 콘솔 색상
  * 플레이어와 적의 구분 및 미적 효과 강조


## 간단 게임 설명
1. 플레이어 / 적 정보

    ![image](https://github.com/Yooonjeong/Conquer_Us/assets/115490096/d3f8d083-304b-4cfe-8a4d-66507272961a)

2. 조작키

* 전략 관련
  ![image](https://github.com/Yooonjeong/Conquer_Us/assets/115490096/8cd59521-cbb9-4717-8644-5d9bdb8fe014)
  
* 배 컨트롤 관련

  ![image](https://github.com/Yooonjeong/Conquer_Us/assets/115490096/ce0d4384-c96c-459b-92f5-387a612e7280)
  
3. 스테이지

    ![image](https://github.com/Yooonjeong/Conquer_Us/assets/115490096/2f0d18c0-32ab-484a-ad67-256d70dd730f)

4. 강화 내용

    ![image](https://github.com/Yooonjeong/Conquer_Us/assets/115490096/65c0f205-d726-4c3c-b070-09656dae30f2)

5. 승리/패배 조건

  * 승리 조건 - 인구 수 절반 감축 (사망 비율 50%)
  * 패배 조건 - 백신 완성도 100% / 4일 동안 인구 수 절반 감축 실패


## 프로그램 실행 화면
1. 시작 화면
![image](https://github.com/Yooonjeong/Conquer_Us/assets/115490096/75c98faf-4f7e-4a38-91a4-51fe66d88940)
- 아무 키나 누르면 시작

2. 인게임 화면
![image](https://github.com/Yooonjeong/Conquer_Us/assets/115490096/69e80957-0694-4b7e-9a1d-ac06ccba149d)

3. GAME OVER 화면
![image](https://github.com/Yooonjeong/Conquer_Us/assets/115490096/7f77d464-5bfb-4ec3-9b54-a44b0fcff312)






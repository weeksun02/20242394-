#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include <time.h>

#define LEN_MIN 15
#define LEN_MAX 50
#define STM_MIN 0
#define STM_MAX 5
#define PROB_MIN 10
#define PROB_MAX 90
#define AGGRO_MIN 0
#define AGGRO_MAX 9
//마동석 이동방향
#define MOVE_LEFT 1
#define MOVE_STAY 0
//좀비의 공격대상
#define ATK_NONE 0
#define ATK_CITIZEN 1
#define ATK_DONGSEOK 2
//마동석 행동
#define ACTION_REST 0
#define ACTION_PROVOKE 1
#define ACTION_PULL 2
//void intro();
void mamove();
void enter1();
void enter2();
void enter3();
void busanhang2();
void busanhang3();
void busanhang31();
void sangtea();
void sangtea2();
void moveall();
void sangtea3();
void start();
void start2();
void ask1();
void sangtea4();
void zomdongseok();
void sandteaall();
int magro = 1;
int sagro = 1;
int stamina = 6;
int length = 0;
int cprob = 0;
int zprob = 0;
int c = 0;
int z = 0;
int m = 0;
int j = 0;
int space = 0;
int sspace = 0;
int ssspace = 0;
int percent = 0;
int sssspace = 0;
int plus = 0;
int rest = 0;
int moving = -1;
char train[50];
char ctizen[50];
char zombie[50];
char ctizom[50];
char madong[50];
int main(void) {


	//intro();
	enter1();
	enter2();
	enter3();

	srand((unsigned int)time(NULL));
	plus = length - 2;
	z = length - 3;
	c = length - 6;
	m = length - 2;
	space = c - 1;
	sspace = m - z;
	sssspace = plus - m;

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	start();

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	while (1) {
		percent = rand() % 100 + 1;


		moveall();
		mamove();//2-4

		Sleep(4000);

		j++;
	}

	return 0;
}

void stop() {
	if (c == 1) {
		printf("\nSUCCESS!\ncitizen(s) escaped to the next train\n");
		exit(0);
	}
	if (sspace == 0) {
		printf("\nGAME OVER!\nCitizen(s) has(have) been attacked by a zombi\n");
		exit(0);
	}
}
void perccent() {
	if (percent < (100 - cprob)) {
		c -= 1;
		sagro += 1;
		if (sagro < AGGRO_MIN) {
			sagro = AGGRO_MIN;
		}
		else if (sagro > AGGRO_MAX) {
			sagro = AGGRO_MAX;
		}
	}
	else {
		sagro -= 1;
		if (sagro < AGGRO_MIN) {
			sagro = AGGRO_MIN;
		}
		else if (sagro > AGGRO_MAX) {
			sagro = AGGRO_MAX;
		}
	}
	if (sagro > magro) {
		if (j % 2 == 0) {
			z -= 1;
			ssspace += 1;

		}
	}
	else if (sagro < magro) {
		if (j % 2 == 0) {
			z -= 1;
			ssspace += 1;

		}
	}
}
void cctizen() {

	for (int i = 0; i < c - 1; i++) {
		ctizen[i] = ' ';
	}
	for (int i = 0; i < c - 1; i++) {
		printf("%c", ctizen[i]);
	}
}
void zzombie() {

	for (int i = 0; i < ssspace; i++) {
		zombie[i] = ' ';
	}
	for (int i = 0; i < ssspace; i++) {
		printf("%c", zombie[i]);
	}
}
void cctizzom() {
	sspace = z - c - 1;
	for (int i = 0; i < sspace; i++) {
		ctizom[i] = ' ';
	}
	for (int i = 0; i < sspace; i++) {
		printf("%c", ctizom[i]);
	}
}
void zomdongseok() {

	for (int i = 0; i < sssspace; i++) {
		madong[i] = ' ';
	}
	for (int i = 0; i < sssspace; i++) {
		printf("%c", madong[i]);
	}
}
void start2() {
	printf("#");
	cctizen();
	printf("c");
	cctizzom();
	printf("z");
	zzombie();
	printf("m");
	zomdongseok();
	printf("#");

}
void busanhang2() { //두번째 줄 출력하는 함수

	perccent();
	printf("#");
	cctizen();
	printf("c");
	cctizzom();
	printf("z");
	zzombie();
	printf("m");
	zomdongseok();
	printf("#");
}

void busanhang3() { //변하지 않는 기차
	for (int i = 1; i <= length; i++) {
		train[i] = '#';
	}
}
void busanhang31() {
	for (int i = 1; i <= length; i++) {
		printf("%c", train[i]);
	}
}
void sangtea() {
	if (percent < (100 - cprob)) {
		printf("citizen : stay %d -> %d(agro:%d->%d)\n", c + 1, c, sagro, sagro + 1);
	}
	else {
		printf("citizen : stay %d(agro:%d->%d)\n", c, sagro + 1, sagro);
	}
	if (percent < zprob) { 	//좀비상태출력-움직였을때
		sangtea2();
	}
	else { //좀비상태출력-제자리일때
		sangtea3();
	}
}
void sangtea3() {
	if (j % 2 == 0) {
		printf("zombie : stay %d\n", z);
	}
	else {
		printf("zombie : stay %d (Can not move)\n", z);
	}
}
void sangtea2() {
	if (j % 2 == 0) {
		printf("zombie : stay %d -> %d\n", z + 1, z);
	}
	else {
		printf("zombie : stay %d (Can not move)\n", z);
	}
}
void sangtea4() {

	printf("madongseok: stay %d(aggro: %d,stamina: %d)", m, magro, stamina);

}
void ask1() {
	moving = -1;
	while (MOVE_STAY > moving || moving > MOVE_LEFT) {
		printf("madongseok move(0:stay, 1:left)>>>");
		scanf_s("%d", &moving);
	}
	if (moving == MOVE_LEFT) {
		m -= 1;
		ssspace -= 1;
		magro += 1;
		sssspace += 1;
		if (magro < AGGRO_MIN) {
			magro = AGGRO_MIN;
		}
		else if (magro > AGGRO_MAX) {
			magro = AGGRO_MAX;
		}

	}
	else if (moving == MOVE_STAY) {
		magro -= 1;

		if (magro < AGGRO_MIN) {
			magro = AGGRO_MIN;
		}
		else if (magro > AGGRO_MAX) {
			magro = AGGRO_MAX;
		}
	}
}
void sangteamama() {
	if (moving == MOVE_LEFT) {
		printf("madongseok: stay %d(aggro: %d->%d,stamona: %d)\n", m, magro -1, magro, stamina);

	}
	else if (moving == MOVE_STAY) {
		printf("madongseok: stay %d(aggro: %d->%d,stamona: %d)\n", m, magro+1, magro, stamina);
	}
}
void sandteaall() {
	printf("citizen does nothing.\n");
	printf("zombie attcked nobody\n");
	if (z == m-1) {
	printf("madongseok action(0:rest , 1:provoke , 2:pull)>>>\n");
	scanf_s("%d", &rest);
	if (rest == ACTION_REST) {
		magro -= 1;
		stamina += 1;
		printf("madongseok rests...\n");
		printf("madongseok: stay %d(aggro: %d->%d,stamona: %d)\n", m, magro + 1, magro, stamina);
	}
	else if (rest == ACTION_PROVOKE) {
		printf("madongseok provoked zombie...\n");
		printf("madongseok: stay %d(aggro: %d->%d,stamona: %d)\n", m, magro, AGGRO_MAX, stamina);
		magro = AGGRO_MAX;
	}
	else if (rest == ACTION_PULL) {
		magro += 2;
		stamina -= 1;
		if (percent < (100 - cprob)) {
			printf("madongseok pull zombie...Next turn,it can't move\n"); if (magro < AGGRO_MIN) {
				magro = AGGRO_MIN;
			}
			else if (magro > AGGRO_MAX) {
				magro = AGGRO_MAX;
			}
			printf("madongseok: stay %d(aggro: %d->%d,stamona: %d)\n", m, magro -2, magro, stamina);
		}
		else {
			printf("madongseok failed to pull zombie...\n");
			if (magro < AGGRO_MIN) {
				magro = AGGRO_MIN;
			}
			else if (magro > AGGRO_MAX) {
				magro = AGGRO_MAX;
			}
			
		}
		
	}
	
	}
	else {
		printf("madongseok action(0:rest , 1:provoke)>>>\n");
		scanf_s("%d", &rest);
		if (rest == ACTION_REST) {
			magro -= 1;
			stamina += 1;
			printf("madongseok rests...\n");
			printf("madongseok: stay %d(aggro: %d->%d,stamona: %d)\n", m, magro + 1, magro, stamina);
		}
		else if (rest == ACTION_PROVOKE) {
			printf("madongseok provoked zombie...\n");
			printf("madongseok: stay %d(aggro: %d->%d,stamona: %d)\n", m, magro, AGGRO_MAX, stamina);
			magro = AGGRO_MAX;
		}
	}
}
void mamove() {

	ask1();
	busanhang3();
	busanhang31();
	printf("\n");
	start2();
	printf("\n");
	busanhang3();
	busanhang31();
	printf("\n");
	sangteamama();
	sandteaall();
}
void moveall() {
	printf("\n");
	busanhang3();
	busanhang31();
	printf("\n");
	busanhang2();
	printf("\n");
	busanhang3();
	busanhang31();
	printf("\n");
	sangtea();
	stop();
}
void start() {
	printf("\n");
	busanhang3();
	busanhang31();
	printf("\n");
	start2();
	printf("\n");
	busanhang3();
	busanhang31();
	printf("\n");
}
void intro() {
	printf("나 ");
	Sleep(1000);
	printf("잡");
	Sleep(1000);
	printf("아");
	Sleep(1000);
	printf("봐");
	Sleep(1000);
	printf("라");
	Sleep(1000);
	printf("~!\n");
	Sleep(1000);
	printf("=====================\n");
	printf("= 부산헹 GAME START =\n");
	printf("=====================\n");
	Sleep(2000);
}
void enter1() {

	while (LEN_MIN > length || LEN_MAX < length) {
		printf("train length(15~50) >>  ");
		scanf_s("%d", &length);
	}
}
void enter2() {

	while (STM_MIN > stamina || stamina > STM_MAX) {
		printf("madongseok stamina(0~5) >> ");
		scanf_s("%d", &stamina);
	}
}
void enter3() {
	while (PROB_MIN > cprob || PROB_MAX < cprob) {
		printf("percentile probability citizen'cp'(10~90) >> ");
		scanf_s("%d", &cprob);
	}

}

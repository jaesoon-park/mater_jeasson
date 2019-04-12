#include <iostream>  
#include <cstdlib>  
#include <string>  
#include <ctime>  
#include <Windows.h>  

using namespace std;

void rand_seed() {
	int seed = static_cast<int> (time(0));
	srand(seed);
}

int rand_int(int a, int b) {
	int ret = 0;
	int temp_1 = rand();
	int temp_2 = b - a + 1;
	ret = a + (temp_1 % temp_2);
	return ret;
}

int main() {
	rand_seed();
	while (1) {
		int don = 1000;
		cout << "우기와 함께하는 신나는 경마게임^^;\n";
		cout << "당신은 1000원의 돈을 가지고 게임을 시작합니다.\n";
		cout << "당신은 자신이 원하는 말에 당신이 원하는 만큼 배팅할수 있습니다.\n";
		cout << "그럼 간단한 말을 소개를 하겠습니다^^말마다 상금이 다릅니다^^*\n";
		cout << "\n";
		string jin = "****************************************************************************";
		int beting = 0;
		int count = 0;
		int betingmar;
		int winmar = 0;
		while (don >= 0) {
			cout << "종료 방법은 자신이 가진돈보다 많은돈을 배팅하시면 됩니다^^;\n";
			cout << "괄호 안은 배팅 대비 상금 입니다^^\n";
			cout << "배팅액의 0을 입력하시면 모두 초기화되고 처음으로 돌아갑니다.\n";
			cout << "--------------------------------------------------------------------------\n";
			cout << " 1 - 적토마. 설명이 따로 필요 없는 명마.              (2배)등급 ★★★★★\n";
			cout << " 2 - 적로. 유비를 구해준 명마.                        (3배)등급 ★★★★\n";
			cout << " 3 - 조황비전.                                        (5배)등급 ★★★\n";
			cout << " 4 - 제주도 조랑말.                                  (13배)등급 ★★\n";
			cout << " 5 - 당나귀.                                         (30배)등급 ★\n";
			cout << "--------------------------------------------------------------------------\n";

			int mar[5] = { 0 };
			int m = 0;
			while (1) {
				cout << "배팅할 말을 선택하시오( 1 ~ 5 ) :";
				cin >> betingmar;
				if (betingmar >= 1 && betingmar <= 5) {
					break;
				}
				else {
					cout << "배팅할 말이 잘못선택되었습니다. 다시 입력바랍니다.\n";
				}
			}
			cout << "배팅할 금액을 입력하시오 : ";
			cin >> beting;
			cout << "\n";
			if (beting == 0) {
				break;
			}
			if (beting > don) {
				cout << "돈이나 갖고 배팅하지....^^?\n";
				Sleep(2000);
				return 0;
			}
			don = don - beting;
			cout << "그럼 경기를 시작해볼까요^^\n";
			cout << "-------------------------------------------------------\n";
			int woon;
			while (m < 50) {
				system("cls");
				Sleep(10);
				cout << m;
				woon = rand_int(1, 100);
				if (woon >= 76) {
					mar[0] = mar[0]++;
					m = max(mar[0], m);
				}
				else if (woon >= 54) {
					mar[1] = mar[1]++;
					m = max(mar[1], m);
				}
				else if (woon >= 34) {
					mar[2] = mar[2]++;
					m = max(mar[2], m);
				}
				else if (woon >= 16) {
					mar[3] = mar[3]++;
					m = max(mar[3], m);
				}
				else if (woon >= 1) {
					mar[4] = mar[4]++;
					m = max(mar[4], m);
				}
				string jindo[5];
				int i, j;
				for (i = 0; i < 5; i++) {
					for (j = 0; j < mar[i]; j++) {
						jindo[i] += "*";
						if (mar[i] == m) {
							winmar = i + 1;
						}
					}
				}
				cout << "게임 현황\n";
				cout << "====================================================================\n";
				cout << "1번마 : *" << jindo[0] << "\n";
				cout << "2번마 : *" << jindo[1] << "\n";
				cout << "3번마 : *" << jindo[2] << "\n";
				cout << "4번마 : *" << jindo[3] << "\n";
				cout << "5번마 : *" << jindo[4] << "\n";
				cout << "====================================================================\n";
			}
			if (winmar == betingmar) {
				if (winmar == 1) {
					don = don + 2 * beting;
					cout << "축하합니다~ 적토마가 우승했군요. 괜히 명성이 있는것이 아니었습니다!\n";
					cout << "상금을 더해서 당신의 돈은 " << don << "원이 되었습니다.\n";
					cout << "\n";
				}
				else if (winmar == 2) {
					don = don + 3 * beting;
					cout << "축하합니다~ 적로가 우승했군요 역시 기량이 뛰어난 말 답네요^^*\n";
					cout << "상금을 더해서 당신의 돈은 " << don << "원이 되었습니다.\n";
					cout << "\n";
				}
				else if (winmar == 3) {
					don = don + 5 * beting;
					cout << "축하합니다~ 조황비전이 우승했군요. 조금 의외군요^^!\n";
					cout << "상금을 더해서 당신의 돈은 " << don << "원이 되었습니다.\n";
					cout << "\n";
				}
				else if (winmar == 4) {
					don = don + 13 * beting;
					cout << "축하합니다~ 조랑말이 우승했군요. 너무나 뜻밖입니다!!\n";
					cout << "상금을 더해서 당신의 돈은 " << don << "원이 되었습니다.\n";
					cout << "\n";
				}
				else if (winmar == 5) {
					don = don + 30 * beting;
					cout << "축하합니다~ 당나귀가 우승했군요. 천지가 개벽할 일이군요!!\n";
					cout << "상금을 더해서 당신의 돈은 " << don << "원이 되었습니다.\n";
					cout << "\n";
				}
			}
			else {
				cout << "안타깝지만 배팅한 말이 우승하지 못했군요...\n";
				cout << "우승은 " << winmar << "번 말이 우승하였습니다.\n";
				cout << "돈은 배팅금을 잃어서 " << don << "원이 되었습니다.\n";
				cout << "\n";
			}
		}
	}
	return 0;
}



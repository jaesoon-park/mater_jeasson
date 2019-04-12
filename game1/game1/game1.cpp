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
		cout << "���� �Բ��ϴ� �ų��� �渶����^^;\n";
		cout << "����� 1000���� ���� ������ ������ �����մϴ�.\n";
		cout << "����� �ڽ��� ���ϴ� ���� ����� ���ϴ� ��ŭ �����Ҽ� �ֽ��ϴ�.\n";
		cout << "�׷� ������ ���� �Ұ��� �ϰڽ��ϴ�^^������ ����� �ٸ��ϴ�^^*\n";
		cout << "\n";
		string jin = "****************************************************************************";
		int beting = 0;
		int count = 0;
		int betingmar;
		int winmar = 0;
		while (don >= 0) {
			cout << "���� ����� �ڽ��� ���������� �������� �����Ͻø� �˴ϴ�^^;\n";
			cout << "��ȣ ���� ���� ��� ��� �Դϴ�^^\n";
			cout << "���þ��� 0�� �Է��Ͻø� ��� �ʱ�ȭ�ǰ� ó������ ���ư��ϴ�.\n";
			cout << "--------------------------------------------------------------------------\n";
			cout << " 1 - ���丶. ������ ���� �ʿ� ���� ��.              (2��)��� �ڡڡڡڡ�\n";
			cout << " 2 - ����. ���� ������ ��.                        (3��)��� �ڡڡڡ�\n";
			cout << " 3 - ��Ȳ����.                                        (5��)��� �ڡڡ�\n";
			cout << " 4 - ���ֵ� ������.                                  (13��)��� �ڡ�\n";
			cout << " 5 - �糪��.                                         (30��)��� ��\n";
			cout << "--------------------------------------------------------------------------\n";

			int mar[5] = { 0 };
			int m = 0;
			while (1) {
				cout << "������ ���� �����Ͻÿ�( 1 ~ 5 ) :";
				cin >> betingmar;
				if (betingmar >= 1 && betingmar <= 5) {
					break;
				}
				else {
					cout << "������ ���� �߸����õǾ����ϴ�. �ٽ� �Է¹ٶ��ϴ�.\n";
				}
			}
			cout << "������ �ݾ��� �Է��Ͻÿ� : ";
			cin >> beting;
			cout << "\n";
			if (beting == 0) {
				break;
			}
			if (beting > don) {
				cout << "���̳� ���� ��������....^^?\n";
				Sleep(2000);
				return 0;
			}
			don = don - beting;
			cout << "�׷� ��⸦ �����غ����^^\n";
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
				cout << "���� ��Ȳ\n";
				cout << "====================================================================\n";
				cout << "1���� : *" << jindo[0] << "\n";
				cout << "2���� : *" << jindo[1] << "\n";
				cout << "3���� : *" << jindo[2] << "\n";
				cout << "4���� : *" << jindo[3] << "\n";
				cout << "5���� : *" << jindo[4] << "\n";
				cout << "====================================================================\n";
			}
			if (winmar == betingmar) {
				if (winmar == 1) {
					don = don + 2 * beting;
					cout << "�����մϴ�~ ���丶�� ����߱���. ���� ���� �ִ°��� �ƴϾ����ϴ�!\n";
					cout << "����� ���ؼ� ����� ���� " << don << "���� �Ǿ����ϴ�.\n";
					cout << "\n";
				}
				else if (winmar == 2) {
					don = don + 3 * beting;
					cout << "�����մϴ�~ ���ΰ� ����߱��� ���� �ⷮ�� �پ �� ��׿�^^*\n";
					cout << "����� ���ؼ� ����� ���� " << don << "���� �Ǿ����ϴ�.\n";
					cout << "\n";
				}
				else if (winmar == 3) {
					don = don + 5 * beting;
					cout << "�����մϴ�~ ��Ȳ������ ����߱���. ���� �ǿܱ���^^!\n";
					cout << "����� ���ؼ� ����� ���� " << don << "���� �Ǿ����ϴ�.\n";
					cout << "\n";
				}
				else if (winmar == 4) {
					don = don + 13 * beting;
					cout << "�����մϴ�~ �������� ����߱���. �ʹ��� ����Դϴ�!!\n";
					cout << "����� ���ؼ� ����� ���� " << don << "���� �Ǿ����ϴ�.\n";
					cout << "\n";
				}
				else if (winmar == 5) {
					don = don + 30 * beting;
					cout << "�����մϴ�~ �糪�Ͱ� ����߱���. õ���� ������ ���̱���!!\n";
					cout << "����� ���ؼ� ����� ���� " << don << "���� �Ǿ����ϴ�.\n";
					cout << "\n";
				}
			}
			else {
				cout << "��Ÿ������ ������ ���� ������� ���߱���...\n";
				cout << "����� " << winmar << "�� ���� ����Ͽ����ϴ�.\n";
				cout << "���� ���ñ��� �Ҿ " << don << "���� �Ǿ����ϴ�.\n";
				cout << "\n";
			}
		}
	}
	return 0;
}



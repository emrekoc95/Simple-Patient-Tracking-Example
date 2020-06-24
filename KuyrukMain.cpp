//KuyrukMain.cpp
#include "Kuyruk.h"
using namespace std;

int main() {
	//Kullan�c�dan de�er almak i�in tcno, onun basamak say�s�n� hesaplamak i�in gec,
	//basamak de�eri ve men� i�in se�im de�erleri tan�mland�.
	__int64 tcno;
	__int64 gec;
	int basamak = 0;
	int secim;
	while (1) {
		cout << "						HASTA TAKIP SISTEMI" << endl;
		cout << "							MENU							" << endl;
		cout << "			    Asagidaki islemlerden birini yapmak icin gerekli tusa basiniz" << endl << endl;
		cout << "						Hasta Ekleme                (1)" << endl;
		cout << "						Hasta Silme (Bakilan Hasta) (2)" << endl;
		cout << "						Kalan Hasta Listeleme       (3)" << endl;
		cout << "						Kalan Hasta Sayisi          (4)" << endl;
		cout << "						Cikis                       (0)" << endl;
		cout << "						Seciminiz: ";

		cin >> secim;
		cout << endl << endl;
		system("cls");
		//Se�im de�eriyle men� se�imlerine giri�
		switch (secim) {
		//Birinci se�imde istenen say�n�n basamak de�erine bak�ld� ve uygunlu�una g�re kuyru�a eklendi
		//Di�er se�imlerde de s�ras�nda g�re fonksiyonlar kullan�ld� ve hatal� giri� yap�lmas� durumunda hata ��kt�s� sa�land�.
		case 1:
			while (1) {
				cout << "Eklemek istediginiz hastanin TC Kimlik Numarasi giriniz: ";
				cin >> tcno;
				gec = tcno;
				while(gec != 0){
					gec = gec / 10;
					basamak++;
				}
				if (basamak != 11) {
					basamak = 0;
					cout << "Lutfen gecerli bir TC Kimlik Numarasi giriniz! " << endl;
				}
				else{
					basamak = 0;
					break;
				}

			}
			cout << endl;
			ekleme(tcno);
			break;
		case 2:
			silme();
			break;
		case 3:
			listeleme();
			break;
		case 4:
			elemansayisi();
			break;
		case 0 :
			exit(0);
		default:
			cout << "Lutfen gecerli bir secim yapiniz. " << endl;
			break;
		}


	}
	system("pause");
}
//Fonksiyon sonu
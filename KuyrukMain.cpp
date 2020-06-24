//KuyrukMain.cpp
#include "Kuyruk.h"
using namespace std;

int main() {
	//Kullanýcýdan deðer almak için tcno, onun basamak sayýsýný hesaplamak için gec,
	//basamak deðeri ve menü için seçim deðerleri tanýmlandý.
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
		//Seçim deðeriyle menü seçimlerine giriþ
		switch (secim) {
		//Birinci seçimde istenen sayýnýn basamak deðerine bakýldý ve uygunluðuna göre kuyruða eklendi
		//Diðer seçimlerde de sýrasýnda göre fonksiyonlar kullanýldý ve hatalý giriþ yapýlmasý durumunda hata çýktýsý saðlandý.
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
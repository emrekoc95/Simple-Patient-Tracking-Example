//Kuyruk.cpp
#include "Kuyruk.h"
using namespace std;
//Kuyruðun baþ ve son deðerlerini tutmasý için pointerlar tanýmlandý.
kuyruk *bas = NULL;
kuyruk *son = NULL;
//Ekleme Fonksiyonu
void ekleme(__int64 tcno) {
	//11 basamaklý tamsayý tutabilmesi için ve ondalýklý sonuç istenmediði için __int64 tipi kullanýldý
	kuyruk *yenidugum = new kuyruk;
	yenidugum->tcno = tcno;
	yenidugum->sonraki = NULL;
	yenidugum->onceki = NULL;
	//Kuyrukta eleman olmamasý durumu
	if (bas == NULL) {
		bas = yenidugum;
		son = yenidugum;
		cout << "Yeni hasta eklendi. " << endl;
	}
	//Kuyrukta eleman varsa
	else{
		son->sonraki = yenidugum;
		yenidugum->onceki = son;
		son = yenidugum;
		cout << "Yeni hasta eklendi. " << endl;
	}
}
//Silme Fonksiyonu
void silme() {
	//Listenin boþ olmasý durumu
	if (bas == NULL) {
		cout << "Liste zaten bos. Su an hasta silemezsiniz." << endl;
	}
	//Listenin tek bir elemaný olmasý durumu
	else if (bas->sonraki == NULL) {
		delete(bas);
		bas = NULL;
		cout << "Hasta muayene edildi ve sistemden silindi. " << endl;
	}
	//Diðer durumlar
	else {
		bas = bas->sonraki;
		delete(bas->onceki);
		bas->onceki = NULL;
		cout << "Hasta muayene edildi ve sistemden silindi. " << endl;
	}
}
//Listeleme Fonksiyonu
void listeleme() {
	//Geçici bir deðer tanýmlandý ve ilk düðüm bu deðere atanarak son deðere kadar ilerleme saðlandý
	kuyruk *gecici = new kuyruk;
	gecici = bas;
	int i = 1;
	//Listenin boþ olmasý durumu
	if (bas == NULL) {
		cout << "Liste bos. Lutfen once hasta ekleyiniz. " << endl;
	}
	else {
		cout << "Bekleyen hastalarin listesi: ";
		//Son deðere kadar ilerleme ve yazdýrma iþlemi
		while (gecici != NULL) {
			cout <<endl<< i <<". " << gecici->tcno << endl;
			gecici = gecici->sonraki;
			i++;
		}
		cout << endl;
	}
}
//Sayma Fonksiyonu
void elemansayisi() {
	//Üstteki fonksiyon gibi gecici bir deðerle eleman sayýsýna ulaþýldý
	kuyruk *gecici = new kuyruk;
	gecici = bas;
	int i = 0;
	while (gecici != NULL) {
		gecici = gecici->sonraki;
		i++;
	}
	cout <<"Kalan hasta sayisi: " << i << endl;
}

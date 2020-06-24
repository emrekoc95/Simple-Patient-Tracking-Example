//Kuyruk.cpp
#include "Kuyruk.h"
using namespace std;
//Kuyru�un ba� ve son de�erlerini tutmas� i�in pointerlar tan�mland�.
kuyruk *bas = NULL;
kuyruk *son = NULL;
//Ekleme Fonksiyonu
void ekleme(__int64 tcno) {
	//11 basamakl� tamsay� tutabilmesi i�in ve ondal�kl� sonu� istenmedi�i i�in __int64 tipi kullan�ld�
	kuyruk *yenidugum = new kuyruk;
	yenidugum->tcno = tcno;
	yenidugum->sonraki = NULL;
	yenidugum->onceki = NULL;
	//Kuyrukta eleman olmamas� durumu
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
	//Listenin bo� olmas� durumu
	if (bas == NULL) {
		cout << "Liste zaten bos. Su an hasta silemezsiniz." << endl;
	}
	//Listenin tek bir eleman� olmas� durumu
	else if (bas->sonraki == NULL) {
		delete(bas);
		bas = NULL;
		cout << "Hasta muayene edildi ve sistemden silindi. " << endl;
	}
	//Di�er durumlar
	else {
		bas = bas->sonraki;
		delete(bas->onceki);
		bas->onceki = NULL;
		cout << "Hasta muayene edildi ve sistemden silindi. " << endl;
	}
}
//Listeleme Fonksiyonu
void listeleme() {
	//Ge�ici bir de�er tan�mland� ve ilk d���m bu de�ere atanarak son de�ere kadar ilerleme sa�land�
	kuyruk *gecici = new kuyruk;
	gecici = bas;
	int i = 1;
	//Listenin bo� olmas� durumu
	if (bas == NULL) {
		cout << "Liste bos. Lutfen once hasta ekleyiniz. " << endl;
	}
	else {
		cout << "Bekleyen hastalarin listesi: ";
		//Son de�ere kadar ilerleme ve yazd�rma i�lemi
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
	//�stteki fonksiyon gibi gecici bir de�erle eleman say�s�na ula��ld�
	kuyruk *gecici = new kuyruk;
	gecici = bas;
	int i = 0;
	while (gecici != NULL) {
		gecici = gecici->sonraki;
		i++;
	}
	cout <<"Kalan hasta sayisi: " << i << endl;
}

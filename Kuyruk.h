//Kuyruk.h
//Temel kuyruk d���m� ve fonksiyonlar tan�mland�
#pragma once
#include <iostream>
struct kuyruk {
	__int64 tcno;
	kuyruk* sonraki;
	kuyruk* onceki;
};

void ekleme(__int64);
void silme();
void listeleme();
void elemansayisi();

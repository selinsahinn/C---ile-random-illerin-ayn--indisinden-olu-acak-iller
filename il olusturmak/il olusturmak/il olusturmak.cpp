// il olusturmak.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>         //giris cikis fonksiyon kutuphanesi
#include <time.h>           //random icin gerekli kutuphane
using  namespace std;       //standart isim uzayi

int main()                  //ilk calisacak ana fonksiyon
{
	string gecici = " ";				//harfi tutmak icin bos string
	string rastgeleIl[14] = {};			//random ile secilen rastgele illerin tutuldugu string dizisi
	int indis[14] = { 0 };				//harfi tutmak icin tamsayi dizisi
	string iller[81] = { "adana","adiyaman","afyonkarahisar","agri","aksaray","amasya","ankara","antalya","ardahan","artvin","aydin","balikesir","bartin","batman","bayburt","bilecik","bingol","bitlis","bolu","burdur","bursa","canakkale","cankiri","corum","denizli","diyarbakir","duzce","edirne","elazig","erzincan","erzurum","eskisehir","gaziantep","giresun","gumushane","hakkari","hatay","igdir","isparta","istanbul","izmir","kahramanmaras","karabuk","karaman","kars","kastamonu","kayseri","kirikkale","kirklareli","kirsehir","kilis","kocaeli","konya","kutahya","malatya","manisa","mardin","mersin","mugla","mus","nevsehir","nigde","ordu","osmaniye","rize","sakarya","samsun","siirt","sinop","sivas","sanliurfa","sirnak","tekirdag","tokat","trabzon","tunceli","usak","van","yalova","yozgat","zonguldak" };
	//81 ilin bulundugu string dizisi
	srand(time(0));						//random fonksiyonunun her seferinde farkli iller getirmesini saglayan fonksiyon

	int minimum = iller[0].size();		 //minimum harf sayisini bulmak icin minimum degeri ilk ilin harf buyuklugune atar.
	int maksimum = iller[0].size();      //maksimum harf sayisini bulmak icin maksimum degeri ilk ilin harf buyuklugune atar.

	for (int i = 0; i < 81; i++) {           //i degeri 0'dan 81'e kadar doner ve 81 ilin bulundugu string dizisini gezer.
		if (minimum > iller[i].size())       //eger minimum deger baska bir ilin harf buyuklugunden buyukse
			minimum = iller[i].size();       //minimum degeri en kucuk yeni deger ile degistirir.
	}

	for (int i = 0; i < 81; i++) {				//i degeri 0'dan 81'e kadar doner ve 81 ilin bulundugu string dizisini gezer.
		if (maksimum < iller[i].size())			//eger maksimum deger baska bir ilin harf buyuklugunden kucukse
			maksimum = iller[i].size();			//maksimum degeri en buyuk yeni deger ile degistirir.
	}

	cout << "En kisa ilin harf sayisi -> " << minimum << endl;     //minimum harfli ilin harf sayisini ekrana yazdirir.
	cout << "En uzun ilin harf sayisi -> " << maksimum << endl;   //maksimum harfli ilin harf sayisini ekrana yazdirir.

	int kontrol = 0;								//if fonksiyonunda kullanmak icin tamsayi kontrol degiskeni tanimlanir.

	for (int i = minimum; i <= maksimum; i++) {				//i degeri minimum(3)'ten maksimum(14)'e kadar gezer.
		cout << i << " harfli il -> ";						//dongudeki her i degerini ekrana yazdirir.

		if (kontrol == 0 && i != minimum)			//eger kontrol degiskeni 0 ise ve i degiskeni minimum degere esit degil ise
			cout << "Bulunamadi..." << endl;       //yukaridaki kosul saglanirsa ekrana bulunamadi yazdirir.

		for (int j = 0; j < 100000; j++) {			//j degeri 0'dan 100000'e kadar gezer yani 100000 kere rastgele il bulur.
			int kontrol = 0;						//tam sayi olan kontrol degiskenini 0'a esitler.

			for (int s = 0; s < i; s++) {                //s degeri 0'dan i'ye kadar gezer.
				rastgeleIl[s] = iller[rand() % 81];     //81 ilden olusan iller dizisinden rastgele iller bulup rastgeleIl stringine atar.
			}

			int minRastgeleIl = rastgeleIl[0].size();   //minimum rastgele il degiskeni tanimlar ve bunu rastgele il dizisinin ilk elemaninin harf buyuklugune esitler.

			for (int k = 0; k < i; k++) {							// k degeri 0'dan i degerine kadar gezer.
				if (minRastgeleIl > rastgeleIl[k].size())			//eger minimum rastgele ilin harf sayisi rastgele ilin harf sayisindan buyukse
					minRastgeleIl = rastgeleIl[k].size();			//minimum rastgele ilin harf sayisini yeni rastgele ilin harf sayisina esitler.
			}

			for (int k = 0; k < minRastgeleIl; k++) {       // k degeri 0'dan minimum rastgele il sayisina kadar gezer.
				gecici = "";								//gecici adli diziyi bos olarak tanimlar.

				for (int t = 0; t < i; t++)                 // t degeri 0'dan i'ye kadar gezer.
					gecici += rastgeleIl[t].at(k);			//bos gecici adli diziye rastgele ilin harflerini atar.

				for (int x = 0; x < 81; x++) {				//x degeri 0'dan 81'e kadar gezer.
					if (iller[x] == gecici) {				//eger bir il gecici adli dizideki ile esitse
						cout << gecici << endl;				//gecici diziyi ekrana yazdirir.
						kontrol = 1;						//yukaridaki sart saglanirsa kontrol degiskenini 1'e esitler.
					}
				}
			}

			if (kontrol == 1)           //eger kontrol degiskeni 1'e esitse
				break;                  //donguyu kirar ve sonlandirir.
		}
	}
	return 0;           //program bu satira kadar sorunsuz bir sekilde geldiyse program calisir.
}

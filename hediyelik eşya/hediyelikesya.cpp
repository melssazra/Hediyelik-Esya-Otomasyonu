#include<iostream>
#include<conio.h>
#include<cstring>
#include<fstream>
using namespace std;

struct bilgi{
	int urunkodu;
	char esyaadi[100];
	int urunadedi;
	float urunmaliyeti;
	float satisfiyati;
	bilgi* baglink;
};


 bilgi* liste=NULL;
 
 bilgi* newbilgi(){
 	bilgi* yeni=new bilgi;
 	yeni->baglink=NULL;
 	return (yeni);
 }
 
 void ekleme(bilgi*& liste);
 void arama(bilgi* liste);
 void kayitsilme(bilgi*& liste);
 void guncelleme(bilgi*& liste);
 void listeleme(bilgi* liste);
 
void ekleme(bilgi*& liste) {
    system("cls");
    bilgi* yeni = newbilgi();
    cout << "Ekleyeceginiz urunun bilgilerini giriniz: " << endl;
    cin.ignore();
    cout << "Urunun ADI: "; cin.getline(yeni->esyaadi, 100);
    cout << "Urun Kodu: "; cin >> yeni->urunkodu;
    cout << "Urun Adedi:  "; cin >> yeni->urunadedi;
    cout << "Urunun Maliyeti: "; cin>>yeni->urunmaliyeti;
    cout << "Urunun Satis Fiyati: "; cin>>yeni->satisfiyati;
    if (liste == NULL) liste = yeni;
    else {
        yeni->baglink = liste;
        liste = yeni;
    }
    cout << "URUN BASARIYLA EKLENDİ!" << endl;
}
 
void arama(bilgi* liste) {
    system("cls");
    int aranan;
    char cevap;
    cout << "Aradiginiz Urunun kodunu tuslayiniz: ";
    cin >> aranan;
    bilgi* yedek = liste;
    while (yedek != NULL) {
        if (aranan == yedek->urunkodu) {
            cout << " URUNUN ADI: " << yedek->esyaadi << endl;
            cout << " URUNUN KODU: " << yedek->urunkodu << endl;
            cout << " URUNUN ADEDI: " << yedek->urunadedi << endl;
            cout << " URUNUN MALIYETI: " << yedek->urunmaliyeti << endl;
            cout << " URUNUN SATIS FIYATI: " << yedek->satisfiyati << endl;
            cout << "\n Aradiginiz urun bu mu? (E/H)"; cin >> cevap;
            if (cevap == 'e' || cevap == 'E') {
                int secim;
                cout << "Bulunan urun üzerinde islem yapmak ister misiniz? " << endl;
                cout << "1-Kaydini silme  \n2-Bilgilerini güncelleme \n3-CIKIS \n";
                cin >> secim;
                switch (secim) {
                    case 1:
                        kayitsilme(liste);
                        break;
                    case 2:
                        guncelleme(liste);
                        break;
                    case 3:
                        break;
                }
            }
        }
        yedek = yedek->baglink;
    }
    cout<<"kayit bulunamadı"<<endl;
}
 
 void kayitsilme(bilgi*& liste) {
    system("cls");
    int aranan;
    char cevap;
    cout << "Kaydini silmek istediginiz urunun kodunu giriniz: ";
    cin >> aranan;
    bilgi* onceki = NULL;
    bilgi* yedek = liste;
    while (yedek != NULL) {
        if (yedek->urunkodu == aranan) {
            cout << " URUNUN ADI: " << yedek->esyaadi << endl;
            cout << " URUNUN KODU: " << yedek->urunkodu << endl;
            cout << " URUNUN ADEDI: " << yedek->urunadedi << endl;
            cout << " URUNUN MALIYETI: " << yedek->urunmaliyeti << endl;
            cout << " URUNUN SATIS FIYATI: " << yedek->satisfiyati << endl;
            cout << "\n Aradiginiz urun bu mu? (E/H): ";
            cin >> cevap;
            if (cevap == 'e' || cevap == 'E') {
                char secim;
                cout << "Urunun kaydini sildikten sonra urunun kaydina bir daha ulasamayacaksiniz!" << endl;
                cout << "Urunu silmek yerine urun adedini '0' yapmak ister misiniz? (E/H): ";
                cin >> secim;
                if (secim == 'e' || secim == 'E') {
                    yedek->urunadedi = 0;
                    cout << "Urun adedi 0 yapildi." << endl;
                } else {
                    if (onceki == NULL) {
                        liste = yedek->baglink;
                    } else {
                        onceki->baglink = yedek->baglink;
                    }
                    delete yedek;
                    cout << "Urunun kaydi silindi." << endl;
                }
                return; // Fonksiyondan çık
            }
        }
        onceki = yedek;
        yedek = yedek->baglink;
    }
    cout << "Aradiginiz urun kayitlarda bulunamamistir!" << endl;
}

 
void guncelleme(bilgi*& liste) {
    system("cls");
    int aranan;
    char cevap;
    cout << "Bilgilerini guncellemek istediginiz urunun kodunu tuslayiniz: "; cin >> aranan;
    bilgi* yedek = liste;
    while (yedek != NULL) {
        if (yedek->urunkodu == aranan) {
            cout << " URUNUN ADI: " << yedek->esyaadi << endl;
            cout << " URUNUN KODU: " << yedek->urunkodu << endl;
            cout << " URUNUN ADEDI: " << yedek->urunadedi << endl;
            cout << " URUNUN MALIYETI: " << yedek->urunmaliyeti << endl;
            cout << " URUNUN SATIS FIYATI: " << yedek->satisfiyati << endl;
            cout << "\n Aradiginiz urun bu mu? (E/H)"; cin >> cevap;
            if (cevap == 'e' || cevap == 'E') {
                cout << "Urunun guncel bilgilerini giriniz: " << endl;
                cin.ignore();
                cout << "Urunun ADI: "; cin.getline(yedek->esyaadi, 100);
                cout << "Urun Kodu: "; cin >> yedek->urunkodu;
                cout << "Urun Adedi:  "; cin >> yedek->urunadedi;
                cout << "Urunun Maliyeti: "; cin>>yedek->urunmaliyeti;
                cout << "Urunun Satis Fiyati: "; cin>>yedek->satisfiyati;
            }
        }
        yedek = yedek->baglink;
    }
}
 
 void listeleme(bilgi* liste){
 	system("cls");
 	bilgi* yedek=liste;
 	while(yedek!=NULL){
            cout << " URUNUN ADI: " << yedek->esyaadi << endl;
            cout << " URUNUN KODU: " << yedek->urunkodu << endl;
            cout << " URUNUN ADEDI: " << yedek->urunadedi << endl;
            cout << " URUNUN MALIYETI: " << yedek->urunmaliyeti << endl;
            cout << " URUNUN SATIS FIYATI: " << yedek->satisfiyati << endl;
            cout<<endl<<endl;         
		 yedek=yedek->baglink;       		 
    }
 }



void dosyayayazma(bilgi* liste){
    system("cls");
    ofstream yaz("HediyelikEsya.dat", ios::binary | ios::out);
    bilgi* yedek = liste;
    while (yedek != NULL) {
        yaz.write(reinterpret_cast<char*>(yedek), sizeof(bilgi));
        yedek = yedek->baglink;
    }
    yaz.close();
}

void listeyeaktarma(bilgi*& liste){
    system("cls");
    ifstream oku("HediyelikEsya.dat", ios::binary | ios::in);
    if (!oku) {
        cout << "Dosya acilamadi!" << endl;
        return;
    }
    bilgi* yeni;
    while (!oku.eof()) {
        yeni = newbilgi();
        oku.read(reinterpret_cast<char*>(yeni), sizeof(bilgi));
        if (oku.eof()) break;
        if (liste == NULL) {
            liste = yeni;
        } else {
            yeni->baglink = liste;
            liste = yeni;
        }
    }
    oku.close();
}



 
 int main(){
 	int secim;
 	char secenek='E';
 	 listeyeaktarma(liste);
 	
 	
 	while(secenek=='e' || secenek=='E'){
	 system("cls");

        cout << "1. Urun Ekleme" << endl;
        cout << "2. Urun Arama" << endl;
        cout << "3. Kayit Silme" << endl;
        cout << "4. Guncelleme" << endl;
        cout << "5.  Listeleme" << endl;
        cout << "6. Dosyaya Yazma" << endl;
        cout << "Seciminizi yapiniz: ";
        cin >> secim;
	switch (secim){
		case 1:
			ekleme(liste);
			break;
		case 2:
			arama(liste);
			break;
		case 3:
			kayitsilme(liste);
			dosyayayazma(liste);
			break;
		case 4:
			guncelleme(liste);
			break;
		case 5:
			listeleme(liste);
			break;
		case 6:
			dosyayayazma(liste);
			break;
			
	}
	cout<<"Baska bir islem yapmak istiyor musun? (E/H) ";
	cin>>secenek;
    }
    dosyayayazma(liste);
    return 0;
 }

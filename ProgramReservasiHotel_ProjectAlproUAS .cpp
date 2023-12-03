#include <iostream>
#include <cstdlib>
using namespace std;

struct Pemesan{
    string nama;
    int hariMenginap;
    int noKamar;
    string noTelp;
    Pemesan *next;
};

// Double Linked List
Pemesan *head = nullptr;
Pemesan *tail = nullptr;

void showAvailableRooms(bool myArrKamar[]);
void reserveRoom(string namaPemesan, int hariMenginap, int noKamar, string noTelp);
void showVisitorsList();


int main() {
    int pilihan, hariMenginap, noKamar;
    bool myArrKamar[10];
    string namaPengunjung, noTelp;
    char repeat;

    for(int i = 0; i < 10; i++) {
        myArrKamar[i] = true;
    };

    do {
        system("cls");
        cout << "\n==========================================" << endl;
        cout << "|            RESERVASI HOTEL             |" << endl;
        cout << "==========================================" << endl;
        cout << "|                                        |" << endl;
        cout << "| 1. Pesan Kamar                         |" << endl;
        cout << "| 2. Daftar Kamar yang Tersedia          |" << endl;
        cout << "| 3. Daftar Pemesan Kamar                |" << endl;
        // cout << "| 4. Hapus Daftar Pemesanan              |" << endl;
        cout << "| 0. Keluar                              |" << endl;
        cout << "|                                        |" << endl;
        cout << "==========================================" << endl;
        cout << "Silahkan pilih salah satu daftar menu diatas." << endl;
        cout << "Pilihan : ";
        cin >> pilihan;

        switch (pilihan){
            case 1:
                do {
                    system("cls");
                    showAvailableRooms(myArrKamar);
                    cout << "| 0 untuk kembali       |" << endl;
                    cout << "=========================" << endl;

                    cout << "\nSilahkan pilih kamar sesuai nomor kamar." << endl;
                    cout << "Pilih nomor kamar : ";
                    cin >> noKamar;

                    if(noKamar == 0){
                        break;
                    };
                    if(noKamar > 10 || noKamar < 0) {
                        do{
                            cout << "Harap masukkan nomor kamar sesuai menu." << endl;
                            cout << "Pilih kembali nomor kamar : "; 
                            cin >> noKamar;
                        }while(noKamar > 10);
                        
                    };
                    if(!myArrKamar[noKamar-1]) {
                        do{
                        cout << "Kamar ini tidak tersedia/sudah dipesan!\nSilahkan pilih kamar lain." << endl;
                        cout << "Pilih kembali nomor kamar : ";
                        cin >> noKamar;
                        } while(!myArrKamar[noKamar-1]);
                    } 

                    cout << "Nama Pemesan : ";
                    getline(cin >> ws, namaPengunjung);
                    cout << "Masukkan nomor telepon : ";
                    cin >> noTelp;
                    cout << "Masukkan berapa hari menginap : ";
                    cin >> hariMenginap;
                    myArrKamar[noKamar-1] = false;
                    reserveRoom(namaPengunjung, hariMenginap, noKamar, noTelp);

                    cout << "Apakah anda ingin memesan kamar lagi? (y/n) : ";
                    cin >> repeat;
                } while (repeat == 'y' || repeat == 'Y');
                break;
            case 2:
                showAvailableRooms(myArrKamar);

                cout << "Ingin kembali ke menu utama?(y/n) : " << endl;
                cin >> repeat;
                if (repeat == 'y' || repeat == 'Y') {
                    break;
                }; 
                pilihan = 0;
                break;
            case 3:
                showVisitorsList();
                cout << "Ingin kembali ke menu utama?(y/n) : " << endl;
                cin >> repeat;
                if (repeat == 'y' || repeat == 'Y') {
                    break;
                };
                pilihan = 0;
                break;
            // case 4:
            // do{
            //     if(head == nullptr) {
            //         cout << "Tidak ada pemesan yang memesan kamar." << endl;
            //         break;
            //     };
            //     showVisitorsList();
            //     cout << "Masukkan nomor kamar yang ingin dihapus : ";
            //     cin >> noKamar;
            //     delVisitors(noKamar);
            // } while(repeat == 'y' || repeat == 'Y');

            //     cout << "Pilihan 4" << endl;
            //     break;
            case 0:
                cout << "Program Selesai." << endl;
                break;
            default:
                do {
                cout << "Pilihan tidak valid, ulangi lagi." << endl;
                cout << "Masukkan 1 untuk melanjutkan : ";
                cin >> pilihan;
                } while ( pilihan > 4);            
                break;
        };
    } while (pilihan != 0);

    return 0;
};

void showAvailableRooms(bool myArrKamar[]) {
    cout << "\n=========================" << endl;
    cout << "|  Kamar Yang Tersedia  |" << endl;
    cout << "=========================" << endl;
    cout << "|     Kamar Standar     |" << endl;
    cout << "|-----------------------|" << endl;

    for(int i = 0; i < 5; i++) {
        if(myArrKamar[i]) {
            cout << "| " << "Kamar Nomor " << i+1 << "         |" << endl;
        };
    };

    cout << "|-----------------------|" << endl;
    cout << "|    Kamar Eksklusive   |" << endl;
    cout << "|-----------------------|" << endl;
    
    for(int i = 5; i < 10; i++) {
        if(myArrKamar[i]) {
            if(i == 9 && myArrKamar[i]) {
                cout << "| " << "Kamar Nomor " << i+1 << "        |" << endl;
                break;
            };
            cout << "| " << "Kamar Nomor " << i+1 << "         |" << endl;
        };
    };
    cout << "=========================" << endl;
};

void reserveRoom(string namaPemesan, int hariMenginap, int noKamar, string noTelp) {
    int uangUser, kembalian;
    int hargaKamar = 150000;
    if(noKamar > 5) {
        hargaKamar = 250000;
    };

    cout << "Total biaya yaitu Rp. " << hargaKamar*hariMenginap << endl;
    cout << "Lakukan pembayaran : ";
    cin >> uangUser;

    if(uangUser < hargaKamar*hariMenginap) {
        do{
            cout << "Pembayaran tidak cukup.\nLakukan kembali pembayaran : ";
            cin >> uangUser;
        }while(uangUser < hargaKamar*hariMenginap);
    };
    cout << "\nPembayaran berhasil.\nKembalian : " << uangUser - hargaKamar*hariMenginap << endl;

    Pemesan *pemesanBaru = new Pemesan;
    pemesanBaru->nama = namaPemesan;
    pemesanBaru->hariMenginap = hariMenginap;
    pemesanBaru->noKamar = noKamar;
    pemesanBaru->noTelp = noTelp;
    pemesanBaru->next = NULL;
    
    if(head == nullptr) {
        head = pemesanBaru;
        tail = pemesanBaru;
    } else {
        tail->next = pemesanBaru;
        tail = pemesanBaru;
    };
    
    cout << "\n==============================" << endl;
    cout << "No Kamar : " << pemesanBaru->noKamar << endl;
    cout << "Nama Pemesan : " << pemesanBaru->nama << endl;
    cout << "Nomor Telepon : " << pemesanBaru->noTelp << endl;
    cout << "Total menginap : " << pemesanBaru->hariMenginap << " hari" << endl;
    cout << "==============================\n" << endl;
    
};

void showVisitorsList() {
    Pemesan *tempPtr = head;

    if(tempPtr == NULL) {
        cout << "Tidak ada pemesan kamar." << endl;
    };
    while(tempPtr != NULL){
        if(tempPtr->noKamar <= 5) {
            cout << "==============================" << endl;
            cout << "Kamar Standar" << endl;
            cout << "No Kamar " << tempPtr->noKamar << endl;
            cout << "Nama Pemesan : " << tempPtr->nama << endl;
            cout << "Nomor Telepon : " << tempPtr->noTelp << endl;
            cout << "Hari menginap : " << tempPtr->hariMenginap << endl;
            cout << "==============================\n" << endl;
        }else {
            cout << "==============================" << endl;
            cout << "Kamar Eksklusif" << endl;
            cout << "No Kamar " << tempPtr->noKamar << endl;
            cout << "Nama Pemesan : " << tempPtr->nama << endl;
            cout << "Nomor Telepon : " << tempPtr->noTelp << endl;
            cout << "Hari menginap : " << tempPtr->hariMenginap << endl;
            cout << "==============================\n" << endl;
        };
        tempPtr = tempPtr->next;
    };
};
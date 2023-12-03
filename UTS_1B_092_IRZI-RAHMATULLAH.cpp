
#include <iostream>

using namespace std;

int main() {

    string namaKaryawan;
    int gajiPokok, tunjangan, gajiBersih, pajak;

    cout << "\n----------------------------------------------" << endl;
    cout << "Program menghitung gaji bersih karyawan." << endl;
    cout << "----------------------------------------------" << endl << endl;
    cout << "Masukkan nama karyawan/nama anda : ";
    getline(cin, namaKaryawan); // Menggunakan method getline agar membaca inputan user yang menggunakan spasi.
    cout << "Masukkan gaji pokok anda (harap berupa bilangan bulat tanpa titik) : ";
    cin >> gajiPokok;
    
    // Melakukan pengkondisian jika inputan user dibawah seratus ribu.
    if (gajiPokok < 100000) {
        do {
            cout << "Gaji pokok yang dimasukkan harus lebih dari 100.000 (Seratus ribu)" << endl;
            cout << "Masukkan kembali gaji pokok anda : ";
            cin >> gajiPokok;
        } while (gajiPokok <= 100000);
    }

    // Meakukan pengkondisian sesuai gaji user.
    if(gajiPokok >= 500000) {
        tunjangan = gajiPokok * 20/100;
        gajiBersih = gajiPokok + tunjangan;
        pajak = gajiBersih * 15/100;
        gajiBersih -= pajak;
        cout << endl;

        cout << "Jika gaji pokok anda sebesar " << gajiPokok << " anda mendapatkan\ntunjangan sebesar " << tunjangan << " dan pajak sebesar " << pajak << endl << endl;
        cout << "Sehingga gaji bersih anda sebesar : " << gajiBersih << endl;
    } else {
        tunjangan = gajiPokok * 10/100;
        gajiBersih = gajiPokok + tunjangan;
        pajak = gajiBersih * 5/100;
        gajiBersih -= pajak;
        cout << endl;

        cout << "Jika gaji pokok anda sebesar " << gajiPokok << " anda mendapatkan\ntunjangan sebesar " << tunjangan << " dan pajak sebesar " << pajak << endl << endl;
        cout << "Sehingga gaji bersih anda sebesar : " << gajiBersih << endl << endl;
    }
    
    return 0;
};
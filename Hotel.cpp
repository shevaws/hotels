#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Node untuk menyimpan informasi hotel
struct Hotel {
    string nama;
    int harga;

    Hotel(string n, int h) : nama(n), harga(h) {}
};

// Kelas untuk mengelola daftar hotel
class HotelList {
private:
    vector<Hotel> hotels;

public:
    // Menambahkan hotel ke daftar
    void addHotel(string nama, int harga) {
        hotels.push_back(Hotel(nama, harga));
    }

    // Menampilkan daftar hotel
    void displayHotels() {
        for (size_t i = 0; i < hotels.size(); ++i) {
            cout << i + 1 << ". " << hotels[i].nama << ", Harga: " << hotels[i].harga << endl;
        }
    }

    // Mengambil hotel berdasarkan indeks
    Hotel getHotel(int index) {
        return hotels[index];
    }
};

int main() {
    // Membuat list sederhana menggunakan std::vector
    vector<string> ListHotel1;
    vector<string> ListHotel2;
    vector<string> BCA;
    vector<string> Dana;
    vector<string> OVO;

    // Menambahkan elemen ke dalam list
    ListHotel1.push_back("Hotel A, Terletak di Jakarta Utara");
    ListHotel1.push_back("Hotel B, Terletak di Jakarta Selatan");
    ListHotel1.push_back("Hotel C, Terletak di Jakarta Pusat");

    ListHotel2.push_back("Hotel A, Terletak di Denpasar");
    ListHotel2.push_back("Hotel B, Terletak di Kuta");  
    ListHotel2.push_back("Hotel C, Terletak di Pesanggaran");

    BCA.push_back("1. AN: Aji. Nomor Rekening: 012948712");
    BCA.push_back("2. AN: Haikal. Nomor Rekening: 012948712");
    BCA.push_back("3. AN: Arvan. Nomor Rekening: 012948712");

    Dana.push_back("1. AN: Aji. Nomor Dana: 012948712");
    Dana.push_back("2. AN: Haikal. Nomor Dana: 012948712");
    Dana.push_back("3. AN: Arvan. Nomor Dana: 012948712");

    OVO.push_back("1. AN: Aji. Nomor OVO: 012948712");
    OVO.push_back("2. AN: Haikal. Nomor OVO: 012948712");
    OVO.push_back("3. AN: Arvan. Nomor OVO: 012948712");

    


    HotelList Hotels;
    Hotels.addHotel("Single", 500000);
    Hotels.addHotel("Queen", 750000);
    Hotels.addHotel("King", 1000000);

    int choice, tgl, locationChoice;
    vector<pair<Hotel, int>> cart; // Vektor untuk menyimpan pesanan

    do {
        menu:
        cout << "\n\nPusat Pemesanan Hotel" << endl;
        cout << "Selamat datang, user." << endl;
        cout << "1. Pesan kamar" << endl;
        cout << "2. Pembayaran" << endl;
        cout << "Masukkan pilihan: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "\nPilih lokasi destinasi anda:" << endl;
                cout << "1. Jakarta" << endl;
                cout << "2. Bali" << endl;

                cout << "Masukkan pilihan anda: ";
                cin >> locationChoice;
                
                if (locationChoice == 1) {
                    cout << "\nHotel yang tersedia di Jakarta adalah:" << endl;
                    for (size_t i = 0; i < ListHotel1.size(); ++i) {
                        cout << i + 1 << ". " << ListHotel1[i] << endl;
                    }
                    int hotelChoice;
                    cout << "Harap masukkan pilihan: ";
                    cin >> hotelChoice;

                    cout << "\nHarap pilih tipe kamar: " << endl;
                    Hotels.displayHotels();
                    cout << "Masukkan pilihan anda: ";
                    int roomChoice;
                    cin >> roomChoice;
                    
                    cout << "\nMasukkan tanggal anda ingin menginap: ";
                    cin >> tgl;

                    int jumlah;
                    cout << "\nMasukkan jumlah kamar yang ingin anda pesan: ";
                    cin >> jumlah;

                    // Menambahkan pesanan ke dalam keranjang (cart)
                    cart.push_back(make_pair(Hotels.getHotel(roomChoice - 1), jumlah));

                    cout << "Pesanan anda akan kami proses." << endl;
                    goto menu;
                } else if (locationChoice == 2) {
                    cout << "\nHotel yang tersedia di Bali adalah:" << endl;
                    for (size_t i = 0; i < ListHotel2.size(); ++i) {
                        cout << i + 1 << ". " << ListHotel2[i] << endl;
                    }
                    int hotelChoice;
                    cout << "Harap masukkan pilihan: ";
                    cin >> hotelChoice;

                    cout << "\nHarap pilih tipe kamar: " << endl;
                    Hotels.displayHotels();
                    cout << "Masukkan pilihan anda: ";
                    int roomChoice;
                    cin >> roomChoice;
                    
                    cout << "\nMasukkan tanggal anda ingin menginap: ";
                    cin >> tgl;

                    int jumlah;
                    cout << "\nMasukkan jumlah kamar yang ingin anda pesan: ";
                    cin >> jumlah;

                    // Menambahkan pesanan ke dalam keranjang (cart)
                    cart.push_back(make_pair(Hotels.getHotel(roomChoice - 1), jumlah));

                    cout << "Pesanan anda akan kami proses." << endl;
                    goto menu;
                } else {
                    cout << "Pilihan tidak valid." << endl;
                }
                break;
            }
            case 2: {
                 // Menampilkan pesanan yang ada dalam keranjang
                string Lokasi;
                if (locationChoice == 1) {
                    Lokasi = "Jakarta";
                } else if (locationChoice == 2) {
                    Lokasi = "Bali";
                }

                int totalHarga = 0; // Variabel untuk menyimpan total harga pesanan
                cout << "Pesanan Anda:" << endl;
                for (size_t i = 0; i < cart.size(); ++i) {
                    cout << "Pesanan " << i + 1 << ": " << "Tipe Kamar: "<< cart[i].first.nama << ", Lokasi: " << Lokasi <<", Jumlah: " << cart[i].second << ", Tanggal Masuk: " << tgl << endl;
                    totalHarga += cart[i].first.harga * cart[i].second; // Menghitung total harga
                }
                
                cout << "\nTotal Harga: Rp. " << totalHarga << endl;
                // Menampilkan pilihan pembayaran
                cout << "\nPilih metode pembayaran" << endl;
                cout << "1. BCA" << endl;
                cout << "2. Dana" << endl;
                cout << "3. OVO" << endl;
                int paymentChoice;
                cout << "Masukkan pilihan anda: ";
                cin >> paymentChoice;

                // Menangani pilihan pembayaran
                switch (paymentChoice) {
                    case 1:
                        cout << '\n';
                        for (size_t i = 0; i < BCA.size(); ++i) {
                            cout << BCA[i] << endl;
                        }
                        cout << "Transfer cukup 1 kali ke salah satu tujuan." << endl;
                        intptr_t kontak;
                        cout << "\nHarap masukkan nomor telepon anda: ";
                        cin >> kontak;
                        break;
                    case 2:
                        cout << '\n';
                        for (size_t i = 0; i < Dana.size(); ++i) {
                            cout << Dana[i] << endl;
                        }
                        cout << "Transfer cukup 1 kali ke salah satu tujuan." << endl;
                        cout << "\nHarap masukkan nomor telepon anda: ";
                        cin >> kontak;
                        break;
                    case 3:
                        cout << '\n';
                        for (size_t i = 0; i < OVO.size(); ++i) {
                            cout << OVO[i] << endl;
                        }
                        cout << "Transfer cukup 1 kali ke salah satu tujuan." << endl;
                        cout << "\nHarap masukkan nomor telepon anda: ";
                        cin >> kontak;
                        break;
                    default:
                        cout << "Metode pembayaran tidak valid." << endl;
                }
                break;
            }
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (choice != 1 && choice != 2);

    cout << "\nPesanan anda akan kami proses.\nTerima Kasih telah mempercayai kami. Silahkan menikmati liburan anda." << endl;

    return 0;
}

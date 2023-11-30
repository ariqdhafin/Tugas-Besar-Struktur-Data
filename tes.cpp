// Fungsi untuk menampilkan Menu Utama
string printMenu(){
    string input;
    cout << "Mau iPad Pro Gen 5 dr Anastasya" << endl;
    cout << "Kosasih? Hub di *500*952#" << endl;
    cout << "1.Transfer Pulsa" << endl;
    cout << "2.Minta Pulsa" << endl;
    cout << "3.Auto TP" << endl;
    cout << "4.Delete Auto TP" << endl;
    cout << "5.List Auto TP" << endl;
    cout << "6.Cek Kupon Undian TP" << endl;
    cin>>input;
    cout<<endl;
    if (confirmation() == "Cancel" ){
        return "Cancel";
    }else{
        return input;
    }
}

// Fungsi untuk meminta konfirmasi input yang dimasukkan user
string confirmation(){
    string confirm;
    cout << "Cancel OR Send" << endl;
    cin >> confirm;
    return confirm;
}

// Fungsi untuk men-transfer pulsa ke nomor yang dituju
void transferPulsa(){
    string nomorTelepon;
    int jumlahPulsa;
    string pilihan;

    cout << "Silahkan masukkan nomor tujuan" << endl;
    cout << "Transfer Pulsa:(contoh:08xxxx" << endl;
    cout << "atau 628xxxx" << endl;
    cin >> nomorTelepon;
    if (confirmation() != "Cancel"){
        cout << "Silahkan masukkan jumlah pulsa yang" << endl;
        cout << "akan ditransfer : (min 5000, max 1jt &" << endl;
        cout << "tanpa . (titik) atau , (koma)" << endl;
        cin >> jumlahPulsa;
        if (confirmation() != "Cancel"){
            cout << "Hati2 penipuan. Anda akan Transfer Pulsa" << endl;
            cout << jumlahPulsa << "ke nomor" << nomorTelepon << "? (Biaya" << endl;
            cout << "3000 & 1Poin undian TP iPhone14)" << endl;
            cout << "1.Ya" << endl;
            cout << "9.Back" << endl;
            cout << "0.Home" << endl;
            cin >> pilihan;
            if (confirmation() != "Cancel" && pilihan == "1"){
                // Transfer pulsa ke nomor yang dituju
            }
        }
    }
}

int main(){
    string pilihan = printMenu()

    while(pilihan != "Cancel"){
        if(pilihan == "1"){
            // Jika user memilih pilihan Transfer Pulsa
            transferPulsa();
        }else if (pilihan == "2"){
            // Jika user memilih pilihan Minta Pulsa
        }else if (pilihan == "3"){
            // Jika user memilih pilihan Auto TP
        }else if (pilihan == "4"){
            // Jika user memilih pilihan Delete Auto TP
        }else if (pilihan == "5"){
            // Jika user memilih pilihan List Auto TP
        }else if (pilihan == "6"){
            // Jika user memilih pilihan Cek Kupon Undian TP
        }else{
            // Jika user memasukkan pilihan diluar angka 1-6
            cout<<"Input invalid"<<endl;
            cout<<endl;
        }
        pilihan = printMenu()
    }
}

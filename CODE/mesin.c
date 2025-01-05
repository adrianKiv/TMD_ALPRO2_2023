/* 
Saya Adrian Mulianto mengerjakan TMD dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. 
*/
#include "head.h"

int idx;
int Pkata;
char kataS[71];

// Fungsi untuk mendapatkan panjang kata saat ini
int getlen(){
    return Pkata;
}

// Fungsi untuk mendapatkan kata saat ini
char *getkata_sekarang(){
    return kataS;
}

// Fungsi untuk memeriksa akhir dari proses
int eop(char string[]){
    // Memeriksa apakah karakter saat ini merupakan simbol akhir pita
    if (string[idx] == ';'){
        return 1;
    }
    else{
        return 0;
    }
}

// Prosedur untuk memulai mesin kata
void mulai(char string[]){
    // inisialisasi index dan panjang kata
    idx = 0;
    Pkata = 0;

    // jika karakter dalam index adalah spasi, maka index terus maju
    while (string[idx] == ' '){
        idx++;
    }

    // jika masukan berupa karakter selain spasi dan EOP, kata diatur ke variabel global
    while ((string[idx] != ' ') && (eop(string) == 0)){
        kataS[Pkata] = string[idx];
        Pkata++;
        idx++;
    }

    // mengatur agar kata saat ini index terakhirnya menjadi NULL
    kataS[Pkata] = '\0';
}

// Prosedur untuk memajukan kata
void inc(char string[]){
    // inisialisasi ulang panjang kata
    Pkata = 0;

    // jika karakter dalam pita adalah spasi, maka index terus maju
    while (string[idx] == ' '){
        idx++;
    }

    // jika masukan berupa karakter selain spasi dan EOP, kata diatur ke variabel global
    while ((string[idx] != ' ') && (eop(string) == 0)){
        kataS[Pkata] = string[idx];
        Pkata++;
        idx++;
    }

    // mengatur agar kata saat ini index terakhirnya menjadi NULL
    kataS[Pkata] = '\0';
}

int ss_data(int n, agribisnis source[], char keyword[100]){
    int ketemu = 0; // set 0
    int i = 0; // index 0
    while((i < n) && (ketemu == 0)) { // syarat
        if(strcmp(source[i].kode, keyword) == 0){ // jika yang dicari ketemu maka :
            ketemu = 1; // nilai temu jadi 1
        } else {
            i++; // jika tidak ada
        }
    }

    if (ketemu == 1){
        return i; // mengambil index jika ketemu
    }
    else {
        return -1; // jika tidak ketemu
    }
}
// menegcek query perintah single
int perintah1(){
    int commnad = 0;
    if (strcmp(penyimpanan[0], "INSERT") == 0){ // menegecek query
        return commnad = 1; // pengenbalian nilai
    }
    else if (strcmp(penyimpanan[0], "UPDATE") == 0){ // menegecek query
        return commnad = 2; // pengenbalian nilai
    }
    else if (strcmp(penyimpanan[0], "DELETE") == 0){ // menegecek query
        return commnad = 3; // pengenbalian nilai
    }
    else if (strcmp(penyimpanan[0], "SELECT") == 0){ // menegecek query
        return commnad = 4; // pengenbalian nilai
    }
    else if (strcmp(penyimpanan[0], "JOIN") == 0){ // menegecek query
        return commnad = 5; // pengenbalian nilai
    }
    else if (strcmp(penyimpanan[0], "keluar") == 0){ // menegecek query
        printf("\ndadahhhhh\n\n");
    }
    else {
        printf("[[ERROR]] perintah %s yang kamu masukan tidak ada\n\n", penyimpanan[0]); // jika query salah
        return commnad = -1;
    }
}
// menegcek query perintah double
int perintah2(){
    int commnad = 0;
    if (strcmp(penyimpanan[1], "INSERT") == 0){ // menegcek query
        return commnad = 1; // pengembalian nilai
    }
    else if (strcmp(penyimpanan[1], "UPDATE") == 0){ // menegcek query
        return commnad = 2; // pengembalian nilai
    }
    else if (strcmp(penyimpanan[1], "DELETE") == 0){ // menegcek query
        return commnad = 3; // pengembalian nilai
    }
    else if (strcmp(penyimpanan[1], "SELECT") == 0){ // menegcek query
        return commnad = 4; // pengembalian nilai
    }
    else {
        return commnad = -1;
    }
}

void read_data(int *n, agribisnis data[], char file[]){
    FILE *P_sementara;
    P_sementara = fopen(file, "r"); // buka file dengan mode read
// scan 4 data pertama (baris 1)
    int scan = fscanf(P_sementara, "%s %s %s %s", data[*n].kode, data[*n].nama, data[*n].jumlah, data[*n].asal);

    // cek apakah scan tadi kolom nimnya merukan EOF dummy atau return hasil fscanf adalah EOF(-1)?
    if (strcmp(data[*n].kode, "+++") == 0 || scan == EOF) {
        // jika, ya maka file kosong
        printf("File Belum Di isi...\n");
    } 
    else {
        // jika tidak maka bisa scan kembali selama kolom nim bukan EOF
        while (strcmp(data[*n].kode, "+++") != 0) {
            *n = *n + 1; // maju ke indeks penampung berikutnya
            // scan 4 data selanjutnya (baris 2 dan seterusnya)
            fscanf(P_sementara, "%s %s %s %s", data[*n].kode, data[*n].nama, data[*n].jumlah, data[*n].asal);
        }
    }
    // "tutup file"
    fclose(P_sementara);  
}

void read_data2(int *n, agribisnis data[], char file[]){
    FILE *P_sementara;
    P_sementara = fopen(file, "r"); // buka file dengan mode read
// scan 4 data pertama (baris 1)
    int scan = fscanf(P_sementara, "%s %s %s %s %s", data[*n].kode, data[*n].nama, data[*n].jumlah, data[*n].asal, data[*n].kode2);

    // cek apakah scan tadi kolom nimnya merukan EOF dummy atau return hasil fscanf adalah EOF(-1)?
    if (strcmp(data[*n].kode, "+++") == 0 || scan == EOF) {
        // jika, ya maka file kosong
        printf("File Belum Di isi...\n");
    } 
    else {
        // jika tidak maka bisa scan kembali selama kolom nim bukan EOF
        while (strcmp(data[*n].kode, "+++") != 0) {
            *n = *n + 1; // maju ke indeks penampung berikutnya
            // scan 4 data selanjutnya (baris 2 dan seterusnya)
            fscanf(P_sementara, "%s %s %s %s %s", data[*n].kode, data[*n].nama, data[*n].jumlah, data[*n].asal, data[*n].kode2);
        }
    }
    // "tutup file"
    fclose(P_sementara);  
}

void write_data(int n, agribisnis data[], char file[]){
    FILE *P_sementara; // pointer ke file
    P_sementara = fopen(file, "w"); // buka file dengan mode write

    // tulis data ke file
    for (int i = 0; i < n; i++){
        // tulis 4 kolom lalu beri newline
        fprintf(P_sementara, "%s %s %s %s\n", data[i].kode, data[i].nama, data[i].jumlah, data[i].asal);
    }

    // berikan EOF di akhir file
    fprintf(P_sementara, "%s %s %s %s\n", "+++", "+++", "+++", "+++");

    // "tutup file"
    fclose(P_sementara);
}

void write_data2(int n, agribisnis data[], char file[]){
    FILE *P_sementara; // pointer ke file
    P_sementara = fopen(file, "w"); // buka file dengan mode write

    // tulis data ke file
    for (int i = 0; i < n; i++){
        // tulis 4 kolom lalu beri newline
        fprintf(P_sementara, "%s %s %s %s %s\n", data[i].kode, data[i].nama, data[i].jumlah, data[i].asal, data[i].kode2);
    }

    // berikan EOF di akhir file
    fprintf(P_sementara, "%s %s %s %s %s\n", "+++", "+++", "+++", "+++", "+++");

    // "tutup file"
    fclose(P_sementara);
}

void insert_tani(){
    int a = perintah1(); // pengecekan perintah query
    int b = perintah2(); // pengecekan perintah query

    if (bqr < 7){ // mengecek apakah query kurang
        printf("[[ERROR]] QUERY kurang dari kolom table\n\n");
    }
    else { // jika tidak
        if ((a != -1) && (b == -1)){ // jika masukan perintah single query
            int p = 0;
            read_data2(&p, arrpertanian, "../FILE/pertanian.dat"); // memanggil prosedur membaca file pertanian
            int cekada = ss_data(p, arrpertanian, penyimpanan[2]); // menegcek kode apakah sudah ada
            if (cekada != -1){
                printf("[[ERROR]] Data dengan PRIMARY key %s sudah ada\n\n", penyimpanan[2]);
            }
            else {
                for (int s = 0; s < p; s++){ // proses memasukan data dari mesin kata ke file
                    strcpy(arrpertanian[p].kode, penyimpanan[2]);
                    strcpy(arrpertanian[p].nama, penyimpanan[3]);
                    strcpy(arrpertanian[p].jumlah, penyimpanan[4]);
                    strcpy(arrpertanian[p].asal, penyimpanan[5]);
                    strcpy(arrpertanian[p].kode2, penyimpanan[6]);
                }
                printf("\nINSERT berhasil\n\n");
                p++;
                write_data2(p, arrpertanian, "../FILE/pertanian.dat"); // memanggil prosedur menulis untuk memasukan data
            }
        }
        else if ((a != -1) && (b != -1)){ // jika masukan double query
            int p = 0;
            read_data2(&p, arrpertanian, "../FILE/pertanian.dat"); // memanggil prosedur membaca file pertanian
            int cekada = ss_data(p, arrpertanian, penyimpanan[3]);
            if (cekada != -1){
                printf("[[ERROR]] Data dengan PRIMARY key %s sudah ada\n\n", penyimpanan[3]);
            }
            else {
                for (int s = 0; s < p; s++){ // proses memasukan data dari mesin kata ke file
                    strcpy(arrpertanian[p].kode, penyimpanan[3]);
                    strcpy(arrpertanian[p].nama, penyimpanan[4]);
                    strcpy(arrpertanian[p].jumlah, penyimpanan[5]);
                    strcpy(arrpertanian[p].asal, penyimpanan[6]);
                    strcpy(arrpertanian[p].kode2, penyimpanan[7]);
                }
                printf("\nINSERT berhasil\n\n");
                p++;
                write_data2(p, arrpertanian, "../FILE/pertanian.dat"); // memanggil prosedur menulis untuk memasukan data
            }
        }
        else {
            printf("[[ERROR]] INSERT gagal query kamu salah\n\n");
        }
    }
}

void insert_ternak(){
    int a = perintah1(); // pengecekan perintah query
    int b = perintah2(); // pengecekan perintah query

    if (bqr < 6){ // jika query kurang
        printf("[[ERROR]] QUERY kurang dari kolom table\n\n");
    }
    else {
        if ((a != -1) && (b == -1)){ // jika masukan perintah sigle query
            int p = 0;
            read_data(&p, arrpeternakan, "../FILE/peternakan.dat"); // memanggil prosedur untuk membaca file peternakan
            int cekada = ss_data(p, arrpertanian, penyimpanan[2]); // menegcek kode apakah sudah ada
            if (cekada != -1){
                printf("[[ERROR]] Data dengan PRIMARY key %s sudah ada\n\n", penyimpanan[2]);
            }
            else {
                for (int s = 0; s < p; s++){ // proses memasukan data dari mesin kata ke file
                    strcpy(arrpeternakan[p].kode, penyimpanan[2]);
                    strcpy(arrpeternakan[p].nama, penyimpanan[3]);
                    strcpy(arrpeternakan[p].jumlah, penyimpanan[4]);
                    strcpy(arrpeternakan[p].asal, penyimpanan[5]);
                }
                printf("\nINSERT berhasil\n\n");
                p++;
                write_data(p, arrpeternakan, "../FILE/peternakan.dat"); // memanggil prosedur menulis untuk memasukan data 
            }
        }
        else if ((a != -1) && (b != -1)){ // jika masukan perintah double query
            int p = 0;
            read_data(&p, arrpeternakan, "../FILE/peternakan.dat"); // memanggil prosedur untuk membaca file peternakan
            int cekada = ss_data(p, arrpertanian, penyimpanan[3]);
            if (cekada != - 1){
                printf("[[ERROR]] Data dengan PRIMARY key %s sudah ada\n\n", penyimpanan[3]);
            }
            else {
                for (int s = 0; s < p; s++){ // proses memasukan data dari mesin kata ke file
                    strcpy(arrpeternakan[p].kode, penyimpanan[3]);
                    strcpy(arrpeternakan[p].nama, penyimpanan[4]);
                    strcpy(arrpeternakan[p].jumlah, penyimpanan[5]);
                    strcpy(arrpeternakan[p].asal, penyimpanan[6]);
                }
                printf("\nINSERT berhasil\n\n");
                p++;
                write_data(p, arrpeternakan, "../FILE/peternakan.dat"); // memanggil prosedur menulis untuk memasukan data 
            }
        }
        else {
            printf("[[ERROR]] INSERT gagal query yang kamu masukan salah\n\n");
        }
    }
}

void update_tani(){
    int a = perintah1(); // pengecekan perintah query
    int b = perintah2(); // pengecekan perintah query

    if (bqr < 7){ // jika query kurang
        printf("[[ERROR]] QUERY kurang dari kolom table\n\n");
    }
    else { // jika tidak
        if ((a != -1) && (b == -1)){ // jika masukan perintah single query
            int x = 0;
            read_data2(&x, arrpertanian, "../FILE/pertanian.dat"); // memanggil prosedur untuk membaca file pertanian
            int p = ss_data(x, arrpertanian, penyimpanan[2]); // mengecek kode apakah sudah ada
            if (p != -1){ // menegcek apakah perintah yang di berikan user kode nya sudah dipakai atau belum 
                for (int s = 0; s < x; s++){ // proses update data dari mesin kata ke file
                    strcpy(arrpertanian[p].nama, penyimpanan[3]);
                    strcpy(arrpertanian[p].jumlah, penyimpanan[4]);
                    strcpy(arrpertanian[p].asal, penyimpanan[5]);
                    strcpy(arrpertanian[p].kode2, penyimpanan[6]);
                }
                printf("\nUPDATE berhasil\n\n");
                write_data2(x, arrpertanian, "../FILE/pertanian.dat"); // memanggil prosedur menulis untuk memasukan data
            }
            else {
                printf("[[ERROR]] UPDATE gagal data dengan PRIMARY key %s tidak ada\n\n", penyimpanan[2]);
            }
        }
        else if ((a != -1) && ( b != -1)){ // jika masukan perintah double query
            int x = 0;
            read_data2(&x, arrpertanian, "../FILE/pertanian.dat"); // memanggil prosedur untuk membaca file pertanian
            int p = ss_data(x, arrpertanian, penyimpanan[3]); // mengecek data kode apakah sudah ada
            if (p != -1){ // menegcek apakah perintah yang di berikan user kode nya sudah dipakai atau belum 
                for (int s = 0; s < x; s++){ // proses update data dari mesin kata ke file
                    strcpy(arrpertanian[p].nama, penyimpanan[4]);
                    strcpy(arrpertanian[p].jumlah, penyimpanan[5]);
                    strcpy(arrpertanian[p].asal, penyimpanan[6]);
                    strcpy(arrpertanian[p].kode2, penyimpanan[7]);
                }
                printf("\nUPDATE berhasil\n\n");
                write_data2(x, arrpertanian, "../FILE/pertanian.dat"); // memanggil prosedur menulis untuk memasukan data
            }
            else {
                printf("[[ERROR]] UPDATE gagal data dengan PRIMARY key %s tidak ada\n\n", penyimpanan[3]);
            }
        }
        else {
            printf("[[ERROR]] UPDATE gagal query yang kamu masukan salah\n\n");
        }
    }
}

void update_ternak(){
    int a = perintah1(); // pengecekan perintah query
    int b = perintah2(); // pengecekan perintah query

    if (bqr < 6){ // jika query kurang
        printf("[[ERROR]] QUERY kurang dari kolom table\n\n");
    }
    else {
        if ((a != -1) && (b == -1)){ // jika masukan perintah single query
            int x = 0;
            read_data(&x, arrpeternakan, "../FILE/peternakan.dat"); // memanggil prosedur untuk membaca file peternakan
            int p = ss_data(x, arrpeternakan, penyimpanan[2]); // menecek data kode apakah sudah ada
            if (p != -1){ // menegcek apakah perintah yang di berikan user kode nya sudah dipakai atau belum 
                for (int s = 0; s < x; s++){ // proses update data dari mesin kata ke file
                    strcpy(arrpeternakan[p].nama, penyimpanan[3]);
                    strcpy(arrpeternakan[p].jumlah, penyimpanan[4]);
                    strcpy(arrpeternakan[p].asal, penyimpanan[5]);
                }
                printf("\nUPDATE berhasil\n\n");
                write_data(x, arrpeternakan, "../FILE/peternakan.dat"); // memanggil prosedur menulis untuk memasukan data
            }
            else {
                printf("[[ERROR]] UPDATE gagal data dengan PRIMARY key %s tidak ada\n\n", penyimpanan[2]);
            }
        }
        else if ((a != -1) && ( b != -1)){ // jika masukan perintah double query
            int x = 0;
            read_data(&x, arrpeternakan, "../FILE/peternakan.dat"); // memanggil prosedur untuk membaca file peternakan
            int p = ss_data(x, arrpeternakan, penyimpanan[3]); // mengecek data kode apakah sudah ada
            if (p != -1){ // menegcek apakah perintah yang di berikan user kode nya sudah dipakai atau belum 
                for (int s = 0; s < x; s++){ // proses update data dari mesin kata ke file
                    strcpy(arrpeternakan[p].nama, penyimpanan[4]);
                    strcpy(arrpeternakan[p].jumlah, penyimpanan[5]);
                    strcpy(arrpeternakan[p].asal, penyimpanan[6]);
                }
                printf("\nUPDATE berhasil\n\n");
                write_data(x, arrpeternakan, "../FILE/peternakan.dat"); // memanggil prosedur menulis untuk memasukan data
            }
            else {
                printf("[[ERROR]] UPDATE gagal data dengan PRIMARY key %s tidak ada\n\n", penyimpanan[3]);
            }
        }
        else {
            printf("[[ERROR]] query kamu masukan salah bre\n\n");
        }
    }
}

void delete_tani(){
    int a = perintah1(); // pengecekan perintah query
    int b = perintah2(); // pengecekan perintah query

    if ((a != -1) && (b == -1)){ // jika masukan perintah single query
        int x = 0;
        read_data2(&x, arrpertanian, "../FILE/pertanian.dat"); // memanggil prosedur untuk membaca file pertanian
        int p = ss_data(x, arrpertanian, penyimpanan[2]); // mengecek kode apakah sudah ada
        if (p != -1){ // menegcek apakah perintah yang di berikan user kode nya sudah dipakai atau belum 
            for (int s = p; s < x; s++){ // proses delete data
                strcpy(arrpertanian[s].kode, arrpertanian[s + 1].kode);
                strcpy(arrpertanian[s].nama, arrpertanian[s + 1].nama);
                strcpy(arrpertanian[s].jumlah, arrpertanian[s + 1].jumlah);
                strcpy(arrpertanian[s].asal, arrpertanian[s + 1].asal);
                strcpy(arrpertanian[s].kode2, arrpertanian[s + 1].kode2);
            }
            printf("\nDELETE berhasil\n\n");
            x--;
            write_data2(x, arrpertanian, "../FILE/pertanian.dat"); // memanggil prosedur menulis untuk memasukan data
        }
        else {
            printf("[[ERROR]] DELETE dengan PRIMARY key %s gagal karena data tidak ada\n\n", penyimpanan[2]);
        }
    }
    else if ((a != -1) && (b != -1)){ // jika masukan perintah double query
        int x = 0;
        read_data2(&x, arrpertanian, "../FILE/pertanian.dat"); // memanggil prosedur untuk membaca file pertanian
        int p = ss_data(x, arrpertanian, penyimpanan[3]); // mengecek data kode apakah sudah ada
        if (p != -1){ // menegcek apakah perintah yang di berikan user kode nya sudah dipakai atau belum 
            for (int s = p; s < x; s++){ // proses delete data
                strcpy(arrpertanian[s].kode, arrpertanian[s + 1].kode);
                strcpy(arrpertanian[s].nama, arrpertanian[s + 1].nama);
                strcpy(arrpertanian[s].jumlah, arrpertanian[s + 1].jumlah);
                strcpy(arrpertanian[s].asal, arrpertanian[s + 1].asal);
                strcpy(arrpertanian[s].kode2, arrpertanian[s + 1].kode2);
            }
            printf("\nDELETE berhasil\n\n");
            x--;
            write_data2(x, arrpertanian, "../FILE/pertanian.dat"); // memanggil prosedur menulis untuk memasukan data
        }
        else {
            printf("[[ERROR]] DELETE dengan PRIMARY key %s gagal karena data tidak ada\n\n", penyimpanan[3]);
        }
    }
    else {
        printf("[[ERROR]] query kamu masukan salah bre\n\n");
    }
}

void delete_ternak(){
    int a = perintah1(); // pengecekan perintah query
    int b = perintah2(); // pengecekan perintah query

    if ((a != -1) && (b == -1)){ // jika masukan perintah single query
        int x = 0;
        read_data(&x, arrpeternakan, "../FILE/peternakan.dat"); // memanggil prosedur untuk membaca file peternakan
        int p = ss_data(x, arrpeternakan, penyimpanan[2]); // menecek data kode apakah sudah ada
        if (p != -1){ // menegcek apakah perintah yang di berikan user kode nya sudah dipakai atau belum 
            for (int s = p; s < x; s++){ // proses delete data
                strcpy(arrpeternakan[s].kode, arrpeternakan[s + 1].kode);
                strcpy(arrpeternakan[s].nama, arrpeternakan[s + 1].nama);
                strcpy(arrpeternakan[s].jumlah, arrpeternakan[s + 1].jumlah);
                strcpy(arrpeternakan[s].asal, arrpeternakan[s + 1].asal);
            }
            printf("\nDELETE berhasil\n\n");
            x--;
            write_data(x, arrpeternakan, "../FILE/peternakan.dat"); // memanggil prosedur menulis untuk memasukan data
        }
        else {
            printf("[[ERROR]] DELETE dengan PRIMARY key %s gagal karena data tidak ada\n\n", penyimpanan[2]);
        }
    }
    else if ((a != -1) && (b != -1)){ // jika masukan perintah double query
        int x = 0;
        read_data(&x, arrpeternakan, "../FILE/peternakan.dat"); // memanggil prosedur untuk membaca file peternakan
        int p = ss_data(x, arrpeternakan, penyimpanan[3]); // mengecek data kode apakah sudah ada
        if (p != -1){ // menegcek apakah perintah yang di berikan user kode nya sudah dipakai atau belum 
            for (int s = p; s < x; s++){ // proses delete data
                strcpy(arrpeternakan[s].kode, arrpeternakan[s + 1].kode);
                strcpy(arrpeternakan[s].nama, arrpeternakan[s + 1].nama);
                strcpy(arrpeternakan[s].jumlah, arrpeternakan[s + 1].jumlah);
                strcpy(arrpeternakan[s].asal, arrpeternakan[s + 1].asal);
            }
            printf("\nDELETE berhasil\n\n");
            x--;
            write_data(x, arrpeternakan, "../FILE/peternakan.dat"); // memanggil prosedur menulis untuk memasukan data
        }
        else {
            printf("[[ERROR]] DELETE dengan PRIMARY key %s gagal karena data tidak ada\n\n", penyimpanan[3]);
        }
    }
    else {
        printf("[[ERROR]] query kamu masukan salah bre\n\n");
    }
}

void select_tani(){
    // mengambil nilai terpanjang dari kata untuk table
    maxcode1 = strlen("KODE PERTANIAN");
    maxnama1 = strlen("NAMA HASIL PERTANIAN");
    maxberat1 = strlen("BERAT BARANG");
    maxasal1 = strlen("ASAL KOTA");
    tmaxcode1 = strlen("KODE PETERNAKAN");
    int a = 0;
    read_data2(&a, arrpertanian, "../FILE/pertanian.dat"); // memanggil prosedur membaca data peternakan

    // pengecekan kata paling panjang akan di ambil nilainnya
    for (int s = 0;s < a; s++){
        if (strlen(arrpertanian[s].kode) > maxcode1){
            maxcode1 = strlen(arrpertanian[s].kode);
        }
        if (strlen(arrpertanian[s].nama) > maxnama1){
            maxnama1 = strlen(arrpertanian[s].nama);
        }
        if (strlen(arrpertanian[s].jumlah) > maxberat1){
            maxberat1 = strlen(arrpertanian[s].jumlah);
        }
        if (strlen(arrpertanian[s].asal) > maxasal1){
            maxasal1 = strlen(arrpertanian[s].asal);
        }
        if (strlen(arrpertanian[s].kode2) > tmaxcode1){
            tmaxcode1 = strlen(arrpertanian[s].kode2);
        }
    }

    // outout atas table dan pengaturan spasi agar table pas
    printf("\n[TABLE PERTANIAN]\n\n");
    garis1();

    printf("| KODE PERTANIAN ");
    for (int i = 0; i < maxcode1 - strlen("KODE PERTANIAN"); i++){
        printf(" ");
    }
    printf("| NAMA HASIL PERTANIAN ");
    for (int i = 0; i < maxnama1 - strlen("NAMA HASIL PERTANIAN"); i++){
        printf(" ");
    }
    printf("| BERAT BARANG ");
    for (int i = 0; i < maxberat1 - strlen("BERAT BARANG"); i++){
        printf(" ");
    }
    printf("| ASAL KOTA ");
    for (int i = 0; i < maxasal1 - strlen("ASAL KOTA"); i++){
        printf(" ");
    }
    printf("| KODE PETERNAKAN ");
    for (int i = 0; i < tmaxcode1 - strlen("KODE PETERNAKAN"); i++){
        printf(" ");
    }
    printf("|\n");
    garis1();

    // output isi table dan pengaturan spasi agar table pas
    for (int s = 0;s < a; s++){
        printf("| %s ", arrpertanian[s].kode);
        for (int i = 0; i < maxcode1 - strlen(arrpertanian[s].kode); i++){
            printf(" ");
        }
        printf("| %s ", arrpertanian[s].nama);
        for (int i = 0; i < maxnama1 - strlen(arrpertanian[s].nama); i++){
            printf(" ");
        }
        printf("| %s ", arrpertanian[s].jumlah);
        for (int i = 0; i < maxberat1 - strlen(arrpertanian[s].jumlah); i++){
            printf(" ");
        }
        printf("| %s ", arrpertanian[s].asal);
        for (int i = 0; i < maxasal1 - strlen(arrpertanian[s].asal); i++){
            printf(" ");
        }
        printf("| %s ", arrpertanian[s].kode2);
        for (int i = 0; i < tmaxcode1 - strlen(arrpertanian[s].kode2); i++){
            printf(" ");
        }
        printf("|\n");
    }
    garis1();
    printf("\n");
}

void select_ternak(){
    // mengambil nilai terpanjang dari kata untuk table
    maxcode2 = strlen("KODE PETERNAKAN");
    maxnama2 = strlen("NAMA HASIL PETERNAKAN");
    maxberat2 = strlen("BERAT BARANG");
    maxasal2 = strlen("ASAL KOTA");
    int a = 0;
    read_data(&a, arrpertanian, "../FILE/peternakan.dat"); // memanggil prosedur membaca data peternakan

    // pengecekan kata paling panjang akan di ambil nilainnya
    for (int s = 0;s < a; s++){
        if (strlen(arrpertanian[s].kode) > maxcode2){
            maxcode2 = strlen(arrpertanian[s].kode);
        }
        if (strlen(arrpertanian[s].nama) > maxnama2){
            maxnama2 = strlen(arrpertanian[s].nama);
        }
        if (strlen(arrpertanian[s].jumlah) > maxberat2){
            maxberat2 = strlen(arrpertanian[s].jumlah);
        }
        if (strlen(arrpertanian[s].asal) > maxasal2){
            maxasal2 = strlen(arrpertanian[s].asal);
        }
    }

    // outout atas table dan pengaturan spasi agar table pas
    printf("\n[TABLE PETERNAKAN]\n\n");
    garis2();

    printf("| KODE PETERNAKAN ");
    for (int i = 0; i < maxcode2 - strlen("KODE PETERNAKAN"); i++){
        printf(" ");
    }
    printf("| NAMA HASIL PETERNAKAN ");
    for (int i = 0; i < maxnama2 - strlen("NAMA HASIL PETERNAKAN"); i++){
        printf(" ");
    }
    printf("| BERAT BARANG ");
    for (int i = 0; i < maxberat2 - strlen("BERAT BARANG"); i++){
        printf(" ");
    }
    printf("| ASAL KOTA ");
    for (int i = 0; i < maxasal2 - strlen("ASAL KOTA"); i++){
        printf(" ");
    }
    printf("|\n");
    garis2();

    // output isi table dan pengaturan spasi agar table pas
    for (int s = 0;s < a; s++){
        printf("| %s ", arrpertanian[s].kode);
        for (int i = 0; i < maxcode2 - strlen(arrpertanian[s].kode); i++){
            printf(" ");
        }
        printf("| %s ", arrpertanian[s].nama);
        for (int i = 0; i < maxnama2 - strlen(arrpertanian[s].nama); i++){
            printf(" ");
        }
        printf("| %s ", arrpertanian[s].jumlah);
        for (int i = 0; i < maxberat2 - strlen(arrpertanian[s].jumlah); i++){
            printf(" ");
        }
        printf("| %s ", arrpertanian[s].asal);
        for (int i = 0; i < maxasal2 - strlen(arrpertanian[s].asal); i++){
            printf(" ");
        }
        printf("|\n");
    }

    garis2();
    printf("\n");
}

void garis1(){
    printf("+");
    for (int i = 0; i < maxcode1 + 2; i++){
        printf("-");
    }
    printf("+");
    for (int i = 0; i < maxnama1 + 2; i++){
        printf("-");
    }
    printf("+");
    for (int i = 0; i < maxberat1 + 2; i++){
        printf("-");
    }
    printf("+");
    for (int i = 0; i < maxasal1 + 2; i++){
        printf("-");
    }
    printf("+");
    for (int i = 0; i < tmaxcode1 + 2; i++){
        printf("-");
    }
    printf("+\n");
}

void garis2(){
    printf("+");
    for (int i = 0; i < maxcode2 + 2; i++){
        printf("-");
    }
    printf("+");
    for (int i = 0; i < maxnama2 + 2; i++){
        printf("-");
    }
    printf("+");
    for (int i = 0; i < maxberat2 + 2; i++){
        printf("-");
    }
    printf("+");
    for (int i = 0; i < maxasal2 + 2; i++){
        printf("-");
    }
    printf("+\n");
}

void garis3(){
    printf("+");
    for (int i = 0; i < maxcode1 + 2; i++){
        printf("-");
    }
    printf("+");
    for (int i = 0; i < maxnama1 + 2; i++){
        printf("-");
    }
    printf("+");
    for (int i = 0; i < maxberat1 + 2; i++){
        printf("-");
    }
    printf("+");
    for (int i = 0; i < maxasal1 + 2; i++){
    printf("-");
    }
    printf("+");
    for (int i = 0; i < maxnama2 + 2; i++){
    printf("-");
    }
    printf("+");
    for (int i = 0; i < maxasal2 + 2; i++){
    printf("-");
    }
    printf("+\n");
}

void join(){
    // mengambil nilai terpanjang dari kata untuk table
    maxcode1 = strlen("KODE PERTANIAN");
    maxnama1 = strlen("NAMA HASIL PERTANIAN");
    maxberat1 = strlen("BERAT BARANG");
    maxasal1 = strlen("ASAL KOTA PERTANIAN");
    maxnama2 = strlen("NAMA HASIL PETERNAKAN");
    maxasal2 = strlen("ASAL KOTA PETERNAKAN");
    int a = 0, b = 0;
    read_data2(&a, arrpertanian, "../FILE/pertanian.dat"); // memanggil prosedur membaca data pertanian
    read_data(&b, arrpeternakan, "../FILE/peternakan.dat"); // memanggil prosedur membaca data peternakan

    // variable tampung semenatara
    char kode1[a][65];
    char nama1[a][65];
    char berat[a][65];
    char asal1[a][65];
    char nama2[a][65];
    char asal2[a][65];
    // proses join
    for (int x = 0; x < a; x++){
        int c = ss_data(b, arrpeternakan, arrpertanian[x].kode2);
        strcpy(kode1[x], arrpertanian[x].kode);
        strcpy(nama1[x], arrpertanian[x].nama);
        strcpy(berat[x], arrpertanian[x].jumlah);
        strcpy(asal1[x], arrpertanian[x].asal);
        strcpy(nama2[x], arrpeternakan[c].nama);
        strcpy(asal2[x], arrpeternakan[c].asal);
    }
    // pengecekan kata paling panjang akan di ambil nilainnya 
    for (int s = 0;s < a; s++){
        if (strlen(arrpertanian[s].kode) > maxcode1){
            maxcode1 = strlen(arrpertanian[s].kode);
        }
        if (strlen(arrpertanian[s].nama) > maxnama1){
            maxnama1 = strlen(arrpertanian[s].nama);
        }
        if (strlen(arrpertanian[s].jumlah) > maxberat1){
            maxberat1 = strlen(arrpertanian[s].jumlah);
        }
        if (strlen(arrpertanian[s].asal) > maxasal1){
            maxasal1 = strlen(arrpertanian[s].asal);
        }
        if (strlen(arrpeternakan[s].nama) > maxnama2){
            maxnama2 = strlen(arrpeternakan[s].nama);
        }
        if (strlen(arrpeternakan[s].asal) > maxasal2){
            maxasal2 = strlen(arrpeternakan[s].asal);
        }
    }

    // outout atas table dan pengaturan spasi agar table pas
    printf("\n[TABLE JOIN Ttani dan Tternak]\n\n");
    garis3();
    printf("| KODE PERTANIAN ");
    for (int i = 0; i < maxcode1 - strlen("KODE PERTANIAN"); i++){
        printf(" ");
    }
    printf("| NAMA HASIL PERTANIAN ");
    for (int i = 0; i < maxnama1 - strlen("NAMA HASIL PERTANIAN"); i++){
        printf(" ");
    }
    printf("| BERAT BARANG ");
    for (int i = 0; i < maxberat1 - strlen("BERAT BARANG"); i++){
        printf(" ");
    }
    printf("| ASAL KOTA PERTANIAN ");
    for (int i = 0; i < maxasal1 - strlen("ASAL KOTA PERTANIAN"); i++){
        printf(" ");
    }
    printf("| NAMA HASIL PETERNAKAN ");
    for (int i = 0; i < maxnama2 - strlen("NAMA HASIL PETERNAKAN"); i++){
        printf(" ");
    }
    printf("| ASAL KOTA PETERNAKAN ");
    for (int i = 0; i < maxasal2 - strlen("ASAL KOTA PETERNAKAN"); i++){
        printf(" ");
    }
    printf("|\n");
    garis3();

    // output isi table dan pengaturan spasi agar table pas
    for (int s = 0;s < a; s++){
        printf("| %s ", kode1[s]);
        for (int i = 0; i < maxcode1 - strlen(kode1[s]); i++){
            printf(" ");
        }
        printf("| %s ", nama1[s]);
        for (int i = 0; i < maxnama1 - strlen(nama1[s]); i++){
            printf(" ");
        }
        printf("| %s ", berat[s]);
        for (int i = 0; i < maxberat1 - strlen(berat[s]); i++){
            printf(" ");
        }
        printf("| %s ", asal1[s]);
        for (int i = 0; i < maxasal1 - strlen(asal1[s]); i++){
            printf(" ");
        }
        printf("| %s ", nama2[s]);
        for (int i = 0; i < maxnama2 - strlen(nama2[s]); i++){
            printf(" ");
        }
        printf("| %s ", asal2[s]);
        for (int i = 0; i < maxasal2 - strlen(asal2[s]); i++){
            printf(" ");
        }
        printf("|\n");
    }
    garis3();
    printf("\n");
}

void proses(char tape[]){
    int yy = perintah1(); // pengecekan masukan perintah query
    int zz = perintah2(); // pengecekan masukan perintah query

    // mengecek apakah querynya hanya 1 perintah dan perintahnnya adalah insert
    if ((yy == 1) && (strcmp(penyimpanan[1], "Ttani") == 0) || (yy == 1) && (strcmp(penyimpanan[1], "Tternak") == 0)){
        if (strcmp(penyimpanan[1], "Ttani") == 0){ // mengecek apakah masukan user adalah table pertanian (Ttani)
            insert_tani();
        }
        else if (strcmp(penyimpanan[1], "Tternak") == 0){ // mengecek apakah masukan user adalah table peternakan (Tternak)
            insert_ternak();
        }
        else {
            printf("[[ERROR]] table gada\n\n");
        }
    }// mengecek apakah querynya hanya 1 perintah dan perintahnnya adalah update
    else if ((yy == 2) && (strcmp(penyimpanan[1], "Ttani") == 0) || (yy == 2) && (strcmp(penyimpanan[1], "Tternak") == 0)){
        if (strcmp(penyimpanan[1], "Ttani") == 0){ // mengecek apakah masukan user adalah table pertanian (Ttani)
            update_tani();
        }
        else if (strcmp(penyimpanan[1], "Tternak") == 0){ // mengecek apakah masukan user adalah table peternakan (Tternak)
            update_ternak();
        }
        else {
            printf("[[ERROR]] table gada\n\n");
        }
    }// mengecek apakah querynya hanya 1 perintah dan perintahnnya adalah delete
    else if ((yy == 3) && (strcmp(penyimpanan[1], "Ttani") == 0) || (yy == 3) && (strcmp(penyimpanan[1], "Tternak") == 0)){
        if (strcmp(penyimpanan[1], "Ttani") == 0){ // mengecek apakah masukan user adalah table pertanian (Ttani)
            delete_tani();
        }
        else if (strcmp(penyimpanan[1], "Tternak") == 0){ // mengecek apakah masukan user adalah table peternakan (Tternak)
            delete_ternak();
        }
        else {
            printf("[[ERROR]] table gada\n\n");
        }
    }// mengecek apakah querynya hanya 1 perintah dan perintahnnya adalah select
    else if ((yy == 4) && (strcmp(penyimpanan[1], "Ttani") == 0) || (yy == 4) && (strcmp(penyimpanan[1], "Tternak") == 0)){
        if (strcmp(penyimpanan[1], "Ttani") == 0){ // mengecek apakah masukan user adalah table pertanian (Ttani)
            select_tani();
        }
        else if (strcmp(penyimpanan[1], "Tternak") == 0){ // mengecek apakah masukan user adalah table peternakan (Tternak)
            select_ternak();
        }
        else{
            printf("[[ERROR]] table gada\n\n");
        }
    }// mengecek apakah querynya hanya 1 perintah dan perintahnnya adalah select table
    else if ((yy == 4) && (strcmp(penyimpanan[1], "table") == 0)){
        select_tani();
        select_ternak();
    }// mengecek apakah querynya hanya 1 perintah dan perintahnnya adalah join 
    else if ((yy == 5) && (strcmp(penyimpanan[1], "Ttani") == 0) && (strcmp(penyimpanan[2], "Tternak") == 0) || (yy == 5) && (strcmp(penyimpanan[1], "Tternak") == 0) && (strcmp(penyimpanan[2], "Ttani") == 0)){
        join();
    }
    else if ((yy == 1) && (zz == 2) || (yy == 2) && (zz == 1)){ // INSERT UPDATE atau UPDATE INSERT
        if (strcmp(penyimpanan[2], "Ttani") == 0){
            int x = 0;
            read_data2(&x, arrpertanian, "../FILE/pertanian.dat"); // memanggil prosedur untuk membaca file pertanian
            int p = ss_data(x, arrpertanian, penyimpanan[3]); // mengecek data kode apakah sudah ada

            if (p != -1){ // menegcek apakah perintah yang di berikan user kode nya sudah dipakai atau belum 
                update_tani();
                printf("data dengan PRIMARY key %s sudah ada jadi di UPDATE\n\n", penyimpanan[3]);
            }
            else {
                insert_tani();
                printf("data dengan PRIMARY key %s belum ada jadi di INSERT\n\n", penyimpanan[3]);
            }   
        }
        else if (strcmp(penyimpanan[2], "Tternak") == 0){
            int x = 0;
            read_data(&x, arrpeternakan, "../FILE/peternakan.dat"); // memanggil prosedur untuk membaca file peternakan
            int p = ss_data(x, arrpeternakan, penyimpanan[3]); // mengecek data kode apakah sudah ada

            if (p != -1){ // menegcek apakah perintah yang di berikan user kode nya sudah dipakai atau belum 
                update_ternak();
                printf("data dengan PRIMARY key %s sudah ada jadi di UPDATE\n\n", penyimpanan[3]);
            }
            else {
                insert_ternak();
                printf("data dengan PRIMARY key %s belum ada jadi di INSERT\n\n", penyimpanan[3]);
            }   
        }
        else {
            printf("[[ERROR]] table gada\n\n");
        }
    }
    else if ((yy == 1) && (zz == 3) || (yy == 3) && (zz == 1)){ // INSERT DELETE dan DELETE INSERT
        if (strcmp(penyimpanan[2], "Ttani") == 0){
            int x = 0;
            read_data2(&x, arrpertanian, "../FILE/pertanian.dat"); // memanggil prosedur untuk membaca file pertanian
            int p = ss_data(x, arrpertanian, penyimpanan[3]); // mengecek data kode apakah sudah ada

            if (p != -1){ // menegcek apakah perintah yang di berikan user kode nya sudah dipakai atau belum 
                delete_tani();
                printf("data dengan PRIMARY key %s sudah ada jadi di DELETE\n\n", penyimpanan[3]);
            }
            else {
                insert_tani();
                printf("data dengan PRIMARY key %s belum ada jadi di INSERT\n\n", penyimpanan[3]);
            }   
        }
        else if (strcmp(penyimpanan[2], "Tternak") == 0){
            int x = 0;
            read_data(&x, arrpeternakan, "../FILE/peternakan.dat"); // memanggil prosedur untuk membaca file peternakan
            int p = ss_data(x, arrpeternakan, penyimpanan[3]); // mengecek data kode apakah sudah ada

            if (p != -1){ // menegcek apakah perintah yang di berikan user kode nya sudah dipakai atau belum 
                delete_ternak();
                printf("data dengan PRIMARY key %s sudah ada jadi di DELETE\n\n", penyimpanan[3]);
            }
            else {
                insert_ternak();
                printf("data dengan PRIMARY key %s belum ada jadi di INSERT\n\n", penyimpanan[3]);
            }
        }
        else {
            printf("[[ERROR]] table gada\n\n");
        }
    }
    else if ((yy == 1) && (zz == 4) || (yy == 4) && (zz == 1)){ // INSERT select dan select INSERT
        if (strcmp(penyimpanan[2], "Ttani") == 0){
            int x = 0;
            read_data2(&x, arrpertanian, "../FILE/pertanian.dat"); // memanggil prosedur untuk membaca file pertanian
            int p = ss_data(x, arrpertanian, penyimpanan[3]); // mengecek data kode apakah sudah ada

            if (p != -1){ // menegcek apakah perintah yang di berikan user kode nya sudah dipakai atau belum 
                printf("\ndata dengan PRIMARY key %s sudah ada jadi di SELECT\n", penyimpanan[3]);
                select_tani();
            }
            else {
                insert_tani();
                printf("data dengan PRIMARY key %s belum ada jadi di INSERT\n\n", penyimpanan[3]);
            }   
        }
        else if (strcmp(penyimpanan[2], "Tternak") == 0){
            int x = 0;
            read_data(&x, arrpeternakan, "../FILE/peternakan.dat"); // memanggil prosedur untuk membaca file peternakan
            int p = ss_data(x, arrpeternakan, penyimpanan[3]); // mengecek data kode apakah sudah ada

            if (p != -1){ // menegcek apakah perintah yang di berikan user kode nya sudah dipakai atau belum 
                printf("\ndata dengan PRIMARY key %s sudah ada jadi di SELECT\n", penyimpanan[3]);
                select_ternak();
            }
            else {
                insert_ternak();
                printf("data dengan PRIMARY key %s belum ada jadi di INSERT\n\n", penyimpanan[3]);
            }
        }
        else {
            printf("[[ERROR]] table gada\n\n");
        }
    }
    else if ((yy == 2) && (zz == 4) || (yy == 4) && (zz == 2)){ // UPDATE select dan select UPDATE
        if (strcmp(penyimpanan[2], "Ttani") == 0){
            int x = 0;
            read_data2(&x, arrpertanian, "../FILE/pertanian.dat"); // memanggil prosedur untuk membaca file pertanian
            int p = ss_data(x, arrpertanian, penyimpanan[3]); // mengecek data kode apakah sudah ada

            if (p != -1){ // menegcek apakah perintah yang di berikan user kode nya sudah dipakai atau belum 
                update_tani();
                printf("\ndata dengan PRIMARY key %s sudah ada jadi di UPDATE\n\n", penyimpanan[3]);
            }
            else {
                printf("data dengan PRIMARY key %s belum ada jadi di SELECT\n", penyimpanan[3]);
                select_tani();
            }   
        }
        else if (strcmp(penyimpanan[2], "Tternak") == 0){
            int x = 0;
            read_data(&x, arrpeternakan, "../FILE/peternakan.dat"); // memanggil prosedur untuk membaca file peternakan
            int p = ss_data(x, arrpeternakan, penyimpanan[3]); // mengecek data kode apakah sudah ada

            if (p != -1){ // menegcek apakah perintah yang di berikan user kode nya sudah dipakai atau belum  // data ada
                update_ternak();
                printf("\ndata dengan PRIMARY key %s sudah ada jadi di UPDATE\n\n", penyimpanan[3]);
            }
            else {
                printf("data dengan PRIMARY key %s belum ada jadi di SELECT\n", penyimpanan[3]);
                select_ternak();
            }
        }
        else {
            printf("[[ERROR]] table gada\n\n");
        }
    }
    else if ((yy == 3) && (zz == 4) || (yy == 4) && (zz == 3)){ // DELETE select dan select DELETE
        if (strcmp(penyimpanan[2], "Ttani") == 0){
            int x = 0;
            read_data2(&x, arrpertanian, "../FILE/pertanian.dat"); // memanggil prosedur untuk membaca file pertanian
            int p = ss_data(x, arrpertanian, penyimpanan[3]); // mengecek data kode apakah sudah ada
            if (p != -1){ // menegcek apakah perintah yang di berikan user kode nya sudah dipakai atau belum 
                delete_tani();
                printf("data dengan PRIMARY key %s sudah ada jadi di DELETE\n\n", penyimpanan[3]);
            }
            else {
                printf("data dengan PRIMARY key %s belum ada jadi di SELECT tablenya\n", penyimpanan[3]);
                select_tani();
            }   
        }
        else if (strcmp(penyimpanan[2], "Tternak") == 0){
            int x = 0;
            read_data(&x, arrpeternakan, "../FILE/peternakan.dat"); // memanggil prosedur untuk membaca file peternakan
            int p = ss_data(x, arrpeternakan, penyimpanan[3]); // mengecek data kode apakah sudah ada

            if (p != -1){ // menegcek apakah perintah yang di berikan user kode nya sudah dipakai atau belum 
                delete_ternak();
                printf("data dengan PRIMARY key %s sudah ada jadi di DELETE\n\n", penyimpanan[3]);
            }
            else {
                printf("data dengan PRIMARY key %s belum ada jadi di SELECT tablenya\n", penyimpanan[3]);
                select_ternak();
            }
        }
        else {
            printf("[[ERROR]] table gada\n\n");
        }
    }
    else {
        if ((yy == 1) && (zz == -1) || (yy == 2) && (zz == -1) || (yy == 3) && (zz == -1) || (yy == 4) && (zz == -1)){ // error handling untuk double query
            if ((strcmp(penyimpanan[2], "Ttani") == 0) && (yy == -1) || (yy == -1) && (strcmp(penyimpanan[2], "Tternak") == 0)){
                printf("[[ERROR]] perintah %s tidak ada\n\n", penyimpanan[0]);
            }
            else {
                printf("[[ERROR]] perintah %s tidak ada\n\n", penyimpanan[1]);
            }
        }// eror handling khusus untuk perintah double query update delete karana tidak ada
        else if ((yy == 2) && (zz == 3) || (yy == 3) && (zz == 2)){
            printf("[[ERROR]] perintah %s %s tidak ada\n\n",penyimpanan[0], penyimpanan[1]);
        }
        else if (yy == 5){ // eror handling untuk join
            printf("[[ERROR]] perintah %s tidak ada tablenya\n\n",penyimpanan[0]);
        }
        // eror handling untuk single query
        if ((yy == -1) && (strcmp(penyimpanan[1], "Ttani") == 0)){
            printf("[[ERROR]] perintah %s tidak ada\n\n",penyimpanan[0]);
        }
        // jika keluar mengeluarkan pesan dibawah
        if ((strcmp(tape, "keluar;") == 0) || (strcmp(tape, "keluar") == 0)){
            printf("TERIMA KASIH UNTUK TETAP HIDUP...\n");
        }
    }
}
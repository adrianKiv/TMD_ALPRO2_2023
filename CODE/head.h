/*
Saya Adrian Mulianto mengerjakan TMD dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. 
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// struct penampung data
typedef struct{
    char kode[30];
    char nama[45];
    char jumlah[20];
    char asal[25];
    char kode2[30];
}agribisnis;

extern agribisnis arrpertanian[245];       // variable penampung data pertanian
extern agribisnis arrpeternakan[245];      // variabel penampung data peternakan
extern char penyimpanan[50][80];           // variabel penampung sementara dari mesin kata

// Deklarasi variabel global
int maxcode1, maxnama1, maxberat1, maxasal1, tmaxcode1;    // variabel tampung nilai panjang dari string
int maxcode2, maxnama2, maxberat2, maxasal2;               // variabel tampung nilai panjang dari string
int bqr;

extern int idx;        // index dari karakter terakhir pada kata
extern int Pkata;      // panjang kata (word length)
extern char kataS[71]; // kata saat ini (current word)

// bagian untuk mengecek perintah (INSERT, UPDATE, DELETE, SELECT)
// dan juga perintah duoble query (INSERT UPDATE, INSERT DELETE, INSERT SELECT, UPDATE SELECT, DELETE SELECT)
int perintah1();
int perintah2();

// Bagian untuk memulai, mengecek EOP, dan memajukan kata
void mulai(char string[]);
int eop(char string[]);
void inc(char string[]);

// Bagian mendapatkan variabel global/atribut mesin kata
int getlen();
char *getkata_sekarang();

// bagian proses perintah mesin kata
void proses(char tape[]);

// prosedur mengabungkan table (JOIN)
void join();

// bagian mempercantik output
void garis1();
void garis2();
void garis3();

// bagian insert data ke file
void insert_tani();
void insert_ternak();

// bagian update data ke file
void update_tani();
void update_ternak();

// bagian delete data ke file
void delete_tani();
void delete_ternak();

// bagian select data ke file
void select_tani();
void select_ternak();

// bagian membaca data dari file
void read_data(int *n, agribisnis data[], char file[]);
void read_data2(int *n, agribisnis data[], char file[]);

// bagian memasukan data ke file
void write_data(int n, agribisnis data[], char file[]);
void write_data2(int n, agribisnis data[], char file[]);

// bagian untuk mencari data
int ss_data(int n, agribisnis source[], char keyword[100]);
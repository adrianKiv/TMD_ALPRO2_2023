#include "head.h"

int main(){
    // deklarasi variabel pita
    system("cls");
    printf("++~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~++\n");
    printf("|| welcome di DBMS UMKM AGRIBISNIS iyan :) ||\n");
    printf("++~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~++\n");
    printf("Versi 1.99\n\n");
    char tape[151];
    // memulai mesin kata dan membaca pita
    int cek = 0;
    while (cek == 0){ // jika belum sampai
        bqr = 0;
        printf("DBMS YANNN > ");
        scanf(" %150[^\n]s", &tape);
        mulai(tape);
        strcpy(penyimpanan[bqr], getkata_sekarang());
        bqr++;
        while (eop(tape) == 0){
            inc(tape); // majukan kata
            strcpy(penyimpanan[bqr], getkata_sekarang()); // menyalin kata       
            bqr++; // iterasi maju
        }
        // menegcek apakah query masukan user adalah keluar
        if ((strcmp(tape, "keluar;") == 0) || (strcmp(tape, "keluar") == 0)){
            cek = 1;
        }

        proses(tape); // memanggil prosedur proses
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct barang
{
    char kode[7];
    char nama[10001];
    int harga;
    int jumlah;
    int hargabeli;
    int modal;
    int bersih;
    int untung;
};
struct order
{
    char kode[7];
    char nama[10001];
    int jumlah;
    int harga;
    int order_id;
    char kasir[10001];
    int y;
    int m;
    int d;
};
struct struk
{
    char kasir[10001];
    char kode[7];
    char nama[10001];
    int jumlah;
    int harga;
    int order_id;
    int y;
    int m;
    int d;
};
struct pembayaran
{
    int order_id;
    int total;
    int bayar;
    int kembali;
};


int total;
int bayar;
int kembali;
struct user
{
    char username[10001];
    char password[10001];
    char nama[10001];
};

char kasirsekarang[10001];

void tambahbarang();
void tambahstok();
void ubahharga();
void lihatbarang();
void editbarang();
void deletebarang();
void ubahnama();
void order();
void login();
void listbarang();
void riwayatorder();
void cetakstruk(int order_id, int total, int bayar, int kembali);
void keuangan();
void laphari();
void lapbulan();
void laptahun();


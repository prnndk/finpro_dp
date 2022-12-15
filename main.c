#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "custom.h"
int main()
{
    login();
    while (1)
    {
        int input;
        system("cls");
        printf("Selamat datang %s di Menu Kasir Sederhana\n",kasirsekarang);
        printf("Silahkan pilih menu yang tersedia dibawah\n");
        printf("1. Transaksi\n");
        printf("2. Stok\n");
        printf("3. Keuangan\n");
        printf("0. Keluar\n");
        scanf("%d", &input);
        if (input==1)
        {
            while (1)
            {
            int in;
            printf("Menu Transaksi\n");
            printf("1. Buat Transaksi Baru\n");
            printf("2. Tampilkan Riwayat Transaksi\n");
            printf("0. Kembali\n");
            scanf("%d", &in);
            if (in==1)
            {
                order();
            }
            else if(in==2)
            {
                riwayatorder();
            }
            else if(in==0)
            {
                break;
            }
            else{
                printf("Angka yang dimasukkan salah\n");
            }
            
            }
        }
        else if (input==2)
        {
        system("cls");
        while (1)
        {
            int in;
            printf("Menu Barang\n");
            printf("1. Tambah Barang\n");
            printf("2. Tambah Stok\n");
            printf("3. Lihat Barang\n");
            printf("4. Ubah Harga Jual\n");
            printf("5. Ubah Nama Barang\n");
            printf("6. Hapus Barang\n");
            printf("0. Kembali\n");
            scanf("%d", &in);
            if (in==1)
            {
                tambahbarang();
            }
            else if(in==2)
            {
                tambahstok();
            }
            else if(in==3)
            {
                lihatbarang();
            }
            else if(in==4)
            {
                ubahharga();
            }
            else if(in==5)
            {
                ubahnama();
            }
            else if(in==6)
            {
                deletebarang();
            }
            else if(in==0)
            {
                break;
            }
            else{
                printf("Angka yang dimasukkan salah\n");
            }
        }
        }
        else if (input==3)
        {
            system("cls");
            while (1)
            {
                int in;
                printf("Menu Keuangan\n");
                printf("1. Lihat Keuangan\n");
                printf("2. Laporan Transaksi Harian\n");
                printf("3. Laporan Transaksi Bulanan\n");
                printf("4. Laporan Transaksi Tahunan\n");
                printf("0. Kembali\n");
                scanf("%d", &in);
                if (in==1)
                {
                    keuangan();
                }
                else if(in==2)
                {
                    laphari();
                }
                else if(in==3)
                {
                    lapbulan();
                }
                else if(in==4)
                {
                    laptahun();
                }
                else if(in==0)
                {
                    break;
                }
                else{
                    printf("Angka yang dimasukkan salah\n");
                }
            }
        }
        else if (input==0)
        {
            break;
        }
        else{
            printf("Angka yang dimasukkan salah\n");
        }
    }
    
}
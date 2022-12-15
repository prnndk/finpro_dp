#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "custom.h"

void lihatbarang(){
    FILE *f;
    struct barang barang;
    system("cls");
    if ((f=fopen("barang.dat", "rb"))==NULL)
    {
        printf("File tidak dapat dibuka\n");
        fclose(f);
    }
    else{
        int found = 0;
    while (!feof(f))
    {
        if (fread(&barang, sizeof(struct barang), 1, f))
        {
            if(found==0){
                printf("%-5s %-25s %-7s %-3s %-7s\n", "Kode", "Nama", "Harga", "Jml", "HargaBeli");
            }
            if (strcmp(barang.kode, " ")&&strcmp(barang.nama, ""))
            {
                found = 1;
                printf("%-5s %-25s %-7d %-3d %-7d\n", barang.kode, barang.nama, barang.harga, barang.jumlah, barang.hargabeli);
            }
        }
    }
    if (found==0)
    {
        printf("Tidak ada barang yang tersedia.\n");
    }
    fclose(f);
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "custom.h"

void tambahbarang(){
    FILE *f;
    struct barang barang;
    system("cls");
    if ((f=fopen("barang.dat", "rb+"))!=NULL){
    printf("Silahkan masukkan data barang\n");
    while (1)
    {
        printf("Akhiri Input dengan masukkan kode 0000\n");
        printf("Masukkan kode barang:\n");
        scanf("%s", barang.kode);
        if (!strcmp(barang.kode, "0000"))
        {
            break;
        }
        printf("Masukkan nama barang:\n");
        scanf(" %[^\n]s", barang.nama);
        printf("Masukkan harga jual barang:\n");
        scanf("%d", &barang.harga);
        printf("Masukkan jumlah barang:\n");
        scanf("%d", &barang.jumlah);
        printf("Masukkan harga beli barang:\n");
        scanf("%d", &barang.hargabeli);
        barang.modal = barang.hargabeli * barang.jumlah;
        barang.bersih = 0;
        barang.untung = 0-(barang.modal);
        int kode=atoi(barang.kode);
        fseek(f, (kode - 1) * sizeof(struct barang), SEEK_SET);
        fwrite(&barang, sizeof(struct barang), 1, f);
    }
    fclose(f);
    }
    else{
        printf("File tidak dapat dibuka\n");
        fclose(f);
    } 
}
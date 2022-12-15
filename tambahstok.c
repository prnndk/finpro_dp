#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "custom.h"

void tambahstok(){
    FILE *f;
    if ((f = fopen("barang.dat", "rb+")) == NULL)
    {
        printf("File tidak ditemukan\n");
        fclose(f);
    }
    else
    {
        while (1)
        {
        f=fopen("barang.dat", "rb+");
        struct barang barang;
        char kode[5];
        int jumlah;
        int found = 0;
        lihatbarang();
        printf("Akhiri dengan kode 0000\n");
        printf("Masukkan kode barang: ");
        scanf("%s", kode);
        if (!strcmp(kode, "0000"))
        {
            break;
            system("cls");
        }
        
        while (!feof(f))
        {
            if (fread(&barang, sizeof(struct barang), 1, f))
            {
                if (strcmp(barang.kode, kode) == 0)
                {
                    found = 1;
                    printf("Masukkan jumlah barang yang ingin ditambahkan: ");
                    scanf("%d", &jumlah);
                    barang.jumlah += jumlah;
                    barang.modal+=barang.hargabeli*jumlah;
                    barang.untung-=barang.hargabeli*jumlah;
                    int posisi=atoi(barang.kode);
                    fseek(f, (posisi-1)*sizeof(struct barang), SEEK_SET);
                    fwrite(&barang, sizeof(struct barang), 1, f);
                    break;
                }
            }
        }
        if (found == 0)
        {
            printf("Kode barang tidak ditemukan\n");
        }
        fclose(f);
        }
    }
    
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "custom.h"

void ubahnama(){
    FILE *f;
    struct barang barang;
    if ((f=fopen("barang.dat","rb+"))==NULL)
    {
        printf("Tidak dapat membuka file.\n");
        fclose(f);
    }
    else{
        while (1)
        {
        printf("Ubah Nama Barang\n");
        listbarang();
          printf("Masukkan kode barang: ");
          char kode[7];
            int found = 0;
          scanf("%s", kode);
            if (strcmp(kode, "0000")==0)
            {
                break;
            }
            f=fopen("barang.dat","rb+");
            while (!feof(f))
            {
                if (fread(&barang, sizeof(struct barang), 1, f))
                {
                    if (!strcmp(barang.kode, kode))
                    {
                        found = 1;
                        printf("Masukkan nama baru: ");
                        scanf(" %[^\n]s", barang.nama);
                        int p=atoi(barang.kode);
                        fseek(f, (p-1)*sizeof(struct barang), SEEK_SET);
                        fwrite(&barang, sizeof(struct barang), 1, f);
                        break;
                    }
                }
            }
            if (found==0)
            {
                printf("Kode barang tidak ditemukan.\n");
            }
        fclose(f);
        }
    }
    fclose(f);
}
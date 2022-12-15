#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "custom.h"

void ubahharga(){
    FILE *f;
    f=fopen("barang.dat","rb+");
    struct barang barang;
    if (f==NULL)
    {
        printf("Tidak dapat membuka file.\n");
        system("cls");
        fclose(f);
    }
    else{
        while (1)
        {
            system("cls");
            printf("Pilih Jenis Harga yang ingin diubah:\n");
            printf("1. Harga Jual\n");
            printf("2. Harga Modal\n");
            printf("0. Kembali\n");
            int pilih;
            scanf("%d", &pilih);
            if (pilih==1)
            {
               while (1)
               {
                   lihatbarang();
                   printf("Masukkan Kode Barang yang ingin diubah harga jualnya: ");
                   char kode[7];
                   int found=0;
                   scanf("%s", kode);
                   f=fopen("barang.dat","rb+");
                   if (!strcmp(kode,"0000"))
                   {
                    break;
                   }
                   while (!feof(f))
                   {
                       if (fread(&barang, sizeof(struct barang), 1, f))
                       {
                           if (strcmp(barang.kode, kode) == 0)
                           {
                            found=1;
                            printf("Masukkan harga jual baru: ");
                            scanf("%d", &barang.harga);
                            int posisi=atoi(barang.kode);
                            fseek(f, (posisi-1)*sizeof(struct barang), SEEK_SET);
                            fwrite(&barang, sizeof(struct barang), 1, f);
                            break;
                           }
                       }
                   }
                   if (found==0)
                   {
                    printf("Kode barang tidak ditemukan\n");
                   }
                   fclose(f);
                }
            }
            else if(pilih==2)
            {
                while (1)
                {
                lihatbarang();
                   printf("Masukkan Kode Barang yang ingin diubah harga modalnya: ");
                   char kode[7];
                   int found=0;
                   scanf("%s", kode);
                   f=fopen("barang.dat","rb+");
                   if (!strcmp(kode,"0000"))
                   {
                    break;
                   }
                   while (!feof(f))
                   {
                       if (fread(&barang, sizeof(struct barang), 1, f))
                       {
                           if (strcmp(barang.kode, kode) == 0)
                           {
                            found=1;
                            printf("Masukkan harga modal baru: ");
                            scanf("%d", &barang.hargabeli);
                            int posisi=atoi(barang.kode);
                            fseek(f, (posisi-1)*sizeof(struct barang), SEEK_SET);
                            fwrite(&barang, sizeof(struct barang), 1, f);
                            break;
                           }
                       }
                   }
                   if (found==0)
                   {
                    printf("Kode barang tidak ditemukan\n");
                   }
                   fclose(f);
                }
            }
            else if(pilih==0)
            {
                break;
            }
            else{
                printf("Angka yang dimasukkan salah\n");
            }
        } 
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "custom.h"

void deletebarang(){
    FILE *f;
    f=fopen("barang.dat","rb+");
    if (f==NULL)
    {
        printf("Tidak dapat membuka file.\n");
        fclose(f);
        system("cls");
    }else{
        while (1)
        {
            lihatbarang();
            printf("Masukkan kode barang yang ingin dihapus: ");
            char kode[7];
            int found=0;
            scanf("%s", kode);
            if (!strcmp(kode,"0000"))
            {
                system("cls");
                break;
            }
            struct barang barang;
            f=fopen("barang.dat","rb+");
            while (!feof(f))
            {
                if (fread(&barang, sizeof(struct barang), 1, f))
                {
                    if (strcmp(barang.kode, kode) == 0)
                    {
                        found=1;
                        printf("Anda Yakin Ingin Menghapus barang %s? (Y/N): ", barang.nama);
                        char pilih[1];
                        scanf("%s", pilih);
                        int posisi=atoi(barang.kode);
                        if (strcmp(pilih,"N") == 0)
                        {
                            printf("Batal Menghapus Barang\n");
                            break;
                        }
                        else if(strcmp(pilih,"Y")==0){
                        strcpy(barang.kode, " ");
                        strcpy(barang.nama, " ");
                        barang.harga=0;
                        barang.hargabeli=0;
                        barang.jumlah=0;
                        fseek(f, (posisi-1)*sizeof(struct barang), SEEK_SET);
                        fwrite(&barang, sizeof(struct barang), 1, f);
                        break;
                        }
                        else{
                            printf("Masukkan Input Yang Benar!\n");
                        }
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
fclose(f);
    
    
}
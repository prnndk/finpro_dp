#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "custom.h"

void listbarang(){
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
                
                
                if (strcmp(barang.kode, " ") && strcmp(barang.nama, ""))
                {
                if (found==0)
                {
                    printf("%-5s %-30s %-6s %-6s\n", "Kode", "Nama Barang", "Harga", "Jumlah");
                }
                    found = 1;
                    printf("%-5s %-30s %-6d %-6d\n", barang.kode, barang.nama, barang.harga, barang.jumlah);
                }
            }
    }
    fclose(f);
    }
}
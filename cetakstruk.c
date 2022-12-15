#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "custom.h"

void cetakstruk(int order_id){
    FILE *f;
    struct struk struk;
    int found = 0;
    f=fopen("struk.dat","rb");
    if (f==NULL)
    {
        printf("Tidak dapat membuka file.\n");
        system("cls");
        fclose(f);
    }
    else{
        printf("STRUK BELANJA\n");
        while (!feof(f))
        {
        if(fread(&struk, sizeof(struct struk), 1, f)){
        if (struk.order_id==order_id)
        {
        if (found==0)
        {
        printf("------------------------------------------------------------\n");
        printf("Tanggal : %d - %d - %d \t Kasir: %s\n",struk.d,struk.m,struk.y,struk.kasir);
        printf("------------------------------------------------------------\n");
        printf("%-7s %-40s %-7s %-7s\n","Kode","Nama","Jumlah","Harga");
        }
        }
        found = 1;
        printf("%-7s %-40s %-7d %-7d\n",struk.kode,struk.nama,struk.jumlah,struk.harga);
        }
        }
            printf("------------------------------------------------------------\n");
            printf("%-10s: %-7d\n","Total",total);
            printf("%-10s: %-7d\n","Bayar",bayar);
            if (total==bayar)
            {
               printf("%-10s: 0000\n","Kembali");
            }else{
            printf("%-10s: %-7d\n","Kembali",kembali);
            }
            printf("------------------------------------------------------------\n");
            printf("Terima kasih telah berbelanja di toko kami.\n");
        }
        if (found==0)
        {
            printf("Order ID tidak ditemukan.\n");
        }
        fclose(f);
}
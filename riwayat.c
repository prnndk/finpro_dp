#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "custom.h"

void riwayatorder(){
    FILE *f;
    struct order order;
    f=fopen("order.dat","rb");
    system("cls");
    if (f==NULL)
    {
        printf("Tidak dapat membuka file.\n");
        system("cls");
        fclose(f);
    }
    else{
        printf("Riwayat Transaksi Kasir\n");
        printf("%-7s %-40s %-7s %-7s %-9s %-7s %-12s\n","Kode","Nama","Jumlah","Harga","Order_Id","Kasir","Tanggal");
        while (!feof(f)){
            if(fread(&order, sizeof(struct order), 1, f)){
            if (!strcmp(order.kasir,kasirsekarang))
            {
                printf("%-7s %-40s %-7d %-7d %-9d %-7s %-2d-%-2d-%-4d\n",order.kode,order.nama,order.jumlah,order.harga,order.order_id,order.kasir,order.d,order.m,order.y);
            }
            }
        }
        fclose(f);
    }
}
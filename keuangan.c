#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "custom.h"

void keuangan(){
    FILE *f,*o;
    struct barang barang;
    struct order order;
    if ((f=fopen("barang.dat","rb"))==NULL)
    {
        printf("Tidak dapat membuka file.\n");
        fclose(f);
    }else if ((o=fopen("order.dat","rb"))==NULL)
    {
        printf("Tidak dapat membuka file.\n");
        fclose(o);
    }else{
        int found = 0,jumlah=0,modal=0,terjual=0,pendapatan=0,pbersih=0;
        while(!feof(f)){
            if(fread(&barang,sizeof(struct barang),1,f)){
                if (found == 0)
                {
                    printf("%-5s %-25s %-7s %-3s %-7s %-7s %-7s %-10s\n", "Kode", "Nama", "Harga", "Jml", "HrgBeli", "Modal", "P.Bersih","Pendapatan");
                }
                if(strcmp(barang.kode," ") && strcmp(barang.nama," ")){
                    found = 1;
                    jumlah+=barang.jumlah;
                    modal+=barang.modal;
                    pbersih+=barang.bersih;
                    printf("%-5s %-25s %-7d %-3d %-7d %-7d %-7d %-10d\n", barang.kode, barang.nama, barang.harga, barang.jumlah, barang.hargabeli, barang.modal, barang.bersih,barang.untung);
                }
            }
        }
        while (!feof(o))
        {
            fread(&order,sizeof(struct order),1,o);
            terjual+=order.jumlah;
            pendapatan+=order.harga*order.jumlah;
        }
        printf("\n");
        printf("----------------------------------------\n");
        printf("Total barang: %d\n",jumlah);
        printf("Modal Belanja: %d\n",modal);
        printf("Total barang terjual: %d\n",terjual);
        printf("Total penjualan adalah: %d\n",pendapatan);
        printf("Total pendapatan bersih adalah: %d\n",pbersih);
        if (pbersih-modal>0)
        {
            printf("Status keuangan adalah UNTUNG sebesar %d\n",pbersih-modal);
        }else if (pbersih-modal<0){
            printf("Status keuangan adalah RUGI sebesar %d\n",pbersih-modal);
        }    
        printf("----------------------------------------\n");
        fclose(f);
        fclose(o);
    }
    
}
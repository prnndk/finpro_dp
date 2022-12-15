#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "custom.h"

void laphari(){
    FILE *f,*b;
    struct order order;
    struct barang barang;
    if ((f=fopen("order.dat","rb"))==NULL)
    {
        printf("Tidak dapat membuka file.\n");
        fclose(f);
    }else if ((b=fopen("barang.dat","rb"))==NULL)
    {
       printf("Tidak dapat membuka file.\n");
        fclose(b);
    }else{
        int hari,bulan,tahun,pendapatan=0,pbersih=0,sumorder=0,found;
        while(1){
        found = 0;
        printf("Masukkan tanggal transaksi yang diinginkan: \n");
        scanf("%d",&hari);
        printf("Masukkan bulan transaksi yang diinginkan: \n");
        scanf("%d",&bulan);
        printf("Masukkan tahun transaksi yang diinginkan: \n");
        scanf("%d",&tahun);
        while(!feof(f)){
            if(fread(&order,sizeof(struct order),1,f)){
                int hargamodal=0;

                if (order.d == hari && order.m == bulan && order.y == tahun)
                {
                    if (found == 0)
                    {
                        printf("%-7s %-20s %-7s %-3s\n", "Kode", "Nama", "Harga", "Jml");
                    }
                    printf("%-7s %-20s %-7d %-3d\n", order.kode, order.nama, order.harga, order.jumlah);
                    while (!feof(b))
                    {
                        if (fread(&barang, sizeof(struct barang), 1, b))
                        {
                            if (!strcmp(barang.kode, order.kode))
                            {
                                hargamodal += (barang.hargabeli) * order.jumlah;
                                break;
                            }
                        }
                    }
                    found = 1;
                    pendapatan += order.harga * order.jumlah;
                    pbersih+=pendapatan-hargamodal;
                    sumorder += order.jumlah;
            }
            }
        }
        if (found==0)
        {
            printf("Tidak ada transaksi pada tanggal tersebut.\n");
        }else if (found==1)
        {
        printf("\n");
        printf("------------------------------------------------------------------------------\n");
        printf("Penjualan total tanggal %d/%d/%d ini sebesar: %-7d\n",order.d,order.m,order.y,pendapatan);
        printf("Pendapatan bersih tanggal %d/%d/%d ini sebesar: %-7d\n",order.d,order.m,order.y,pbersih);
        printf("Total barang terjual adalah: %-4d\n",sumorder);
        printf("------------------------------------------------------------------------------\n");
        }
        break;
        }
    
    }
    fclose(f);
    fclose(b);
    
}
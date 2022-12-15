#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "custom.h"
#include <time.h>

void order(){
    FILE *f,*o,*s;
    struct barang barang;
    struct order order;
    struct struk struk;
    int order_id;
    
    if ((f=fopen("barang.dat","rb+"))==NULL)
    {
        printf("File tidak dapat dibuka\n");
        fclose(f);
    }else if((o=fopen("order.dat","ab"))==NULL){
        printf("File tidak dapat dibuka\n");
        fclose(o);
    }else if((s=fopen("struk.dat","wb"))==NULL){
        printf("File tidak dapat dibuka\n");
        fclose(s);
    }else{
    int error = 0,i=1,d,m,y,minute,h,scnd;
    time_t currtime;
	time(&currtime);
	struct tm *local = localtime(&currtime);
    scnd=local->tm_sec;
    h=local->tm_hour;
    minute=local->tm_min;
	d = local->tm_mday;
	m = local->tm_mon + 1;
	y = local->tm_year + 1900;
    order_id = d+m+y+minute+h+scnd;
    while (1)
    {
        f=fopen("barang.dat","rb+");
        o=fopen("order.dat","ab+");
        s=fopen("struk.dat","ab+");
        listbarang();
        if (error == 1)
        {
            printf("Jumlah barang tidak cukup.\n");
        }else if (error==2)
        {
            printf("Jumlah barang tidak boleh 0.\n");
        }
        error = 0;
        printf("Order ID: %d",order_id);
        printf("Masukkan kode barang: ");
        char kode[5];
        scanf("%s",kode);
        if (!strcmp(kode,"0000"))
        {
            break;
        }else{

        while (!feof(f))
            {
            fread(&barang, sizeof(struct barang), 1, f);
            if (strcmp(barang.kode, kode) == 0){
                printf("Masukkan jumlah %s yang akan dibeli: ",barang.nama);
                int jumlah;
                scanf("%d", &jumlah);   
                if (jumlah>barang.jumlah){
                    error = 1;
                    break;
                }else if (jumlah==0){
                    error = 2;
                    break;
                }else{
                    barang.jumlah-=jumlah;
                    total+=barang.harga*jumlah;
                    barang.bersih+=barang.hargabeli*barang.jumlah;
                    barang.untung+=(barang.harga*barang.jumlah)-(barang.jumlah*barang.hargabeli);
                    int p=atoi(barang.kode);
                    fseek(f, (p - 1) * sizeof(struct barang), SEEK_SET);
                    fwrite(&barang,sizeof(struct barang),1,f);

                    strcpy(order.kode,barang.kode);
                    strcpy(order.nama,barang.nama);
                    strcpy(order.kasir,kasirsekarang);
                    order.harga=barang.harga;
                    order.jumlah=jumlah;
                    order.order_id=order_id;
                        
                    strcpy(struk.kode,barang.kode);
                    strcpy(struk.nama,barang.nama);
                    strcpy(struk.kasir,kasirsekarang);
                    struk.harga=barang.harga;
                    struk.jumlah=jumlah;
                    struk.order_id=order_id;

                    order.d = d;
                    order.m = m;
                    order.y = y;
			        struk.d = order.d;
			        struk.m = order.m;
			        struk.y = order.y;

			        fwrite(&struk, sizeof(struct struk), 1, s);
			            
			        fwrite(&order, sizeof(struct order), 1, o);
			                
			        i++;
					break;
                }
            }
        }
        fclose(f);
        fclose(o);
        fclose(s);
        }
    }
    
    

    if (total>0){
        printf("Total Belanja anda sebesar: %d\n",total);
        while (1){
            printf("Masukkan uang: ");
            scanf("%d",&bayar);
            if (bayar<total)
            {
                printf("Uang tidak cukup.\n");
            }
            else if(bayar>=total){
                if (bayar>total)
                {
                kembali=bayar-total;
                printf("Total Kembalian anda sebesar: %d\n",kembali);
                }else if (bayar==total){
                kembali=0;
                printf("Uang belanja pas!\n");
                }
                char cetak[2];
                printf("Cetak Struk? (y/n): ");
                scanf("%s",cetak);
                if (!strcmp(cetak,"y"))
                {
                cetakstruk(order_id);
                total = 0;
                break;
                }else if (!strcmp(cetak,"n")){
                    break;
                }else{
                    printf("Input tidak valid.\n");
                }
            }
        }
        kembali=0;
    }
    }
}
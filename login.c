#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "custom.h"

void login(){
    FILE *f;
    if ((f=fopen("user.dat","rb+"))==NULL)
    {
        printf("Tidak dapat membuka file.\n");
        system("cls");
        fclose(f);
    }else{
    struct user user;
    while (1)
    {
        printf("Selamat Datang Di Aplikasi Kasir, Pilih Menu dibawah untuk melanjutkan\n");
        printf("1. Login\n");
        printf("2. Register\n");
        printf("0. Kembali\n");
        int pilih,log=0;
        scanf("%d", &pilih);
        if (pilih==1)
        {
        f=fopen("user.dat","rb+");
        printf("Login Aplikasi Kasir\n");
        printf("Masukkan Username: ");
        char uname[1001],pass[1001];
        scanf("%s", uname);
        printf("Masukkan Password: ");
        scanf("%s", pass);
        while (!feof(f))
        {
            if (fread(&user, sizeof(struct user), 1, f))
            {
                if (strcmp(user.username, uname) == 0 && strcmp(user.password, pass) == 0)
                {
                    log = 1;
                    printf("Login Berhasil\n");
                    system("cls");
                    fclose(f);
                    strcpy(kasirsekarang,user.username);
                    break;
                }
                else{
                    printf("Login Gagal Cek Username dan Password\n");
                    fclose(f);
                    break;
                }
            }
        }
        if (log==1)
        {
            break;
        }
        }else if(pilih==2){
            f=fopen("user.dat","rb+");
            char uname[1001],pass[1001];
            printf("Register Aplikasi Kasir\n");
            printf("Masukkan Nama Anda: ");
            scanf("%s", user.nama);
            printf("Masukkan Username: ");
            scanf("%s", uname);
            printf("Masukkan Password: ");
            scanf("%s", pass);
            while (!feof(f))
            {
                if (fread(&user, sizeof(struct user), 1, f))
                {
                    if (strcmp(user.username, uname) == 0)
                    {
                        printf("Username sudah ada\n");
                        system("cls");
                        fclose(f);
                        break;
                    }
                }
            }
            strcpy(user.username,uname);
            strcpy(user.password,pass);
            fwrite(&user, sizeof(struct user), 1, f);
            printf("Register Berhasil\n");
            system("cls");
            fclose(f);
        }else if(pilih==0){
            break;
        }
        else{
            printf("Angka yang dimasukkan salah\n");
        }    
    }
    fclose(f);
    }
    
}
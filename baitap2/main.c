#include <stdio.h>

#define MAX_SIZE 4

int main() {
    int tuoi_benh_nhan[MAX_SIZE];
    int co_bao_hiem[MAX_SIZE];
    int phi_kham[MAX_SIZE];

    int tong_doanh_thu = 0;
    int so_ca_uu_tien = 0;
    int i;

    for (i = 0; i < MAX_SIZE; i++) {
        printf("\nNhap thong tin benh nhan %d\n", i + 1);

        printf("Nhap tuoi: ");
        scanf("%d", &tuoi_benh_nhan[i]);

        printf("Nhap BHYT (1: Co, 0: Khong): ");
        scanf("%d", &co_bao_hiem[i]);

        if (co_bao_hiem[i] != 0 && co_bao_hiem[i] != 1) {
            co_bao_hiem[i] = 0;
        }

        if (tuoi_benh_nhan[i] <= 0 || tuoi_benh_nhan[i] > 120) {
            phi_kham[i] = 0;
        } else {
            if (co_bao_hiem[i] == 1) {
                phi_kham[i] = 40000;
            } else {
                phi_kham[i] = 200000;
            }

            if (tuoi_benh_nhan[i] > 70) {
                so_ca_uu_tien++;
            }
        }

        tong_doanh_thu += phi_kham[i];
    }

    printf("\n========== BAO CAO KHAM BENH ==========\n");

    for (i = 0; i < MAX_SIZE; i++) {
        printf("\nBenh nhan %d (Index %d)\n", i + 1, i);
        printf("Tuoi: %d\n", tuoi_benh_nhan[i]);
        printf("BHYT: %d\n", co_bao_hiem[i]);
        printf("Phi kham: %d VND\n", phi_kham[i]);

        if (tuoi_benh_nhan[i] <= 0 || tuoi_benh_nhan[i] > 120) {
            printf("Luong kham: LOI DU LIEU\n");
        } else if (tuoi_benh_nhan[i] > 70) {
            printf("Luong kham: UU TIEN\n");
        } else {
            printf("Luong kham: THUONG\n");
        }
    }

    printf("\n========== TONG KET CA TRUC ==========\n");
    printf("Tong doanh thu: %d VND\n", tong_doanh_thu);
    printf("Tong so ca uu tien: %d\n", so_ca_uu_tien);

    return 0;
}

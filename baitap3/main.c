#include <stdio.h>

#define MAX 100

void hienThiBaoCao(int ma_so[], int tuoi[], int bao_hiem[], int n) {
    int i;
    int phi_kham;
    int tong_doanh_thu = 0;
    int so_ca_uu_tien = 0;

    printf("\n========== DANH SACH HANG CHO ==========\n");

    if (n == 0) {
        printf("Hang cho dang rong.\n");
    }

    for (i = 0; i < n; i++) {
        if (bao_hiem[i] == 1) {
            phi_kham = 30000;
        } else {
            phi_kham = 150000;
        }

        tong_doanh_thu += phi_kham;

        printf("\nBenh nhan %d (Index %d)\n", ma_so[i], i);
        printf("Tuoi: %d\n", tuoi[i]);
        printf("BHYT: %d\n", bao_hiem[i]);
        printf("Phi kham: %d VND\n", phi_kham);

        if (tuoi[i] >= 70) {
            printf("Phan loai: UU TIEN\n");
            so_ca_uu_tien++;
        } else {
            printf("Phan loai: THUONG\n");
        }
    }

    printf("\nTong so benh nhan: %d\n", n);
    printf("Tong doanh thu du kien: %d VND\n", tong_doanh_thu);
    printf("So ca uu tien: %d\n", so_ca_uu_tien);
}

int main() {
    int ma_so[MAX];
    int tuoi[MAX];
    int bao_hiem[MAX];

    int n;
    int i;
    int k;

    do {
        printf("Nhap so luong benh nhan (0-%d): ", MAX);
        scanf("%d", &n);

        if (n < 0 || n > MAX) {
            printf("So luong khong hop le. Vui long nhap lai.\n");
        }
    } while (n < 0 || n > MAX);

    for (i = 0; i < n; i++) {
        printf("\nNhap thong tin benh nhan thu %d\n", i + 1);

        printf("Nhap ma so thu tu: ");
        scanf("%d", &ma_so[i]);

        do {
            printf("Nhap tuoi (1-120): ");
            scanf("%d", &tuoi[i]);

            if (tuoi[i] < 1 || tuoi[i] > 120) {
                printf("Tuoi khong hop le. Vui long nhap lai.\n");
            }
        } while (tuoi[i] < 1 || tuoi[i] > 120);

        do {
            printf("Nhap BHYT (1: Co, 0: Khong): ");
            scanf("%d", &bao_hiem[i]);

            if (bao_hiem[i] != 0 && bao_hiem[i] != 1) {
                printf("BHYT khong hop le. Vui long nhap lai.\n");
            }
        } while (bao_hiem[i] != 0 && bao_hiem[i] != 1);
    }

    printf("\n========== BAO CAO BAN DAU ==========\n");
    hienThiBaoCao(ma_so, tuoi, bao_hiem, n);

    printf("\nNhap chi so K can huy: ");
    scanf("%d", &k);

    if (n == 0) {
        printf("Khong the huy vi hang cho dang rong.\n");
    } else if (k < 0 || k >= n) {
        printf("Vi tri huy khong hop le. Danh sach duoc giu nguyen.\n");
    } else {
        for (i = k; i < n - 1; i++) {
            ma_so[i] = ma_so[i + 1];
            tuoi[i] = tuoi[i + 1];
            bao_hiem[i] = bao_hiem[i + 1];
        }

        n--;

        printf("\nDa huy thanh cong benh nhan tai index %d.\n", k);
    }

    printf("\n========== BAO CAO SAU KHI HUY ==========\n");
    hienThiBaoCao(ma_so, tuoi, bao_hiem, n);

    return 0;
}

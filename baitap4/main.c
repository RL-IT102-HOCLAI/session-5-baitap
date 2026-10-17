#include <stdio.h>
#include <string.h>

#define MAX 100

int ma_so[MAX];
char ten[MAX][30];
int tuoi[MAX];
int uu_tien[MAX];
int mang_thai[MAX];
int bao_hiem[MAX];
int phi_kham[MAX];
char ten_bac_si[MAX][30];
char khung_gio[MAX][20];

int so_luong = 0;
int ma_tiep_theo = 1001;

int readInt(char message[]) {
    char buffer[100];
    int value;
    char extra;

    while (1) {
        printf("%s", message);

        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            continue;
        }

        if (sscanf(buffer, " %d %c", &value, &extra) == 1) {
            return value;
        }

        printf("Du lieu khong hop le. Vui long nhap so nguyen.\n");
    }
}

void readString(char message[], char result[], int size) {
    int i;
    int c;

    while (1) {
        printf("%s", message);

        if (fgets(result, size, stdin) == NULL) {
            continue;
        }

        for (i = 0; result[i] != '\0'; i++) {
            if (result[i] == '\n') {
                result[i] = '\0';
                break;
            }
        }

        if (i == (int)strlen(result) && i == size - 1) {
            while ((c = getchar()) != '\n' && c != EOF) {
            }
        }

        if (strlen(result) > 0) {
            return;
        }

        printf("Du lieu khong duoc de trong.\n");
    }
}

int tinhPhiKham(int bhyt) {
    if (bhyt == 1) {
        return 40000;
    }

    return 200000;
}

int tinhUuTien(int age, int pregnancy) {
    if (age > 70 || pregnancy == 1) {
        return 1;
    }

    return 0;
}

int demBenhNhanBacSi(char doctor[], char slot[]) {
    int i;
    int count = 0;

    for (i = 0; i < so_luong; i++) {
        if (strcmp(ten_bac_si[i], doctor) == 0 &&
            strcmp(khung_gio[i], slot) == 0) {
            count++;
        }
    }

    return count;
}

int timTheoMa(int code) {
    int i;

    for (i = 0; i < so_luong; i++) {
        if (ma_so[i] == code) {
            return i;
        }
    }

    return -1;
}

void inBenhNhan(int i) {
    printf("\nMa so thu tu: %d\n", ma_so[i]);
    printf("Ten benh nhan: %s\n", ten[i]);
    printf("Tuoi: %d\n", tuoi[i]);
    printf("Mang thai: %s\n", mang_thai[i] == 1 ? "Co" : "Khong");
    printf("Uu tien: %s\n", uu_tien[i] == 1 ? "Co" : "Khong");
    printf("BHYT: %s\n", bao_hiem[i] == 1 ? "Co" : "Khong");
    printf("Phi kham: %d VND\n", phi_kham[i]);
    printf("Bac si: %s\n", ten_bac_si[i]);
    printf("Khung gio: %s\n", khung_gio[i]);
}

void hienThiDanhSach() {
    int i;
    int tong_phi = 0;
    int tong_uu_tien = 0;

    if (so_luong == 0) {
        printf("\nDanh sach hang cho dang rong.\n");
        return;
    }

    printf("\n========== DANH SACH HANG CHO ==========\n");

    for (i = 0; i < so_luong; i++) {
        printf("\nVi tri hang cho: %d\n", i);
        inBenhNhan(i);

        tong_phi += phi_kham[i];

        if (uu_tien[i] == 1) {
            tong_uu_tien++;
        }
    }

    printf("\nTong so benh nhan: %d\n", so_luong);
    printf("Tong chi phi kham so bo: %d VND\n", tong_phi);
    printf("So benh nhan uu tien: %d\n", tong_uu_tien);
}

void dangKyBenhNhan() {
    int age;
    int pregnancy;
    int bhyt;
    int position;
    int i;
    int code;

    char patient_name[30];
    char doctor[30];
    char slot[20];

    if (so_luong >= MAX) {
        printf("Hang cho da day. Khong the tiep nhan them.\n");
        return;
    }

    readString("Nhap ten benh nhan: ", patient_name, sizeof(patient_name));

    do {
        age = readInt("Nhap tuoi (1-120): ");

        if (age < 1 || age > 120) {
            printf("Tuoi khong hop le.\n");
        }
    } while (age < 1 || age > 120);

    do {
        pregnancy = readInt("Mang thai? (1: Co, 0: Khong): ");

        if (pregnancy != 0 && pregnancy != 1) {
            printf("Chi nhap 0 hoac 1.\n");
        }
    } while (pregnancy != 0 && pregnancy != 1);

    do {
        bhyt = readInt("Co BHYT? (1: Co, 0: Khong): ");

        if (bhyt != 0 && bhyt != 1) {
            printf("Chi nhap 0 hoac 1.\n");
        }
    } while (bhyt != 0 && bhyt != 1);

    readString("Nhap ten bac si: ", doctor, sizeof(doctor));
    readString("Nhap khung gio (vi du 08:00): ", slot, sizeof(slot));

    if (demBenhNhanBacSi(doctor, slot) >= 5) {
        printf("Bac si da dat gioi han 5 benh nhan trong khung gio nay.\n");
        printf("Dang ky that bai.\n");
        return;
    }

    code = ma_tiep_theo;
    position = so_luong;

    if (tinhUuTien(age, pregnancy) == 1) {
        for (i = 0; i < so_luong; i++) {
            if (uu_tien[i] == 0) {
                position = i;
                break;
            }
        }
    }

    for (i = so_luong; i > position; i--) {
        ma_so[i] = ma_so[i - 1];
        strcpy(ten[i], ten[i - 1]);
        tuoi[i] = tuoi[i - 1];
        uu_tien[i] = uu_tien[i - 1];
        mang_thai[i] = mang_thai[i - 1];
        bao_hiem[i] = bao_hiem[i - 1];
        phi_kham[i] = phi_kham[i - 1];
        strcpy(ten_bac_si[i], ten_bac_si[i - 1]);
        strcpy(khung_gio[i], khung_gio[i - 1]);
    }

    ma_so[position] = code;
    strcpy(ten[position], patient_name);
    tuoi[position] = age;
    mang_thai[position] = pregnancy;
    uu_tien[position] = tinhUuTien(age, pregnancy);
    bao_hiem[position] = bhyt;
    phi_kham[position] = tinhPhiKham(bhyt);
    strcpy(ten_bac_si[position], doctor);
    strcpy(khung_gio[position], slot);

    so_luong++;
    ma_tiep_theo++;

    printf("\nDang ky thanh cong!\n");
    printf("Ma so thu tu: %d\n", code);
    printf("Vi tri trong hang cho: %d\n", position);
    printf("Phi kham so bo: %d VND\n", phi_kham[position]);
}

void capNhatBenhNhan() {
    int code;
    int position;
    int choice;
    int age;
    int bhyt;

    code = readInt("Nhap ma so thu tu can cap nhat: ");
    position = timTheoMa(code);

    if (position == -1) {
        printf("Khong tim thay benh nhan.\n");
        return;
    }

    printf("\nThong tin hien tai:");
    inBenhNhan(position);

    printf("\n1. Sua ten\n");
    printf("2. Sua tuoi\n");
    printf("3. Sua BHYT\n");
    printf("0. Quay lai\n");

    choice = readInt("Chon thong tin can sua: ");

    switch (choice) {
        case 1:
            readString("Nhap ten moi: ", ten[position], sizeof(ten[position]));
            break;

        case 2:
            do {
                age = readInt("Nhap tuoi moi (1-120): ");

                if (age < 1 || age > 120) {
                    printf("Tuoi khong hop le.\n");
                }
            } while (age < 1 || age > 120);

            tuoi[position] = age;
            uu_tien[position] = tinhUuTien(
                tuoi[position], mang_thai[position]
            );
            break;

        case 3:
            do {
                bhyt = readInt("Nhap BHYT moi (1: Co, 0: Khong): ");

                if (bhyt != 0 && bhyt != 1) {
                    printf("Chi nhap 0 hoac 1.\n");
                }
            } while (bhyt != 0 && bhyt != 1);

            bao_hiem[position] = bhyt;
            phi_kham[position] = tinhPhiKham(bhyt);
            break;

        case 0:
            return;

        default:
            printf("Lua chon khong hop le.\n");
            return;
    }

    printf("Cap nhat thanh cong.\n");
    inBenhNhan(position);
}

void huyBenhNhan() {
    int code;
    int position;
    int i;

    code = readInt("Nhap ma so thu tu can huy: ");
    position = timTheoMa(code);

    if (position == -1) {
        printf("Khong tim thay benh nhan.\n");
        return;
    }

    for (i = position; i < so_luong - 1; i++) {
        ma_so[i] = ma_so[i + 1];
        strcpy(ten[i], ten[i + 1]);
        tuoi[i] = tuoi[i + 1];
        uu_tien[i] = uu_tien[i + 1];
        mang_thai[i] = mang_thai[i + 1];
        bao_hiem[i] = bao_hiem[i + 1];
        phi_kham[i] = phi_kham[i + 1];
        strcpy(ten_bac_si[i], ten_bac_si[i + 1]);
        strcpy(khung_gio[i], khung_gio[i + 1]);
    }

    so_luong--;

    printf("Da huy benh nhan co ma so %d.\n", code);
    printf("Hang cho da duoc cap nhat.\n");
}

void timKiemBenhNhan() {
    int choice;
    int code;
    int position;
    int i;
    int found = 0;

    printf("\n1. Tim theo ma so thu tu\n");
    printf("2. Tim theo ten\n");

    choice = readInt("Chon cach tim kiem: ");

    if (choice == 1) {
        code = readInt("Nhap ma so thu tu: ");
        position = timTheoMa(code);

        if (position == -1) {
            printf("Khong tim thay benh nhan.\n");
        } else {
            inBenhNhan(position);
        }
    } else if (choice == 2) {
        char patient_name[30];

        readString("Nhap ten can tim: ", patient_name, sizeof(patient_name));

        for (i = 0; i < so_luong; i++) {
            if (strcmp(ten[i], patient_name) == 0) {
                inBenhNhan(i);
                found = 1;
            }
        }

        if (found == 0) {
            printf("Khong tim thay benh nhan.\n");
        }
    } else {
        printf("Lua chon khong hop le.\n");
    }
}

int main() {
    int choice;

    do {
        printf("\n========== MEDCARE CLINIC ==========\n");
        printf("1. Tiep nhan benh nhan moi\n");
        printf("2. Hien thi danh sach hang cho\n");
        printf("3. Cap nhat thong tin dang ky\n");
        printf("4. Huy so thu tu\n");
        printf("5. Tim kiem benh nhan\n");
        printf("0. Thoat chuong trinh\n");

        choice = readInt("Nhap lua chon: ");

        switch (choice) {
            case 1:
                dangKyBenhNhan();
                break;

            case 2:
                hienThiDanhSach();
                break;

            case 3:
                capNhatBenhNhan();
                break;

            case 4:
                huyBenhNhan();
                break;

            case 5:
                timKiemBenhNhan();
                break;

            case 0:
                printf("Da thoat chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop le.\n");
        }
    } while (choice != 0);

    return 0;
}

#include <stdio.h>
#include <stdbool.h>
#include <string.h>


typedef struct {
    char maSinhVien[15];
    char tenSinhVien[30];
    char SDTSinhVien[15];
} SinhVien;

char tenFile[] = "danhSachSinhVien.txt";

void nhapDanhSachSachSinhVien(SinhVien danhSachSinhVien[], int biendem);

void xuatDanhSachSachSinhVien(SinhVien danhSachSinhVien[], int biendem);

void luuDanhSachSinhVienRaFile(SinhVien danhSachSinhVien[], int a);

void docDanhSachSinhVienTuFile();

void tambiet();

int main() {
    int bienDem = 0;
    SinhVien danhSachSinhVien[10];
    int chon;

    do {
        printf("||--| MENU |----------------------------------------||\n");
        printf("|| chon 1 de them moi sinh vien                     ||\n");
        printf("|| chon 2 de hien thi danh sinh vien                ||\n");
        printf("|| chon 3 de luu danh sach sinh vien ra file        ||\n");
        printf("|| chon 4 de doc danh sach sinh vien tu file        ||\n");
        printf("|| chon 5 de thoat chuong trinh                     ||\n");
        printf("||-----------------------------------------| END |--||\n");
        printf("lua chon cua ban la gi :\n");

        scanf("%d", &chon);

        switch (chon) {
            case 1: {
                if (bienDem == 10) {
                    printf("\n\n\nDANH SACH SINH VIEN DA DAY KHONG THE NAP THEM  !!!\n\n\n");
                    break;
                }
                nhapDanhSachSachSinhVien(danhSachSinhVien, bienDem);
                bienDem++;
                luuDanhSachSinhVienRaFile(danhSachSinhVien,bienDem);
                break;
            }
            case 2: {
                xuatDanhSachSachSinhVien(danhSachSinhVien, bienDem);
            }
                break;
            case 3: {
                luuDanhSachSinhVienRaFile(danhSachSinhVien, bienDem);
            }
                break;
            case 4: {
                docDanhSachSinhVienTuFile();
            }
                break;
            case 5: {
                tambiet();
            }
                break;
            default: {
            }
                printf("\n!!! SAI CHUC NANG VUI LONG CHON LAI.\n\n");
                break;
        }
    } while (chon != 5);
}


void nhapDanhSachSachSinhVien(SinhVien danhSachSinhVien[], int biendem) {
    for (int i = biendem; i <= biendem; i++) {
        printf("moi ban nhap vao ma sinh vien\n");
        getchar();
        scanf("%[^\n]s", danhSachSinhVien[i].maSinhVien);
        printf("moi ban nhap vao ten sinh vien\n");
        getchar();
        scanf("%[^\n]s", danhSachSinhVien[i].tenSinhVien);
        strupr(danhSachSinhVien[i].tenSinhVien);
        printf("moi ban nhap vao SDT sinh vien\n");
        scanf("%s", danhSachSinhVien[i].SDTSinhVien);
    }
}


void xuatDanhSachSachSinhVien(SinhVien danhSachSinhVien[], int biendem) {
    printf("||***-danh sach sinh vien-*******************************************************************||\n");
    printf("%-5s%15s%10s %-5s%18s%10s %-5s%15s%10s\n", "||", "ma sinh vien", "||", "", "ten sinh vien", "", "||",
           "SDT sinh vien", "||");
    printf("||-------------------------------------------------------------------------------------------||\n");
    for (int i = 0; i <= biendem - 1; i++) {
        printf("%-5s%15s%10s %-5s%18s%10s %-5s%15s%10s\n", "||", danhSachSinhVien[i].maSinhVien, "||", "",
               danhSachSinhVien[i].tenSinhVien, "", "||", danhSachSinhVien[i].SDTSinhVien, "||");
    }
    printf("||----------------------------------------------------------------------------------END------||\n\n");
}


void luuDanhSachSinhVienRaFile(SinhVien danhSachSinhVien[], int a) {
    FILE *conTrofile;
    conTrofile = fopen(tenFile, "a");
    if (conTrofile == NULL) {
        printf("khong the mo file");
        return;
    }
    {
        fprintf(conTrofile, "||");
        fprintf(conTrofile, "ma sinh vien: ");
        fprintf(conTrofile, danhSachSinhVien[a - 1].maSinhVien);
        fprintf(conTrofile, "||");
        fprintf(conTrofile, "ten sinh vien: ");
        fprintf(conTrofile, danhSachSinhVien[a - 1].tenSinhVien);
        fprintf(conTrofile, "||");
        fprintf(conTrofile, "SDT sinh vien: ");
        fprintf(conTrofile, danhSachSinhVien[a - 1].SDTSinhVien);
        fprintf(conTrofile, "||\n");
        fclose(conTrofile);
    }
    printf("\n--| LUU FILE THANH CONG !!! |--\n\n\n");
}


void docDanhSachSinhVienTuFile() {
    FILE *controfile;
    controfile = fopen(tenFile, "r");
    char soLuongKiTu[10000];
    while (true) {
        if (fgets(soLuongKiTu, 10000, controfile) == NULL) {
            break;
        }
        printf("%s\n", soLuongKiTu);
    }
    printf("\n\n--| DOC FILE THANH CONG |--\n\n");
}


void tambiet(){
    printf("                                                                              EEEE\n");
    printf("                                                                            EE    EE\n\n");
    printf("TTT TTTT TTT       AA         MMM         MMM        BB BBB BBB B     II   EE EEE EEE  TT TT TT TT TT     !!!\n");
    printf("     TT          AA  AA       MM MM     MM MM        BB          bb        EE                TT           !!!\n");
    printf("     TT         AA    AA      MM  MM   MM  MM        BB          bb   II   EE                TT           !!!\n");
    printf("     TT        AA      AA     MM   MM MM   MM        BB          bb   II   EE                TT           !!!\n");
    printf("     TT       AA        AA    MM     M     MM        BB BBB BBB B     II   EE EEE EEE        TT           !!!\n");
    printf("     TT      AA AA AA AA AA   MM           MM        BB          bb   II   EE                TT           !!!\n");
    printf("     TT      AA          AA   MM           MM        BB          bb   II   EE                TT           \n");
    printf("     TT      AA          AA   MM           MM        BB          bb   II   EE                TT           !!!\n");
    printf("     TT      AA          AA   MM           MM        BB BBB BBB B     II   EE EEE EEEE       TT           !!!\n\n");
    printf("                  000                                                           000\n");
    printf("                  000                                                           000\n");
}
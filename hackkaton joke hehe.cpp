#include <stdio.h>

int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;  
        }
    }
    return -1;  
}

int main() {
    int choice;
    int i, n = 0, arr[100];
    do {
        printf("\nMenu\n");
        printf("1. Nhap so luong va gia tri cho cac phan tu\n");
        printf("2. In mang\n");
        printf("3. Dem so luong so hoan hao\n");
        printf("4. Dem so luong so nguyen to\n");
        printf("5. Tim gia tri lon thu 2 (khong sap xep)\n");
        printf("6. Tim gia tri nho thu 2 (khong sap xep)\n");
        printf("7. Them phan tu tai vi tri\n");
        printf("8. Xoa phan tu tai vi tri\n");
        printf("9. Sap xep mang tang dan (sap xep chen)\n");
        printf("10. Sap xep mang giam dan (sap xep chen)\n");
        printf("11. Tim kiem phan tu (Tim kiem tuan tu)\n");
        printf("12. Xoa phan tu trung lap va in phan tu doc nhat\n");
        printf("13. Sap xep va hien thi so chan dung truoc, so le dung sau\n");
        printf("14. Sap xep va hien thi so le dung truoc, so chan dung sau\n");
        printf("15. Dao nguoc mang\n");
        printf("16. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Nhap so luong: ");
                scanf("%d", &n);
                for (i = 0; i < n; i++) {
                    printf("Nhap gia tri: ");
                    scanf("%d", &arr[i]);
                }
                break;
            case 2:
                for (i = 0; i < n; i++) {
                    printf("arr[%d] = %d\n", i, arr[i]);
                }
                break;
            case 3: {
                int count = 0, sum;
                for (i = 0; i < n; i++) {
                    sum = 0;
                    for (int a = 1; a <= arr[i] / 2; a++) {
                        if (arr[i] % a == 0) {
                            sum += a;
                        }
                    }
                    if (sum == arr[i] && arr[i] > 0) {
                        count++;
                    }
                }
                printf("Co %d so la so hoan hao\n", count);
                break;
            }
            case 4: {
                int count = 0;
                for (i = 0; i < n; i++) {
                    if (arr[i] < 2) continue;
                    int isPrime = 1;
                    for (int j = 2; j * j <= arr[i]; j++) {
                        if (arr[i] % j == 0) {
                            isPrime = 0;
                            break;
                        }
                    }
                    if (isPrime) {
                        count++;
                    }
                }
                printf("So luong so nguyen to la: %d\n", count);
                break;
            }
            case 13: {
                int temp;
                for (i = 0; i < n - 1; i++) {
                    for (int j = 0; j < n - i - 1; j++) {
                        if (arr[j] % 2 == 1 && arr[j + 1] % 2 == 0) {
                            temp = arr[j];
                            arr[j] = arr[j + 1];
                            arr[j + 1] = temp;
                        }
                    }
                }
                printf("Mang sau khi sap xep so chan truoc, so le sau:\n");
                for (i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            }
            case 14: {
                int temp;
                for (i = 0; i < n - 1; i++) {
                    for (int j = 0; j < n - i - 1; j++) {
                        if (arr[j] % 2 == 0 && arr[j + 1] % 2 == 1) {
                            temp = arr[j];
                            arr[j] = arr[j + 1];
                            arr[j + 1] = temp;
                        }
                    }
                }
                printf("Mang sau khi sap xep so le truoc, so chan sau:\n");
                for (i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            }
            case 15: {
                for (int i = 0, j = n - 1; i < j; i++, j--) {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
                printf("Mang sau khi dao nguoc: ");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            }
            case 16:
                printf("Thoat chuong trinh\n");
                break;
            default:
                printf("Lua chon khong hop le\n");
        }
    } while (choice != 16);
    return 0;
}


/*

Lê Nguyễn Minh Trí - 75DCTT21

ĐỀ BÀI

Viết chương trình QuanLyDaySo.java:
1. Nhập số phần tử n (1 ≤ n ≤ 100). Nếu sai thì nhập lại (dùng while hoặc do-while).
2. Nhập n số nguyên vào mảng a.
3. Hiển thị menu, lặp lại cho đến khi chọn `0`:

===== MENU =====
1. In dãy số
2. Tổng và trung bình cộng
3. Số lớn nhất, nhỏ nhất
4. Đếm số chẵn, số dương
5. Tìm một số x trong dãy
6. Sắp xếp tăng dần rồi in
0. Thoát
Chọn:

*/

import java.util.Scanner;
public class QuanLyDaySo {
    private static String menu() {
        return """
        ===== MENU =====
        1. In day so
        2. Tong va trung binh cong
        3. So lon nhat, nho nhat
        4. Dem so chan, so duong
        5. Tim mot so x trong day
        6. Sap xep tang dan roi in
        0. Thoat
        Chon:\s""";
    }

    private static void inDaySo(int[] a) {
        System.out.print("Day so: ");
        for(int i = 0; i < a.length; i++) System.out.print("%d".formatted(a[i]));
        System.out.println();
    }

    private static void tongVaTrungBinhCong(int[] a) {
        long tong = 0;
        for(int i = 0; i < a.length; i++) tong += a[i];
        double tbc = (double) tong / a.length;
        System.out.println("Tong day so: %d".formatted(tong));
        System.out.println("Trung binh cong: %.2f".formatted(tbc));
    }

    private static int[] nhapDaySo(Scanner sc) {
        int n;
        do {
            System.out.print("Nhap so phan tu cua mang a (1 - 100): ");
            n = sc.nextInt();
            if(n < 1 || n > 100) System.out.println("Vui long nhap lai!");
        } while(n < 1 || n > 100);
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            System.out.print("Nhap a[%d]: ".formatted(i));
            a[i] = sc.nextInt();
        }
        return a;
    }

    private static void timMaxMin(int[] a) {
        int max = a[0], min = a[0];
        for(int i = 1; i < a.length; i++) {
            if(a[i] > max) max = a[i];
            if(a[i] < min) min = a[i];
        }
        System.out.println("So lon nhat: %d".formatted(max));
        System.out.println("So nho nhat: %d".formatted(min));
    }

    private static void demSoChanDuong(int[] a) {
        int demChan = 0, demDuong = 0;
        for(int i = 0; i < a.length; i++) {
            if(a[i] % 2 == 0) demChan++;
            if(a[i] > 0) demDuong++;
        }
        System.out.println("So luong so chan: %d".formatted(demChan));
        System.out.println("So luong so duong: %d".formatted(demDuong));
    }

    private static void timSoX(Scanner sc, int[] a) {
        System.out.print("Nhap so x can tim: ");
        int x = sc.nextInt();
        boolean found = false;
        for(int i = 0; i < a.length; i++) {
            if(a[i] == x) {
                if(!found) System.out.println("Tim thay %d tai cac vi tri:".formatted(x));
                System.out.println("Vi tri %d".formatted(i + 1));
                found = true;
            }
        }
        if(!found) System.out.println("Khong tim thay %d trong day!".formatted(x));
    }

    private static void sapXepTron(int[] a) {
        int[] temp = new int[a.length];
        mergeSort(a, temp, 0, a.length - 1);
        System.out.println("Day so sau khi sap xep tang dan:");
        inDaySo(a);
    }
    // Chia mang thanh hai nua
    private static void mergeSort(int[] a, int[] temp, int left, int right) {
        if(left >= right) return;
        int mid = left + (right - left) / 2;
        mergeSort(a, temp, left, mid); // Sap xep nua ben trai
        mergeSort(a, temp, mid + 1, right); // Sap xep nua ben phai
        merge(a, temp, left, mid, right); // Tron hai nua da sap xep
    }
    // Tron hai mang con da sap xep
    private static void merge(int[] a, int[] temp, int left, int mid, int right) {
        int i = left, j = mid + 1, k = left;
        while(i <= mid && j <= right) // So sanh va tron hai nua
            temp[k++] = (a[i] <= a[j]) ? a[i++] : a[j++];
        // Sao chep phan tu con lai cua nua ben trai
        while(i <= mid) temp[k++] = a[i++];
        // Sao chep phan tu con lai cua nua ben phai
        while(j <= right) temp[k++] = a[j++];
        // Ghi ket qua da tron tro lai mang ban dau
        for(int p = left; p <= right; p++) a[p] = temp[p];
    }

    private static void handleMenu(Scanner sc, int[] a) {
        int opt;
        do {
            System.out.println();
            System.out.print(menu());
            opt = sc.nextInt();
            switch(opt) {
                case 1: inDaySo(a); break;
                case 2: tongVaTrungBinhCong(a); break;
                case 3: timMaxMin(a); break;
                case 4: demSoChanDuong(a); break;
                case 5: timSoX(sc, a); break;
                case 6: sapXepTron(a); break;
                case 0: System.out.println("Da thoat chuong trinh!"); break;
                default: System.out.println("Vui long chon tu 0 - 6!"); break;
            }
        } while(opt != 0);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] a = nhapDaySo(sc);
        handleMenu(sc, a);
    }
}

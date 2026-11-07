// Le Nguyen Minh Tri - 75DCTT21
import java.util.Scanner;
public class TienDien {
    private static int soDienTieuThu(Scanner sc, String khach) {
        int cu, moi;
        do {
        	System.out.println("[ Khach hang " + khach + " ]");
            System.out.print("Nhap chi so cu: ");
            cu = sc.nextInt();
            System.out.print("Nhap chi so moi: ");
            moi = sc.nextInt();
            if(cu < 0 || moi < 0) {
            	System.out.println("Chi so dien khong duoc am!");
            } else if(moi < cu) System.out.println("Chi so moi khong duoc phep nho hon chi so cu!");
        } while (moi < cu || cu < 0 || moi < 0);
        sc.nextLine(); // Xoa ky tu '\n'
        return moi - cu;
    }
    private static long tongTienDien(int soDien) {
        if(soDien >= 0 && soDien <= 50) {
            return soDien * 1800L;
        } else if (soDien <= 100) {
            return 50 * 1800L + (soDien - 50) * 2200L;
        } else {
            return 50 * 1800L + 50 * 2200L + (soDien - 100) * 3000L;
        }
    }
    private static String mucTieuThu(int soDien) {
        return (soDien >= 0 && soDien <= 50) ? "Tiet kiem" : (soDien <= 150 ? "Binh thuong" : "Cao");
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n;
        do {
        	System.out.print("Nhap so luong khach hang: ");
        	n = sc.nextInt();
        	if(n <= 0) System.out.println("So luong khach hang phai lon hon 0!");
        } while(n <= 0);
        sc.nextLine(); // Xoa ky tu '\n'
        for(int i = 1; i <= n; i++) {
            System.out.println("\n===== KHACH HANG THU " + i + " =====");
            System.out.print("Nhap ten khach hang: ");
            String khach = sc.nextLine();
            int soDien = soDienTieuThu(sc, khach);
            long tienDien = tongTienDien(soDien);
            long thueVAT = tienDien * 10 / 100;
            long tongTien = tienDien + thueVAT;
            System.out.println("\n========== HOA DON ==========");
            System.out.println("Ten khach hang: " + khach);
            System.out.println("So dien tieu thu: " + soDien + " kWh");
            System.out.println("Tien dien: " + tienDien + " VND");
            System.out.println("Thue VAT (10%): " + thueVAT + " VND");
            System.out.println("Tong tien dien: " + tongTien + " VND");
            System.out.println("Muc tieu thu: " + mucTieuThu(soDien));
            System.out.println("===============================\n");
        }
    }
}
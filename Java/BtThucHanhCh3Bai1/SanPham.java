
import java.util.Locale;
public class SanPham {
    private String ten;
    private double gia;
    private int soLuong;
    void setThongTin(String t, double g, int sl) {
        if(g > 0 && sl > 0) {
            this.ten = t;
            this.gia = g;
            this.soLuong = sl;
        } else System.out.println("Du lieu khong hop le: " + t);
    }
    void setThongTin(String t, double g) {
        this.setThongTin(t, g, 1);
    }
    double thanhTien() {
        return gia * soLuong;
    }
    boolean laHangDat() {
        return gia >= 1e6;
    }
    void giamGia(double phanTram) {
        if(phanTram > 0 && phanTram <= 50) gia -= gia * phanTram / 100;
        else System.out.println("Muc giam khong hop le");
    }
    void inThongTin() {
        System.out.printf(Locale.US,
        	"%-10s gia %,.0f x %d = %,.0f | hang dat: %b\n",
        	ten, gia, soLuong, thanhTien(), laHangDat());
    }
    public static void main(String args[]) {
        // Cau 1 tao sp a roi in thong tin
        SanPham a = new SanPham();
        a.setThongTin("But bi", 5000, 10);
        a.inThongTin();

        // Cau 2 tao sp b 2 tham so roi in thong tin
        SanPham b = new SanPham();
        b.setThongTin("Tai nghe", 1.2e6);
        b.inThongTin();

        // Cau 3 giam gia b 20% va in lai
        b.giamGia(20);
        b.inThongTin();

        // Cau 4 giam gia b 70% bi tu choi
        b.giamGia(70);

        // Cau 5 dat a = Vo, gia -3000, so luong 5 (bi tu choi)
        a.setThongTin("Vo", -3000, 5);

        // Cau 6 in tong thanh tien cua a va b
        System.out.printf(Locale.US, "Tong tien: %,.0f%n", a.thanhTien() + b.thanhTien());
    }
}

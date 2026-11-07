import java.util.Scanner;
public class TinhDiemTB {
    private static double nhapDiem(Scanner sc, String mon) {
        double d;
        do {
            System.out.println("Nhap diem (0 - 10) cho mon %s: ".formatted(mon));
            d = sc.nextDouble();
            if(d < 0 || d > 10) System.out.println("Diem cua ban khong hop le, vui long nhap diem tu 0 den 10!\n");
        } while(d < 0 || d > 10);
        return d;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double toan = nhapDiem(sc, "Toan");
        double van = nhapDiem(sc, "Van");
        double anh = nhapDiem(sc, "Anh");
        System.out.println("Diem trung binh 3 mon cua ban la: %.2f".formatted((toan + van + anh)/3));
    }
}
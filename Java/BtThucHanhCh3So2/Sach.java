import java.util.Objects;
public class Sach {
    private String ma, ten, tacGia;
    private int namXB;
    private boolean dangMuon = false;
    private static int tongSoSach = 0;
    public String getMa() {
        return ma;
    }
    public boolean isDangMuon() {
        return dangMuon;
    }
    public void setNamXB(int nam) {
        if (nam >= 1900 && nam <= 2026) {
            namXB = nam;
        } else {
            System.out.println("Nam XB khong hop le: " + nam);
            namXB = 2026;
        }
    }
    public Sach(String ma, String ten) {
        this(ma, ten, "Khuyet danh", 2026);
    }
    public Sach(String ma, String ten, String tacGia, int namXB) {
        this.ma = ma;
        this.ten = ten;
        this.tacGia = tacGia;
        this.setNamXB(namXB);
        tongSoSach++;
    }
    public boolean muon() {
        if(dangMuon) return false;
        dangMuon = true;
        return true;
    }
    public boolean tra() {
        if(!dangMuon) return false;
        dangMuon = false;
        return true;
    }
    public int tuoiSach(int namHienTai) {
        return namHienTai - namXB;
    }

    @Override
    public String toString() {
        return "%-5s%-24s%-15s%-5d%s".formatted(this.ma, this.ten, this.tacGia, this.namXB, dangMuon ? "\t[dang muon]" : "");
    }

    @Override
    public boolean equals(Object o) {
        if(this == o) return true;
        if(!(o instanceof Sach)) return false;
        Sach sach = (Sach) o;
        return Objects.equals(this.ma, sach.ma);
    }

    public static int getTongSoSach() {
        return tongSoSach;
    }
}

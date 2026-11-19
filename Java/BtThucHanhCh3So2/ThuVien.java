public class ThuVien {
    private Sach[] ds = new Sach[100];
    private int n = 0;
    public boolean themSach(Sach s) {
        if(n == 100) return false;
        for(int i = 0; i < n; i++) if(s.equals(ds[i])) return false;
        ds[n++] = s;
        return true;
    }
    public Sach timTheoMa(String ma) {
        for(int i = 0; i < n; i++) if(ma.equals(ds[i].getMa())) return ds[i];
        return null;
    }
    public boolean choMuon(String ma) {
        Sach s = timTheoMa(ma);
        return s != null && s.muon();
    }
    public int demDangMuon() {
        int cnt = 0;
        for(int i = 0; i < n; i++) if(ds[i].isDangMuon()) cnt++;
        return cnt;
    }
    public void inDanhSach() {
        for(int i = 0; i < n; i++) System.out.println(ds[i]);
    }
    public static void main(String[] args) {
        ThuVien tv = new ThuVien();

        // Cau 1. Them 3 sach
        tv.themSach(new Sach("S01", "Lap trinh Java", "Nguyen Van A", 2020));
        tv.themSach(new Sach("S02", "Cau truc du lieu", "Tran Thi B", 1850));
        tv.themSach(new Sach("S03", "Nhap mon AI"));

        // Cau 2. Them sach trung ma
        System.out.println("Them trung ma: " + tv.themSach(new Sach("S01", "Ban sao")));

        // Cau 3. Cho muon S01 roi muon S99
        System.out.println("Muon S01: " + tv.choMuon("S01"));
        System.out.println("Muon S01 lan 2: " + tv.choMuon("S01"));
        System.out.println("Muon S99: " + tv.choMuon("S99"));

        // Cau 4. Tim S03 muon truc tiep roi danh sach
        Sach s = tv.timTheoMa("S03");
        if(s != null) s.muon();
        tv.inDanhSach();

        // Cau 5. In sach dang muon, tuoi S01 tinh den 2026, in danh sach
        System.out.println("Dang muon: " + tv.demDangMuon());
        System.out.println("Tuoi S01: " + tv.timTheoMa("S01").tuoiSach(2026));
        System.out.println("Tong so doi tuong Sach: " + Sach.getTongSoSach());
    }
}

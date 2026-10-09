using System;
using System.Data;
using System.Data.SqlClient;
using System.Globalization;
using System.Windows.Forms;

namespace giuaky_quanlysinhvien
{
    public partial class Form1 : Form
    {
        private readonly string connectionString = @"Data Source=localhost\SQLEXPRESS01;Initial Catalog=QLDIEM_LeNguyenMinhTri; Integrated Security = True";

        private string MaSV;
        private string TenSV;
        private DateTime NgaySinh;
        private int GioiTinh;
        private decimal DiemChuyenCan;
        private decimal DiemGiuaKy;
        private decimal DiemCuoiKy;
        private decimal TongDiem;
        private bool isEditing = false;

        // Chuyển chuỗi -> decimal, chấp nhận cả dấu , và .
        private bool TryDoc(string s, out decimal d)
        {
            s = s.Trim().Replace(',', '.');
            return decimal.TryParse(s, NumberStyles.Number, CultureInfo.InvariantCulture, out d);
        }

        private decimal tinhTongDiem()
        {
            return 0.1m * DiemChuyenCan + 0.2m * DiemGiuaKy + 0.7m * DiemCuoiKy;
        }

        private void HienTongDiem()
        {
            txtTongDiem.Text = tinhTongDiem().ToString("0.##");
        }

        // Đọc + kiểm tra dữ liệu từ form. Trả về false nếu có lỗi.
        private bool getDataValue()
        {
            MaSV = txtMaSV.Text.Trim();
            TenSV = tensv.Text.Trim();
            NgaySinh = ngaysinh.Value;
            GioiTinh = gioitinh.SelectedIndex;

            if (MaSV == "")
            {
                errorDialog("Vui lòng nhập mã sinh viên!");
                return false;
            }
            if (MaSV.Length > 30)
            {
                errorDialog("Mã sinh viên không được quá 30 ký tự!");
                return false;
            }
            if (TenSV == "")
            {
                errorDialog("Vui lòng nhập tên sinh viên!");
                return false;
            }
            if (TenSV.Length > 50)
            {
                errorDialog("Tên sinh viên không được quá 50 ký tự!");
                return false;
            }
            if (GioiTinh == -1)
            {
                errorDialog("Vui lòng chọn giới tính!");
                return false;
            }
            if (NgaySinh.Date > DateTime.Today)
            {
                errorDialog("Ngày sinh không được ở tương lai!");
                return false;
            }
            if (!TryDoc(txtDiemChuyenCan.Text, out DiemChuyenCan) || DiemChuyenCan < 0 || DiemChuyenCan > 10)
            {
                errorDialog("Điểm chuyên cần phải là số từ 0 đến 10!");
                return false;
            }
            if (!TryDoc(txtDiemGiuaKy.Text, out DiemGiuaKy) || DiemGiuaKy < 0 || DiemGiuaKy > 10)
            {
                errorDialog("Điểm giữa kỳ phải là số từ 0 đến 10!");
                return false;
            }
            if (!TryDoc(txtDiemCuoiKy.Text, out DiemCuoiKy) || DiemCuoiKy < 0 || DiemCuoiKy > 10)
            {
                errorDialog("Điểm cuối kỳ phải là số từ 0 đến 10!");
                return false;
            }

            TongDiem = tinhTongDiem();
            return true;
        }

        private void setDefault()
        {
            button1.Enabled = true;
            button2.Enabled = true;
            button3.Enabled = true;
            button5.Enabled = false;
            button6.Enabled = false;
            txtMaSV.Enabled = true;

            tensv.Enabled = false;
            ngaysinh.Enabled = false;
            gioitinh.Enabled = false;
            txtDiemGiuaKy.Enabled = false;
            txtDiemChuyenCan.Enabled = false;
            txtDiemCuoiKy.Enabled = false;
            txtTongDiem.Enabled = false;

            isEditing = false;

            tensv.Clear();
            txtDiemGiuaKy.Clear();
            txtDiemChuyenCan.Clear();
            txtDiemCuoiKy.Clear();
            txtTongDiem.Clear();
            txtMaSV.Clear();
            gioitinh.SelectedIndex = -1;
        }

        private void LoadData()
        {
            SqlConnection conn = new SqlConnection(connectionString);

            try
            {
                conn.Open();
                string query = "SELECT * FROM tblDiemSV ORDER BY MaSV";
                SqlDataAdapter da = new SqlDataAdapter(query, conn);
                DataTable dt = new DataTable();
                da.Fill(dt);

                dataGridView1.DataSource = dt;

                if (dt.Rows.Count > 0)
                {
                    dataGridView1.ClearSelection();
                    dataGridView1.Rows[0].Selected = true;
                    txtMaSV.Text = dataGridView1.Rows[0].Cells["MaSV"].Value.ToString();
                }
                else
                {
                    txtMaSV.Clear();
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
            finally
            {
                conn.Close();
            }
        }

        private bool ThemData()
        {
            SqlConnection conn = new SqlConnection(connectionString);

            try
            {
                conn.Open();

                string query = @"INSERT INTO tblDiemSV (MaSV, TenSV, NgaySinh, GioiTinh, DiemGiuaKy, DiemChuyenCan, DiemCuoiKy)
                                 VALUES (@MaSV, @TenSV, @NgaySinh, @GioiTinh, @DiemGiuaKy, @DiemChuyenCan, @DiemCuoiKy)";
                SqlCommand cmd = new SqlCommand(query, conn);
                cmd.Parameters.AddWithValue("@MaSV", MaSV);
                cmd.Parameters.AddWithValue("@TenSV", TenSV);
                cmd.Parameters.AddWithValue("@NgaySinh", NgaySinh);
                cmd.Parameters.AddWithValue("@GioiTinh", GioiTinh);
                cmd.Parameters.AddWithValue("@DiemGiuaKy", DiemGiuaKy);
                cmd.Parameters.AddWithValue("@DiemChuyenCan", DiemChuyenCan);
                cmd.Parameters.AddWithValue("@DiemCuoiKy", DiemCuoiKy);

                if (cmd.ExecuteNonQuery() != 0)
                {
                    MessageBox.Show("Thêm thành công!");
                    LoadData();
                    return true;
                }
                return false;
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                return false;
            }
            finally
            {
                conn.Close();
            }
        }

        private bool XoaData()
        {
            if (txtMaSV.Text.Trim() == "")
            {
                errorDialog("Vui lòng chọn sinh viên cần xóa!");
                return false;
            }

            SqlConnection conn = new SqlConnection(connectionString);

            try
            {
                conn.Open();

                string query = "DELETE FROM tblDiemSV WHERE MaSV = @MaSV";
                SqlCommand cmd = new SqlCommand(query, conn);
                cmd.Parameters.AddWithValue("@MaSV", txtMaSV.Text.Trim());

                if (cmd.ExecuteNonQuery() != 0)
                {
                    MessageBox.Show("Xóa thành công!");
                    LoadData();
                    return true;
                }
                else
                {
                    MessageBox.Show("Không tìm thấy sinh viên!");
                    return false;
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                return false;
            }
            finally
            {
                conn.Close();
            }
        }

        private void TimKiem()
        {
            SqlConnection conn = new SqlConnection(connectionString);

            try
            {
                conn.Open();

                string query = @"SELECT * FROM tblDiemSV
                                 WHERE TenSV LIKE @TuKhoa
                                    OR MaSV LIKE @TuKhoa
                                    OR (CASE GioiTinh WHEN 0 THEN N'Nữ' WHEN 1 THEN N'Nam' END) LIKE @TuKhoa
                                 ORDER BY MaSV";
                SqlCommand cmd = new SqlCommand(query, conn);
                cmd.Parameters.AddWithValue("@TuKhoa", "%" + textBox4.Text.Trim() + "%");

                SqlDataAdapter da = new SqlDataAdapter(cmd);
                DataTable dt = new DataTable();
                da.Fill(dt);

                dataGridView1.DataSource = dt;
                if (dt.Rows.Count > 0)
                {
                    dataGridView1.ClearSelection();
                    dataGridView1.Rows[0].Selected = true;
                    txtMaSV.Text = dataGridView1.Rows[0].Cells["MaSV"].Value.ToString();
                    MessageBox.Show("Tìm thấy " + dt.Rows.Count + " sinh viên!");
                }
                else
                {
                    txtMaSV.Clear();
                    MessageBox.Show("Không tìm thấy sinh viên nào!");
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
            finally
            {
                conn.Close();
            }
        }

        private bool SuaData()
        {
            SqlConnection conn = new SqlConnection(connectionString);

            try
            {
                conn.Open();

                string query = @"
                    UPDATE tblDiemSV
                    SET TenSV = @TenSV,
                        NgaySinh = @NgaySinh,
                        GioiTinh = @GioiTinh,
                        DiemGiuaKy = @DiemGiuaKy,
                        DiemChuyenCan = @DiemChuyenCan,
                        DiemCuoiKy = @DiemCuoiKy
                    WHERE MaSV = @MaSV";

                SqlCommand cmd = new SqlCommand(query, conn);
                cmd.Parameters.AddWithValue("@MaSV", MaSV);
                cmd.Parameters.AddWithValue("@TenSV", TenSV);
                cmd.Parameters.AddWithValue("@NgaySinh", NgaySinh);
                cmd.Parameters.AddWithValue("@GioiTinh", GioiTinh);
                cmd.Parameters.AddWithValue("@DiemGiuaKy", DiemGiuaKy);
                cmd.Parameters.AddWithValue("@DiemChuyenCan", DiemChuyenCan);
                cmd.Parameters.AddWithValue("@DiemCuoiKy", DiemCuoiKy);

                if (cmd.ExecuteNonQuery() != 0)
                {
                    MessageBox.Show("Sửa thành công!");
                    LoadData();
                    return true;
                }
                else
                {
                    MessageBox.Show("Không tìm thấy sinh viên!");
                    return false;
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                return false;
            }
            finally
            {
                conn.Close();
            }
        }

        private void HienThiDong(int rowIndex)
        {
            DataGridViewRow row = dataGridView1.Rows[rowIndex];

            txtMaSV.Text = row.Cells["MaSV"].Value.ToString();
            tensv.Text = row.Cells["TenSV"].Value.ToString();
            ngaysinh.Value = Convert.ToDateTime(row.Cells["NgaySinh"].Value);
            gioitinh.SelectedIndex = Convert.ToInt32(row.Cells["GioiTinh"].Value);

            txtDiemChuyenCan.Text = row.Cells["DiemChuyenCan"].Value.ToString();
            txtDiemGiuaKy.Text = row.Cells["DiemGiuaKy"].Value.ToString();
            txtDiemCuoiKy.Text = row.Cells["DiemCuoiKy"].Value.ToString();

            // Hiển thị tổng điểm
            if (TryDoc(txtDiemChuyenCan.Text, out DiemChuyenCan) &&
                TryDoc(txtDiemGiuaKy.Text, out DiemGiuaKy) &&
                TryDoc(txtDiemCuoiKy.Text, out DiemCuoiKy))
            {
                HienTongDiem();
            }
        }

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            gioitinh.Items.Add("Nữ");
            gioitinh.Items.Add("Nam");
            setDefault();
            LoadData();
        }

        private void editField()
        {
            button1.Enabled = false;
            button2.Enabled = false;
            button3.Enabled = false;
            button5.Enabled = true;
            button6.Enabled = true;
            txtMaSV.Enabled = !isEditing; // khi sửa thì không cho đổi mã SV

            tensv.Enabled = true;
            ngaysinh.Enabled = true;
            gioitinh.Enabled = true;
            txtDiemGiuaKy.Enabled = true;
            txtDiemChuyenCan.Enabled = true;
            txtDiemCuoiKy.Enabled = true;

            tensv.Focus();
        }

        private void button1_Click(object sender, EventArgs e) // thêm
        {
            isEditing = false;
            editField();

            txtMaSV.Clear();
            tensv.Clear();
            txtDiemGiuaKy.Clear();
            txtDiemChuyenCan.Clear();
            txtDiemCuoiKy.Clear();
            txtTongDiem.Clear();
            gioitinh.SelectedIndex = -1;
            txtMaSV.Focus();
        }

        private void errorDialog(string text)
        {
            MessageBox.Show(text, "Thông báo lỗi", MessageBoxButtons.OK, MessageBoxIcon.Error);
        }

        private void button2_Click(object sender, EventArgs e) // sửa
        {
            if (txtMaSV.Text.Trim() == "")
            {
                errorDialog("Vui lòng chọn sinh viên cần sửa!");
                return;
            }
            isEditing = true;
            editField();
        }

        private void button3_Click(object sender, EventArgs e) // xóa
        {
            if (XoaData()) setDefault(); // Trong xóa data đã có load data
        }

        private void button5_Click(object sender, EventArgs e) // ghi
        {
            if (!getDataValue()) return;

            HienTongDiem();

            bool ok = isEditing ? SuaData() : ThemData();
            if (ok) setDefault();
        }

        private void button6_Click(object sender, EventArgs e) // hủy bỏ
        {
            setDefault();
        }

        private void dataGridView1_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            if (e.RowIndex < 0) return;
            if (dataGridView1.Rows[e.RowIndex].IsNewRow) return;
            HienThiDong(e.RowIndex);
        }

        private void button4_Click(object sender, EventArgs e) // tìm kiếm
        {
            TimKiem();
        }


        // Toàn bộ phía dưới ko dùng

        private void gioitinh_SelectedIndexChanged(object sender, EventArgs e) { }
        private void ngaysinh_ValueChanged(object sender, EventArgs e) { }
        private void label8_Click(object sender, EventArgs e) { }
        private void label9_Click(object sender, EventArgs e) { }
        private void richTextBox1_TextChanged(object sender, EventArgs e) { }
        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e) { }
    }
}
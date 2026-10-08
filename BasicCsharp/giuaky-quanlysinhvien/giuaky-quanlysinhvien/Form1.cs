using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace giuaky_quanlysinhvien
{
    public partial class Form1 : Form
    {
        private readonly string connectionString = @"Data Source=localhost\SQLEXPRESS01;Initial Catalog=QLSV_HoTenSV;Integrated Security=True";

        private string TenSV;
        private DateTime NgaySinh;
        private string QueQuan;
        private int TrinhDoHocVan;
        private int GioiTinh;
        private string DiaChi;
        private string GhiChu;
        private bool isEditing = false;
        private void getDataValue()
        {
            TenSV = tensv.Text.Trim();
            NgaySinh = ngaysinh.Value;
            QueQuan = quequan.Text.Trim();
            TrinhDoHocVan = trinhdohocvan.SelectedIndex;
            GioiTinh = gioitinh.SelectedIndex;
            DiaChi = diachi.Text.Trim();
            GhiChu = ghichu.Text;
        }

        private void setDefault()
        {
            button1.Enabled = true;
            button2.Enabled = true;
            button3.Enabled = true;
            button5.Enabled = false;
            button6.Enabled = false;
            idInput.Enabled = true;

            tensv.Enabled = false;
            ngaysinh.Enabled = false;
            gioitinh.Enabled = false;
            trinhdohocvan.Enabled = false;
            quequan.Enabled = false;
            diachi.Enabled = false;
            ghichu.Enabled = false;

            isEditing = false;

            tensv.Clear();
            quequan.Clear();
            diachi.Clear();
            ghichu.Clear();
            idInput.Clear();
            gioitinh.SelectedIndex = -1;
            trinhdohocvan.SelectedIndex = -1;
        }
        private void LoadData()
        {
            SqlConnection conn = new SqlConnection(connectionString);

            try
            {
                if (conn.State == ConnectionState.Closed)
                {
                    conn.Open();
                }
                string query = "SELECT * FROM tblSinhVien ORDER BY ID";
                SqlCommand cmd = new SqlCommand(query, conn);

                SqlDataAdapter da = new SqlDataAdapter(cmd);
                DataTable dt = new DataTable();
                da.Fill(dt);

                dataGridView1.DataSource = dt;

                // Có dữ liệu -> chọn dòng đầu tiên và hiển thị dữ liệu dòng đầu
                if (dt.Rows.Count > 0)
                {
                    dataGridView1.ClearSelection();
                    dataGridView1.Rows[0].Selected = true;
                    idInput.Text = dataGridView1.Rows[0].Cells["ID"].Value.ToString();
                }
                else
                {
                    idInput.Clear();
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

        private void ThemData()
        {
            SqlConnection conn = new SqlConnection(connectionString);

            try
            {
                if (conn.State == ConnectionState.Closed)
                {
                    conn.Open();
                }

                getDataValue();

                string query = "INSERT INTO tblSinhVien VALUES (@TenSV, @NgaySinh, @GioiTinh, @TrinhDoHocVan, @QueQuan, @DiaChi, @GhiChu)";
                SqlCommand cmd = new SqlCommand(query, conn);

                cmd.Parameters.AddWithValue("@TenSV", TenSV);
                cmd.Parameters.AddWithValue("@NgaySinh", NgaySinh);
                cmd.Parameters.AddWithValue("@GioiTinh", GioiTinh);
                cmd.Parameters.AddWithValue("@TrinhDoHocVan", TrinhDoHocVan);
                cmd.Parameters.AddWithValue("@QueQuan", QueQuan);
                cmd.Parameters.AddWithValue("@DiaChi", DiaChi);
                cmd.Parameters.AddWithValue("@GhiChu", GhiChu);

                var result = cmd.ExecuteNonQuery();

                if (result != 0)
                {
                    MessageBox.Show("Thêm thành công!");
                    LoadData();
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

        private bool XoaData()
        {
            SqlConnection conn = new SqlConnection(connectionString);

            try
            {
                if (conn.State == ConnectionState.Closed)
                {
                    conn.Open();
                }

                string query = "DELETE FROM tblSinhVien WHERE ID = @ID";

                SqlCommand cmd = new SqlCommand(query, conn);

                cmd.Parameters.AddWithValue("@ID", idInput.Text.Trim());

                var result = cmd.ExecuteNonQuery();

                if (result != 0)
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
                if (conn.State == ConnectionState.Closed)
                {
                    conn.Open();
                }

                string query = @"SELECT * FROM tblSinhVien WHERE TenSV LIKE @TuKhoa
                       OR CASE TrinhDoHocVan
                            WHEN 0 THEN N'Tiến sĩ'
                            WHEN 1 THEN N'Thạc sĩ'
                            WHEN 2 THEN N'Đại học'
                            WHEN 3 THEN N'Khác'
                          END LIKE @TuKhoa ORDER BY ID";
                SqlCommand cmd = new SqlCommand(query, conn);

                string tuKhoa = textBox4.Text.Trim();

                cmd.Parameters.AddWithValue("@TuKhoa", "%" + tuKhoa + "%");


                SqlDataAdapter da = new SqlDataAdapter(cmd);
                DataTable dt = new DataTable();
                da.Fill(dt);

                dataGridView1.DataSource = dt;
                if (dt.Rows.Count > 0)
                {
                    dataGridView1.ClearSelection();
                    dataGridView1.Rows[0].Selected = true;
                    idInput.Text = dataGridView1.Rows[0].Cells["ID"].Value.ToString();
                    MessageBox.Show("Tìm thấy " + dt.Rows.Count + " sinh viên!");
                }
                else
                {
                    idInput.Clear();
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

        private void SuaData()
        {
            SqlConnection conn = new SqlConnection(connectionString);

            try
            {
                if (conn.State == ConnectionState.Closed)
                {
                    conn.Open();
                }

                string query = @"
                    UPDATE tblSinhVien
                    SET TenSV = @TenSV,
                        NgaySinh = @NgaySinh,
                        GioiTinh = @GioiTinh,
                        TrinhDoHocVan = @TrinhDoHocVan,
                        QueQuan = @QueQuan,
                        DiaChi = @DiaChi,
                        GhiChu = @GhiChu
                    WHERE ID = @ID";

                SqlCommand cmd = new SqlCommand(query, conn);
                getDataValue();
                int ID = int.Parse(idInput.Text.Trim());
                cmd.Parameters.AddWithValue("@ID", ID);
                cmd.Parameters.AddWithValue("@TenSV", TenSV);
                cmd.Parameters.AddWithValue("@NgaySinh", NgaySinh);
                cmd.Parameters.AddWithValue("@GioiTinh", GioiTinh);
                cmd.Parameters.AddWithValue("@TrinhDoHocVan", TrinhDoHocVan);
                cmd.Parameters.AddWithValue("@QueQuan", QueQuan);
                cmd.Parameters.AddWithValue("@DiaChi", DiaChi);
                cmd.Parameters.AddWithValue("@GhiChu", GhiChu);

                var result = cmd.ExecuteNonQuery();

                if (result != 0)
                {
                    MessageBox.Show("Sửa thành công!");
                    LoadData();
                }
                else
                {
                    MessageBox.Show("Không tìm thấy sinh viên!");
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

        private void HienThiDong(int rowIndex)
        {
            DataGridViewRow row = dataGridView1.Rows[rowIndex];

            idInput.Text = row.Cells["ID"].Value.ToString();
            tensv.Text = row.Cells["TenSV"].Value.ToString();
            ngaysinh.Value = Convert.ToDateTime(row.Cells["NgaySinh"].Value);
            quequan.Text = row.Cells["QueQuan"].Value.ToString();

            gioitinh.SelectedIndex =
                Convert.ToInt32(row.Cells["GioiTinh"].Value);

            trinhdohocvan.SelectedIndex =
                Convert.ToInt32(row.Cells["TrinhDoHocVan"].Value);

            diachi.Text = row.Cells["DiaChi"].Value.ToString();
            ghichu.Text = row.Cells["GhiChu"].Value.ToString();
        }

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            setDefault();
            LoadData();
            trinhdohocvan.Items.Add("Tiến sĩ");
            trinhdohocvan.Items.Add("Thạc sĩ");
            trinhdohocvan.Items.Add("Đại học");
            trinhdohocvan.Items.Add("Khác");
            gioitinh.Items.Add("Nữ");
            gioitinh.Items.Add("Nam");
        }

        private void editField()
        {
            button1.Enabled = false;
            button2.Enabled = false;
            button3.Enabled = false;
            button5.Enabled = true;
            button6.Enabled = true;
            idInput.Enabled = false;

            tensv.Enabled = true;
            ngaysinh.Enabled = true;
            gioitinh.Enabled = true;
            trinhdohocvan.Enabled = true;
            quequan.Enabled = true;
            diachi.Enabled = true;
            ghichu.Enabled = true;

            tensv.Focus();

        }

        private void button1_Click(object sender, EventArgs e) // thêm
        {
            isEditing = false;
            editField();

            idInput.Clear();
            tensv.Clear();
            quequan.Clear();
            diachi.Clear();
            ghichu.Clear();
            gioitinh.SelectedIndex = -1;
            trinhdohocvan.SelectedIndex = -1;
        }

        private void errorDialog(string text)
        {
            MessageBox.Show(text, "Thông báo lỗi", MessageBoxButtons.OK, MessageBoxIcon.Error);
        }
        private void button2_Click(object sender, EventArgs e) // sửa
        {
            isEditing = true;
            editField();
        }

        private void button3_Click(object sender, EventArgs e) // xóa
        {
            if(XoaData()) setDefault(); // Trong xóa data đã có load data
        }
        
        private void button5_Click(object sender, EventArgs e) // ghi
        {
            getDataValue();
            if (TenSV.Trim().Length > 50)
            {
                errorDialog("Tên sinh viên không được quá 50 ký tự!");
                return;
            }

            if (quequan.Text.Trim().Length > 30)
            {
                errorDialog("Quê quán không được quá 30 ký tự!");
                return;
            }

            if (diachi.Text.Trim().Length > 100)
            {
                errorDialog("Địa chỉ không được quá 100 ký tự!");
                return;
            }

            if (ghichu.Text.Length > 200)
            {
                errorDialog("Ghi chú không được quá 200 ký tự!");
                return;
            }

            if (TenSV == "")
            {
                errorDialog("Vui lòng nhập tên sinh viên!");
                return;
            }
            if (TrinhDoHocVan == -1)
            {
                errorDialog("Vui lòng chọn trình độ học vấn!");
                return;
            }
            if (GioiTinh == -1)
            {
                errorDialog("Vui lòng chọn giới tính của bạn!");
                return;
            }
            if(isEditing)
            {
                SuaData();
            } else
            {
                ThemData();
            }
        }

        // sao đề cứ tồ tồ tđn ấy nhỉ đọc hơi khó hiểu <(")
        private void button6_Click(object sender, EventArgs e) // hủy bỏ
        {
            setDefault();
        }

        private void dataGridView1_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            if (e.RowIndex < 0) return;
            if (dataGridView1.Rows[e.RowIndex].IsNewRow) return;
            if (e.RowIndex >= 0)
            {
                HienThiDong(e.RowIndex);

            }
        }

        private void button4_Click(object sender, EventArgs e) // tìm kiếm
        {
            TimKiem();
        }


        // Double click nhầm nên toàn bộ phần bên dưới so I don't fcking care them


        private void gioitinh_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void ngaysinh_ValueChanged(object sender, EventArgs e)
        {

        }

        private void label8_Click(object sender, EventArgs e)
        {

        }

        private void label9_Click(object sender, EventArgs e)
        {

        }

        private void richTextBox1_TextChanged(object sender, EventArgs e)
        {

        }
        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

    }
}

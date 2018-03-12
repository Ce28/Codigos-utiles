using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using System.Data.Odbc;
using System.Data.SqlClient;

namespace CRUDChristian
{
    public partial class Form2 : Form
    {
        SqlConnection con = new SqlConnection();
        DataTable dt = new DataTable();

        public Form2(SqlConnection conexion)
        {
            con = conexion;
            InitializeComponent();
        }
        private void Form2_Load(object sender, EventArgs e)
        {
            fConsultaTodo();
            CambiarNombresDataGridView();
        }

        //Propiedades.
        public string sCodigo { get; set; }

        private void Form2_KeyUp(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Escape)
            {
                DialogResult = DialogResult.Abort;
                this.Close();
            }
        }

        private void dgvTabla_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            sCodigo = Convert.ToString(dgvTabla.Rows[e.RowIndex].Cells[0].Value);
            cerrar();
        }

        private void btnBuscar_Click(object sender, EventArgs e)
        {
            if (txtBuscar.Text != string.Empty)
            {
                fConsultaPorNombre();
            }
            else
            {
                fConsultaTodo();
            }
        }

        private void cerrar()
        {
            DialogResult = DialogResult.OK;
            this.Close();
        }

        private void CambiarNombresDataGridView()
        {
            dgvTabla.Columns[0].HeaderText = "Codigo";
            dgvTabla.Columns[1].HeaderText = "Nombre";
            dgvTabla.Columns[2].HeaderText = "Apellido paterno";
            dgvTabla.Columns[3].HeaderText = "Apellido materno";
            dgvTabla.Columns[4].HeaderText = "Direccion";
            dgvTabla.Columns[5].HeaderText = "Telefono";
            dgvTabla.Columns[6].HeaderText = "Fecha de nacimiento";
            dgvTabla.Columns[2].Width = 120;
            dgvTabla.Columns[3].Width = 120;
            dgvTabla.Columns[6].Width = 150;
        }

        private void fConsultaTodo()
        {
            con.Open();
            try
            {
                string sConsulta = string.Format("EXEC dbo.proc_UtileriasCRUDChristian 1,'','','','','','',''");
                SqlCommand comando = new SqlCommand(sConsulta, con);
                SqlDataAdapter da = new SqlDataAdapter(comando);
                dgvTabla.DataSource = dt;
                dt.Clear();
                da.Fill(dt);
            }
            catch (Exception ex)
            {
                MessageBox.Show("Error en la funcion fconsulta[" + ex.Message + "]", "Error en la consulta", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            }
            con.Close();
        }

        private void fConsultaPorNombre()
        {
            con.Open();
            try
            {
                string sConsulta = string.Format("EXEC dbo.proc_UtileriasCRUDChristian 4,'' ,'{0}','','','','',''", txtBuscar.Text);
                SqlCommand comando = new SqlCommand(sConsulta, con);
                SqlDataAdapter da = new SqlDataAdapter(comando);
                dgvTabla.DataSource = dt;
                dt.Clear();
                da.Fill(dt);
            }
            catch (Exception ex)
            {
                MessageBox.Show("Error en la funcion fConsultaPorNombre[" + ex.Message + "]", "Error en la consulta", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            }
            con.Close();
        }

    }
}

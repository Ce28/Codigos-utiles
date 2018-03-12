using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using System.Data.SqlClient;

namespace CRUDChristian
{
    public partial class Form1 : Form
    {
        //Conexion a base de datos.
        SqlConnection con = new SqlConnection("Data Source=DELL;Initial Catalog=EmpleadosCoppel;Integrated Security=True");

        public Form1()
        {
            InitializeComponent();
        }
        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void txtCod_Leave(object sender, EventArgs e)
        {
            if (txtCod.Text != string.Empty)
            {
                fConsultaPorCodigo();
            }
        }

        private void txtCod_KeyUp(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.F1)
            {
                Form2 vent = new Form2(con);
                
                if (vent.ShowDialog() == DialogResult.OK)
                {
                    txtCod.Text = vent.sCodigo;
                }
                if (txtCod.Text != string.Empty)
                {
                    txtNom.Focus();
                }
            }
        }

        private void btnCancelar_Click(object sender, EventArgs e)
        {
            Limpiar();
        }

        private void Limpiar()
        {
            txtCod.Text = string.Empty;
            txtNom.Text = string.Empty;
            txtApePat.Text = string.Empty;
            txtApeMat.Text = string.Empty;
            txtDir.Text = string.Empty;
            txtTel.Text = string.Empty;
            dtpFecNac.Text = string.Empty;
            txtCod.Focus();
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            Form3 vent = new Form3();
            if (vent.ShowDialog() != DialogResult.Yes)
            {
                e.Cancel = true;
            }
        }

        private void fConsultaPorCodigo()
        {
            con.Open();
            try
            {
       
                string sConsulta = string.Format("EXEC EmpleadosCoppel.dbo.proc_UtileriasCRUDChristian 5,{0},'','','','','',''", txtCod.Text);
                SqlCommand comando = new SqlCommand(sConsulta, con);
                SqlDataReader registros = comando.ExecuteReader();
                if (registros.Read())
                {
                    txtCod.Text = registros["iCodigo"].ToString();
                    txtNom.Text = registros["cNombre"].ToString();
                    txtApePat.Text = registros["cApellidoPaterno"].ToString();
                    txtApeMat.Text = registros["cApellidoMaterno"].ToString();
                    txtDir.Text = registros["cDireccion"].ToString();
                    txtTel.Text = registros["cTelefono"].ToString();
                    dtpFecNac.Text = registros["dFechaNacimiento"].ToString();
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show("Error en la funcion fConsultaPorCodigo[" + ex.Message + "]", "Error en la consulta", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            }
            con.Close();
        }

        private void fConsultaPorCodigoMOD(ref string nombre)
        {
            nombre = string.Empty;

            con.Open();
            try
            {
                string sConsulta = string.Format("EXEC EmpleadosCoppel.dbo.proc_UtileriasCRUDChristian 5,{0},'','','','','',''", txtCod.Text);
                SqlCommand comando = new SqlCommand(sConsulta, con);
                SqlDataReader registros = comando.ExecuteReader();
                if (registros.Read())
                {
                    nombre = registros["iCodigo"].ToString();
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show("Error en la funcion fConsultaPorCodigoMOD[" + ex.Message + "]", "Error en la consulta", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            }
            con.Close();
        }

        private void fGuardar()
        {
            con.Open();
            try
            {
                string sConsulta = string.Format("EXEC EmpleadosCoppel.dbo.proc_UtileriasCRUDChristian 0,{0},'{1}','{2}','{3}','{4}','{5}','{6}'", txtCod.Text, txtNom.Text, txtApePat.Text, txtApeMat.Text, txtDir.Text, txtTel.Text, dtpFecNac.Text);
                SqlCommand comando = new SqlCommand(sConsulta, con);
                comando.ExecuteNonQuery();
                MessageBox.Show("Empleado guardado", "Aviso", MessageBoxButtons.OK, MessageBoxIcon.None);
   
            }
            catch (Exception ex)
            {
                MessageBox.Show("Error en la funcion fGuardar[" + ex.Message + "]", "Error en la consulta", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            } 
            con.Close();
        }

        private void fActualizar()
        {
            con.Open();
            try
            { 
                string sConsulta = string.Format("EXEC EmpleadosCoppel.dbo.proc_UtileriasCRUDChristian 2,{0},'{1}','{2}','{3}','{4}','{5}','{6}'", txtCod.Text, txtNom.Text, txtApePat.Text, txtApeMat.Text, txtDir.Text, txtTel.Text, dtpFecNac.Text);
                SqlCommand comando = new SqlCommand(sConsulta, con);
                int cant;
                cant = comando.ExecuteNonQuery();
                if (cant > 0)
                {
                    MessageBox.Show("Empleado actualizado", "Aviso", MessageBoxButtons.OK, MessageBoxIcon.None);
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show("Error en la funcion fActualizar[" + ex.Message + "]", "Error en la consulta", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            }
            con.Close();
        }

        private void btnEliminar_Click(object sender, EventArgs e)
        {
            if (txtCod.Text != string.Empty)
            {
                con.Open();
                try
                {
                    string sConsulta = string.Format("EXEC EmpleadosCoppel.dbo.proc_UtileriasCRUDChristian 5,{0},'','','','','',''", txtCod.Text);
                    SqlCommand comando = new SqlCommand(sConsulta, con);
                    SqlDataReader registro = comando.ExecuteReader();
                    if (registro.Read())
                    {
                        con.Close();
                        con.Open();
                        if (MessageBox.Show("Esta seguro de eliminar el empleado", "Aviso", MessageBoxButtons.YesNo, MessageBoxIcon.Question) == DialogResult.Yes)
                        {
                            string sConsulta1 = string.Format("EXEC EmpleadosCoppel.dbo.proc_UtileriasCRUDChristian 3,{0},'','','','','',''", txtCod.Text);
                            SqlCommand comando1 = new SqlCommand(sConsulta1, con);
                            int cant;
                            cant = comando1.ExecuteNonQuery();
                            if (cant > 0)
                            {
                                MessageBox.Show("Empleado eliminado", "Aviso", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                            }
                        }
                        else
                        {
                            MessageBox.Show("Empleado no eliminado", "Aviso", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                        }
                    }
                }
                catch (Exception ex)
                {
                    MessageBox.Show("Error en la funcion fEliminar[" + ex.Message + "]", "Error en la consulta", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                }
                con.Close();
            }
            Limpiar();
        }

        private void btnGuardar_Click(object sender, EventArgs e)
        {
            if (txtCod.Text != string.Empty)
            {
                string nombre = string.Empty;
                fConsultaPorCodigoMOD(ref nombre);
                if (nombre != string.Empty)
                {
                    fActualizar();
                }
                else
                {
                    fGuardar();
                }
            }
            Limpiar();
        }

    }
}

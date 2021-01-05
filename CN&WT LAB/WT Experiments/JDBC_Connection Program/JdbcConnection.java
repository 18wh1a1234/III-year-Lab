import java.sql.*;

public class JdbcConnection {

	public static void main(String[] args) throws SQLException {
		try {
			Class.forName("com.mysql.jdbc.Driver");
			Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/it2018", "root", "1234");
			Statement st = con.createStatement();
			
			System.out.println("Connection Established!!!");
			ResultSet rs = st.executeQuery("Select * from employee");
			
			while(rs.next()) {
				System.out.println(rs.getInt(1) + " " + rs.getString(2) + " " + rs.getDouble(3) + " " + rs.getString(4) + " " + rs.getString(5));
			}
			st.close();
			con.close();
			
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		}
	}
}

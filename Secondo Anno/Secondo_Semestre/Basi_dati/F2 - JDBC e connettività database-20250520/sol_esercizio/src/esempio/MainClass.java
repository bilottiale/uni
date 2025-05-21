package esempio;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class MainClass {
	
	public static void main(String[] args){
		try{
			Class.forName ("org.postgresql.Driver");  // Load the Driver
			Connection conn = DriverManager.getConnection( "jdbc:postgresql://localhost:5432/studenti", "user", "pw" );
			Statement stmt = conn.createStatement();
			
			String sql = "CREATE TABLE STUDENTI(matr integer primary key, cognome varchar, nome varchar)";
			stmt.executeUpdate(sql);
			sql = "INSERT INTO STUDENTI VALUES(1, 'rossi', 'mario'), (2, 'bianchi', 'sergio')";
			stmt.executeUpdate(sql);
			sql = "SELECT * FROM STUDENTI";
			ResultSet rs = stmt.executeQuery(sql);
			while (rs.next()) {
				int matr = rs.getInt("matr");
				String cognome = rs.getString("cognome");
				String nome = rs.getString("nome");
				System.out.println(matr+" "+cognome+" "+nome);
			}
			rs.close();
			stmt.close();
			
			sql = "SELECT * FROM STUDENTI WHERE nome = ? and matr > ?";
			PreparedStatement preparedStatement = conn.prepareStatement(sql);
			preparedStatement.setString(1, "sergio");
			preparedStatement.setInt(2, 0);
			rs = preparedStatement.executeQuery();
			while (rs.next()) {
				int matr = rs.getInt(1);
				String cognome = rs.getString(2);
				String nome = rs.getString(3);
				System.out.println(matr+" "+cognome+" "+nome);
			}
			rs.close();
			preparedStatement.close();
			
			conn.close();
		}
		catch (ClassNotFoundException e) {
			e.printStackTrace();
		}
		catch (SQLException e) {
			e.printStackTrace();
		}
		
	}
}

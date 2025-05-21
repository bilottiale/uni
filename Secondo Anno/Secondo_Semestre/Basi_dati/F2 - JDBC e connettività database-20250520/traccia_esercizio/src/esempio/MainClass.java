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
			
			...
			
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

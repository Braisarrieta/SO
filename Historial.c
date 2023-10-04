#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>

int main(int argc, char *argv[]) {
	con = mysql_init(NULL);
	if (con==NULL) {
		printf ("Error al crear la conexi￳n: %u %s\n", 
				mysql_errno(con), mysql_error(con));
		exit (1);
	}
	con = mysql_real_connect (con, "localhost","root", "mysql", "Historial",0, NULL, 0);
	if (con==NULL) {
		printf ("Error al inicializar la conexion: %u %s\n", 
				mysql_errno(con), mysql_error(con));
		exit (1);
	}
	// Añadir un jugador al historial
	char query[255];
	printf(query, "INSERT INTO Historiales (victorias, derrotas, N_Partidas, Personajes) VALUES (3, 2, 5, 4)");
	
	if (mysql_query(con, query) != 0) {
		printf("No se pudo añadir el jugador %s\n", mysql_error(con));
		mysql_close(con);
		exit(1);
	}
	printf("Historial actualizado correctamente!\n");
	
	// Consultar el ID en el historial
	char ConsultaID[255];
	printf(ConsultaID, "SELECT HistorialID FROM Historiales WHERE Username = 'JuanDB'");
	MYSQL_RES *res = mysql_query(con, ConsultaID);
	if (res == NULL) {
		printf("No se pudo consultar el ID del jugador: %s\n", mysql_error(con));
		mysql_close(con);
		exit(1);
	}
	MYSQL_ROW row;
	while ((row = mysql_fetch_row(res))) {
		printf("%s\n", row[0]);
	}
	
	// Cerrar conexion
	mysql_free_result(res);
	mysql_close(con);
	
	return 0;
}


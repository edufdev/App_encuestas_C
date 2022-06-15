#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h> 
#include <Windows.h>

#define ENTER 13
#define BACKSPACE 8
#define INTENTOS 3
  
using namespace std;

void gotoxy(int x,int y);
void Crearencuesta(FILE *fichero);
void VerEncuesta(FILE *fichero);
int login_alumno();
int login_administrador();
int login_super_admin();
int dasboard_administrador();
int solicitar_datos();
int menu_super_admin();
void crearCarne(FILE * fichero);
void opcion_semestre();
void CursosPorSemestre();
void PensumIngenieria();
void Crearfichero(FILE *fichero);
void Instertarcarne(FILE*fichero);
void InsertarDatos(FILE *fichero);
void VerDatos(FILE *fichero);
void inicio_super_admin();
void respuestas_encuesta();
//void VerresultadosEncuesta(FILE *fichero);
void menu_consultas();
void Pregunta1(FILE *fichero);
void Pregunta2(FILE *fichero);
void Pregunta3(FILE *fichero);
void Pregunta4(FILE *fichero);
void Pregunta5(FILE *fichero);

string usuario, password;

struct sEncuesta 
   {
   	
   	int EX,MB,B,NB;
   	int acumEX, acumMB, acumB,acumNB;
    
   }encuesta;

struct sEstudiante
{
char nombre[30], apellido[30];
char seccion[30];
char carne[30];
int carrera, semestre;	
}estudiante;

struct sRegistro 
   {
	char seccion[30];
	char carne[30];
	char nombre[30],catedratico[30];
   	int codigo, semestre,carrera;
//   int carrera;
   }registro;
   
main()
{
	int exit = 0;
	char opcion;
	
	cout << "Bienvenido a UMG APP\n\n";
	cout << "Ingrese una opcion:\n\n";
	cout << "1) Alumno\n";
	cout << "2) Administrador\n";
	cout << "3) Super Administrador\n";
	cout << "4) Salir del programa\n\n";
	cout << "Opcion Seleccionada:  ";
	cin >> opcion;
	system("cls");
	
	switch (opcion)
	{
		case '1':
			login_alumno();
			break;
		case '2':
			login_administrador();
			break;
		case '3':
			login_super_admin();
			break;
		case '4':
			cout << "Gracias, hasta luego!";
			exit = 1;
			break;
		default:
			cout << "Opcion invalida, verifique su respuesta";
			sleep(2);
			system ("cls");
			main();
	}
	return 0;
}

void gotoxy(int x,int y)
{  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 } 
 
void Crearencuesta(FILE *fichero)
{
//	int carne;
	
        fichero = fopen("resultados", "r");
        if(!fichero)
        {
        fichero = fopen("resultados", "w");
        }
        else
        {
        cout <<"\n Archivo leido con exito";
        system("cls");
        }
        fclose (fichero);
        return;
} 


void VerEncuesta(FILE *fichero)
{
int numero = 1;
        fichero = fopen("resultados", "r");
        if(fichero == NULL)
        {
            cout << "\nfichero no existe! \n Por favor creelo\n\n";
            system("PAUSE");
            system("cls");
//            getch();
            return;
        }
        fread(&encuesta, sizeof(struct sEncuesta), 1, fichero);
        printf("\nPregunta \tExcelente \tMuy Bien \tBien \tNo Muy Bien");
        while(!feof(fichero))
        {
            printf("\n%d 	\t%d 	\t%d 	\t%d 	\t%d", numero, encuesta.EX, encuesta.MB, encuesta.B, encuesta.NB);
            fread(&encuesta, sizeof(struct sEncuesta), 1, fichero);
            numero++;
        }
    cout << "\n\n";
    system("PAUSE");
    fclose(fichero);
    return;
}

//void VerresultadosEncuesta(FILE *fichero)
//{
//int numero = 1;
//        fichero = fopen("resultados", "r");
//        if(fichero == NULL)
//        {
//            cout << "\nfichero no existe! \n Por favor creelo";
//            getch();
//            return;
//        }
//        fread(&encuesta, sizeof(struct sEncuesta), 1, fichero);
//        printf("\nPregunta \tExcelente \tMuy Bien \tBien \tNo Muy Bien");
//        while(!feof(fichero))
//        {
//            printf("\n%d 	\t%d 	\t%d 	\t%d 	\t%d", numero, encuesta.acumEX, encuesta.acumMB, encuesta.acumB, encuesta.acumNB);
//            fread(&encuesta, sizeof(struct sEncuesta), 1, fichero);
//            numero++;
//            system("PAUSE");
//        }
//    fclose(fichero);
//    return;
//}


int login_alumno()
{
	vector<string> usuarios;
    vector<string> claves; 

    // Se añaden usuarios al vector
    usuarios.push_back("eduardo");
    usuarios.push_back("elber");
    usuarios.push_back("javier");

    // Se añaden claves al vector
    claves.push_back("123");
    claves.push_back("456");
    claves.push_back("789");;

    int contador = 0;
    bool ingresa = false;

    do
    {
        system("cls");
        cout << "\tLOGIN ALUMNO\n\n" << endl;
        cout << "Ingresa tus datos de estudiante para iniciar sesion\n(presiona ENTER)" << endl;
        cout << "\nUsuario: ";
        getline(cin, usuario);

        char caracter;

        cout << "Password: ";
        caracter = getch();

        password = "";

        while (caracter != ENTER)
        {

            if (caracter != BACKSPACE)
            {
                password.push_back(caracter);
                cout << "*";
            }
            else
            {
                if (password.length() > 0)
                {
                    cout << "\b \b";
                    password = password.substr(0, password.length() - 1);
                }
            }

            caracter = getch();
        }

        for (int i = 0; i < usuarios.size(); i++)
        {
            if (usuarios[i] == usuario && claves[i] == password)
            {
                ingresa = true;
                break;
            }
        }

        if (!ingresa)
        {
            cout << "\n\n\tEl usuario y/o password son incorrectos" << endl;
            cin.get();
            contador++;
        }

    } while (ingresa == false && contador < INTENTOS);

    if (ingresa == false)
    {
        cout << "\n\tUsted no pudo ingresar al sistema. ADIOS" << endl;
    }
    else
    {
        cout << "\n\nEntrando en sesion..." << endl;
        sleep(2);
        system("cls");
        solicitar_datos();
    }

    cin.get();

    return 0;
}

int login_administrador()
{
	vector<string> usuarios;
    vector<string> claves; 

    // Se añaden usuarios al vector
    usuarios.push_back("administrador");

    // Se añaden claves al vector
    claves.push_back("123456");;

    int contador = 0;
    bool ingresa = false;

    do
    {
        system("cls");
        cout << "\tLOGIN ADMINISTRADOR\n\n" << endl;
        cout << "Ingresa tus datos de administrador para iniciar sesion\n(presiona ENTER)" << endl;
        cout << "\nUsuario: ";
        getline(cin, usuario);

        char caracter;

        cout << "Password: ";
        caracter = getch();

        password = "";

        while (caracter != ENTER)
        {

            if (caracter != BACKSPACE)
            {
                password.push_back(caracter);
                cout << "*";
            }
            else
            {
                if (password.length() > 0)
                {
                    cout << "\b \b";
                    password = password.substr(0, password.length() - 1);
                }
            }

            caracter = getch();
        }

        for (int i = 0; i < usuarios.size(); i++)
        {
            if (usuarios[i] == usuario && claves[i] == password)
            {
                ingresa = true;
                break;
            }
        }

        if (!ingresa)
        {
            cout << "\n\n\tEl usuario y/o password son incorrectos" << endl;
            cin.get();
            contador++;
        }

    } while (ingresa == false && contador < INTENTOS);

    if (ingresa == false)
    {
        cout << "\n\tUsted no pudo ingresar al sistema. ADIOS" << endl;
    }
    else
    {
        cout << "\n\nEntrando como administrador..." << endl;
        sleep(2);
        system("cls");
        dasboard_administrador();
    }

    cin.get();

    return 0;
}
   
 
int login_super_admin()
{
	vector<string> usuarios;
    vector<string> claves; 

    // Se añaden usuarios al vector
    usuarios.push_back("supeAdmin");

    // Se añaden claves al vector
    claves.push_back("super123");;

    int contador = 0;
    bool ingresa = false;

    do
    {
        system("cls");
        cout << "\tLOGIN Super Administrador\n\n" << endl;
        cout << "Ingresa sus datos de Super Administrador para iniciar sesion\n(presiona ENTER)" << endl;
        cout << "\nUsuario: ";
        getline(cin, usuario);

        char caracter;

        cout << "Password: ";
        caracter = getch();

        password = "";

        while (caracter != ENTER)
        {

            if (caracter != BACKSPACE)
            {
                password.push_back(caracter);
                cout << "*";
            }
            else
            {
                if (password.length() > 0)
                {
                    cout << "\b \b";
                    password = password.substr(0, password.length() - 1);
                }
            }

            caracter = getch();
        }

        for (int i = 0; i < usuarios.size(); i++)
        {
            if (usuarios[i] == usuario && claves[i] == password)
            {
                ingresa = true;
                break;
            }
        }

        if (!ingresa)
        {
            cout << "\n\n\tEl usuario y/o password son incorrectos" << endl;
            cin.get();
            contador++;
        }

    } while (ingresa == false && contador < INTENTOS);

    if (ingresa == false)
    {
        cout << "\n\tUsted no pudo ingresar al sistema. ADIOS" << endl;
    }
    else
    {
        cout << "\n\nIniciando como Super Administrador..." << endl;
        sleep(2);
        system("cls");
        menu_super_admin();
    }

    cin.get();

    return 0;
}

int dasboard_administrador()
{
	char encuesta;
	FILE *fichero;
	
	cout << "BIENVENIDO AL USUARIO DE MAESTRO\n\n";
	cout << "Inicio: \n\n";
	cout << "==========================\n";
	cout << "1) Ver encuestas\n";
	cout << "2) Salir de sesion";
	cout << "\n\nSeleccione una opcion: ";
	cin >> encuesta;
	system("cls");
	
	switch (encuesta)
	{
		case '1':
			cout << "Estos son los resultados de las evaluaciones:\n\n";
			cout << "Carrera: Ingenieria en Sistemas\n";
			cout << "Seccion B\n";
//			cout << "Tercer Semestre\n";
			VerEncuesta(fichero);
			system("cls");
//			VerresultadosEncuesta(fichero);
			break;
		case '2':
			cout << "Hasta luego!!";
			sleep(2);
			system("cls");
			break;
		default:
			cout << "Opcion invalida, verifique su respuesta";
			sleep(2);
			system ("cls");
			dasboard_administrador();
	}
	
	
	main();
}

int solicitar_datos()
{
	int opcion;
	int exit = 0;
    FILE *fichero;
    
	char evaluacion;
	
	cout << "BIENVENIDO A SU DASHBOARD\n\n";
	cout << "=======================================\n";
	cout << "Evaluacion Ingenieria en Sistemas\n\n";
	
	cout << "NOTA:\n";
	cout << "Para poder realizar la evaluacion de catedraticos necesitamos que siga los siguientes pasos\n";
	cout << "\nPaso 1: Crear un archivo\n(presione 1)";
	cin >>opcion;
    switch(opcion)
    {
        case 1:
        crearCarne(fichero);
        sleep(2);
        system("cls");
        break;
        default:
        cout <<"\n Opcion no valida!!!";
        sleep(2);
        system("cls");
        }
	
return 0;	
}

int menu_super_admin()
{
	int opcion;
	int exit = 0;
    FILE *fichero;
    while (!exit)
    {       
            inicio_super_admin();
            cout <<" \nOpcion: ";
            cin >>opcion;
            switch(opcion)
            {
                case 1:
                Crearfichero(fichero);
//                InsertarDatos(fichero);
                sleep(2);
        		system("cls");
                break;
                case 2:
                system("cls");
                opcion_semestre();
                sleep(2);
        		system("cls");
        		
//                VerDatos(fichero);
//                sleep(2);
//        		system("cls");
                break;
                case 3:
                menu_consultas();
                break;
                case 4:
                sleep(2);
        		system("cls");
                exit = 1;
                break;
                default:
                cout <<"\n Opcion no valida!!!";
                sleep(2);
        		system("cls");
            }
    };
 
 
    return 0;
}

void crearCarne(FILE * fichero)
{
	fichero = fopen("carne", "r");
    if(!fichero)
    {
    fichero = fopen("carne", "w");
    cout <<"\nArchivo creado!";
    sleep(2);
    system("cls");
    }
    else
    {
    cout <<"\n El Archivo ya existe!";
    sleep(2);
    system("cls");
    }
    Instertarcarne(fichero);
    fclose (fichero);
	return;
}

void opcion_semestre()
{
	int opcion;
	int exit = 0;
    FILE *fichero;
    while (!exit)
    {       
    		cout << "===========================\n";
    		cout << "1) Ver cursos por semestre\n";
			cout << "2) Ver cursos agregados recientemente\n";
			cout << "3) Ver cursos Pensum Ingenieria\n";
			cout << "4) Salir del programa";
			cout << "===========================\n";
            cout <<" \nOpcion: ";
            cin >>opcion;
            system("cls");
            switch(opcion)
            {
                case 1:
                CursosPorSemestre();
                system("cls");
                break;
                case 2:
                VerDatos(fichero);
                system("cls");
        		break;
        		case 3:
        		PensumIngenieria();
        		system("cls");
				break;
				case 4:
				exit = 1;
				system("cls");
				break;
        		default:
        		cout << "Respuesta incorrecta";
        		sleep(2);
        		system("cls");
        		break;
        	}
    }
	
	
	
	return; 
}

void CursosPorSemestre()
{
	system("PAUSE");
	system("cls");
	cout << "-------Ingrese el semestre-------\n\n";
				cin >> registro.semestre;
				system("cls");
				
				if (registro.semestre == 1)
				{
					cout << "					PRIMER SEMESTRE\n\n";
					cout << "		CURSO										CATEDRATICO\n\n";
					cout << "	1. Desarrollo humano y profesional 							Lic. Hugo Hernandez\n";
					cout << "	2. Metodologia										Inga. Veronica contreras\n";
					cout << "\n	3. Contabilidad I									Lic. Wilson Lopez\n";
					cout << "	4. Introduccion a los Sistemas de Computo						Ing Gustavo Adolfo Vides Solis\n";
					cout << "	5. Logica de sistemas									Ing Esau Hernandez Castillo\n\n";
					system("PAUSE");
					system("cls");
				}
				else if (registro.semestre == 2 )
				{
					cout << "					SEGUNDO SEMESTRE\n\n";
					cout << "		CURSO										CATEDRATICO\n\n";
					cout << "	6. Precalculo									Licda. Alma Magnolia Garcia\n";
					cout << "	7. Algebra									Ing. Juan Fernando Contreras\n";
					cout << "	8. Algoritmos									Ing. Domingo Antonio Alvarado Bamaca\n";
					cout << "	9. Contabilidad II								Lic. Wilson Lopez Florian\n";
					cout << "  	10. Matematica Discreta								Ing. Esau Hernandez Castillo\n";
					system("PAUSE");
					system("cls");
				}
				else if (registro.semestre == 3 )
				{
					cout << "					TERCER SEMESTRE\n\n";
					cout << "		CURSO											CATEDRATICO\n\n";
					cout << "  11. Fisica I											Ing. Mynor Rafael Fuentes Orozco\n";
					cout << "  12. Programacion I										Ing Gustavo Adolfo Vides Solis \n";
					cout << "  13. Calculo I											Inga. Elisa Margarita Sandoval\n";
					cout << "  14. Proceso Administrativo									Licda. Maria Jose Poggio Sanchez\n";
					cout << "  15. Derecho Informatico									Licda. Susana Betsabe Villagran \n\n";
					system("PAUSE");
					system("cls");
				}
				else if (registro.semestre == 4 )
				{
					cout << "					CUARTO SEMESTRE\n\n";
					cout << "		CURSO											CATEDRATICO\n\n";
					cout << "  16. Microeconomia									Lic. Wilson Lopez Florian\n";
					cout << "  17. Programacion II									Inga. Claudia Maritza Ramirez Gomez\n";
					cout << "  18. Calculo II									Ing. Sergio Augusto Solorzano Espinoza\n";
					cout << "  19. Estadistica I									Ing. Sergio Augusto Solorzano Espinoza\n";
					cout << "  20. Fisica II										Inga. Elisa Margarita Sandoval\n\n";
					system("PAUSE");
					system("cls");
				}
				else if (registro.semestre == 5 )
				{
					cout << "					QUINTO SEMESTRE\n\n";
					cout << "		CURSO											CATEDRATICO\n\n";
					cout << "  21. Metodos Numericos									Ing. Juan Manuel Ramirez\n";
					cout << "  22. Programacion III									Ing Gustavo Adolfo Vides Solis\n";
					cout << "  23. Emprendedores de Negocios								Licda. Yansi Patricia Molina Jimenez\n";
					cout << "  24. Electronica Analogica								Ing. Rolando Palacios\n";
					cout << "  25. Estadistica II									Ing. Marco Tulio Marroquin Portillo\n\n";
					system("PAUSE");
					system("cls");
				}
				else if (registro.semestre == 6 )
				{
					cout << "					SEXTO SEMESTRE\n\n";
					cout << "		CURSO											CATEDRATICO\n\n";
					cout << "  26. Investigacion de operaciones						Licda. Alma Magnolia Garcia\n";
					cout << "  27. Bases de Datos I								Ing. Kenneth E. Zea Rodriguez\n";
					cout << "  28. Automatas y lenguajes formales						Ing. Gustavo Enrique Zacarias Alonzo\n";
					cout << "  29. Sistemas Operativos I							Ing. Antonio Josue Barillas Garcia\n";
					cout << "  30. Electronica Digital I							Ing. Mynor Rafael Fuentes Orozco\n\n";
					system("PAUSE");
					system("cls");
				}
				else if (registro.semestre == 7 )
				{
					cout << "					SEPTIMO SEMESTRE\n\n";
					cout << "		CURSO											CATEDRATICO\n\n";
					cout << "  31. Bases de Datos II								Ing. Kenneth E. Zea Rodriguez\n";
					cout << "  32. Analisis de Sistema I							Ing. Wilson Vasquez\n";
					cout << "  33. Sistemas Operativos II							Ing. Josseph Emmanuel Turnil Murga\n";
					cout << "  34. Arquitectura de computadoras I						Ing. Domingo Antonio Alvarado Bamaca\n";
					cout << "  35. Compiladores								Ing. Gustavo Enrique Zacarias Alonzo \n\n";
					system("PAUSE");
					system("cls");
				}
				else if (registro.semestre == 8 )
				{
					cout << "					OCTAVO SEMESTRE\n\n";
					cout << "		CURSO											CATEDRATICO\n\n";
					cout << "  36. Desarrollo Web								Ing. Augusto Armando Cardona Paiz\n";
					cout << "  37. Analisis de Sistemas II							Inga. Emma Gabriela Luna Lopez\n";
					cout << "  38. Redes de Computadoras I							Inga. Veronica Contreras\n";
					cout << "  39. Etica Profesional								Lic. Josué David Rodriguez Rivas\n";
					cout << "  40. Arquitectura de Computadoras II						Ing. Domingo Antonio Alvarado Bamaca\n\n";
					system("PAUSE");
					system("cls");
				}
				else if (registro.semestre == 9 )
				{
					cout << "					NOVENO SEMESTRE\n\n";
					cout << "		CURSO											CATEDRATICO\n\n";
					cout << "  41. Administracion de Tecnologias de Informacion				Ing. Kenneth E. Zea Rodriguez\n";
					cout << "  42. Ingenieria de Software							Ing. Kenneth E. Zea Rodriguez\n";
					cout << "  43. Proyecto de Graduacion I							Ing. Marco Tulio Marroquín Portillo\n";
					cout << "  44. Redes de Computadoras II							Ing. Hector Jahaziel Luna Iriarte\n";
					cout << "  45. Inteligencia Artificial							Inga. Emma Gabriela Luna López\n\n";
					system("PAUSE");
					system("cls");
				}
				else if (registro.semestre == 10 )
				{
					cout << "					DECIMO SEMESTRE\n\n";
					cout << "		CURSO											CATEDRATICO\n\n";
					cout << "  46. Telecomunicaciones								Ing. Hector Jahaziel Luna Iriarte\n";
					cout << "  47. Seminario de tecnologias de Informacion						Ing. Kenneth E. Zea Rodriguez\n";
					cout << "  48. Aseguramiento de la calidad de Software						Ing. Marco Tulio Marroquin Portillo\n";
					cout << "  49. Proyecto de Graduacion II								Ing. Marco Tulio Marroquin Portillo\n";
					cout << "  50. Seguridad y Auditoria de sistemas							Ing. Antonio Josue Barillas Garcia\n\n";
					system("PAUSE");
					system("cls");
				}
				else
				{
					cout << "EL SEMESTRE NO EXISTE EN NUESTRA BASE DE DATOS";
				}
	
return;
}

void PensumIngenieria()
{
	FILE *fichero;
					cout << "================================================================================\n";
					cout << "					PRIMER SEMESTRE\n\n";					
					cout << "		CURSO										CATEDRATICO\n\n";
					cout << "	1. Desarrollo humano y profesional 							Lic. Hugo Hernandez\n";
					cout << "	2. Metodologia										Inga. Veronica contreras\n";
					cout << "\n	3. Contabilidad I									Lic. Wilson Lopez\n";
					cout << "	4. Introduccion a los Sistemas de Computo						Ing Gustavo Adolfo Vides Solis\n";
					cout << "	5. Logica de sistemas									Ing Esau Hernandez Castillo\n\n";
					cout << "================================================================================\n";
					cout << "					SEGUNDO SEMESTRE\n\n";
					cout << "		CURSO										CATEDRATICO\n\n";
					cout << "	6. Precalculo									Licda. Alma Magnolia Garcia\n";
					cout << "	7. Algebra									Ing. Juan Fernando Contreras\n";
					cout << "	8. Algoritmos									Ing. Domingo Antonio Alvarado Bamaca\n";
					cout << "	9. Contabilidad II								Lic. Wilson Lopez Florian\n";
					cout << "  	10. Matematica Discreta								Ing. Esau Hernandez Castillo\n";
					cout << "================================================================================\n";
					cout << "					TERCER SEMESTRE\n\n";
					cout << "		CURSO											CATEDRATICO\n\n";
					cout << "  11. Fisica I											Ing. Mynor Rafael Fuentes Orozco\n";
					cout << "  12. Programacion I										Ing Gustavo Adolfo Vides Solis \n";
					cout << "  13. Calculo I											Inga. Elisa Margarita Sandoval\n";
					cout << "  14. Proceso Administrativo									Licda. Maria Jose Poggio Sanchez\n";
					cout << "  15. Derecho Informatico									Licda. Susana Betsabe Villagran \n\n";
					cout << "================================================================================\n";
					cout << "					CUARTO SEMESTRE\n\n";
					cout << "		CURSO											CATEDRATICO\n\n";
					cout << "  16. Microeconomia									Lic. Wilson Lopez Florian\n";
					cout << "  17. Programacion II									Inga. Claudia Maritza Ramirez Gomez\n";
					cout << "  18. Calculo II									Ing. Sergio Augusto Solorzano Espinoza\n";
					cout << "  19. Estadistica I									Ing. Sergio Augusto Solorzano Espinoza\n";
					cout << "  20. Fisica II										Inga. Elisa Margarita Sandoval\n\n";
					cout << "================================================================================\n";
					cout << "					QUINTO SEMESTRE\n\n";
					cout << "		CURSO											CATEDRATICO\n\n";
					cout << "  21. Metodos Numericos									Ing. Juan Manuel Ramirez\n";
					cout << "  22. Programacion III									Ing Gustavo Adolfo Vides Solis\n";
					cout << "  23. Emprendedores de Negocios								Licda. Yansi Patricia Molina Jimenez\n";
					cout << "  24. Electronica Analogica								Ing. Rolando Palacios\n";
					cout << "  25. Estadistica II									Ing. Marco Tulio Marroquin Portillo\n\n";
					cout << "================================================================================\n";
				cout << "					SEXTO SEMESTRE\n\n";
					cout << "		CURSO											CATEDRATICO\n\n";
					cout << "  26. Investigacion de operaciones						Licda. Alma Magnolia Garcia\n";
					cout << "  27. Bases de Datos I								Ing. Kenneth E. Zea Rodriguez\n";
					cout << "  28. Automatas y lenguajes formales						Ing. Gustavo Enrique Zacarias Alonzo\n";
					cout << "  29. Sistemas Operativos I							Ing. Antonio Josue Barillas Garcia\n";
					cout << "  30. Electronica Digital I							Ing. Mynor Rafael Fuentes Orozco\n\n";
					cout << "================================================================================\n";
					cout << "					SEPTIMO SEMESTRE\n\n";
					cout << "		CURSO											CATEDRATICO\n\n";
					cout << "  31. Bases de Datos II								Ing. Kenneth E. Zea Rodriguez\n";
					cout << "  32. Analisis de Sistema I							Ing. Wilson Vasquez\n";
					cout << "  33. Sistemas Operativos II							Ing. Josseph Emmanuel Turnil Murga\n";
					cout << "  34. Arquitectura de computadoras I						Ing. Domingo Antonio Alvarado Bamaca\n";
					cout << "  35. Compiladores								Ing. Gustavo Enrique Zacarias Alonzo \n\n";
					cout << "================================================================================\n";
					cout << "					OCTAVO SEMESTRE\n\n";
					cout << "		CURSO											CATEDRATICO\n\n";
					cout << "  36. Desarrollo Web								Ing. Augusto Armando Cardona Paiz\n";
					cout << "  37. Analisis de Sistemas II							Inga. Emma Gabriela Luna Lopez\n";
					cout << "  38. Redes de Computadoras I							Inga. Veronica Contreras\n";
					cout << "  39. Etica Profesional								Lic. Josué David Rodriguez Rivas\n";
					cout << "  40. Arquitectura de Computadoras II						Ing. Domingo Antonio Alvarado Bamaca\n\n";
					cout << "================================================================================\n";
					cout << "					NOVENO SEMESTRE\n\n";
					cout << "		CURSO											CATEDRATICO\n\n";
					cout << "  41. Administracion de Tecnologias de Informacion				Ing. Kenneth E. Zea Rodriguez\n";
					cout << "  42. Ingenieria de Software							Ing. Kenneth E. Zea Rodriguez\n";
					cout << "  43. Proyecto de Graduacion I							Ing. Marco Tulio Marroquín Portillo\n";
					cout << "  44. Redes de Computadoras II							Ing. Hector Jahaziel Luna Iriarte\n";
					cout << "  45. Inteligencia Artificial							Inga. Emma Gabriela Luna López\n\n";
					cout << "================================================================================\n";
					cout << "					DECIMO SEMESTRE\n\n";
					cout << "		CURSO											CATEDRATICO\n\n";
					cout << "  46. Telecomunicaciones								Ing. Hector Jahaziel Luna Iriarte\n";
					cout << "  47. Seminario de tecnologias de Informacion						Ing. Kenneth E. Zea Rodriguez\n";
					cout << "  48. Aseguramiento de la calidad de Software						Ing. Marco Tulio Marroquin Portillo\n";
					cout << "  49. Proyecto de Graduacion II								Ing. Marco Tulio Marroquin Portillo\n";
					cout << "  50. Seguridad y Auditoria de sistemas							Ing. Antonio Josue Barillas Garcia\n\n";
					cout << "================================================================================\n";
					cout << "  CURSOS AGREGADOS RECIENTEMENTE\n\n";
					VerDatos(fichero);
					system("PAUSE");
					system("cls");;
}

void Crearfichero(FILE *fichero)
{
        fichero = fopen("cursos", "r");
        if(!fichero)
        {
        fichero = fopen("cursos", "w");
        cout <<"\nArchivo creado!";
        sleep(2);
        system("cls");
        }
        else
        {
        cout <<"\n El Archivo ya existe!";
        sleep(2);
        system("cls");
        }
        InsertarDatos(fichero);
        fclose (fichero);
        return;
}

void Instertarcarne(FILE*fichero)
{
	int exit = 0;
	int encuesta;
	
		fichero = fopen("carne", "a+");
        if(fichero == NULL)
        {
        cout << "\nArchivo no existe! \nPor favor creelo";
        return;
        }
        cout << "===========================\n";
        cout << "\n\nPaso 2: Datos del estudiante \n\n";
		cout << "a) Ingrese un nombre: ";
		cin >> estudiante.nombre;
		cout << "b) Ingrese un apellido: ";
		cin >> estudiante.apellido;
		cout << "e) Ingrese su carne estudiantil(0000-00-0000): ";
		cin >> estudiante.carne;
//		CursosPorSemestre();
		cout << "f) Ingrese el semestre  que estar cursando (000): ";
		cin >> estudiante.semestre;
		
		cout << "Gracias por sus respuestas!!\n\n";
//		cout << "Cargando evaluacion...";
		sleep(2);
		system ("cls");
		cout << "===========================\n";
		cout << "DATOS ALUMNO\n\n";
		
		cout << "Nombre Alumno: " << estudiante.nombre << " " << estudiante.apellido;
		cout << "\nCarne: " << estudiante.carne << "\n\n";
		cout << "\nSeccion: B";
		
		cout << "\nSemestre: " << estudiante.semestre;
		cout << "===========================\n";
		
		
		cout << "\n\n1) Hacer encuesta \n";
		cout << "2) Salir del programa\n";
		cout << "Opcion seleccionada: ";
		cin >> encuesta;
		system("cls");
		
		switch(encuesta)
		{
			case 1:
			cout << "Cargando evaluacion...";
			sleep(2);
			system ("cls");
			Pregunta1(fichero);
			Pregunta2(fichero);
			Pregunta3(fichero);
			Pregunta4(fichero);
			Pregunta5(fichero);
			break;
			case 2:
			exit = 1;
			break;
			default:
			cout << "Opcion invalida";
			break;
		}
		
		
        fwrite(&estudiante, sizeof(struct sEstudiante), 1, fichero);
        cout << "Guardando datos...";
        sleep(2);
        system("cls");
        fclose(fichero);
        main();
        
        
        return;
}

void InsertarDatos(FILE *fichero)
{
        fichero = fopen("cursos", "a+");
        if(fichero == NULL)
        {
        cout << "\nArchivo no existe! \nPor favor creelo";
        return;
        }
        cout << "\nIngresa el codigo del curso: ";
        scanf("%d", &registro.codigo);
        cout << "\nIngresa el nombre  del curso (ejemplo_I): ";
        scanf("%s", &registro.nombre);
        cout << "\nIngresa el semestre  del curso: ";
        scanf("%d", &registro.semestre);
        

        cout << "\nIngresa el nombre  del catedratico: ";
        scanf("%s", &registro.catedratico);
        fwrite(&registro, sizeof(struct sRegistro), 1, fichero);
        cout << "\n\nGuardando datos...";
        sleep(2);
        system("cls");
        fclose(fichero);
        
        
        return;
}

void VerDatos(FILE *fichero)
{
int numero = 1;
        fichero = fopen("cursos", "r");
        if(fichero == NULL)
        {
            cout << "\nArchivo no existe! \n Por favor creelo\n\n";
//            getch();
			system("PAUSE");
        	system("cls");
            return;
        }
        cout << "Carrera: Ingenieria en Sistemas";
        fread(&registro, sizeof(struct sRegistro), 1, fichero);
        printf("\nCodigo \tNombre Curso		 	\tSemestre	 \tCatedratico");
        while(!feof(fichero))
        {
            printf("\n%d \t%s	\t%d 	\t%s\n\n", numero, registro.nombre,registro.semestre, registro.catedratico);
			fread(&registro, sizeof(struct sRegistro), 1, fichero);
			numero++;
        }
    system("PAUSE");
	fclose(fichero);
    return;
}
 
void inicio_super_admin()
{

    cout << "\n  INICIO SUPER ADMINISTRADOR" << endl;
    cout << "==================" << endl;
//    cout << "\t1 .- CREAR ARCHIVO" << endl;
    cout << "\t1 .- AGREGAR NUEVO CURSO" << endl;
    cout << "\t2 .- VER INFORMACION DE LOS CURSOS" << endl;
//    cout << "\t4 .- EDITAR INFORMACION DE CURSOS" << endl;
    cout << "\t3 .- VER DATOS DE ENCUESTAS" << endl;
    cout << "\t4 .- SALIR DEL PROGRAMA" << endl;
    cout << "==================" << endl;
    cout << "Elije una opcion: ";
}

void respuestas_encuesta()
{
	int semestre;
	int pregunta;
	FILE *fichero;
	
	cout << "1) Ver respuestas de alumnos \n";
//	cout << "2) Ver resultados por semestre\n\n";
	cin >> pregunta;
		
	if (pregunta == 1)
	{
	cout << "TABLA DE RESPUESTAS\nTotal:\n ";
	VerEncuesta(fichero);
	}
//	else if (pregunta == 2)
//	{
//		cout << "Ingrese el semestre: ";
//		cin >> semestre;
//		
//	}
	else
	{
		cout << "Incorrecto\n";
		system("PAUSE");
	}
}
 

void menu_consultas()
{
	int exit = 0;
    char opcion;
    char codigo[100];
 
        system("cls");
		cout << "\n  MENU DE CONSULTAS" << endl;
        cout << "========================" << endl;
        cout << "1 .- VER PREGUNTAS DE LA ENCUESTA" << endl;
        cout << "2 .- VER RESULTADOS DE LA ENCUESTA" << endl;
        cout << "3 .- SALIR DEL PROGRAMA\n";
        cout << "=======================" << endl;
        cout << "Elije una opcion: ";
 
        cin >> opcion;
        system("cls");
 
        switch(opcion)
        {
        	case '1':
        	cout << "\n=================================================================\n";
        	cout << "\n\n1) Asistencia y Puntualidad a su clase\n";
        	cout << "2) Conocimiento y Dominio de los temas\n";
        	cout << "3) Utiliza las herramientas tecnologicas provistas en el aula\n";
        	cout << "4) Utilizacion de plataforma virtual para gestionar su curso\n";
        	cout << "5) Evaluacion de actividades academicas en orden y equidad\n\n";
        	cout << "\n=================================================================\n";
        	system("PAUSE");
        	system("cls");
			break;
			case '2':
//			system("cls");
			respuestas_encuesta();
			system("cls");
			break;
			case '3':
			exit = 1;
			system("cls");
			break;
			default:
				cout << "Opcion invalida";
				sleep(2);
				system("cls");
			break;
			
				
				
		}
		
 
}

void Pregunta1(FILE *fichero)
{
		 	int opc1;
		 	cout << "DATOS ALUMNO\n\n";
		
			cout << "Nombre Alumno: " << estudiante.nombre << " " << estudiante.apellido;
			cout << "\nCarne: " << estudiante.carne << "\n\n";
			cout << "\nSeccion: B";
			
			cout << "\nSemestre: " << estudiante.semestre;
			
		 	gotoxy(15,14);
			cout <<"------Evaluacion Semestre-------\n";
			gotoxy(5,15);
			cout <<"----------------------------------------------------\n";
			gotoxy(5,16);
			cout <<"/                                                  /\n";
			gotoxy(5,17);
			cout <<"/     Asistencia y puntualidad a su clase          /\n";
			gotoxy(5,18);
			cout <<"/                                                  /\n";
			gotoxy(5,19);
			cout <<"----------------------------------------------------\n";
			
			cout <<"1.Excelente \n";
			cout <<"2.Muy Bien \n";
			cout <<"3.Bien \n";
			cout <<"4.No Muy Bien \n";
			cin >> opc1;	 
			
			fichero = fopen("resultados", "a+");
			switch (opc1)
           		{
            case 1: 
            //registro.EX = registro.EX = 0;
            encuesta.acumEX = encuesta.acumEX +1;
            encuesta.EX = encuesta.EX = 1;
            encuesta.MB = encuesta.MB = 0;
            encuesta.B = encuesta.B = 0;
            encuesta.NB = encuesta.NB = 0;
            break;

            case 2: 
            //registro.MB = registro.MB = 0;
            encuesta.acumMB = encuesta.acumMB +1;
			encuesta.MB = encuesta.MB = 1;
			encuesta.EX = encuesta.EX = 0;
			encuesta.B = encuesta.B = 0;
			encuesta.NB = encuesta.NB = 0;
			break;

            case 3: 
            //registro.B = registro.B = 0;
            encuesta.acumB = encuesta.acumB +1;
            encuesta.B = encuesta.B = 1;
			encuesta.EX = encuesta.EX = 0;
			encuesta.MB = encuesta.MB = 0;	
			encuesta.NB = encuesta.NB = 0;		
        	break;
        	
            case 4: 
            //registro.NB = registro.NB = 0;
            encuesta.acumNB = encuesta.acumNB +1;
            encuesta.NB = encuesta.NB = 1;
            encuesta.EX = encuesta.EX = 0;
            encuesta.MB = encuesta.MB = 0;
            encuesta.B = encuesta.B = 0;		
            break;
        	
			default: 	
			cout <<"El valor no es valido\n";
			system("PAUSE");
			system("cls");
			Pregunta1(fichero);
			 }	
			fwrite(&encuesta, sizeof(struct sEncuesta), 1, fichero);
			fclose(fichero);
			
			system("cls");
		 	
		 return;
}
void Pregunta2(FILE *fichero)
{
		  	int opc2;
		  	int resultado;
		  	cout << "DATOS ALUMNO\n\n";
		
			cout << "Nombre Alumno: " << estudiante.nombre << " " << estudiante.apellido;
			cout << "\nCarne: " << estudiante.carne << "\n\n";
			cout << "\nSeccion: B";
			
			cout << "\nSemestre: " << estudiante.semestre;
		 	gotoxy(5,14);
			cout <<"----------------------------------------------------\n";
			gotoxy(5,15);
			cout <<"/                                                  /\n";
			gotoxy(5,16);
			cout <<"/      Conocimiento y dominio de los temas         /\n";
			gotoxy(5,17);
			cout <<"/                                                  /\n";
			gotoxy(5,18);
			cout <<"----------------------------------------------------\n";
			
			cout <<"1.Excelente \n";
			cout <<"2.Muy Bien \n";
			cout <<"3.Bien \n";
			cout <<"4.No Muy Bien \n";
			cin >> opc2;	 
			
			fichero = fopen("resultados", "a+");
			switch (opc2)
           		{
            case 1:
           //registro.EX = registro.EX = 0;
           	encuesta.acumEX = encuesta.acumEX +1;
            encuesta.EX = encuesta.EX = 1;
            encuesta.MB = encuesta.MB = 0;
            encuesta.B = encuesta.B = 0;
            encuesta.NB = encuesta.NB = 0;
            break;

            case 2:
            //registro.MB = registro.MB = 0;
            encuesta.acumMB = encuesta.acumMB +1;
			encuesta.MB = encuesta.MB = 1;
			encuesta.EX = encuesta.EX = 0;
			encuesta.B = encuesta.B = 0;
			encuesta.NB = encuesta.NB = 0;
			break;

            case 3: 
           // registro.B = registro.B = 0;
            encuesta.acumB = encuesta.acumB +1;
            encuesta.B = encuesta.B = 1;
			encuesta.EX = encuesta.EX = 0;
			encuesta.MB = encuesta.MB = 0;	
			encuesta.NB = encuesta.NB = 0;
        	break;
        	
            case 4: 
           // registro.NB = registro.NB = 0;
            encuesta.acumNB = encuesta.acumNB +1;
            encuesta.NB = encuesta.NB = 1;
            encuesta.EX = encuesta.EX = 0;
            encuesta.MB = encuesta.MB = 0;
            encuesta.B = encuesta.B = 0;
            break;
        	
			default: 	
			cout <<"El valor no es valido\n";
			system("PAUSE");
			system("cls");
			Pregunta2(fichero);
			 }
			 
			fwrite(&encuesta, sizeof(struct sEncuesta), 1, fichero);
			fclose(fichero);
			
			system("cls");
		 	
		 return;
}
		 
		 
void Pregunta3(FILE *fichero)
{
		  	int opc3;
		  	cout << "DATOS ALUMNO\n\n";
		
			cout << "Nombre Alumno: " << estudiante.nombre << " " << estudiante.apellido;
			cout << "\nCarne: " << estudiante.carne << "\n\n";
			cout << "\nSeccion: B";
			
			cout << "\nSemestre: " << estudiante.semestre;
			
		 	gotoxy(5,14);
			cout <<"----------------------------------------------------------------\n";
			gotoxy(5,15);
			cout <<"/                                                              /\n";
			gotoxy(5,16);
			cout <<"/  Utiliza las herramientas tecnologicas provistas en el aula  /\n";
			gotoxy(5,17);
			cout <<"/                                                              /\n";
			gotoxy(5,18);
			cout <<"----------------------------------------------------------------\n";
			
			cout <<"1.Excelente \n";
			cout <<"2.Muy Bien \n";
			cout <<"3.Bien \n";
			cout <<"4.No Muy Bien \n";
			cin >> opc3;
			
			fichero = fopen("resultados", "a+");
			
			switch (opc3)
           		{
            case 1: 
           // registro.EX = registro.EX = 0;
            encuesta.acumEX = encuesta.acumEX +1;
            encuesta.EX = encuesta.EX = 1;
            encuesta.MB = encuesta.MB = 0;
            encuesta.B = encuesta.B = 0;
            encuesta.NB = encuesta.NB = 0;
            break;

            case 2: 
           // registro.MB = registro.MB = 0;
            encuesta.acumMB = encuesta.acumMB +1;
			encuesta.MB = encuesta.MB + 1;
			encuesta.EX = encuesta.EX = 0;
			encuesta.B = encuesta.B = 0;
			encuesta.NB = encuesta.NB = 0;
			break;

            case 3: 
           // registro.B = registro.B = 0;
            encuesta.acumB = encuesta.acumB +1;
            encuesta.B = encuesta.B = 1;
			encuesta.EX = encuesta.EX = 0;
			encuesta.MB = encuesta.MB = 0;	
			encuesta.NB = encuesta.NB = 0;
        	break;
        	
            case 4: 
           // registro.NB = registro.NB = 0;
            encuesta.NB = encuesta.NB = 1;
            encuesta.EX = encuesta.EX = 0;
            encuesta.MB = encuesta.MB = 0;
            encuesta.B = encuesta.B = 0;
            break;
        	
			default: 	
			cout <<"El valor no es valido\n";
			system("PAUSE");
			system("cls");
			Pregunta3(fichero);
			 }
			 
			fwrite(&encuesta, sizeof(struct sEncuesta), 1, fichero);
			fclose(fichero);
			
			system("cls");
		 	
		 return;
}
		 
		 
void Pregunta4(FILE *fichero)
{
	
		  	int opc4;
		  	cout << "DATOS ALUMNO\n\n";
		
			cout << "Nombre Alumno: " << estudiante.nombre << " " << estudiante.apellido;
			cout << "\nCarne: " << estudiante.carne << "\n\n";
			cout << "\nSeccion: B";
			
			cout << "\nSemestre: " << estudiante.semestre;
		 	gotoxy(5,14);
			cout <<"----------------------------------------------------------------\n";
			gotoxy(5,15);
			cout <<"/                                                              /\n";
			gotoxy(5,16);
			cout <<"/  Utilizacion de plataforma virtual para gestionar su curso   /\n";
			gotoxy(5,17);
			cout <<"/                                                              /\n";
			gotoxy(5,18);
			cout <<"----------------------------------------------------------------\n";
			
			cout <<"1.Excelente \n";
			cout <<"2.Muy Bien \n";
			cout <<"3.Bien \n";
			cout <<"4.No Muy Bien \n";
			cin >> opc4;
			
			fichero = fopen("resultados", "a+");
			
			switch (opc4)
           		{
            case 1: 
         //  	registro.EX = registro.EX = 0;
         	encuesta.acumEX = encuesta.acumEX +1;
            encuesta.EX = encuesta.EX = 1;
            encuesta.MB = encuesta.MB = 0;
            encuesta.B = encuesta.B = 0;
            encuesta.NB = encuesta.NB = 0;
            break;

            case 2:
           // registro.MB = registro.MB = 0;
            encuesta.acumMB = encuesta.acumMB +1;
			encuesta.MB = encuesta.MB = 1;
			encuesta.EX = encuesta.EX = 0;
			encuesta.B = encuesta.B = 0;
			encuesta.NB = encuesta.NB = 0;
			break;

            case 3: 
          //  registro.B = registro.B = 0;
           encuesta.acumB = encuesta.acumB +1;
            encuesta.B = encuesta.B = 1;
			encuesta.EX = encuesta.EX = 0;
			encuesta.MB = encuesta.MB = 0;	
			encuesta.NB = encuesta.NB = 0;	
        	break;
        	
            case 4: 
           // registro.NB = registro.NB = 0;
            encuesta.acumNB = encuesta.acumNB +1;
            encuesta.NB = encuesta.NB = 1;
            encuesta.EX = encuesta.EX = 0;
            encuesta.MB = encuesta.MB = 0;
            encuesta.B = encuesta.B = 0;	
            break;
            
            default: 	
			cout <<"El valor no es valido\n";
			system("PAUSE");
			system("cls");
			Pregunta4(fichero);
			 }
			 
			fwrite(&encuesta, sizeof(struct sEncuesta), 1, fichero);
			fclose(fichero);
			
			system("cls");
		 	
		 return;
}
		 
void Pregunta5(FILE *fichero)
{
		  	int opc5;
		  	cout << "DATOS ALUMNO\n\n";
		
			cout << "Nombre Alumno: " << estudiante.nombre << " " << estudiante.apellido;
			cout << "\nCarne: " << estudiante.carne << "\n\n";
			cout << "\nSeccion: B";
			
			cout << "\nSemestre: " << estudiante.semestre;
		 	gotoxy(5,14);
			cout <<"----------------------------------------------------------------\n";
			gotoxy(5,15);
			cout <<"/                                                              /\n";
			gotoxy(5,16);
			cout <<"/ Evaluacion de actividades academicas en orden y con equidad   /\n";
			gotoxy(5,17);
			cout <<"/                                                              /\n";
			gotoxy(5,18);
			cout <<"----------------------------------------------------------------\n";
			
			cout <<"1.Excelente \n";
			cout <<"2.Muy Bien \n";
			cout <<"3.Bien \n";
			cout <<"4.No Muy Bien \n";
			cin >> opc5;
			
			fichero = fopen("resultados", "a+");
			
		switch (opc5)
           		{
            case 1: 
           // registro.EX = registro.EX = 0;
            encuesta.acumEX = encuesta.acumEX +1;
            encuesta.EX = encuesta.EX = 1;
            encuesta.MB = encuesta.MB = 0;
            encuesta.B = encuesta.B = 0;
            encuesta.NB = encuesta.NB = 0;
            break;

            case 2: 
           // registro.MB = registro.MB = 0;
            encuesta.acumNB = encuesta.acumNB +1;
			encuesta.MB = encuesta.MB = 1;
			encuesta.EX = encuesta.EX = 0;
			encuesta.B = encuesta.B = 0;
			encuesta.NB = encuesta.NB = 0;
			break;

            case 3:
          //  registro.B = registro.B = 0;
          	encuesta.acumB = encuesta.acumB +1;
            encuesta.B = encuesta.B = 1;
			encuesta.EX = encuesta.EX = 0;
			encuesta.MB = encuesta.MB = 0;	
			encuesta.NB = encuesta.NB = 0;		
        	break;
        	
            case 4: 
           // registro.NB = registro.NB = 0;
            encuesta.acumNB = encuesta.acumNB +1;
            encuesta.NB = encuesta.NB = 1;
            encuesta.EX = encuesta.EX = 0;
            encuesta.MB = encuesta.MB = 0;
            encuesta.B = encuesta.B = 0;
            break;
            
            default: 	
			cout <<"El valor no es valido\n";
			system("PAUSE");
			system("cls");
			Pregunta5(fichero);
			 }
			fwrite(&encuesta, sizeof(struct sEncuesta), 1, fichero); 
			fclose(fichero);
			
			system("cls");
			gotoxy(10,7);
			cout <<"---------Respuestas almacenadas gracias por su cooperacion--------- \n";	
			system("PAUSE");
			system("cls");
		 	
	return;
}
		 
		 

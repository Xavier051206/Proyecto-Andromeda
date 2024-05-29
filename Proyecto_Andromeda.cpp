include <iostream>
#include <vector>
#include <array>
#include <string>

using namespace std;

/*ESTRUCTURAS*/

struct Razas{
    string nombre;
    int Energia;
    int Salud; 
    string Ambiente;
    string Fidelidad;
};

struct Accesorios {
    string Nombre;
    string Tipo;
    int Valor;
    string Otro_Tipo;
    int Energia;
    int Contenedor;
};

struct Mochila {
    Accesorios Accesorio1;
    Accesorios Accesorio2;
    Accesorios Accesorio3;
    Accesorios Accesorio4;
    Accesorios Accesorio5;
};

struct Ambiente {
    string Nombre;
};


struct Jugador {
    string Nombre;
    Razas Raza;
    Mochila Accesorios;
};

/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/

int main() {
    vector<Razas> razas;
    vector<Accesorios> objetos;
    vector<Ambiente> lugares;
    vector<Jugador> Jugadores;
    vector<Mochila> mochila;
  
    
    /*RAZAS PREDETERMINADAS*/
    razas.push_back({"Andromedanos",80,100,"Andromeda","Desconocida"});
    razas.push_back({"Humano",80,100,"Tierra","Desconocida"});
    razas.push_back({"Georgianos",60,100,"Georgia","Desconocida"});

    /*OBJETOS PREDETERMINADOS*/
    objetos.push_back({"Lanza","Ataque",25,"No tiene",25,0 });
    objetos.push_back({"Pastilla anti-estres","Defensa",100,"No tiene",0,40 });
    objetos.push_back({"Botiquin","Supervivencia",60,"No tiene",0,0 });
    
    /*AMBIENTES PREDETERMINADOS*/
    lugares.push_back({"Tierra"});
    lugares.push_back({"Andromeda"});
    lugares.push_back({"Georgia"});


    mochila.push_back({objetos[0]});
    mochila.push_back({objetos[1]});
    mochila.push_back({objetos[2]});

    /*Jugadores predeterminados*/
    Jugadores.push_back({"Steve",razas[0],mochila[0]});
    Jugadores.push_back({"Alejandro",razas[1],mochila[1]});
    Jugadores.push_back({"Andres",razas[2],mochila[2]});


    /*DECLARACION DE VARIABLES*/
    string nombre_primer_personaje;
    int main = 1;
    
    //Inicio
    while(main==1) {
        
        //Menu Principal
        int opcion;
        int opciones_razas = 1;
        int opciones_accesorios = 1;
        int opciones_ambientes = 1;
        int opciones_mochila =1;
        int opciones_jugadores =1;

        cout << "INVASION EXTRATERRESTRE" << endl;
        cout << "ELABORADO POR: DIEGO MORENO, ANDRES VIERA Y XAVIER LUIS" << endl;
        cout << "╔══════════════════════════════════════╗" << endl;
        cout << "║           ** MENU PRINCIPAL **       ║" << endl;
        cout << "║                                      ║" << endl;
        cout << "║ 1. Menú de razas                     ║" << endl;
        cout << "║ 2. Menú de accesorios                ║" << endl;
        cout << "║ 3. Menú de Ambientes                 ║" << endl;
         cout <<"║ 4. Menu mochila                      ║" << endl;
        cout << "║ 5. Menu jugadores                    ║" << endl;
        cout << "║ 4. Salir                             ║" << endl;
        cout << "╚══════════════════════════════════════╝" << endl;
        cout << "¿Qué acción deseas realizar?: " << endl;
        cin>> opcion;
        
        //Selector de Opciones
        //Opcion invalida
        if((opcion=!1) or (opcion=!2) or (opcion=!3) or (opcion=!4)) {
            cout << "El número que ha seleccionado es invalido" << endl << endl;
        }
        //Opcion 1, razas
        else if(opcion==1) {
            while(opciones_razas==1) {
                int seleccionar_raza;
                cout << "Estas son las razas que participan: " << endl;
                cout << " " <<endl;

                for (int i=0; i<razas.size(); ++i) {
                    cout << i << ") " << razas[i].nombre << ", " << razas[i].Energia << ", " << razas[i].Salud << ", ";
                    cout << razas[i].Ambiente << ", " << razas[i].Fidelidad << endl;
                }
                cout << endl << endl;

                cout << "╔══════════════════════════════════════╗" << endl;
                cout << "║           ** MENU DE RAZAS **        ║" << endl;
                cout << "║                                      ║" << endl;
                cout << "║ 1. Agregar raza                      ║" << endl;
                cout << "║ 2. Elimminar raza                    ║" << endl;
                cout << "║ 3. Modificar raza                    ║" << endl;
                cout << "║ 4. Volver                            ║" << endl;
                cout << "╚══════════════════════════════════════╝" << endl;
                cout << "¿Qué acción deseas realizar?: ";
                cin>> seleccionar_raza;
                cout << endl << endl;
                
                //Seleccion de opciones en Razas
                //Seleccion 1
                if(seleccionar_raza == 1) {
                    string nuevo_nombre_raza = "";
                    int nueva_energia_raza = 0;
                    int nueva_salud_raza = 0;
                    string nuevo_ambiente_raza = "";
                    cout << "Ingresa el nombre de la raza: ";
                    cin>> nuevo_nombre_raza;
                    cout << endl << "Ingresa la energía de la raza: ";
                    cin>> nueva_energia_raza;
                    cout << endl << "Ingresa la salud de la raza: ";
                    cin>> nueva_salud_raza;
                    cout << endl << "Ingresa el ambiente de la raza: ";
                    cin>> nuevo_ambiente_raza;
                    razas.push_back({nuevo_nombre_raza, nueva_energia_raza, nueva_salud_raza, nuevo_ambiente_raza, "Desconocida"});
                }
                //Seleccion 2
                else if(seleccionar_raza == 2) {
                    int numero_eliminar_raza = 0;
                    cout << endl << "Ingresa el número de la raza que desea eliminar: ";
                    cin>> numero_eliminar_raza;
                    if(numero_eliminar_raza >= 0 and numero_eliminar_raza < razas.size()) {
                        razas.erase(razas.begin() + numero_eliminar_raza);
                        cout << "Raza eliminada exitosamente." << endl;
                    } else {
                        cout << "El número que ha colocado es invalido" << endl;
                    }
                }

                //Seleccion 3
                else if(seleccionar_raza == 3) { // opción para modificar una raza
                    int buscar_raza;
                    cout << "Ingrese el índice de la raza que desea modificar: ";
                    cin >> buscar_raza;

                    if(buscar_raza >= 0 and buscar_raza < razas.size()) { // verifica si el índice es válido
                        string nuevo_nombre_raza = "";
                        int nueva_energia_raza = 0;
                        int nueva_salud_raza = 0;
                        string nuevo_ambiente_raza = "";

                        cout << "Ingrese el nuevo nombre de la raza: ";
                        cin >> nuevo_nombre_raza;
                        cout << endl << "Ingrese la nueva energía de la raza: ";
                        cin >> nueva_energia_raza;
                        cout << endl << "Ingrese la nueva salud de la raza: ";
                        cin >> nueva_salud_raza;
                        cout << endl << "Ingrese el nuevo ambiente de la raza: ";
                        cin >> nuevo_ambiente_raza;

                        // actualiza los atributos de la raza seleccionada
                        razas[buscar_raza].nombre = nuevo_nombre_raza;
                        razas[buscar_raza].Energia = nueva_energia_raza;
                        razas[buscar_raza].Salud = nueva_salud_raza;
                        razas[buscar_raza].Ambiente = nuevo_ambiente_raza;
                    } else {
                        cout << "El número que ha seleccionado es invalido" << endl;
                    }
                }

                //Seleccion 4
                else if(seleccionar_raza == 4) {
                    cout << endl;
                    opciones_razas = 0;
                }
                //Seleccion invalida
                else {
                    cout << endl << "El número que ha seleccionado es invalido" << endl << endl;
            }
    }}
    //Opcion 2, accesorios
        else if(opcion==2) {
            while(opciones_accesorios == 1){
                int selecciones_accesorio;
                int selecciones_otro_tipo = 0;
                cout << "Estos son los accesorios disponibles" << endl;
                cout << " " << endl;
                for (int i=0; i<objetos.size(); ++i){
                    cout << i << ") " << objetos[i].Nombre << ", " << objetos[i].Tipo << ", " ;
                    cout << objetos[i].Valor << ", " << objetos[i].Otro_Tipo << ", " << objetos[i].Energia << ", " << objetos[i].Contenedor << endl;  
                }
                cout << endl << endl;
                //Menu Accesorios
                cout << "╔══════════════════════════════════════╗" << endl;
                cout << "║       ** MENU DE ACCESORIOS **       ║" << endl;
                cout << "║                                      ║" << endl;
                cout << "║ 1. Agregar Accesorio                 ║" << endl;
                cout << "║ 2. Eliminar Accesorio                ║" << endl;
                cout << "║ 3. Modificar Accesorio               ║" << endl;
                cout << "║ 4. Volver                            ║" << endl;
                cout << "╚══════════════════════════════════════╝" << endl;
                cout << "¿Qué acción deseas realizar?: ";
                cin>> selecciones_accesorio;
                cout << endl << endl;
                //Seleccion de opciones en Accesorios
                //Seleccion 1 (Agregar accesorio)
                if(selecciones_accesorio == 1) {
                    string nuevo_nombre_accesorio = "";
                    string nuevo_tipo_accesorio = "";
                    int nuevo_valor_accesorio = 0;
                    string nuevo_otro_tipo_accesorio = "";
                    int nueva_energia_accesorio = 0;
                    int nuevo_contenedor_accesorio = 0;
                    cout << "Ingrese el nombre del accesorio: ";
                    cin>> nuevo_nombre_accesorio;
                    cout << endl << "Ingrese el tipo del accesorio: ";
                    cin>> nuevo_tipo_accesorio;
                    cout << endl << "Ingrese el valor del accesorio: ";
                    cin>> nuevo_valor_accesorio;
                    cout << endl << "Ingrese la energia de su accesorio: ";
                    cin>> nueva_energia_accesorio;
                    cout << endl << "Ingresa cuanto protege el accesorio: ";
                    cin>> nuevo_contenedor_accesorio;
                    cout << endl << "¿Su accesorio hace uso de un segundo tipo?" << endl <<  "Si es de adaptación indica el ambiente que adapta y si es de supervivencia indica si restaura energía o vida.";
                    cout << endl << "1.- Si" << endl << "2.- No" << endl;
                    cin>> selecciones_accesorio;
                    if(selecciones_otro_tipo == 1) {
                        cout << endl << "ingrese el segundo tipo del accesorio: ";
                        cin >> nuevo_otro_tipo_accesorio;
                    }
                    else if(selecciones_otro_tipo == 2) {
                        nuevo_otro_tipo_accesorio = "No Tiene";
                    }
                    else {
                        cout << endl << "El número ingresado es invalido, se asignara como segundo tipo (no tiene)";
                        nuevo_otro_tipo_accesorio = "No Tiene";
                    }
                    objetos.push_back({nuevo_nombre_accesorio, nuevo_tipo_accesorio, nuevo_valor_accesorio, nuevo_otro_tipo_accesorio, nueva_energia_accesorio, nuevo_contenedor_accesorio});
                }
                //seleccion 2 (Eliminar accesorio)
                else if(selecciones_accesorio == 2){
                    int accesorio_eliminar;
                    cout << "Ingrese el numero del accesorio que desea eliminar: ";
                    cin >> accesorio_eliminar;
                    if (accesorio_eliminar >= 0 and accesorio_eliminar < objetos.size()){
                        objetos.erase(objetos.begin() + accesorio_eliminar);
                        cout << "Accesorio eliminado satisfactoriamente." << endl;
                        }
                        //Seleccion invalida
                    else {
                        cout << "El numero que ha colocado no es valido" << endl << endl;
                    }
                }
                else if(selecciones_accesorio == 3){//seleccion 3 (modificar accesorios)
                    int accesorio_modificar;
                    cout << "Ingrese el numero del accesorio que desea modificar: ";
                    cin >> accesorio_modificar;

                    if(accesorio_modificar >= 0 and accesorio_modificar < objetos.size()){
                        string nuevo_accesorio = "";
                        string tipo_accesorio = "";
                        int valor_accesorio = 0;
                        string tipo2_accesorio = "";
                        int energia_accesorio = 0;
                        int contenedor_accesorio = 0;

                        cout << "Ingrese el nuevo nombre del accesorio: ";
                        cin >> nuevo_accesorio;
                        cout << endl << "Ingrese el nuevo tipo del accesorio: ";
                        cin >> tipo_accesorio;
                        cout << endl << "Ingrese el nuevo valor del accesorio: ";
                        cin >> valor_accesorio;
                        cout << endl << "Ingrese la cantidad de energia del accesorio: ";
                        cin >> energia_accesorio;
                        cout << endl << "Ingresa cuanto protege el objetos: ";
                        cin >> contenedor_accesorio;
                        cout << endl << "Su accesorio hace uso de un segundo tipo" << endl << "Si es de adaptacion indica el ambiente que adapta y si es de supervivencia indica si restaura energia o vida.";
                        cout << endl << "1.- Si" << endl << "2.- No" << endl;
                        cin>> selecciones_accesorio;
                        
                        if(selecciones_otro_tipo == 1) {
                            cout << endl << "ingrese el segundo tipo del accesorio: ";
                            cin>> tipo2_accesorio;
                        }
                        else if(selecciones_otro_tipo == 2) {
                            tipo2_accesorio = "No Tiene";
                        }
                        else {
                            cout << endl << "El numero ingresado no es valido, se asignara como segundo tipo (no tiene)";
                            tipo2_accesorio = "No Tiene";
                        }
                        //actualiza atributos y los guarda
                        objetos[accesorio_modificar].Nombre = nuevo_accesorio;
                        objetos[accesorio_modificar].Tipo = tipo_accesorio;
                        objetos[accesorio_modificar].Valor = valor_accesorio;
                        objetos[accesorio_modificar].Otro_Tipo = tipo2_accesorio;
                        objetos[accesorio_modificar].Energia = energia_accesorio;
                        objetos[accesorio_modificar].Contenedor = contenedor_accesorio;
                    } else {//Seleccion invalida
                        cout << "El numero que ha colocado no es valido" << endl << endl;
                    }
                }
                else if(selecciones_accesorio == 4){//volver al menu
                    cout << endl;
                    opciones_accesorios = 0;
                }
                else {//Seleccion invalida
                cout << endl << "El número que ha seleccionado es invalido" << endl << endl;
                    
                }
    }}
            
    //Opcion 3 Ambiente
                
        else if(opcion == 3){
            while(opciones_ambientes ==1){
                int seleccion_ambiente;
                cout << "Estos serán los ambientes donde tendra lugar la guerra: " << endl;
                cout << " " << endl;
                for(int i = 0; i<lugares.size(); ++i) {
                    cout << i << ") " << lugares[i].Nombre << endl;
                }
                cout << endl;

                cout << "╔══════════════════════════════════════╗" << endl;
                cout << "║       ** MENU DE AMBIENTES **        ║" << endl;
                cout << "║                                      ║" << endl;
                cout << "║ 1. Agregar Ambiente                  ║" << endl;
                cout << "║ 2. Eliminar Ambiente                 ║" << endl;
                cout << "║ 3. Modificar Ambiente                ║" << endl;
                cout << "║ 4. Volver                            ║" << endl;
                cout << "╚══════════════════════════════════════╝" << endl;
                cout << "¿Qué acción deseas realizar?: ";
                cin>> seleccion_ambiente;
                cout << endl << endl;
                
                //seleccion 1: Agregar ambiente
                if(seleccion_ambiente == 1){
                string nuevo_ambiente = "";
                cout << "Ingrese el nombre del ambiente: ";
                cin>> nuevo_ambiente;
                lugares.push_back({nuevo_ambiente});
                   
                }
                //seleccion 2: Eliminar ambiente
                else if(seleccion_ambiente == 2){
                    int ambiente_eliminar;
                    cout << "Ingrese el numero del ambiente que desea eliminar: ";
                    cin >> ambiente_eliminar;
                    if (ambiente_eliminar >= 0 and ambiente_eliminar < lugares.size()){
                        lugares.erase(lugares.begin() + ambiente_eliminar);
                        cout << "Ambiente eliminado satisfactoriamente." << endl;
                        }
                        //Seleccion invalida
                    else {
                        cout << "El numero que ha colocado no es valido" << endl << endl;
                    }
                    
                }
                //seleccion 3 Modificar ambiente
                else if(seleccion_ambiente == 3){
                    int ambiente_modificar;
                    cout << "Ingrese el numero del ambiente que desea modificar: ";
                    cin >> ambiente_modificar;

                    if(ambiente_modificar >= 0 and ambiente_modificar < lugares.size()){
                        string nuevo_ambiente = "";

                        cout << "Ingrese el nuevo nombre del ambiente: ";
                        cin >> nuevo_ambiente; 
                       
                        
                        //actualiza atributos y los guarda
                        lugares[ambiente_modificar].Nombre = nuevo_ambiente;
                        }
                     
                    else {//Seleccion invalida
                        cout << "El nombre ingresado es invalido" << endl << endl;
                    }
                    
                }
            
                //Seleccion 4 Volver
                else if(seleccion_ambiente == 4) {
                    cout << endl;
                    opciones_ambientes = 0;
                }
                else {
                cout << endl << "El número seleccionado es invalido" << endl << endl;
                }


                }}

        else if(opcion== 5){
            while(opciones_jugadores==1){
                 int seleccion_jugador;
                 cout<<"Estos son los jugadores partcipantes:"<<endl;
                 for(int i =0; i<Jugadores.size(); ++i){
                    cout << i << ") " << Jugadores[i].Nombre << ", " << razas[i] << ", " << mochila[i]<<endl;
                }
                cout << "╔══════════════════════════════════════╗" << endl;
                cout << "║       ** MENU DE JUGADORES **        ║" << endl;
                cout << "║ 1. Agregar Jugador                   ║" << endl;
                cout << "║ 2. Eliminar Jugador                  ║" << endl;
                cout << "║ 3. Editar Jugador                    ║" << endl;
                cout << "║ 4. Volver                            ║" << endl;
                cout << "╚══════════════════════════════════════╝" << endl;
                cout << "¿Qué acción deseas realizar?: ";
                cin>>seleccion_jugador;
                if(opcion==1){
                    string nuevo_nombre_jugador = "";
                    vector <Nuevamochila> mo_chila ;
                    string raza ;

                }
            }
        }
        else if (opcion==4){
            while(opciones_mochila==1){\
              int seleccion_mochila_accesorio;
              cout<<"Estos seran los accesrios que podra agregar a su mochila maximo 5"<<endl;
              cout<<"                ";
              for (int i=0; i<objetos.size(); ++i){
                    cout << i << ") " << objetos[i].Nombre << ", " << objetos[i].Tipo << ", " ;
                    cout << objetos[i].Valor << ", " << objetos[i].Otro_Tipo << ", " << objetos[i].Energia << ", " << objetos[i].Contenedor << endl;  
                }
                cout << endl << endl;
                //Menu Accesorios
                cout << "╔══════════════════════════════════════╗" << endl;
                cout << "║       ** MENU DE MOCHILA **          ║" << endl;
                cout << "║ 1. Ver mochila de cada jugador       ║" << endl;
                cout << "║ 2. Volver                            ║" << endl;
                cout << "╚══════════════════════════════════════╝" << endl;
                cout << "¿Qué acción deseas realizar?: ";
                cin>> seleccion_mochila_accesorio;
                if (seleccion_mochila_accesorio==1){


                }

        
                }
        else if(opcion == 6) {
            cout << "Hasta luego";
            main = 2;
        }
        }

        
        return 0;
}

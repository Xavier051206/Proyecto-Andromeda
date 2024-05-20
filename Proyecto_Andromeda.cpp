#include <iostream>
#include <vector>
#include <array>
#include <string>

using namespace std;

struct Especies{
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
    string Tipo2;
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
    Especies Raza;
    Mochila Accesorios;
};

int main() {
    vector<Especies> razas;
    vector<Accesorios> objetos;
    vector<Ambiente> lugares;
    vector<Jugador> Jugador1;
    vector<Jugador> Jugador2;
    
    //Razas predeterminadas
    razas.push_back({"Andromedanos",80,100,"Andromeda","Desconocida"});
    razas.push_back({"Humano",80,100,"Tierra","Desconocida"});
    razas.push_back({"UCABISTA",60,100,"Universitarios","Desconocida"});

    //Objetos predeterminados
    objetos.push_back({"Pastilla anti-estres","Ataque",25,"No tiene",25,0 });
    objetos.push_back({"Escudo","Defensa",0,"No tiene",0,40 });
    objetos.push_back({"Botiquin","Supervivencia",60,"No tiene",0,0 });
    objetos.push_back({"Regulador de temperatura","Adaptación",0,"Gelidax",0,0 });
    
    //Ambientes predeterminados
    lugares.push_back({"Tierra"});
    lugares.push_back({"Andromeda"});
    lugares.push_back({"Georgia"});
    
    //Declaracion de Variables
    string nombre_primer_personaje;
    int main = 1;
    
    
    while(main==1) {
        //Inicio y Menu
        int opcion;
        int parte_razas = 1;
        int parte_accesorios = 1;
        int parte_ambiente = 1;
        cout << "ELABORADO POR: DIEGO MORENO, ANDRES VIERA Y XAVIER LUIS" << endl;
        cout << "MENU PRINCIPAL" << endl;
        cout << "1.- Menu de razas" << endl;
        cout << "2.- Menu de accesorios" << endl;
        cout << "3.- Menu de Ambientes" << endl;
        cout << "4.- Salir" << endl;
        cout << "¿Qué acción desea realizar?: ";
        cin>> opcion;
        
        //Selector de Opciones
        if((opcion<1) or (opcion>4)) {
            cout << "El número que ha seleccionado es invalido" << endl << endl;
        }
        //Seleccion 1, razas
        else if(opcion==1) {
            while(parte_razas==1) {
                int seleccion_raza;
                cout << "Estas son las razas que participan: " << endl;
                cout << " " <<endl;

                for (int i=0; i<razas.size(); ++i) {
                    cout << i << ") " << razas[i].nombre << ", " << razas[i].Energia << ", " << razas[i].Salud << ", ";
                    cout << razas[i].Ambiente << ", " << razas[i].Fidelidad << endl;
                }
                cout << endl;
                
                cout << "MENU DE RAZAS" << endl;
                cout << "1.- Agregar raza" << endl;
                cout << "2.- Eliminar raza" << endl;
                cout << "3.- Modificar raza" << endl;
                cout << "4.- Volver" << endl << endl;
                cout << "¿Qué acción quiere realizar?: ";
                cin>> seleccion_raza;
                
                //Seleccion de opciones en Razas
                //Seleccion 1
                if(seleccion_raza == 1) {
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
                else if(seleccion_raza == 2) {
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
                else if(seleccion_raza == 3) { // opción para modificar una raza
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
                else if(seleccion_raza == 4) {
                    cout << endl;
                    parte_razas = 0;
                }
                //Seleccion invalida
                else {
                    cout << endl << "El número que ha seleccionado es invalido" << endl << endl;
            }
    }}
    //Seleccion 2 accesorios
        else if(opcion==2) {
            while(parte_accesorios == 1){
                int seleccion_accesorio;
                int seleccion_tipo_2 = 0;
                cout << "Estos son los accesorios disponibles" << endl;
                cout << " " << endl;
                for (int i=0; i<objetos.size(); ++i){
                    cout << i << ") " << objetos[i].Nombre << ", " << objetos[i].Tipo << ", " ;
                    cout << objetos[i].Valor << ", " << objetos[i].Tipo2 << ", " << objetos[i].Energia << ", " << objetos[i].Contenedor << endl;  
                }
                cout << endl;
                //Menu Accesorios
                cout << "MENU DE ACCESORIO" << endl;
                cout << "1.- Agregar Accesorio" << endl;
                cout << "2.- Eliminar Accesorio" << endl;
                cout << "3.- Modificar Accesorio" << endl;
                cout << "4.- Volver" << endl << endl;
                cout << "¿Qué acción quiere realizar?: ";
                cin>> seleccion_accesorio;
                //Seleccion de opciones en Accesorios
                //Seleccion 1 (Agregar accesorio)
                if(seleccion_accesorio == 1) {
                    string nuevo_nombre_accesorio = "";
                    string nuevo_tipo_accesorio = "";
                    int nuevo_valor_accesorio = 0;
                    string nuevo_tipo2_accesorio = "";
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
                    cin>> seleccion_accesorio;
                    if(seleccion_tipo_2 == 1) {
                        cout << endl << "ingrese el segundo tipo del accesorio: ";
                        cin >> nuevo_tipo2_accesorio;
                    }
                    else if(seleccion_tipo_2 == 2) {
                        nuevo_tipo2_accesorio = "No Tiene";
                    }
                    else {
                        cout << endl << "El número ingresado es invalido, se asignara como segundo tipo (no tiene)";
                        nuevo_tipo2_accesorio = "No Tiene";
                    }
                    objetos.push_back({nuevo_nombre_accesorio, nuevo_tipo_accesorio, nuevo_valor_accesorio, nuevo_tipo2_accesorio, nueva_energia_accesorio, nuevo_contenedor_accesorio});
                }
                //seleccion 2 (Eliminar accesorio)
                else if(seleccion_accesorio == 2){
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
                else if(seleccion_accesorio == 3){//seleccion 3 (modificar accesorios)
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
                        cin>> seleccion_accesorio;
                        
                        if(seleccion_tipo_2 == 1) {
                            cout << endl << "ingrese el segundo tipo del accesorio: ";
                            cin>> tipo2_accesorio;
                        }
                        else if(seleccion_tipo_2 == 2) {
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
                        objetos[accesorio_modificar].Tipo2 = tipo2_accesorio;
                        objetos[accesorio_modificar].Energia = energia_accesorio;
                        objetos[accesorio_modificar].Contenedor = contenedor_accesorio;
                    } else {//Seleccion invalida
                        cout << "El numero que ha colocado no es valido" << endl << endl;
                    }
                }
                else if(seleccion_accesorio == 4){//volver al menu
                    cout << endl;
                    parte_accesorios = 0;
                }
                else {//Seleccion invalida
                cout << endl << "El número que ha seleccionado es invalido" << endl << endl;
                    
                }
    }}
            
    //seleccion 3 Ambiente
                
        else if(opcion == 3){
            while(parte_ambiente ==1){
                int seleccion_ambiente;
                cout << "Estos serán los ambientes donde tendra lugar la guerra: " << endl;
                cout << " " << endl;
                for(int i = 0; i<lugares.size(); ++i) {
                    cout << i << ") " << lugares[i].Nombre << endl;
                }
                cout << endl;

                cout << "MENU DE AMBIENTEs" << endl;
                cout << "1.- Agregar Ambiente" << endl;
                cout << "2.- Eliminar Ambiente" << endl;
                cout << "3.- Modificar Ambiente" << endl;
                cout << "4.- Volver" << endl << endl;
                cout << "¿Qué acción quiere realizar?: ";
                cin >> seleccion_ambiente;    
                //seleccion 1 Agregar ambiente
                if(seleccion_ambiente == 1){
                string nuevo_ambiente = "";
                cout << "Ingrese el nombre del ambiente: ";
                cin>> nuevo_ambiente;
                lugares.push_back({nuevo_ambiente});
                   
                }
                //seleccion 2 Eliminar ambiente
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
                    parte_ambiente = 0;
                }
                else {
                cout << endl << "El número seleccionado es invalido" << endl << endl;
                }


                }}
        else if(opcion == 4) {
            cout << endl << "¡Hasta Luego Baby!";
            main = 2;
        }
        }

        
        return 0;
}

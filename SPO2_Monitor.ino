//    ______________________________________________________________________________________________________  
//    |*****************************************************************************************************|
//    |########     SISTEMA DE MONITORIZACIÓN SPO2 DE PACIENTES AFECTADOS POR EL VIRUS COVID19      ########|
//    |_____________________________________________________________________________________________________| 
//    |	NOMBRE: SPO2_Monitor.ino																						|
//	  |	AUTOR: Ahicardo																						|
//    |	FECHA: 21/03/2020																					|
//    |_____________________________________________________________________________________________________| 

//###############################    DECLARACION DE LIBRERIAS    ###############################

#include <HTTPClient.h>
#include <WiFi.h>
#include "Nodo.h"


//###############################    DECLARACION DE VARIABLES, CONSTANTES GLOBALES Y OBJETOS    ###############################

const int TIEMPO_ENVIO = 4000;

const char* ssid = "WIFI_SSID";         //Datos de la red
const char* password = "WIFI_PASS";

String uWeb= "usuario";                 //Datos usuario web
String pWeb = "12345";

Nodo miNodo;

//###############################    DECLARACION DE LOS PROTOTIPOS DE LAS FUNCIONES    ###############################
void leerDatos();
void enviarDatos();
void conectarRed();


//    ______________________________________________________________________________________________________  
//    |                                              FUNCIÓN                                                |
//    |_____________________________________________________________________________________________________|
//		Nombre: void setup(void)
//		Descripción: Rutina de inicialización del microcontrolador.
//    ______________________________________________________________________________________________________ 

void setup() 
{
    Serial.begin(115200);

    conectarRed();                          //Nos conectamos a la red.
    miNodo.nodo();                          //Creamos el nodo.
}

//    ______________________________________________________________________________________________________  
//    |                                          LOOP PRINCIPAL                                             |
//    |_____________________________________________________________________________________________________|
//		Nombre: void loop()
//		Descripción: Función principal del programa.
//    ______________________________________________________________________________________________________ 
void loop() 
{
    if (WiFi.status() != WL_CONNECTED)
        conectarRed();


    leerDatos();
    enviarDatos();



    delay(TIEMPO_ENVIO);
}

//*************************************************************************************************************************************************
//*************************************************************************************************************************************************
//*************************************************************************************************************************************************

//    ______________________________________________________________________________________________________  
//    |                                              FUNCIÓN                                                |
//    |_____________________________________________________________________________________________________|
//		Nombre: void leerDatos()
//		Descripción: Lee los datos para el envío.
//    ______________________________________________________________________________________________________ 
void leerDatos()
{
    //Se leen los datos de los sensores...
    miNodo.setPulsacion(104);
    miNodo.setSpo2(97);        
    
    

}
//    ______________________________________________________________________________________________________  
//    |                                              FUNCIÓN                                                |
//    |_____________________________________________________________________________________________________|
//		Nombre: void enviarDatos()
//		Descripción: Envía los datos al servidor.
//    ______________________________________________________________________________________________________ 
void enviarDatos()
{
    if (WiFi.status() == WL_CONNECTED)
    {
        HTTPClient http;
        String datosNodo ="uWeb=" + uWeb + "&pWeb=" + pWeb + "&id=" + miNodo.getId() + "&spo2=" + miNodo.getSpo2() + "&pulsacion=" + miNodo.getPulsacion();

        http.begin("https://TuDOMINIO/registro.php");       
        http.addHeader("content-Type", "application/x-www-form-urlencoded");

        int respuesta = http.POST(datosNodo);

        if (respuesta > 0)
        {
            Serial.println("CODIGO: " + String(respuesta));

            if (respuesta == 200)
            {
                String body = http.getString();
                Serial.println("Respuesta:");
                Serial.println(body);
            }
        }
        else
        {
            Serial.print("Error en el envio POST.");
            Serial.print("CODIGO: " + String(respuesta));
        }

        http.end();

    }
    else
    {
        Serial.println("Error en la conexion WIFI");
    }
}
//    ______________________________________________________________________________________________________  
//    |                                              FUNCIÓN                                                |
//    |_____________________________________________________________________________________________________|
//		Nombre: void conectarRed()
//		Descripción: Establece la conexión con la red.
//    ______________________________________________________________________________________________________ 
void conectarRed()
{
    WiFi.mode(WIFI_STA);           
    WiFi.begin(ssid, password);

    Serial.print("Conectando WIFI");
    while (WiFi.status() != WL_CONNECTED) 
    {
        delay(1000);
        Serial.print(".");
    }

    Serial.println("");
    Serial.print("Conectado correctamente a ");
    Serial.print(ssid);
    Serial.print("IP: ");
    Serial.println(WiFi.localIP());
    Serial.print("MAC: ");
    Serial.println(WiFi.macAddress());

}


//    ______________________________________________________________________________________________________  
//    |*****************************************************************************************************|
//    |########     SISTEMA DE MONITORIZACIÓN SPO2 DE PACIENTES AFECTADOS POR EL VIRUS COVID19      ########|
//    |_____________________________________________________________________________________________________| 
//    |	NOMBRE: nodo.h																						|
//	  |	AUTOR: Ahicardo																						|
//    |	FECHA: 22/03/2020																					|
//    |_____________________________________________________________________________________________________| 

#pragma once

#ifndef _NODO_h			
#define _NODO_h			

//###############################    DECLARACION DE LIBRERIAS    ###############################
#include <WiFi.h>
#if defined(ARDUINO) && ARDUINO >= 100		//Standard Arduino por versiones
#include "arduino.h"
#else
#include "WProgram.h"
#endif

//    ______________________________________________________________________________________________________  
//    |                                              CLASE                                                  |
//    |_____________________________________________________________________________________________________|
//		Nombre: class Nodo
//		Descripción: Almacena informacion del nodo.
//    ______________________________________________________________________________________________________ 

#pragma once

class Nodo
{

private:
	String _id;						//NO ADMITE CAMBIOS - ID único del nodo.	
	uint16_t _spo2;					//Niveles SPO2 en %
	uint16_t _pulsacion;			//Valor de la frecuencia cardiaca



public:
	void nodo();
	void nodo(uint16_t spo2, uint16_t pulsacion);

	String getId();
	//void setId(String id);

	uint16_t getSpo2();
	void setSpo2(uint16_t spo2);

	uint16_t getPulsacion();
	void setPulsacion(uint16_t spo2);


};
#endif				



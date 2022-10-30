/* This code ensures that this file is included only once */
#ifndef __DATA_H
#define __DATA_H
/* If the constant DATA_H is not defined (ifndef), the code is added, otherwise,
 * this code is excluded. When the code is added, the constant is defined, 
 * therefore next time this file will be included it will be defined and no 
 * inclusion will be done. */

#include <stdbool.h>


// Uncomment once exercice 1 is completed
#define TYPEDEF_COMPLETED


#define MAX_COWORKINGCENTERS 50
#define MAX_ADDRESS 15+1
#define MAX_CITY 15+1
#define MAX_NAME 15+1
#define MAX_SURNAME 15+1
#define MAX_DOC_NUMBER 9+1
#define MAX_COWORKERS 100
#define MAX_PATHNAME 255
#define MAX_FILENAME 25
#define MAX_LINE 514
#define NO_COWORKINGCENTER -1
#define NO_COWORKER -1
#define MIN_AGE 25
#define MAX_AGE 35
#define MIN_SATISFACTION 85.0
#define MIN_BOOKINGS 10
#define AGE_INTERVAL_FIRST_LIMIT 30
#define AGE_INTERVAL_SECOND_LIMIT 45
#define AGE_INTERVAL_THIRD_LIMIT 60

/* Definition of the error type. */
typedef enum {OK=1, ERROR=0, ERR_CANNOT_READ=-1, ERR_CANNOT_WRITE=-2, 
              ERR_MEMORY=-3, ERR_DUPLICATED_ENTRY=-4, ERR_INVALID_DATA=-5, 
              ERR_ENTRY_NOT_FOUND=-6,
              ERR_NO_COWORKER=-7,ERR_NO_COWORKINGCENTER=-8,ERR_NO_FREE_GAP=-9} tError;

typedef int tCoworkingCenterId;

typedef enum { STARTUPS, FREELANCERS, RURAL, SPECIALIZED, GENERALIST } tCoworkingType; 


typedef struct {
    tCoworkingCenterId id; 
    char name[MAX_NAME]; 
    char address[MAX_ADDRESS];
    char city[MAX_CITY]; 
    int  category; 
    tCoworkingType type; 
    int numSpaces; 
    float price; 
    float distanceFromCityCenter; 
    bool hasMeetingRooms; 
    bool hasKitchen; 
    bool hasAuditorium; 
    float percentOccupation; 
} tCoworkingCenter;


typedef struct {
	tCoworkingCenter table[MAX_COWORKINGCENTERS];
	int nCoworkingCenters;
} tCoworkingCenterTable;

typedef int tCoworkerId;

typedef enum {
  SINGLE, MARRIED, SEPARATED, DIVORCED, WIDOWED
} tCivilState;

typedef enum {
  FREELANCER, TELEWORKER, ENTREPRENEUR, OCCASIONAL, EMPLOYEE, PARTNER, OTHER
} tProfessionalProfile;

typedef struct {
  int day, month, year;
} tDate;



  
typedef struct {
    tCoworkerId id;
/*************** PR1 EX1  ****************
Definición de datos: En este ejercicio se pide que complete el tipo de datos tCoworker, que está
parcialmente definido en el archivo data.h, con los campos indicados en la tabla
definida anteriormente (tabla Campos del objeto cotrabajador).
IMPORTANTE
● Dado que estamos definiendo la estructura de datos, que es la base de la práctica,
debéis empezar obligatoriamente por este ejercicio. Es importante que respetéis el
orden indicado de los campos y su nomenclatura.
Una vez hecho esto, descomentad la definición de la variable TYPEDEF_COMPLETED
que encontraréis al principio del archivo data.h antes de continuar con el resto de
ejercicios.*/

	char name[MAX_NAME];
    char surname[MAX_SURNAME];	
    char docNumber[MAX_DOC_NUMBER];	
    tDate birthDate;
    char birthCity[MAX_CITY];
    tCivilState status;
    tProfessionalProfile profile;
    int bookingsCounter;
    int points;
    float satisfaction;

/******************************************/
} tCoworker;

typedef struct {
	tCoworker table[MAX_COWORKERS];
	int nCoworkers;
} tCoworkerTable;

/* Definition of the application data structure */
typedef struct {
	/* Path where data will be stored */
	char path[MAX_PATHNAME];
	
	/* Coworking centers table */
	tCoworkingCenterTable coworkingCenters;
	
	/* Coworkers table */
	tCoworkerTable coworkers;
	
} tAppData;

#endif /*__DATA_H*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "coworker.h"


void getCoworkerStr(tCoworker coworker, int maxSize, char *str) 
{
#ifdef TYPEDEF_COMPLETED
	snprintf(str,maxSize-1,"%d %s %s %s %d %d %d %s %d %d %d %d %.2f", 
        coworker.id, coworker.name, coworker.surname, coworker.docNumber, 
        coworker.birthDate.year, coworker.birthDate.month, coworker.birthDate.day, 
        coworker.birthCity, (int)coworker.status, (int)coworker.profile, coworker.bookingsCounter,
        coworker.points, coworker.satisfaction);
#endif
}

void getCoworkerObject(const char *str, tCoworker *coworker) 
{	
#ifdef TYPEDEF_COMPLETED
    int id;
    int status, profile;
    
    id= 0;
	sscanf(str, "%d %s %s %s %d %d %d %s %d %d %d %d %f", &(id), coworker->name, coworker->surname, 
        coworker->docNumber, &(coworker->birthDate.year), &(coworker->birthDate.month), &(coworker->birthDate.day),
        coworker->birthCity, &status, &profile, &coworker->bookingsCounter, 
        &coworker->points, &coworker->satisfaction);
	coworker->status = (tCivilState)(status);
	coworker->profile = (tProfessionalProfile)(profile);
	coworker->id = (tCoworkerId)(id);
#endif
}

int dateCmp( tDate d1, tDate d2 ) {
    
    int result;

    result= 0;
    if (d1.year > d2.year)
        result= 1;
    else if (d1.year < d2.year)
        result= -1;
    else {
        if (d1.month > d2.month)
            result= 1;
        else if (d1.month < d2.month)
            result= -1;
        else {
            if (d1.day > d2.day)
                result= 1;
            else if (d1.day < d2.day)
                result= -1;
        }
    }
    
    return result;
}


void coworkerTableInit(tCoworkerTable *coworkerTable) {
	
	coworkerTable->nCoworkers=0;
}

void convertToUpper( char *string )
{
    int i, len;
    char originalChar;
    
    len= strlen(string);
    for (i= 0; i < len; i++) {
        originalChar= string[i];
        if (originalChar >= 'a' && originalChar <= 'z') 
            string[i]= originalChar + 'A' - 'a';
    }
}

int strcmpUpper( char *s1, char *s2 )
{
    int result;
    result= 0;
/*************** PR1 EX3A *****************
Completad, en el archivo coworker.c, la funci??n strcmpUpper que
compara dos strings (s1 y s2) pasados por par??metro pas??ndolos,
previamente, a may??sculas. La funci??n no debe alterar los ajustes de entrada.
Para ello, ser?? necesario declarar variables locales de tipo string, copiar el
contenido de los par??metros de entrada, transformar a may??sculas y,
finalmente, comparar los strings resultantes. 

La funci??n deber?? devolver: -1 si s1<s2 0 si s1=s2 1 si s1>s2
 
Nota: Os pod??is apoyar en el m??todo strcmp de la librer??a string.h tambi??n en
la funci??n convertToUpper que encontrar?? en coworker.c. */
	
	char string1[MAX_LINE];
    char string2[MAX_LINE];
    
    strcpy( string1, s1 );
    strcpy( string2, s2 );
    convertToUpper( string1 );
    convertToUpper( string2 );
   
    result= strcmp(string1,string2);


/******************************************/
    return result;
}

int coworkerCmp(tCoworker d1, tCoworker d2) {
	
	int result = 0;

/*************** PR1 EX3B ****************
 
Completad, en el fichero coworker.c, la funci??n customer_cmp que
dados dos clientes c1 y c2, nos devuelve:
-1 si c1<c2 0 si c1=c2 1 si c1>c2
El orden de los clientes vendr?? dado por el valor de sus campos con la
prioridad:
1. Nombre (ascendente)
2. Apellido (ascendente)
3. N??mero de documento (ascendente)
4. Fecha de nacimiento (ascendente)
5. Ciudad de nacimiento (ascendente)
6. Estado civil (ascendente)
7. Perfil (ascendente)
8. Contador de reservas (ascendente)
9. Puntos acumulados (ascendente)
10. Satisfacci??n (ascendente)
Esto quiere decir, que si el nombre de d1 es ???Gerard??? y el de d2 ???Manel",
consideraremos que d1<d2. En caso de que sean iguales, se comprobar?? el apellido
para desempatar.
Si tambi??n son iguales, habr?? que comprobar el n??mero de documento, y as??
sucesivamente... Si todos los datos son iguales, indicar?? que d1=d2.*/
    
	result= strcmpUpper(d1.name,d2.name);
    if (result==0)
    {
        result= strcmpUpper(d1.surname,d2.surname);
        if (result==0)
        {
            result= strcmpUpper(d1.docNumber,d2.docNumber);
            if (result==0)
            {
                result= dateCmp(d1.birthDate, d2.birthDate);
                if (result==0)
                {
                    result= strcmpUpper(d1.birthCity, d2.birthCity);
                    if (result==0)
                    {
                        if (d1.status > d2.status)
                            result = 1;
                        else if (d1.status < d2.status)
                            result = -1;
                        else{
                            if (d1.profile > d2.profile)
                                result = 1;
                            else if (d1.profile < d2.profile)
                                result = -1;
                            else{
                                if (d1.bookingsCounter > d2.bookingsCounter)
                                    result = 1;
                                else if (d1.bookingsCounter < d2.bookingsCounter)
                                    result = -1;
                                else {
                                    if (d1.points > d2.points)
                                        result = 1;
                                    else if (d1.points < d2.points)
                                        result = -1;
                                    else {
                                        if (d1.satisfaction > d2.satisfaction)
                                            result = 1;
                                        else if (d1.satisfaction < d2.satisfaction)
                                            result = -1;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }


/******************************************/

    return result;
}

void coworkerCpy(tCoworker *dst, tCoworker src) 
{    
#ifdef TYPEDEF_COMPLETED
    dst->id = src.id; 
    strcpy(dst->name,src.name);
    strcpy(dst->surname,src.surname);
    strcpy(dst->docNumber,src.docNumber);
    dst->birthDate.year = src.birthDate.year;
    dst->birthDate.month = src.birthDate.month;
    dst->birthDate.day = src.birthDate.day;
    strcpy(dst->birthCity,src.birthCity);
    dst->status = src.status;
    dst->profile = src.profile;    
    dst->bookingsCounter = src.bookingsCounter;
    dst->points= src.points;
    dst->satisfaction= src.satisfaction;
#endif
}

void coworkerTableAdd(tCoworkerTable *tabCoworker, tCoworker coworker, tError *retVal) {

	*retVal = OK;

	/* Check if there enough space for the new coworker */
	if(tabCoworker->nCoworkers>=MAX_COWORKERS)
		*retVal = ERR_MEMORY;

	if (*retVal == OK) {
		/* Add the new coworker to the end of the table */
		coworkerCpy(&tabCoworker->table[tabCoworker->nCoworkers],coworker);
		tabCoworker->nCoworkers++;
	}

}

int coworkerTableFind(tCoworkerTable tabCoworker, tCoworkerId id) {

	int i, idx;
    
    i= 0;
    idx= NO_COWORKER;
	while(i< tabCoworker.nCoworkers && idx==NO_COWORKER) {
		/* Check if the id is the same */
		if(tabCoworker.table[i].id==id) {
			idx = i;
		}
		i++;
	}
	
	return idx;
}

void coworkerTableDel(tCoworkerTable *tabCoworker, tCoworker coworker) 
{	
/*************** PR1 EX7 ****************
Se pide que implement??is la acci??n coworkerTableDel del archivo coworker.c, que
dada una tabla de cotrabajadores y un cotrabajador, borra de la tabla el cotrabajador
pasado por par??metro.
Tened presente que el borrado del cotrabajador no debe dejar ninguna posici??n
inv??lida en la tabla. Por tanto, ser?? necesario que ocup??is el espacio liberado por el
cotrabajador desplazando una posici??n atr??s todos los cotrabajadores que hab??a
despu??s del cotrabajador borrado.
Nota: Para facilitar la soluci??n, utilizad la funci??n coworkerTableFind de coworker.c
para localizar el ??ndice del trabajador a borrar.
*/
	
	int i;
    int pos;

    pos = coworkerTableFind(*tabCoworker,coworker.id);
    if (pos!=NO_COWORKER)
    {
        for(i=pos; i<tabCoworker->nCoworkers-1; i++) {		
            coworkerCpy(&tabCoworker->table[i],tabCoworker->table[i+1]);
        }
        tabCoworker->nCoworkers=tabCoworker->nCoworkers-1;		
    }

/******************************************/
}

void coworkerTableSave(tCoworkerTable tabCoworker, const char* filename, tError *retVal) {
	
	FILE *fout;
	int i;
	char str[MAX_LINE];
	*retVal = OK;
	
	/* Open the output file */
	if((fout=fopen(filename, "w"))==0) {
		*retVal = ERR_CANNOT_WRITE;
	} else {
	
        /* Save all coworkers to the file */
        for(i=0;i<tabCoworker.nCoworkers;i++) {
            getCoworkerStr(tabCoworker.table[i], MAX_LINE, str);
            fprintf(fout, "%s\n", str);
        }
            
        /* Close the file */
        fclose(fout);
	}
}

void coworkerTableLoad(tCoworkerTable *tabCoworker, const char* filename, tError *retVal) {
		
	FILE *fin;
	char line[MAX_LINE];
	tCoworker newCoworker;

	*retVal = OK;

	/* Initialize the output table */
	coworkerTableInit(tabCoworker);
	
	/* Open the input file */
	if((fin=fopen(filename, "r"))!=NULL) {

		/* Read all the lines */
		while(!feof(fin) && tabCoworker->nCoworkers<MAX_COWORKERS) {
			/* Remove any content from the line */
			line[0] = '\0';
			/* Read one line (maximum 511 chars) and store it in "line" variable */
			fgets(line, MAX_LINE-1, fin);
			/* Ensure that the string is ended by 0*/
			line[MAX_LINE-1]='\0';
			if(strlen(line)>0) {
				/* Obtain the object */
				getCoworkerObject(line, &newCoworker);
				/* Add the new coworker to the output table */
				coworkerTableAdd(tabCoworker, newCoworker, retVal);		
			}
		}
		/* Close the file */
		fclose(fin);
		
	}else {
		*retVal = ERR_CANNOT_READ;
	}
}

int calculateAge( tDate birthDate )
{
   return 2020 - birthDate.year;
}

void coworkerTableSelectCoworkers(tCoworkerTable coworkers, char *city, tCoworkerTable *result) 
{
/*************** PR1 EX4A ****************
 Filtros basados en expresiones: Completad la acci??n coworkerTableSelectCoworkers en el fichero
coworker.c que, dada una mesa de cotrabajadores y una ciudad, seleccione a
aquellos cotrabajadores susceptibles de escoger centros de cotrabajo de tipo
urbano en esta ciudad. Desde el departamento de marketing de UOCowork se
ha determinado que los cotrabajadores objetivo de este tipo de centros son, en
su mayor??a, los que tienen una edad comprendida entre 25 y 35 a??os (ambos
incluidos), que est??n en estado SINGLE y que tienen un perfil de tipo
OCCASIONAL, EMPLOYEE o PARTNER. Se excluir??n los cotrabajadores que
hayan nacido en la ciudad pasada por par??metro.
Nota: Necesitar??is utilizar la funci??n auxiliar calculateAge de coworker.c que,
a partir de una fecha de nacimiento, calcula la edad respecto a una fecha
???actual??? (que estableceremos en el d??a 31 de diciembre de 2020)*/

    int i, age;
    tError retVal;
    tCivilState status;
    tProfessionalProfile profile;
    
	coworkerTableInit(result);
	for(i=0;i<coworkers.nCoworkers;i++) {
		if (strcmp(city, coworkers.table[i].birthCity)!=0){
            age= calculateAge(coworkers.table[i].birthDate);
            status= coworkers.table[i].status;
            profile= coworkers.table[i].profile;
            if (age >= 25 && age <= 35 && status == SINGLE && 
                (profile == ENTREPRENEUR || profile == OCCASIONAL || profile == EMPLOYEE))
                coworkerTableAdd(result, coworkers.table[i], &retVal);
		}
	}

/******************************************/
}

void coworkerTableSelectSatisfiedCoworkers(tCoworkerTable coworkers, tCoworkerTable *result) {

/*************** PR1 EX4B ****************

Completad la acci??n coworkerTableSelectSatisfiedCoworkers en el
archivo coworker.c que permite seleccionar a aquellos cotrabajadores con un
??ndice de satisfacci??n superior al 85%. S??lo se tendr??n en cuenta aquellos
cotrabajadores que hayan realizado un n??mero significativo de reservas
(estableceremos este umbral en un m??nimo de 10 reservas).
NOTA: Revisad las constantes de data.h y localizad aquellas que puedan serviros para
resolver este ejercicio.*/

    int i;
    tError retVal;
    
	coworkerTableInit(result);
	for(i=0;i<coworkers.nCoworkers;i++) {
		if (coworkers.table[i].satisfaction > 85.0 && coworkers.table[i].bookingsCounter >= 10) {
			coworkerTableAdd(result, coworkers.table[i], &retVal);
		}
	}

/******************************************/
}

float coworkerTableGetAvgPointsPerBooking(tCoworkerTable tabCoworker) 
{
    float avg= 0.0;
/*************** PR1 EX6A ****************
C??lculos estad??sticos: La funci??n coworkerTableGetAvgPointsPerBooking
Que, dada una tabla de cotrabajadores calcule el n??mero de puntos promedio
que un cotrabajador consigue en cada reserva. Para ello, acumulad el n??mero
de reservas totales y el n??mero de puntos totales antes de realizar el c??lculo.
*/

    int i, accPoints, accBookings;

    accPoints= 0;
    accBookings= 0;
	for(i=0;i<tabCoworker.nCoworkers;i++) {
        accPoints += tabCoworker.table[i].points;
        accBookings += tabCoworker.table[i].bookingsCounter;        
	}
    if (accBookings > 0)
        avg= (float)(accPoints) / (float)(accBookings);




/******************************************/
    return avg;
}

void coworkerTableGetMaxSatisfactionPerAgeInterval(tCoworkerTable tabCoworker,
     float *upto29, float *between30and44, float *between45and59, float *from60) 
{
/*************** PR1 EX6B ****************
La acci??n coworkerTableGetMaxSatisfactionPerAgeInterval
Que, dada una tabla de cotrabajadores, calcule la satisfacci??n m??xima para los
siguientes intervalos de edad: menos de 30 a??os, entre 30 y 44, entre 45 y 59 y
60 a??os o m??s. Devolved la informaci??n mediante par??metros de salida. Si,
para una determinada franja de edad, no hay datos que permitan realizar el
c??lculo, devolved un valor cero.
NOTA: Revise las constantes de data.h y localizad aquellas que puedan serviros para
resolver este ejercicio.
*/
     int i, age;
    *upto29= 0;
    *between30and44= 0;
    *between45and59= 0;
    *from60= 0;

	for(i=0;i<tabCoworker.nCoworkers;i++) {
        age= calculateAge(tabCoworker.table[i].birthDate);
        if (age <= 29) {
            if (tabCoworker.table[i].satisfaction > *upto29)
                *upto29= tabCoworker.table[i].satisfaction;
        } 
        else if (age <= 44) {
            if (tabCoworker.table[i].satisfaction > *between30and44)
                *between30and44= tabCoworker.table[i].satisfaction;      
        }
        else if (age <= 59) {
            if (tabCoworker.table[i].satisfaction > *between45and59)
                *between45and59= tabCoworker.table[i].satisfaction;      
        }
        else {
            if (tabCoworker.table[i].satisfaction > *from60)
                *from60= tabCoworker.table[i].satisfaction;
        }
	}


/******************************************/
}





























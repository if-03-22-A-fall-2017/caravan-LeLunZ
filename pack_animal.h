/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: <your class name here>
 * ---------------------------------------------------------
 * Exercise Number: 0
 * File:			pack_animal.h
 * Author:			Peter Bauer
 * Due Date:		#due#
 * ----------------------------------------------------------
 * Description:
 * <Add description>
 * ----------------------------------------------------------
 */
#ifndef PACK_ANIMAL_H
#define PACK_ANIMAL_H

#include <stdlib.h>
typedef struct CaravanImplementation* Caravan;

typedef enum {Camel, Horse} AnimalType;

typedef struct PackAnimalImplementation* PackAnimal;

/**
* Erzeugt ein Kamel
* @param name Name des Kamels
* @param max_speed Maximale Reisegeschwindigkeit des Kamels
* @return PackAnimal Das erzeugte Kamel.
*/
PackAnimal new_camel(const char *name, int max_speed);

/**
* Erzeugt Pferd
* @param name Name des Pferds
* @param max_speed Maximale Reisegeschwindigkeit des Pferds
* @return PackAnimal Das erzeugte Pferd.
*/
PackAnimal new_horse(const char *name, int max_speed);

/**
* @param animal The animal which max speed to be returned
* @return The max speed of an animal
*/
int get_max_speed(PackAnimal animal);

/**
* @param animal The animal which load to be returned
* @return The load of an animal
*/
int get_load(PackAnimal animal);

/**
* @param animal The animal which caravan to be returned
* @return The caravan of an animal
*/
Caravan get_caravan(PackAnimal animal);

/**
* Deletes a pack animal.
* @param animal Pack animal to be deleted.
*/
void delete_animal(PackAnimal animal);

/**
* Gibt Last auf ein Packtier.
* @param animal Tier, das die Last aufgeladen bekommt.
* @param load Gewicht der Last.
*/
void add_load(PackAnimal animal, int load);

/**
* Entlädt ein Lasttier vollständig. Nach unload() hat
* das Packtier keine Last mehr aufgeladen.
*/
void unload(PackAnimal animal);

/**
* Gibt die tatsöchliche Geschwindigkeit eines Packtiers zurück. Die aktuelle
* Geschwindigkeit hängt ab von der Höchstgeschwindigkeit eines Tiers und von
* der Menge der Last, die dem Tier aufgeladen wurde.
* - Kamele verlieren pro aufgeladener Last 1 km/h Geschwindigkeit.
* - Pferde verlieren pro aufgeladener Last 10 km/h Geschwindigkeit.
* @return Die tatsächliche Geschwindigkeit eines Packtiers.
*/
int get_actual_speed(PackAnimal animal);

/**
* @return Die erwartete Geschwindigkeit eines Packtiers, wenn eine bestimmte
* Last dazugegeben werden würde.
* @param animal Das Tier, dessen erwartete Geschwindigkeit getestet wird.
* @param add_load Die Anzahl der Ballen, welche dazugeben werden würden.
* @return Die Geschwindigkeit des Tiers, die zu erwarten wäre, wenn die
* angegebenen Ballen zusätzlich aufgeladen wreden würden.
* @note Ein negativer Wert von add_load simuliert, dass Ballen weggenommen
* werden würden.
*/
int get_expected_speed(PackAnimal animal, int additional_load);

void add_to_caravan(PackAnimal animal, Caravan caravan);

void remove_from_caravan(PackAnimal animal, Caravan caravan);

#endif

/*
 * Crocodile.cpp
 *
 *  Created on: Aug 10, 2020
 *      Author: 1691193_snhu
 */

#include "Crocodile.h"

namespace std {

//constructor which inherits from Animal & Oviparous classes
//assigns the passed in values to those inherited variables
Crocodile::Crocodile(int trackNum, string animalName, string type, string animalSubType, int eggs, int nurse) {

	this -> trackNum = trackNum;
	this -> animalName = animalName;
	this -> type = type;
	this -> animalSubType = animalSubType;
	this -> numberOfEggs = eggs;
	this -> nurse = nurse;

}

Crocodile::~Crocodile() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */

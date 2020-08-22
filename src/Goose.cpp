/*
 * Goose.cpp
 *
 *  Created on: Aug 10, 2020
 *      Author: 1691193_snhu
 */

#include "Goose.h"

namespace std {

//constructor which inherits from Animal & Oviparous classes
//assigns the passed in values to those inherited variables
Goose::Goose(int trackNum, string animalName, string type, string animalSubType, int eggs, int nurse) {

	this -> trackNum = trackNum;
	this -> animalName = animalName;
	this -> type = type;
	this -> animalSubType = animalSubType;
	this -> numberOfEggs = eggs;
	this -> nurse = nurse;


}

Goose::~Goose() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */

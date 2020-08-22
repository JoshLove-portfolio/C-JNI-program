/*
 * Whale.cpp
 *
 *  Created on: Aug 4, 2020
 *      Author: 1691193_snhu
 */

#include "Whale.h"

namespace std {

//constructor which inherits from Animal & Mammal classes
//assigns the passed in values to those inherited variables
Whale::Whale(int trackNum, string animalName, string type, string animalSubType, int eggs, int nurse) {

	this -> trackNum = trackNum;
	this -> animalName = animalName;
	this -> type = type;
	this -> animalSubType = animalSubType;
	this -> nurse = nurse;
	this -> numberOfEggs = eggs;

}

Whale::~Whale() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */

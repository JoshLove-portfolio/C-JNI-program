/*
 * Crocodile.h
 *
 *  Created on: Aug 10, 2020
 *      Author: 1691193_snhu
 */

#ifndef CROCODILE_H_
#define CROCODILE_H
#include "Oviparous.h"
#include <string>

namespace std {

class Crocodile : public Oviparous { //inherits from Oviparous class

public:
	Crocodile(int trackNum, string animalName, string type, string animalSubType, int eggs, int nurse);
	virtual ~Crocodile();

	//overrides Animal virtual function to return the subType
	string getSubType() const {return "Crocodile";} ;

};

} /* namespace std */

#endif /* CROCODILE_H_ */

/*
 * Goose.h
 *
 *  Created on: Aug 10, 2020
 *      Author: 1691193_snhu
 */

#ifndef GOOSE_H_
#define GOOSE_H_
#include "Oviparous.h"
#include <string>

namespace std {

class Goose : public Oviparous { //inherits from Oviparous class

public:
	Goose(int trackNum, string animalName, string type, string animalSubType, int eggs, int nurse);
	virtual ~Goose();

	//overrides Animal virtual function to return the subType
	string getSubType() const {return "Goose";} ;


};

} /* namespace std */

#endif /* GOOSE_H_ */

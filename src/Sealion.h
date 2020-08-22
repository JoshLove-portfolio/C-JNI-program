/*
 * Sealion.h
 *
 *  Created on: Aug 4, 2020
 *      Author: 1691193_snhu
 */

#ifndef SEALION_H_
#define SEALION_H_
#include "Mammal.h"
#include <string>

namespace std {

class Sealion : public Mammal { //inherits from Mammal class
public:
	Sealion(int trackNum, string animalName, string type, string animalSubType, int eggs, int nurse);
	virtual ~Sealion();

	//overrides Animal virtual function to return the subType
	string getSubType() const {return "Sealion";} ;

};

} /* namespace std */

#endif /* SEALION_H_ */

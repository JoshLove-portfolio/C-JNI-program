/*
 * Whale.h
 *
 *  Created on: Aug 4, 2020
 *      Author: 1691193_snhu
 */

#ifndef WHALE_H_
#define WHALE_H_
#include "Mammal.h"
#include <string>

namespace std {

class Whale : public Mammal { //inherits from Mammal class
public:
	Whale(int trackNum, string animalName, string type, string animalSubType, int eggs, int nurse);
	virtual ~Whale();

	//overrides Animal virtual function to return the subType
	string getSubType() const {return "Whale";} ;

};

} /* namespace std */

#endif /* WHALE_H_ */

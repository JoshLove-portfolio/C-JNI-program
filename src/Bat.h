/*
 * Bat.h
 *
 *  Created on: Aug 4, 2020
 *      Author: 1691193_snhu
 */

#ifndef BAT_H_
#define BAT_H_
#include "Mammal.h"
#include <string>

namespace std {

class Bat : public Mammal { //inherits from Mammal class
public:
	Bat(int trackNum, string animalName, string type, string animalSubType, int eggs, int nurse);
	virtual ~Bat();

	//overrides Animal virtual function to return the subType
	string getSubType() const {return "Bat";} ;

};

} /* namespace std */

#endif /* BAT_H_ */

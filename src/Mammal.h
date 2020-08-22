/*
 * Mammal.h
 *
 *  Created on: Aug 4, 2020
 *      Author: 1691193_snhu
 */

#ifndef MAMMAL_H_
#define MAMMAL_H_
#include "Animal.h"

namespace std {

class Mammal : public Animal { //inherits attributes from the animal class
public:
	Mammal();
	virtual ~Mammal();

	//overrides virtual function from Animal class to return the type
	string getType() const {return "Mammal"; };

	//overrides virtual function from the Animal class to return if it's nursing
	int getNurse() const {return nurse; };

	//overrides virtual function from Animal class to return eggs (always 0 for mammals)
	int getNumberOfEggs() const {return numberOfEggs; };

};

} /* namespace std */

#endif /* MAMMAL_H_ */

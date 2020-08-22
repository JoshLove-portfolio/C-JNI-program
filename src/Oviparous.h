/*
 * Oviparous.h
 *
 *  Created on: Aug 10, 2020
 *      Author: 1691193_snhu
 */

#ifndef OVIPAROUS_H_
#define OVIPAROUS_H_
#include "Animal.h"

namespace std {

class Oviparous : public Animal { //inherits from Animal class

public:
	Oviparous();
	virtual ~Oviparous();

	//override virtual function from Animal class to return type
	string getType() const {return "Oviparous"; };

	//override virtual function from Animal class to return number of eggs
	int getNumberOfEggs() const {return numberOfEggs; };

	//override virtual function from Animal class to return if nursing (always 0 for oviparious)
	int getNurse() const {return nurse; };

};

} /* namespace std */

#endif /* OVIPAROUS_H_ */

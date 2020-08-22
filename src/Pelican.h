/*
 * Pelican.h
 *
 *  Created on: Aug 10, 2020
 *      Author: 1691193_snhu
 */

#ifndef PELICAN_H_
#define PELICAN_H_
#include "Oviparous.h"
#include <string>

namespace std {

class Pelican : public Oviparous { //inherits from Oviparous class

public:
	Pelican(int trackNum, string animalName, string type, string animalSubType, int eggs, int nurse);
	virtual ~Pelican();

	//overrides Animal virtual function to return the subType
	string getSubType() const {return "Pelican";} ;

};

} /* namespace std */

#endif /* PELICAN_H_ */

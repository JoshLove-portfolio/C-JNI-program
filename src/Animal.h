/*
 * Animal.h
 *
 *  Created on: Aug 4, 2020
 *      Author: 1691193_snhu
 */

#ifndef ANIMAL_H_
#define ANIMAL_H_
#include <string>

namespace std {

class Animal {
public:
	Animal();
	virtual ~Animal();

	//virtual (to be overridden) function to retrieve numberOfEggs
	virtual int getNumberOfEggs() const {return numberOfEggs; };
	//virtual function to retrieve if the animal is nursing
	virtual int getNurse() const {return nurse; };
	//virtual function to get the type
	virtual string getType() const {return type; };
	//virtual function to get the subType
	virtual string getSubType() const {return animalSubType; };

	//getter method for the name of the animal object
	string getName() const {return animalName; };
	//getter method for the track ID number of the animal object
	int getTrackNum() const {return trackNum; };

	//start variables
	string animalName;
	int trackNum;
	int numberOfEggs;
	int nurse;
	string type;
	string animalSubType;
	int noApply = 0; //end variables

};

} /* namespace std */

#endif /* ANIMAL_H_ */

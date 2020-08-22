#include <iostream>
#include <iomanip>
#include <fstream>
#include <jni.h>
#include <stdlib.h>
#include <stdexcept>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include "Windows.h"
#include "bat.h"
#include "Sealion.h"
#include "Whale.h"
#include "Goose.h"
#include "Crocodile.h"
#include "Pelican.h"
using namespace std;

/*
 * GenerateData() function does not work correctly. Even on entering 'Y' or 'y'
 * When prompted to continue, it still only takes on entry and creates the file.
 * For testing purposes of this project, I created a seperate zoodata_test.txt
 * Which has 6 entries already built in
 * To demonstrate the completion of this program, zoodata_test.txt has been included
 * In this .zip file. To utilize, point the LoadDataFromFile() & SaveDataFromFile()
 * Fstreams to the zoodata_test.txt
 */
void GenerateData()               //DO NOT TOUCH CODE IN THIS METHOD
{
     JavaVM *jvm;                      // Pointer to the JVM (Java Virtual Machine)
     JNIEnv *env;                      // Pointer to native interface
                                                              //================== prepare loading of Java VM ============================
     JavaVMInitArgs vm_args;                        // Initialization arguments
     JavaVMOption* options = new JavaVMOption[1];   // JVM invocation options
     options[0].optionString = (char*) "-Djava.class.path=";   // where to find java .class
     vm_args.version = JNI_VERSION_1_6;             // minimum Java version
     vm_args.nOptions = 1;                          // number of options
     vm_args.options = options;
     vm_args.ignoreUnrecognized = false;     // invalid options make the JVM init fail
                                                                          //=============== load and initialize Java VM and JNI interface =============
     jint rc = JNI_CreateJavaVM(&jvm, (void**)&env, &vm_args);  // YES !!
     delete options;    // we then no longer need the initialisation options.
     if (rc != JNI_OK) {
            // TO DO: error processing...
            cin.get();
            exit(EXIT_FAILURE);
     }
     //=============== Display JVM version =======================================
     cout << "JVM load succeeded: Version ";
     jint ver = env->GetVersion();
     cout << ((ver >> 16) & 0x0f) << "." << (ver & 0x0f) << endl;

     jclass cls2 = env->FindClass("ZooFileWriter");  // try to find the class
     if (cls2 == nullptr) {
            cerr << "ERROR: class not found !";
     }
     else {                                  // if class found, continue
            cout << "Class MyTest found" << endl;
            jmethodID mid = env->GetStaticMethodID(cls2, "createZooFile", "()V");  // find method
            if (mid == nullptr)
                   cerr << "ERROR: method void createZooFile() not found !" << endl;
            else {
                   env->CallStaticVoidMethod(cls2, mid);                      // call method
                   cout << endl;
            }
     }


     jvm->DestroyJavaVM();
     cin.get();
}

void AddAnimal(vector <Animal> &animals) //pass in animals vector by reference
{
	int trackNum; //start variable declarations
	string animalName;
	string type;
	string subType;
	int eggs;
	int nurse;
	char userChoice; //end variable declarations

	cout << "Adding a new animal- " << endl;

	while (true){ //while loop to allow for errors
		try { //start try/catch block
			/*
			 * Each input entry below utilizes the cin.ignore() function to disregard input
			 * which is beyond the set limits, i.e if the name is >15
			 * the cin.ignore() removes anything beyond the 15
			 */
			cout << "Track ID: " << endl;
			cin >> setw(7) >> trackNum;
			cin.ignore(1000, '\n');

			cout << "Animal name: " << endl;
			cin >> setw(15) >> animalName;
			cin.ignore(1000, '\n');

			cout << "Animal type: " << endl;
			cin >> setw(15) >> type;
			cin.ignore(1000, '\n');
				//Error checking for animal type, must be mammal or oviparous
				if (type != "Mammal" && type != "mammal" && type != "Oviparous" && type != "oviparous"){
					throw "Error. Please select either mammal or oviparous.";
				}

			cout << "Animal sub-type: " << endl;
			cin >> setw(15) >> subType;
			cin.ignore(1000, '\n');
				/*
				 * Hard-coded error checking. Tried to make a string vector for types however couldn't find a solution
				 * to search for a specific string. any_of uses an int predicate which wouldn't work for this.
				 */
				if (subType != "Bat" && subType != "bat" && subType != "Crocodile" && subType != "crocodile"
						&& subType != "Goose" && subType != "goose" && subType != "Pelican" && subType != "pelican"
						&& subType != "Sealion" && subType != "sealion" && subType != "Whale" && subType != "whale"){
					throw "Error. Please enter one of the appropriate sub-types (bat, crocodile, goose, pelican, sealion, whale).";
				}

			//since numberOfEggs and nurse are an ints, no need to use cin.ignore()
			cout << "Number of eggs:" << endl;
			cin >> eggs;

			cout << "Nursing? 1 if yes, 0 if no" << endl;
			cin >> nurse;

			break; //leave the loop since if this is reached, no errors were thrown

		} catch (const char* error){ //catch for errors thrown on types
			cerr << error << endl;
			Sleep(1000); //allow time for the user to read the error
			continue; //reloop to allow for the user to try again
		}
	}

	//allowing the user to decide if they wish to enter the record or not
	cout << "Are you sure you wish to enter this record? y/n" << endl;
	cout << "selecting 'n' will return you to the main menu" << endl;
	cin >> userChoice;

	if (userChoice == 'n' || userChoice == 'N'){ //checking if the user doesn't want to enter the record

		cout << endl;
		return; //leaves the function if they don't want to enter the recordv

	}

	try{ //start try/catch block

		/*
		 * Below is an inclusive conditional to allow for unnamed objects to be entered
		 * into the vector. This program went with no names since it's not required.
		 * There must be a unique identifier to link the entries in this function
		 * to the right class for object creation. The unique identifier is the subType field
		 */

		if (subType == "bat" || subType == "Bat"){

			animals.push_back(Bat(trackNum, animalName, type, subType, eggs, nurse));

		} else if (subType == "sealion" || subType == "Sealion"){

			animals.push_back(Sealion(trackNum, animalName, type, subType, eggs, nurse));

		} else if (subType == "whale" || subType == "Whale"){

			animals.push_back(Whale(trackNum, animalName, type, subType, eggs, nurse));

		} else if (subType == "pelican" || subType == "Pelican"){

			animals.push_back(Pelican(trackNum, animalName, type, subType, eggs, nurse));

		} else if (subType == "goose" || subType == "Goose"){

			animals.push_back(Goose(trackNum, animalName, type, subType, eggs, nurse));

		} else if (subType == "crocodile" || subType == "Crocodile"){

			animals.push_back(Crocodile(trackNum, animalName, type, subType, eggs, nurse));

		} else { //if none of the conditionals above are taken, throw an error

			throw "Error reading animal sub-type";
		}

	} catch (const char* error){ //catch and output error

		cerr << error << endl;

	}

	cout << "Record added successfully." << endl;
	cout << endl;

}


void RemoveAnimal(vector <Animal> &animals) //pass in animals vector by reference
{
	int removalID; //int to capture which ID the user wants to remove
	int beginSize = animals.size(); //check the current size of the animal vector
	char choice;

     cout << "Remove an animal record -" << endl;


     while (true){ //loop to allow for error catching

         cout << "Enter the TrackID of the animal you wish to delete" << endl;
         cin >> removalID;

         //for loop to run through each object in the animals vector
    	 for (unsigned int i = 0; i < animals.size(); i++){

    		 //conditional to check each animal object trackNum versus the user selected removal
    		 if (removalID == animals[i].getTrackNum()){
    			 //conditional found a match to current (i) object
    			 animals.erase(animals.begin() + i); //erases the current (i) object

    		 }

    	 }

    	 int newSize = animals.size(); //gets the new size of the vector after erasing

    	 if (beginSize == newSize){ //checks if an entry was deleted
    		 /*
    		  * If this conditional is taken, no entry was deleted in vector
    		  * This is due to the size being the same before and after the loop
    		  * This conditional then asks the user if they want to try again
    		  * Breaks if they don't want to or continues if they do
    		  */
    		 cerr << "Error. TrackID didn't match any existing entries" << endl;
    		 Sleep(500); //allow time for the user to read the error
    		 cout << "Do you wish to continue? y/n" << endl;
    		 cin >> choice;
    		 if (choice == 'y' || choice == 'Y'){
    			 continue;
    		 } else if (choice == 'n' || choice == 'N'){
    			 break; //immediately breaks while loop, returning user to the menu
    		 }
    	 }

    	 cout << "Entry deleted. Returning to menu." << endl;
    	 break;
     }

}


void LoadDataFromFile(vector <Animal> &animals) //pass in animals vector by reference
{
	int trackNum; //begin variable declaration
	string animalName;
	string animalType;
	string animalSubType;
	int eggs;
	int nurse; //end variable declaration

	/*
	 * creates input stream
	 */
	ifstream zoo ("zoodata.txt"); //can be changed to "zoodata_test.txt" to show completion of assignment

	//zoo.open("zoodata.txt");

	if(!zoo.is_open()){
		cerr << "ERROR. File did not open.";
		return;
	}

	cout << "file open successful" << endl;

	while(!zoo.fail()) {

		zoo >> trackNum;
		zoo >> animalName;
		zoo >> animalType;
		zoo >> animalSubType;
		zoo >> eggs;
		zoo >> nurse;

		if (animalSubType == "bat" || animalSubType == "Bat"){

			animals.push_back(Bat(trackNum, animalName, animalType, animalSubType, eggs, nurse));

		} else if (animalSubType == "sealion" || animalSubType == "Sealion"){

			animals.push_back(Sealion(trackNum, animalName, animalType, animalSubType, eggs, nurse));

		} else if (animalSubType == "whale" || animalSubType == "Whale"){

			animals.push_back(Whale(trackNum, animalName, animalType, animalSubType, eggs, nurse));

		} else if (animalSubType == "pelican" || animalSubType == "Pelican"){

			animals.push_back(Pelican(trackNum, animalName, animalType, animalSubType, eggs, nurse));

		} else if (animalSubType == "goose" || animalSubType == "Goose"){

			animals.push_back(Goose(trackNum, animalName, animalType, animalSubType, eggs, nurse));

		} else if (animalSubType == "crocodile" || animalSubType == "Crocodile"){

			animals.push_back(Crocodile(trackNum, animalName, animalType, animalSubType, eggs, nurse));

		} else {

			cerr << "Error reading animal sub-type" << endl;
		}

	}

	zoo.close();
	animals.erase(animals.end());
	cout << "data loaded successfully" << endl;
	cout << endl;

}

void SaveDataToFile(vector <Animal> &animals) //pass in animals vector by reference
{
     fstream overwrite; //fstream to allow simultaneous input and output to .txt

     //ios::trunc erases the current contents of the file and ios::out/ios::in allows for I/O
     overwrite.open("zoodata.txt", ios::trunc | ios::out | ios::in); //can be changed to "zoodata_test.txt" to show completion of assignment

     /*
      * For loop to walk through each object in the animals vector
      * Each iteration accesses the attributes of object at index [i]
      * It then outputs it to the .txt file
      */
     for (unsigned int i = 0; i < animals.size(); i++){

    	 overwrite << animals[i].getTrackNum() << " ";
    	 overwrite << setw(15) << animals[i].getName() << " ";
    	 overwrite << setw(15) << animals[i].getType() << " ";
    	 overwrite << setw(15) << animals[i].getSubType() << " ";
    	 overwrite << animals[i].getNumberOfEggs() << " ";
    	 overwrite << animals[i].getNurse() << endl;
    	 overwrite.flush(); //extremely important with this application of fstream
    	 //flushing ensures that each iteration gets input to the file before moving to the next
     }

     overwrite.close();
     cout << "Data saved successfully." << endl;
     cout << endl;
}

void DisplayAnimalData(vector <Animal> &animals){ //pass in animals vector by reference

	//formatting for the header of the output to display animal data
	//Each column header corresponds to the data printed in said column
	cout << endl;
	cout.width(77);
	cout.fill('-');
	cout << "" << endl;
	cout << "|" << setw(6) << setfill('0') << "Track #";
	cout << "| " << setw(15) << setfill(' ') << "Animal Name"<< " | ";
	cout << setw(15) << setfill (' ') << "Type" ;
	cout << " | " << setw(15) << setfill (' ') << "Sub-Type" << " | ";
	cout << setw(4) << setfill (' ') << "Eggs";
	cout << " | " << setw(5) << setfill (' ') << "Nurse" << "|" << endl;
	cout.width(77);
	cout.fill('-');
	cout << "" << endl;

	/*
	 * The following for loop walks through each object in the animals vector
	 * It then accesses the attributes in order which applie to the headers above
	 * setw(15) is used to ensure consistency
	 */
	for (unsigned i = 0; i < animals.size(); i++){

		cout << "|" << setw(6) << setfill('0') << animals[i].getTrackNum();
		cout << " | " << setw(15) << setfill(' ') <<animals[i].getName() << " | ";
		cout << setw(15) << setfill (' ') << animals[i].getType();
		cout << " | " << setw(15) << setfill (' ') << animals[i].getSubType() << " | ";
		cout << setw(4) << setfill (' ') << animals[i].getNumberOfEggs();
		cout << " | " << setw(5) << setfill (' ') << animals[i].getNurse() << "|" << endl;
		cout.width(77);
		cout.fill('-');
		cout << "" << endl;

	}

	cout << endl;
	cout << "Press enter to continue..." << endl; //allow the user to decide when to move past this display
	cout << endl;
	cin.ignore();
	cin.ignore(1, '\n');

}

void DisplayMenu() //menu for the user to decide where to go in the program
{
	vector <Animal> animals; //Initialization of animals vector used in all other functions
	char userChoice; //char to capture the user choice

		try{ //start try/catch block

			//start output formatting to display the menu
			cout.width(38);
			cout.fill('-');
			cout << "" << endl;
			cout << "Wildlife Zoo Animal Tracking User Menu" << endl;
			cout.width(38);
			cout.fill('-');
			cout << "" << endl;
			cout << endl;

			cout << "Please select from the following menu:" << endl;
			cout << endl;

			cout << "[1] Load Animal Data" << endl;
			cout << "[2] Generate Data" << endl;
			cout << "[3] Display Animal data" << endl;
			cout << "[4] Add Record" << endl;
			cout << "[5] Delete Record" << endl;
			cout << "[6] Save Animal Data" << endl;
			cout << "[q] Quit" << endl;
			cout << endl;
			cout << "Selection: "; //end output formatting for menu display

			cin >> userChoice; //take the user selection

			while(userChoice != 'q' || userChoice != 'Q'){ //used to quit program

				/*
				 * Switch statement to direct the program based on the user choicers
				 * Users select a number which is stored as a char
				 * The switch statement then picks the correct case based on the char
				 * After the function called is done, it breaks the switch statement
				 * And reloops into the while loop
				 */
				switch (userChoice) {
					case '1':
						LoadDataFromFile(animals);
						break;
					case '2':
						GenerateData();
						break;
					case '3':
						DisplayAnimalData(animals);
						break;
					case '4':
						AddAnimal(animals);
						break;
					case '5':
						RemoveAnimal(animals);
						break;
					case '6':
						SaveDataToFile(animals);
						break;
					case 'q': //won't reenter the while loop due to it's conditional
						cout << "Exiting program" << endl;
						break;
					default: //default is to throw an error
						throw "Error. Please enter a choice from the above menu.";
						//this allows the program to capture any input
						//which doesn't follow the menu options and ouput an error
						break;
			}

				Sleep(2000); //every loop waits 2 seconds before outputing the menu again
				cout.width(38);
				cout.fill('-');
				cout << "" << endl;
				cout << "Wildlife Zoo Animal Tracking User Menu" << endl;
				cout.width(38);
				cout.fill('-');
				cout << "" << endl;
				cout << endl;

				cout << "Please select from the following menu:" << endl;
				cout << endl;

				cout << "[1] Load Animal Data" << endl;
				cout << "[2] Generate Data" << endl;
				cout << "[3] Display Animal data" << endl;
				cout << "[4] Add Record" << endl;
				cout << "[5] Delete Record" << endl;
				cout << "[6] Save Animal Data" << endl;
				cout << "[q] Quit" << endl;
				cout << endl;
				cout << "Selection: ";

				cin >> userChoice; //takes the userChoice (after a function has already been called and user)
				//Then loops again into the loop so long as userChoice != 'q' || 'Q'
			}

	} catch (const char* error){ //catch the error which user didn't select the menu

		cerr << error << endl;
		cout << endl;
		Sleep(2000); //allow them time to read the error
		DisplayMenu(); //go back into the menu

	}

}

int main()
{
	DisplayMenu(); //start menu of program
	return 1;
}

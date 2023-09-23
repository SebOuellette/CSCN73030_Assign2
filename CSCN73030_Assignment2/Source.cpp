// # Step 2
// https://github.com/SebOuellette/CSCN73030_Assign2

/*
Next you need to implement the main function to read the StudentData.txt file, create student objects
and store them into a vector space. Create a struct STUDENT_DATA that contains the first and last
names of the students. Each line read from the input file contains a first/last name pair separated by a
comma. Parse the data, create an object and push that object into a vector space
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// Create a struct STUDENT_DATA that contains the first and last names of the students.
typedef struct STUDENT_DATA {
	std::string firstname;
	std::string lastname;
	std::string email;
} STUDENT_DATA;

std::string readName(std::string line, unsigned int start = 0) {
	std::string name = "";

	char c;
	int i = start;
	while ((c = line[i]) != ',' && c != '\t' && c != 0) {
		name += c;
		
		i++;
	}
	name += '\0';


#ifdef _DEBUG
	if (!start)
		std::cout << std::endl;

	std::cout << '"' << name << "\" ";
#endif

	return name;
}


int main() {
	// Update the main source code to print out a message to state if the application is running standard or pre - release source code
	std::cout << "This application is running in "
#ifdef PRE_RELEASE
		<< "Pre-Release"
#else
		<< "Standard"
#endif
		<< " mode";

	//Next you need to implement the main function to read the StudentData.txt file
	/// Update the main source code to read the StudentData_Emails.txt if compiled using a PRE_RELEASE compiler directive, commitand push into your Github Repo PreRelease branch
#ifdef PRE_RELEASE
	std::ifstream file("../StudentData_Emails1.txt", std::ifstream::in);
#else
	std::ifstream file("../StudentData.txt", std::ifstream::in);
#endif 

	if (!file.is_open()) {
		std::cerr << "Could not open file" << std::endl;
		return 1;
	}

	std::vector<STUDENT_DATA> vecSpace;

	///create student objects and store them into a vector space
	while (!file.eof() && file.is_open()) {
		std::string line;
		std::getline(file, line);

		if (line.length() == 0) {
			continue;
		}

		//Each line read from the input file contains a first / last name pair separated by a comma.
		// Parse the data, create an objectand push that object into a vector space
		std::string lastname = readName(line);
		std::string firstname = readName(line, lastname.length() + 1);
		STUDENT_DATA dat = { lastname, firstname };

#ifdef PRE_RELEASE
		std::string email = readName(line, firstname.length() + lastname.length() + 1);
			
		dat.email = email;
#endif
		vecSpace.push_back(dat);
	}

	return 0;
}
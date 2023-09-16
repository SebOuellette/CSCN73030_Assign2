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

	std::cout << '"' << name << "\" ";

	return name;
}


int main() {
	//Next you need to implement the main function to read the StudentData.txt file
	std::ifstream file("../StudentData.txt", std::ifstream::in);

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
		STUDENT_DATA dat = { lastname, readName(line, lastname.length()+1) };

		vecSpace.push_back(dat);

		std::cout << std::endl;
	}

	return 0;
}
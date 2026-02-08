#include <iostream>
#include <fstream>
#include <string>

static std::string replaceAll(const std::string& line, const std::string& s1, const std::string& s2)
{
	std::string result;
	size_t pos = 0;
	size_t found;

	while ((found = line.find(s1, pos)) != std::string::npos)
	{
		result += line.substr(pos, found - pos);
		result += s2;
		pos = found + s1.length();
	}
	result += line.substr(pos);
	return (result);
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return (1);
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (s1.empty())
	{
		std::cerr << "Error: s1 must not be empty" << std::endl;
		return (1);
	}

	std::ifstream inputFile(filename.c_str());
	if (!inputFile.is_open())
	{
		std::cerr << "Error: Could not open file " << filename << std::endl;
		return (1);
	}

	std::string outputFilename = filename + ".replace";
	std::ofstream outputFile(outputFilename.c_str());
	if (!outputFile.is_open())
	{
		std::cerr << "Error: Could not create file " << outputFilename << std::endl;
		inputFile.close();
		return (1);
	}

	std::string line;
	bool firstLine = true;
	while (std::getline(inputFile, line))
	{
		if (!firstLine)
			outputFile << "\n";
		outputFile << replaceAll(line, s1, s2);
		firstLine = false;
	}
	inputFile.close();
	outputFile.close();

	return (0);
}
#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}
ScalarConverter::ScalarConverter(const ScalarConverter &src) { (void)src; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs) { (void)rhs; return *this; }
ScalarConverter::~ScalarConverter(void) {}


static bool isPseudo(const std::string &s)
{
	return (s == "nan" || s == "nanf"
		|| s == "+inf" || s == "+inff" || s == "inf" || s == "inff"
		|| s == "-inf" || s == "-inff");
}

static bool needsDotZero(double val)
{
	if (std::isnan(val) || std::isinf(val))
		return false;
	return (val >= -999999.0 && val <= 999999.0
		&& val == static_cast<int>(val));
}


void ScalarConverter::convert(const std::string &literal)
{
	if (literal.empty())
	{
		std::cerr << "Error: empty input" << std::endl;
		return ;
	}

	double	val;
	bool	overflow = false;

	// 1) Single printable character (non-digit)
	if (literal.length() == 1 && !std::isdigit(literal[0]))
	{
		val = static_cast<double>(literal[0]);
	}
	// 2) Pseudo-literals (nan, inf, ...)
	else if (isPseudo(literal))
	{
		val = std::strtod(literal.c_str(), NULL);
	}
	// 3) Numeric literal (int / float / double)
	else
	{
		std::string toParse = literal;
		if (toParse[toParse.length() - 1] == 'f')
			toParse = toParse.substr(0, toParse.length() - 1);

		char *end;
		errno = 0;
		val = std::strtod(toParse.c_str(), &end);

		if (*end != '\0' || toParse.empty())
		{
			std::cerr << "Error: invalid literal" << std::endl;
			return ;
		}
		if (errno == ERANGE)
			overflow = true;
	}

	// --- char ---
	if (std::isnan(val) || std::isinf(val) || val < 0 || val > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<int>(val)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(val) << "'" << std::endl;

	// --- int ---
	if (overflow || std::isnan(val) || std::isinf(val)
		|| val < static_cast<double>(INT_MIN)
		|| val > static_cast<double>(INT_MAX))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(val) << std::endl;

	// --- float ---
	float f = static_cast<float>(val);
	std::cout << "float: " << f;
	if (needsDotZero(static_cast<double>(f)))
		std::cout << ".0";
	std::cout << "f" << std::endl;

	// --- double ---
	std::cout << "double: " << val;
	if (needsDotZero(val))
		std::cout << ".0";
	std::cout << std::endl;
}

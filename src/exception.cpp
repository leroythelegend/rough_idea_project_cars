#include "exception.h"

#include <sstream>

using std::stringstream;
using std::endl;

namespace pcars {

PCars_Exception::PCars_Exception(const int line, const char * file, const int error) noexcept
	:	line_{line},
		file_{file},
		error_{error},
		message_{} {

}

PCars_Exception::PCars_Exception(const int line, const char * file, const int error, const string message) noexcept
	:	line_{line},
		file_{file},
		error_{error},
		message_{message} {
}

PCars_Exception::PCars_Exception(const int line, const char * file, const string message) noexcept
	:	line_{line},
		file_{file},
		error_{0},
		message_{message} {

	std::stringstream ss;

	ss << "line: "    << line_ << endl
	   << "file: "    << file_ << endl
	   << "error: "   << error_ << endl
	   << "message: " << message_ << endl
	   << endl;

	exceptionmessage_ = ss.str();
}

PCars_Exception::PCars_Exception(const int line, const char * file, const unsigned int compare, const unsigned int to) noexcept
		:	line_{line},
			file_{file},
			error_{0} {

	stringstream ss;

	ss << "line: "    << line_ << endl
	   << "file: "    << file_ << endl
	   << "compare: "   << compare << endl
	   << "to: " << to << endl
	   << endl;

	exceptionmessage_ = ss.str();
}

PCars_Exception::~PCars_Exception() noexcept {
}

const char* PCars_Exception::what() const noexcept {
	return exceptionmessage_.c_str();
}

}


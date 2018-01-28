#ifndef PCARS_EXCEPTION_H_
#define PCARS_EXCEPTION_H_

#include <exception>
#include <string>

using std::string;

namespace pcars {

class PCars_Exception: public std::exception {
public:
	using Line = int;
	using File = const char *;
	using Error = int;
	using Message = std::string;
	using Compare = const unsigned int; 
	using To = const unsigned int; 

	PCars_Exception(const Line, File, const Error) noexcept;
	PCars_Exception(const Line, File, const Error, const Message) noexcept;
	PCars_Exception(const Line, File, const Message) noexcept;
	PCars_Exception(const Line, File, Compare, To) noexcept;
	virtual ~PCars_Exception() noexcept;

	virtual const char* what() const noexcept;

private:
	Line line_;
	std::string file_;
	Error error_;
	Message message_;
	std::string exceptionmessage_;
};

}

#endif


#include "Error.h"



Error::Error(const std::string& error) :_error(error)
{
}


Error::~Error()
{
}

const char* Error::what() const
{
	return _error.c_str();
}

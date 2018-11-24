#pragma once
#include<exception>
#include <string>

class Error :std::exception
{
public:
	Error(const std::string& error);
	~Error();
	//zwrocenie informacji o bledzie
	const char*what() const override;
private:
	std::string _error;
};


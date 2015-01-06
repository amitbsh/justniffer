/*
	Copyright (c) 2007 Plecno s.r.l. All Rights Reserved 
	info@plecno.com
	via Giovio 8, 20144 Milano, Italy

	Released under the terms of the GPLv3 or later

	Author: Oreste Notelli <oreste.notelli@plecno.com>	
*/

#include "regex.h"
#include "protocol.h"

using namespace std;

string regex(const boost::regex& re, const string& text)
{
	string result;
	boost::smatch what;
	if (boost::regex_search(text, what, re))
	for (boost::smatch::const_iterator it = what.begin(); it != what.end(); it++)
	{
		result.assign(*it);
	}
	return result;
}

void regex_handler_base::append(std::basic_ostream<char>& out, const timeval*)
{
	string res = ::regex(_re, get_text());
	if (res.empty())
		out << _not_found;
	else
		out<<res;
}

void regex_handler_base::append(int fd, const timeval*)
{
	string res = ::regex(_re, get_text());
	/*	int length;
	const char *str;
	if (res.empty()) {
		length = _not_found.length() + 1;
		str = _not_found.c_str();
	} else {
		length = res.length() + 1;
		str = res.c_str();
	}
	int n = write(fd, &length, sizeof(int));
	if (n != sizeof(int))
		printf("ERR %d/%d\n", n, sizeof(int));
	n = write(fd, str, length);
	if (n != length)
	printf("ERR %d/%d\n", n, length);*/
	if (res.empty())
		write_to_fd(fd, _not_found);
	else
		write_to_fd(fd, res);
}

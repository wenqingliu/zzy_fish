#include "URLData.h"
URLData::URLData(int statusCode,string data)
{
	this->statusCode = statusCode;
	this->data = data;
}

URLData::~URLData()
{
}
//==============================================================================
// Name        : Client.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0.0 (DD/MM/YYYY)
// Description : Source file of the Client class
//==============================================================================

#include "Client.h"

Client::Client()
{
    this->clear();
}

//Client::Client() :
//        Client()
//{
//    this->set();
//}

Client::Client(const Client& client) :
        Client()
{
    this->copy(client);
}

Client::~Client()
{

}

void Client::clear()
{
    this->set();
}

void Client::set()
{

}

void Client::copy(const Client& client)
{
    this->set();
}

bool Client::equals(const Client& client) const
{
    return true;
}

void Client::fromString(const std::string& fromString, const char& sep)
{
    // TODO void Client::fromString(const std::string& fromString, const char& sep)
    // #warning "'void Client::fromString(const std::string& fromString, const char& sep)' not implemented"
}

const std::string Client::toString(const char& sep) const
{
    // TODO const std::string Client::toString(const char& sep) const
    // #warning "'const std::string Client::toString(const char& sep) const' not implemented"
    return std::string();
}

bool Client::operator==(const Client& client) const
{
    return this->equals(client);
}

bool Client::operator!=(const Client& client) const
{
    return !(this->equals(client));
}

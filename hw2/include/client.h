#ifndef CLIENT_H
#define CLIENT_H

#include<stdio.h>
#include<string>
#include"server.h"
#include"crypto.h"
#include<random>

using namespace std;

class Server;

class Client
{
public:
	Client(std::string id_, const Server& server_);
	const std::string get_id() const;
	std::string get_publickey();
	double get_wallet();
	std::string sign(std::string txt);
	bool transfer_money(std::string receiver, double value);
	size_t generate_nonce();
private:
	Server const* const server;
	const std::string id;
	std::string public_key;
	std::string private_key;
};
#endif //CLIENT_H
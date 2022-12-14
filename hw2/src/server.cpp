#include "server.h"

Server::Server() = default;

std::shared_ptr<Client> Server::add_client(std::string id)
{

};

std::shared_ptr<Client> Server::get_client(std::string id){

};

double Server::get_wallet(std::string id){

}
bool Server::parse_trx(std::string trx, std::string sender, std::string receiver, double value){

}
bool Server::add_pending_trx(std::string trx, std::string signature){

}
size_t Server::mine(){
    
}
#include "client.h"

Client::Client(std::string id_, const Server& server_):id(id_), server(&server_) {
    crypto::generate_key(public_key,private_key);
};

const std::string Client::get_id() const {
    return id;
};

std::string Client::get_publickey() {
    return public_key;
};

double Client::get_wallet(){
    return const_cast<Server *>(server)->get_wallet(id);
};

std::string Client::sign(std::string txt){
    return crypto::signMessage(private_key, txt);
};

bool Client::transfer_money(std::string receiver, double value){

};

size_t Client::generate_nonce(){

};
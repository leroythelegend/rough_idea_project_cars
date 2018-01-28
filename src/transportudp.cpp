#include "transportudp.h"

#include "exception.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>
#include <cstring>
#include <unistd.h>
#include <string>

using std::to_string;
using std::string;

namespace pcars {

Transport_UDP::Transport_UDP(const unsigned int port) {

    struct addrinfo hints, *servinfo, *p;
    int rv = 0;

    string sport = to_string(port);

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC; // set to AF_INET to force IPv4
    hints.ai_socktype = SOCK_DGRAM;
    hints.ai_flags = AI_PASSIVE; // use my IP

    if ((rv = getaddrinfo(NULL, sport.c_str(), &hints, &servinfo)) != 0) {
        throw PCars_Exception(__LINE__, __FILE__, rv, gai_strerror(rv));
    }

    // loop through all the results and bind to the first we can



    for(p = servinfo; p != NULL; p = p->ai_next) {
        if ((socketfd_ = socket(p->ai_family, p->ai_socktype,
                p->ai_protocol)) == -1) {
            continue;
        }

        if (bind(socketfd_, p->ai_addr, p->ai_addrlen) == -1) {
            ::close(socketfd_);
            continue;
        }

        break;
    }

    if (p == NULL) {
        throw PCars_Exception(__LINE__, __FILE__ , errno, "listener: failed to bind socket");
    }

    freeaddrinfo(servinfo);
}

Transport_UDP::~Transport_UDP() {
	close(socketfd_);
}


PCars_Data Transport_UDP::read(const unsigned int amount) {

    int numbytes;
    struct sockaddr_storage their_addr;
    socklen_t addr_len = sizeof their_addr;

    PCars_Data buffer(amount);

    if ((numbytes = recvfrom(socketfd_, buffer.data(), amount , 0,
        (struct sockaddr *)&their_addr, &addr_len)) == -1) {
    	throw PCars_Exception(__LINE__, __FILE__, errno, "recvfrom");
    }

    buffer.resize(numbytes);

    return buffer;
}

void Transport_UDP::write(const PCars_Data & ) {

}


}


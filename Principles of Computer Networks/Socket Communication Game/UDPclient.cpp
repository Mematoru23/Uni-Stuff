#include <iostream>
#include <string>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main()
{
    // create UDP socket and init the server socket snippet
    int clientSocket = socket(AF_INET, SOCK_DGRAM, 0);
    if (clientSocket == -1)
    {
        std::cerr << "Error on creating socket.\n";
        return 1;
    }

    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");

    // send a "start" message to server to init the game
    std::string message = "start";
    if (sendto(clientSocket, message.c_str(), message.size(), 0, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
        std::cerr << "Error sending data to server.\n";
        return 1;
    }

    while (true)
    {
        // allocating memory so it doesnt kill server…and receive data from server
        char buffer[1024];
        memset(buffer, 0, sizeof(buffer));

        socklen_t serverAddrLen = sizeof(serverAddress);
        int bytesReceived = recvfrom(clientSocket, buffer, sizeof(buffer), 0, (struct sockaddr*)&serverAddress, &serverAddrLen);
        if (bytesReceived == -1)
        {
            std::cerr << "Error receiving data from server.\n";
            return 1;
        }
        std::cout << "Server: " << buffer << "\n";

        if (strstr(buffer, "YAAAY! YA DID IT CHAMPION!") != nullptr)
            break;

        // user input
        std::string guess;
        std::cout << "Your guess: ";
        std::getline(std::cin, guess);

        // send data to server
        if (sendto(clientSocket, guess.c_str(), guess.size(), 0, (struct sockaddr*)& serverAddress, sizeof(serverAddress)) == -1)
        {
            std::cerr << "Error sending data to server.\n";
            return 1;
        }

    }

    close(clientSocket);

    return 0;
}

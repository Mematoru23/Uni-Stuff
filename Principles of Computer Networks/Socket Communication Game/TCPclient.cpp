#include <iostream>
#include <string>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main()
{
    // create TCP socket and init the server socket snippet
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1)
    {
        std::cerr << "Error on creating socket.\n";
        return 1;
    }

    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");

    // server connection
    if (connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1)
    {
       std::cerr << "Server connection error.\n";
        return 1;
    }

    while (true) 
    {
		// allocating memory so it doesnt kill server
        char buffer[1024];
        memset(buffer, 0, sizeof(buffer));
        int bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0);
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
        if (send(clientSocket, guess.c_str(), guess.size(), 0) == -1)
        {
            std::cerr << "Error sending data to server.\n";
            return 1;
        }

    }

    close(clientSocket);

    return 0;
}

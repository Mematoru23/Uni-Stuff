import socket
import sys
import signal
import time
import random

server_running = True

# CTRL+C shutdown command signal handle
def handle_shutdown_signal(signal, frame):
    global server_running
    print("Shutting down the server...")
    server_running = False
    time.sleep(3)
    sys.exit(0)

def main():
    # register shutdown signal handler for CTRL+C
    signal.signal(signal.SIGINT, handle_shutdown_signal)

    # create TCP socket and bind the server to ip and port
    try:
        server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        server.bind(('127.0.0.1', 8080))
        server.listen(5)
        print("Server waiting and waiting...")

        # loop while server is up
        while server_running:
            secret_number = random.randint(1, 100)
            
            # timeout server after 5 minutes if no interraction from client 
            server.settimeout(60 * 5)
            
            # accept and handle client connection
            try:
                client, addr = server.accept()
            except socket.timeout:
                print("Connection timed out.")
                break
            print(f"Connection accepted: {addr[0]}:{addr[1]}")

            # solve the problem with data from client
            response = "Number Guessing Game! Guess a number between 1 and 100."
            client.send(response.encode('utf-8'))
            print(f'Number to be guessed - {secret_number}')
            
            

     # loop for values until you guess
            while True:
                # receive the guess from the client
                guess = client.recv(1024).decode('utf-8')
                print(f'client guess: {guess}')
                
                if not guess.isnumeric():
                    response = "ERROR!!! NEED NUMBER!!!"
                    print("invalid client input")
                    continue
                
                # if number guessed we out
                if int(guess) == secret_number:
                    print(int(guess))
                    print(int(guess) == secret_number)
                    response = "YAAAY! YA DID IT CHAMPION!"
                    break
                
                # checking client to server data and decoding the data to the correct format
                if int(guess) < secret_number:
                    response = "higher!"
                else:
                    response = "LOWER!"
                client.send(response.encode('utf-8'))
            client.send(response.encode('utf-8'))
            
        client.close()
    except Exception as e:
        raise
    finally:
        server.close()
        print("Server closed.")

main()

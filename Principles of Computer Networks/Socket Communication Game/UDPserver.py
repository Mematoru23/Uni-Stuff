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

    # create UDP socket and bind the server to ip and port
    try:
        server = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        server.bind(('127.0.0.1', 8080))
        print("Server waiting and waiting...")

        # loop while server is up
        while server_running:
            secret_number = random.randint(1, 100)
            # timeout server after 5 minutes if no interraction from client 
            server.settimeout(60 * 5)
            
            # wait for "start" message from the client
            try:
                data, addr = server.recvfrom(1024)
            except socket.timeout:
                print("Connection timed out.")
                break
            
            if data.decode('utf-8') == "start":
                print(f"Connection accepted: {addr[0]}:{addr[1]}")
                response = "Number Guessing Game! Guess a number between 1 and 100."
                server.sendto(response.encode('utf-8'), addr)
                print(f'Number to be guessed - {secret_number}')
            else:
                print(f"Invalid initial message received from {addr[0]}:{addr[1]}")
            
            # loop for values until you guess
            while True:
                # receive the guess from the client
                try:
                    data, addr = server.recvfrom(1024)
                    guess = data.decode('utf-8')
                except socket.timeout:
                    print("Client connection timed out.")
                    break
                print(f'client guess: {guess}')
                
                if not guess.isnumeric():
                    response = "ERROR!!! NEED NUMBER!!!"
                    print("Invalid client input")
                else:
                    if int(guess) == secret_number:
                        response = "YAAAY! YA DID IT CHAMPION!"
                        server.sendto(response.encode('utf-8'), addr)
                        break
                    elif int(guess) < secret_number:
                        response = "higher!"
                    else:
                        response = "LOWER!"
                server.sendto(response.encode('utf-8'), addr)
            
    except Exception as e:
        print("Error:", e)
    finally:
        server.close()
        print("Server closed.")
        

main()

<p align="left">
  <img src="42paris_white.png" width="170" alt="Sorbonne Université Logo">
</p>

*This project has been created as part of the 42 curriculum by anasimi.*

# Minitalk

## Description

Minitalk is a small client-server communication program written in C.
The goal of the project is to send a string from a client process to a server process using only UNIX signals.

The server displays its PID when it starts, then waits for messages.
The client sends a message to the server using the server PID.

Only `SIGUSR1` and `SIGUSR2` are used for communication.

## Instructions

### Compilation

```bash
make
```

This creates two executables:

```bash
./server
./client
```

### Usage

First, start the server:

```bash
./server
```

The server will print its PID.

Then, in another terminal, run the client:

```bash
./client <server_pid> "your message"
```

Example:

```bash
./client 12345 "Hello 42"
```

The server should receive and display the message.

### Cleaning

```bash
make clean
```

```bash
make fclean
```

```bash
make re
```

## Features

* Communication between two processes
* Uses only UNIX signals
* Server prints its PID
* Client sends a string to the server
* Server can receive several messages without restarting
* Error handling for invalid arguments and PID problems

## Bonus

* The server sends an acknowledgement signal to the client
* Unicode characters are supported

## Resources

Useful references:

* `man signal`
* `man sigaction`
* `man kill`
* `man getpid`
* `man pause`
* UNIX signals documentation
* 42 Minitalk subject


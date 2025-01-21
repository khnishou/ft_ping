# ft_ping

## Summary
ft_ping is a project that involves recoding the `ping` command, which is used to test the accessibility of another machine over an IP network and measure the round-trip time (RTT) of packets.

## Features
- Implements core functionality of `ping`
- Supports IPv4 (address/hostname) as parameters
- Handles FQDN without performing DNS resolution in packet return
- Supports the `-v` and `-?` options
- Built using C with strict error handling

## Installation
### Prerequisites
- A virtual machine running **Debian 7.0 or later**
- A Linux kernel version **greater than 3.14**
- A working C compiler (e.g., `gcc`)

### Compilation
```sh
make
```
This will compile the project and generate the `ft_ping` executable.

## Usage
```sh
./ft_ping [options] <destination>
```
### Options
- `-v` : Verbose mode (displays additional debug information)
- `-?` : Displays usage information

Example:
```sh
./ft_ping -v 8.8.8.8
```

## Mandatory Requirements
- The executable must be named `ft_ping`.
- Must be based on `ping` from inetutils-2.0 (`ping -V`).
- Must handle error cases gracefully.
- Allowed functions:
  - `gettimeofday`, `exit`, `inet_ntop`, `inet_pton`
  - `ntohs`, `htons`, `signal`, `alarm`, `usleep`
  - `socket`, `setsockopt`, `close`, `sendto`, `recvmsg`
  - `getpid`, `getuid`, `getaddrinfo`, `getnameinfo`, `freeaddrinfo`
  - `strerror`, `gai_strerror`, `printf` and its family
- Usage of `fcntl`, `poll`, and `ppoll` is **strictly forbidden**.

## Bonus Features
If the mandatory part is **perfectly implemented**, additional features can be added:
- Support for extra flags: `-f`, `-l`, `-n`, `-w`, `-W`, `-p`, `-r`, `-s`, `-T`, `--ttl`, `--ip-timestamp`.

## Evaluation & Submission
- The project must be submitted via a Git repository.
- The repository should contain all necessary source files and a `Makefile`.
- The program will be evaluated in a VM running **Debian 7.0 stable**.
- The output must follow the indentation of `ping` from inetutils-2.0.
- A delay of **±30ms** is tolerated for packet reception.

## Notes
- Directly calling the real `ping` command is **not allowed**.
- Any bonus work will only be evaluated if the mandatory part is **fully functional**.

## License
This project is for educational purposes and follows the guidelines of the ft_ping assignment.

---
Developed as part of the ft_ping project.


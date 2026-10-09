Naz, here are the most commonly asked Computer Networks Lab viva questions with short answers for B.Tech CSE. 🔥 Focus especially on socket programming, TCP/UDP, DNS, Wireshark, IP addressing, and networking commands if your lab includes these experiments.

💻 Computer Networks Lab Viva — Important Questions

1. Basic networking concepts

Start here — these are fundamental viva questions.

1. What is a computer network? A group of interconnected computers that communicate and share resources.

2. What is a protocol? A set of rules that governs communication between devices.

3. What are the different types of networks?

* LAN — Local Area Network
* MAN — Metropolitan Area Network
* WAN — Wide Area Network
* PAN — Personal Area Network

4. What is the OSI model? A seven-layer reference model used to understand network communication.

Layer	Function
7. Application	Network services to applications
6. Presentation	Data formatting, encryption
5. Session	Manages communication sessions
4. Transport	End-to-end delivery
3. Network	Routing and IP addressing
2. Data Link	Frames and MAC addressing
1. Physical	Transmission of bits

5. What is the TCP/IP model? A networking model commonly represented by four layers: Application, Transport, Internet, and Network Access.

6. Difference between a hub, switch and router?

* Hub: Sends incoming data to all ports.
* Switch: Forwards frames using MAC addresses.
* Router: Forwards packets between networks using IP addresses.

7. What is bandwidth? The maximum data-carrying capacity of a communication link per unit time.

8. What is latency? The time taken for data to travel from source to destination.

2. TCP vs UDP and socket programming ⭐

These are especially important for C-based networking lab experiments.

9. What is TCP? Transmission Control Protocol. It is connection-oriented and provides reliable, ordered data delivery.

10. What is UDP? User Datagram Protocol. It is connectionless and does not guarantee delivery, ordering, or retransmission.

11. Differentiate TCP and UDP.

TCP	UDP
Connection-oriented	Connectionless
Reliable delivery	Best-effort delivery
Ordered byte stream	Independent datagrams
Higher protocol overhead	Lower protocol overhead
listen(), accept() used in server setup	No listen() or accept() needed
Used by HTTPS, SSH	Used by DNS queries, many real-time applications

12. What is a socket? An endpoint for communication between two processes over a network.

13. What is socket programming? Writing programs that communicate over a network using sockets.

14. What are the main functions used in TCP socket programming in C?

socket(), bind(), listen(), accept(), connect(), send(), recv(), close().

15. What are the common functions used in UDP programming?

socket(), bind(), sendto(), recvfrom(), close().

16. What does socket() do? Creates a socket and returns a file descriptor.

17. What does bind() do? Associates a socket with a local IP address and port number.

18. What does listen() do? Marks a TCP socket as a passive socket that can accept incoming connection requests.

19. What does accept() do? Accepts an incoming TCP connection and returns a new socket descriptor for communicating with that client.

20. What does connect() do? Initiates a connection to a remote endpoint, commonly used by a TCP client.

21. Difference between send() and sendto()? send() is commonly used with connected sockets, whereas sendto() can specify the destination address, making it useful for UDP.

22. Difference between recv() and recvfrom()? recv() receives data from a socket. recvfrom() can also provide the sender’s address.

23. Why doesn’t UDP need listen() and accept()? UDP has no connection-establishment process. Data can be sent directly to a destination using datagrams.

24. How does a UDP server know where to send the reply? It obtains the sender’s IP address and port through recvfrom() and passes that address to sendto().

25. Does UDP send a string or a stream? UDP sends datagrams. In C, you can send a string as the bytes of a datagram, but UDP itself does not provide a continuous byte stream.

26. What is the difference between a client and a server? A client initiates a request; a server waits for and processes requests.

3. IP addressing and ports

27. What is an IP address? A logical address used to identify an interface on an IP network.

28. What is the difference between IPv4 and IPv6?

* IPv4: 32-bit address, e.g. 192.168.1.10
* IPv6: 128-bit address, e.g. 2001:db8::1

29. What is a MAC address? A link-layer address used to identify a network interface on a local network.

30. What is a port number? A number used by the transport layer to identify a service or application endpoint.

31. What is the difference between an IP address and a port number? The IP address identifies the network destination interface; the port identifies the relevant application endpoint.

32. What are well-known port numbers?

Protocol	Port
FTP control	21
SSH	22
DNS	53
DHCP server	67
DHCP client	68
HTTP	80
HTTPS	443
SMTP submission	587

33. What is localhost? The local computer, commonly addressed by 127.0.0.1 in IPv4 or ::1 in IPv6.

34. What is a subnet mask? It identifies which bits of an IPv4 address represent the network prefix.

35. What is a default gateway? The router a device uses to reach destinations outside its local network when no more specific route applies.

4. DNS and Wireshark 🔍

36. What is DNS? Domain Name System. It translates domain names such as google.com into IP addresses and provides other DNS records.

37. Which port does DNS use? Port 53, using UDP or TCP depending on the operation.

38. Why does DNS use UDP? UDP has low overhead and is suitable for many small DNS queries. DNS also uses TCP when required, including for zone transfers and some large or truncated responses.

39. What is Wireshark? A network protocol analyzer used to capture and inspect network packets.

40. What is packet sniffing? Capturing and examining network traffic for troubleshooting, analysis, or security monitoring.

41. What is a packet capture filter? A filter that controls which packets Wireshark captures.

42. What is a display filter? A filter that controls which packets are displayed after capture.

Examples:

dns
tcp
udp
icmp
ip.addr == 192.168.1.10
tcp.port == 80

43. What is the difference between capture and display filters? Capture filters restrict packets recorded; display filters only restrict packets shown.

44. How do you identify a DNS query in Wireshark? Apply the dns display filter and inspect the query name, query type, response, and destination port.

45. What is the three-way handshake in TCP? The connection is established using:

* SYN
* SYN-ACK
* ACK

5. Networking commands

46. What does ping do? Tests network reachability using ICMP Echo Request and Echo Reply messages.

47. What does traceroute or tracert do? Shows the network hops toward a destination using probe packets and TTL/hop-limit behavior.

48. What does nslookup do? Queries DNS to obtain information about domain names.

49. What does ipconfig do? Displays Windows IP configuration.

50. What does ifconfig do? Displays or configures network interfaces on systems that support it; ip is preferred on many modern Linux systems.

51. What does netstat do? Displays network connections, listening ports, and related statistics.

52. What is ARP? Address Resolution Protocol, used in IPv4 local networks to map an IP address to a link-layer address.

53. What is DHCP? Dynamic Host Configuration Protocol. It automatically provides IP configuration, such as an IP address, gateway and DNS servers.

6. Common lab-programming viva questions

54. What header files are used for socket programming in C on Linux?

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

55. What is struct sockaddr_in? A structure used to represent an IPv4 socket address, including the IP address and port.

56. Why do we use htons()? Converts a 16-bit value, such as a port number, from host byte order to network byte order.

57. What does inet_addr() do? Converts an IPv4 address in dotted-decimal notation into a binary network-address representation. It is an older function; inet_pton() is generally preferred.

58. Why do we use memset()? To initialize a block of memory, often to zero before filling a socket-address structure.

59. What is AF_INET? It specifies the IPv4 address family.

60. What is SOCK_STREAM? A socket type commonly used for TCP byte-stream communication.

61. What is SOCK_DGRAM? A socket type used for datagram communication, commonly UDP.

62. Why is htons() needed for port numbers? Network protocols use network byte order, which is big-endian. htons() ensures the port is represented in the required byte order.

63. What happens if the server is not running? A TCP client’s connection attempt will normally fail. UDP may still allow a datagram to be sent, but a reply might not arrive; an ICMP error may sometimes be returned.

64. Why should we close a socket? To release the resources associated with it.

65. What does recv() returning zero mean? For a TCP stream socket, it indicates that the peer has performed an orderly shutdown of its sending direction. For UDP, a zero-length datagram is valid and is not an end-of-connection signal.

🎯 Last-minute revision checklist

Viva preparation

0/10 revised

OSI and TCP/IP layers

TCP vs UDP

TCP and UDP socket functions

DNS and port 53

Wireshark capture vs display filters

IP address vs MAC address vs port

TCP three-way handshake

socket(), bind(), listen(), accept(), connect()

sendto() and recvfrom()

ping, traceroute, nslookup, ARP and DHCP

My advice: If your viva is today, prioritize questions 9–25 and 36–45, then revise the functions used in each experiment. Examiners often ask you to explain a single line of your C program, not just define a protocol.

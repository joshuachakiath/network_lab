Experiments covered:

Experiment 2: HTTP Packet Capture Using Wireshark
Experiment 4: DNS Packet Capture Using Wireshark
Experiment 6: UDP Client-Server Abbreviation Translator
Experiment 8: Concurrent Time Server Using UDP
Experiment 9: Concurrent File Server
Experiment 11: Router Commands
Experiment 12: Static Routing
Experiment 13: RIPv2 Routing
Experiment 14: OSPF Routing
Experiment 15: Restrict Communication Using ACL
Experiment 16: Block Hackathon Website Access Using Subnetting and ACL
Experiment 17: Interconnect Subnets Using RIPng
Experiment 2: HTTP Packet Capture Using Wireshark
Aim

To capture and analyze HTTP packets using Wireshark.

Algorithm
Open Wireshark.
Select the active network interface.
Start packet capture.
Generate HTTP traffic by visiting a plain-HTTP test website.
Enter http in the display filter.
Inspect the HTTP requests and responses.
Stop the capture.
Save the captured packets as a .pcapng file.
Important Concepts
Wireshark is a network protocol analyzer.
HTTP stands for Hypertext Transfer Protocol.
HTTP commonly uses TCP port 80.
HTTPS commonly uses TCP port 443.
A capture filter controls which packets are recorded.
A display filter controls which recorded packets are displayed.
Viva Questions and Answers

Q1. What is Wireshark?

Wireshark is an open-source network protocol analyzer used to capture and analyze network packets.

Q2. What is HTTP?

HTTP is an application-layer protocol used for communication between web clients and servers.

Q3. Which port does HTTP use?

TCP port 80 by default.

Q4. What is HTTPS?

HTTPS is HTTP secured using TLS.

Q5. What is a packet?

A unit of data transmitted over a network.

Q6. What is the difference between TCP and UDP?

TCP provides reliable, ordered delivery. UDP is connectionless and does not guarantee delivery or ordering.

Q7. What is a PCAPNG file?

A file format used to save captured network traffic.

Experiment 4: DNS Packet Capture Using Wireshark
Aim

To capture and analyze DNS queries and responses using Wireshark.

Algorithm
Open a terminal or command prompt.
Clear the DNS cache if necessary.
Open Wireshark.
Select the active network interface.
Start capturing packets.
Open a website to generate DNS traffic.
Enter dns in the display filter.
Inspect DNS queries and responses.
Stop capturing.
Save the capture file.
DNS Cache Commands
Windows
ipconfig /flushdns
macOS
sudo dscacheutil -flushcache
sudo killall -HUP mDNSResponder
Linux
sudo resolvectl flush-caches
Important Concepts
DNS stands for Domain Name System.
DNS translates domain names into IP addresses.
DNS commonly uses UDP port 53.
DNS can also use TCP port 53.
A DNS query requests information about a domain.
A DNS response contains the requested information or an error.
Viva Questions and Answers

Q1. What is DNS?

DNS translates human-readable domain names into IP addresses.

Q2. Which port does DNS use?

Port 53, usually UDP.

Q3. What is a DNS query?

A request for information about a domain name.

Q4. What is a DNS response?

The reply containing the requested DNS information or an error.

Q5. Why clear the DNS cache?

To reduce the chance that a cached result prevents a new DNS query.

Q6. What is a DNS cache?

Temporary storage of previously resolved DNS records.

Q7. What happens if DNS fails?

Domain names may not resolve to IP addresses, although direct IP communication may still work.

Experiment 6: UDP Client-Server Abbreviation Translator
Aim

To implement a UDP client-server application that expands abbreviations in a sentence.

Algorithm
Server-Side Algorithm
Create a UDP socket.
Bind the socket to the server IP address and port.
Wait for a datagram from a client.
Receive the sentence and client address.
Split the sentence into words.
Compare each word with the supported abbreviations.
Replace recognized abbreviations with their full forms.
Send the translated sentence to the client.
Repeat to handle additional requests.
Client-Side Algorithm
Create a UDP socket.
Read a sentence from the user.
Send the sentence to the server.
Wait for the server response.
Receive the translated sentence.
Display the result.
Close the socket.
Example

Input:

idk what to do atm

Output:

I don't know what to do at the moment

Example abbreviations:

Abbreviation	Expansion
atm	at the moment
tbh	to be honest
idk	I don't know
lol	laughing out loud
Important Concepts
UDP stands for User Datagram Protocol.
UDP is connectionless.
UDP does not guarantee delivery or ordering.
A socket is a communication endpoint.
bind() assigns a local address and port to a socket.
sendto() sends a datagram to a destination.
recvfrom() receives a datagram and can identify its sender.
Viva Questions and Answers

Q1. What is UDP?

UDP is a connectionless transport-layer protocol.

Q2. Why use UDP in this experiment?

It demonstrates datagram-based client-server communication without establishing a connection.

Q3. Does UDP guarantee delivery?

No. UDP does not guarantee delivery, ordering, or duplicate protection.

Q4. What is a socket?

A communication endpoint used by programs to send and receive data.

Q5. What is bind()?

It assigns a local IP address and port to a socket.

Q6. What is sendto()?

It sends a datagram to a specified destination address.

Q7. What is recvfrom()?

It receives a datagram and can provide the sender's address.

Q8. What is the difference between TCP and UDP server programming?

TCP commonly uses listen() and accept(). UDP commonly uses sendto() and recvfrom() without establishing a connection.

Experiment 8: Concurrent Time Server Using UDP
Aim

To implement a time server that sends the current system time to clients using UDP.

Algorithm
Server-Side Algorithm
Create a UDP socket.
Bind it to the server port.
Wait for a client request.
Receive the request and client address.
Read the current system time.
Convert the time into a string.
Send the time string to the client.
Repeat to process further requests.
Client-Side Algorithm
Create a UDP socket.
Specify the server IP address and port.
Send a request to the server.
Receive the time string.
Display the received time.
Close the socket.
Important Concepts
A time server provides time information to clients.
UDP does not require a connection handshake.
Concurrency means handling multiple tasks during overlapping periods.
A basic UDP server may process requests sequentially.
Threads or processes can be used for concurrent processing.
NTP is a standardized protocol for clock synchronization.
Viva Questions and Answers

Q1. What is a time server?

A server that provides time information to clients.

Q2. What is concurrency?

Handling multiple tasks or requests during overlapping periods.

Q3. Why use UDP?

UDP has low protocol overhead and does not require a connection handshake.

Q4. What is a port number?

A logical identifier used to direct network traffic to an application or service.

Q5. Is a simple time server the same as NTP?

No. NTP is a standardized clock synchronization protocol, whereas a simple lab server may only return a time string.

Q6. How can a server handle multiple clients?

It can process datagrams sequentially or use threads or processes for concurrent handling.

Experiment 9: Concurrent File Server
Aim

To implement a TCP file server that sends requested file contents and the server process ID to clients.

Algorithm
Server-Side Algorithm
Create a TCP socket.
Bind it to the server IP address and port.
Listen for incoming connections.
Accept a client connection.
Obtain the process ID using getpid().
Receive the requested filename.
Check whether the file exists and can be opened.
If the file exists, read its contents.
Send the file contents and process ID to the client.
Otherwise, send an error message.
Close the client connection.
Continue accepting other clients, using processes or threads for concurrent service.
Client-Side Algorithm
Create a TCP socket.
Connect to the server.
Enter the requested filename.
Send the filename to the server.
Receive the server response.
Display the file contents and process ID, or the error message.
Close the socket.
Important Concepts
TCP stands for Transmission Control Protocol.
TCP provides reliable, ordered byte-stream communication.
listen() prepares a TCP socket to accept connections.
accept() accepts a client connection.
getpid() returns the current process ID.
fork() creates a child process on Unix-like systems.
read() reads bytes from a file descriptor.
write() writes bytes to a file descriptor.
Viva Questions and Answers

Q1. What is TCP?

TCP is a connection-oriented transport protocol that provides reliable, ordered data delivery.

Q2. What is listen()?

It marks a TCP socket as a passive socket that can accept connection requests.

Q3. What is accept()?

It accepts a pending client connection and returns a socket for communication with that client.

Q4. What is a PID?

PID stands for Process ID, a number used by the operating system to identify a process.

Q5. What does fork() do?

It creates a child process on Unix-like systems.

Q6. Why use a concurrent file server?

It allows multiple clients to be served without one long-running request blocking all other clients.

Q7. What happens if the requested file does not exist?

The server sends an error message instead of the file contents.

Q8. What is the difference between read() and write()?

read() receives bytes from a file descriptor, while write() sends bytes to a file descriptor.

Important: TCP is a byte stream, not a message protocol. Programs must handle partial reads and writes and define message boundaries.

Experiment 11: Familiarizing Router Commands
Aim

To learn basic router commands and verify interface configuration, routing information, and connectivity.

Algorithm
Open the router CLI or network simulator.
Enter privileged EXEC mode.
Display interface IP addresses and status.
Display the routing table.
Inspect the running configuration.
Test connectivity using ping.
Examine the packet path using traceroute if needed.
Verify the router configuration.
Important Cisco IOS Commands
Command	Purpose
enable	Enter privileged EXEC mode
configure terminal	Enter global configuration mode
show ip interface brief	Display interface addresses and status
show interfaces	Display interface details
show ip route	Display the IPv4 routing table
show running-config	Display the active configuration
show version	Display device and software information
ping 192.168.1.1	Test connectivity
traceroute 192.168.1.1	Trace the path to a destination
show arp	Display the ARP table
Viva Questions and Answers

Q1. What is a router?

A device that forwards packets between IP networks.

Q2. What is a routing table?

A table containing destination networks and information about how to reach them.

Q3. What is a default gateway?

The router a host sends traffic to when the destination is outside its directly connected networks and no more specific route exists.

Q4. What is the difference between a switch and a router?

A switch primarily forwards frames within a LAN using MAC addresses. A router forwards packets between IP networks.

Q5. What does show ip interface brief display?

Interface names, IP addresses, and status.

Q6. What does up/up mean?

The interface and its line protocol are operational.

Q7. What does administratively down mean?

The interface has been disabled through configuration.

Experiment 12: Static Routing
Aim

To configure static routes and establish communication between different networks.

Algorithm
Create a topology containing routers and end devices.
Assign IP addresses and subnet masks.
Configure router interfaces and enable them.
Verify directly connected networks.
Identify remote networks.
Add static routes to remote networks.
Configure return routes where necessary.
Test connectivity between end devices using ping.
Verify the routing tables.
Cisco IOS Example

Suppose R1 must reach network 192.168.2.0/24 through next-hop address 10.0.0.2.

Router> enable
Router# configure terminal
Router(config)# ip route 192.168.2.0 255.255.255.0 10.0.0.2
Router(config)# end
Router# show ip route
Important Concepts
Static routing means manually configuring routes.
A next hop is the next router to which a packet is forwarded.
Static routes do not automatically adapt to topology changes.
A standard Cisco IOS static route has an administrative distance of 1 by default.
A static route must have a valid forwarding path to work correctly.
Viva Questions and Answers

Q1. What is static routing?

Manually configuring routes to destination networks.

Q2. What is a next hop?

The next router or network-layer destination to which a packet is forwarded.

Q3. What is the syntax of a static route?

ip route destination-network subnet-mask next-hop

Q4. What is the administrative distance of a standard static route on Cisco IOS?

Usually 1, unless configured otherwise.

Q5. What is the disadvantage of static routing?

It requires manual updates when network topology changes.

Q6. What is the difference between static and dynamic routing?

Static routes are configured manually, whereas dynamic routes are learned through routing protocols.

Experiment 13: RIPv2 Routing
Aim

To configure RIPv2 and enable dynamic routing between IPv4 networks.

Algorithm
Create a topology with multiple routers and LANs.
Assign IP addresses and subnet masks.
Enable router interfaces.
Verify direct connectivity.
Enter RIP configuration mode on each router.
Select RIP version 2.
Advertise the appropriate networks.
Disable automatic summarization when required.
Verify learned routes.
Test end-to-end connectivity.
Cisco IOS Example
Router> enable
Router# configure terminal
Router(config)# router rip
Router(config-router)# version 2
Router(config-router)# no auto-summary
Router(config-router)# network 192.168.1.0
Router(config-router)# network 10.0.0.0
Router(config-router)# end
Router# show ip route

Use network statements appropriate to the actual interfaces in your topology.

Important Concepts
RIP stands for Routing Information Protocol.
RIPv2 is a distance-vector routing protocol.
RIPv2 supports classless routing and subnet masks.
RIP uses hop count as its metric.
Maximum usable hop count is 15.
A metric of 16 indicates an unreachable destination.
RIP sends periodic updates, commonly every 30 seconds.
RIP routes are marked with R in the Cisco routing table.
Viva Questions and Answers

Q1. What is RIP?

A distance-vector interior gateway routing protocol.

Q2. What metric does RIP use?

Hop count.

Q3. What is the maximum hop count in RIP?

15 usable hops. A metric of 16 means unreachable.

Q4. What is the advantage of RIPv2 over RIPv1?

RIPv2 supports classless routing, subnet masks, and VLSM.

Q5. What is a distance-vector protocol?

A routing protocol in which routers learn routes from neighboring routers using information such as distance and next hop.

Q6. What does no auto-summary do?

It disables automatic classful network summarization.

Q7. What is RIP's main disadvantage?

Its hop-count limit and relatively slow convergence make it unsuitable for many large networks.

Experiment 14: OSPF Routing
Aim

To configure OSPF and establish dynamic routing between different networks.

Algorithm
Create a topology containing multiple routers and networks.
Assign IP addresses and subnet masks.
Enable router interfaces.
Verify directly connected links.
Configure OSPF on each router.
Assign an OSPF process ID.
Advertise the appropriate networks in the correct areas.
Ensure that neighboring routers can establish OSPF adjacencies.
Verify neighbor relationships and learned routes.
Test end-to-end connectivity.
Cisco IOS Example
Router> enable
Router# configure terminal
Router(config)# router ospf 1
Router(config-router)# network 192.168.1.0 0.0.0.255 area 0
Router(config-router)# network 10.0.0.0 0.0.0.3 area 0
Router(config-router)# end
Router# show ip ospf neighbor
Router# show ip route
Important Concepts
OSPF stands for Open Shortest Path First.
OSPF is a link-state routing protocol.
OSPF uses Dijkstra's shortest-path-first algorithm.
OSPF selects routes using cost.
Area 0 is the backbone area.
A wildcard mask is the inverse of the subnet mask.
The default administrative distance of OSPF on Cisco IOS is 110.
OSPF routes are marked with O in the Cisco routing table.
Viva Questions and Answers

Q1. What is OSPF?

An open-standard link-state interior gateway routing protocol.

Q2. Which algorithm does OSPF use?

Dijkstra's shortest-path-first algorithm.

Q3. What is an OSPF area?

A logical grouping of routers and links used to organize an OSPF network.

Q4. What is Area 0?

The OSPF backbone area.

Q5. What is OSPF cost?

A metric used to select routes, commonly related to interface bandwidth.

Q6. What is an OSPF neighbor?

A router with which OSPF establishes a neighbor relationship to exchange routing information.

Q7. What is the difference between RIP and OSPF?

RIP is distance-vector and uses hop count. OSPF is link-state and uses cost.

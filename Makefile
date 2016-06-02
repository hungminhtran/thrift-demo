all:
	server
	client
client:
	#make client
	g++ client.cpp  gen-cpp/*.cpp -o client.out -lthrift
server:
	#make server
	g++ service_server.cpp gen-cpp/*.cpp -o service_server.out -lthrift

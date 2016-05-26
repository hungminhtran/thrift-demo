all:
	#make server
	g++ service_server.cpp gen-cpp/*.cpp -o service_server.out -lthrift
	#make client
	g++ client.cpp  gen-cpp/*.cpp -o client.out -lthrift

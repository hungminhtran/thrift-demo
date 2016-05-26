all:
	#make server
	g++ MyFirstService_server.skeleton.cpp gen-cpp/*.cpp -o MyFirstService_server.skeleton.out -lthrift
	#make client
	g++ client.cpp  gen-cpp/*.cpp -o client.out -lthrift

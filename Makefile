all:
	#make server
	g++ gen-cpp/MyFirstService_server.skeleton.cpp gen-cpp/MyFirstService.h gen-cpp/MyFirstService.cpp gen-cpp/demo2_types.h gen-cpp/demo2_types.cpp gen-cpp/demo2_constants.h gen-cpp/demo2_constants.cpp -o gen-cpp/MyFirstService_server.skeleton.out -lthrift
	#make client
	g++ client.cpp  gen-cpp/MyFirstService.h gen-cpp/MyFirstService.cpp gen-cpp/demo2_types.h gen-cpp/demo2_types.cpp gen-cpp/demo2_constants.h gen-cpp/demo2_constants.cpp -o client.out -lthrift

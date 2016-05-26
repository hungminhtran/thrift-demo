// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "gen-cpp/MyFirstService.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

using namespace  ::myfirst;

class MyFirstServiceHandler : virtual public MyFirstServiceIf {
 public:
  MyFirstServiceHandler() {
    // Your initialization goes here
  }

  void log(const std::string& fileName) {
    // Your implementation goes here
    std::cout<<"file log is "<<fileName<<std::endl;
  }

  int32_t multiply(const int32_t number1, const int32_t number2) {
    // Your implementation goes here
    return number1 * number2;
  }

  int32_t get_log_size(const std::string& fileName) {
    // Your implementation goes here
    std::cout<<"file get size is "<<fileName<<std::endl;
    if (fileName == "") {
        MyError myError;
        myError.error_code = 123;
        myError.error_description = "what the hell, man?";
        throw myError;
    }
    return 9876;
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  shared_ptr<MyFirstServiceHandler> handler(new MyFirstServiceHandler());
  shared_ptr<TProcessor> processor(new MyFirstServiceProcessor(handler));
  shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}
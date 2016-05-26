#include <iostream>

#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>

#include "gen-cpp/MyFirstService.h"

using namespace std;
using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

using namespace  myfirst;

int main() {
  boost::shared_ptr<TTransport> socket(new TSocket("localhost", 9090));
  boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
  boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
  MyFirstServiceClient client(protocol);

  try {
    transport->open();
    client.log("logfile1234.log");
    cout << "log file abc"<<endl;
    client.send_multiply(2, 3);
    cout << "2 * 3 = " <<  client.recv_multiply()<< endl;
    client.send_get_log_size("logxyzt.log");
    cout<<"get log file "<<client.recv_get_log_size()<<endl;
    try {
        client.send_get_log_size("");
        cout<<"get log file "<<client.recv_get_log_size()<<endl;
    }
    catch (MyError myError){
        cout<<"exception catch successfully"<<endl<<"error code: "<<myError.error_code<<endl
        <<"error description: "<<myError.error_description<<endl;
    }
    transport->close();
  } catch (TException& tx) {
    cout << "ERROR: " << tx.what() << endl;
  }
}

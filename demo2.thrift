namespace java myfirst
namespace cpp myfirst

//You can define name for your type
//Usable for primarily for integer
typedef i32 int

//simple exeption
exception MyError {
    1: int error_code,
    2: string error_description,
}

//here starts the server definition
service MyFirstService {

    //log method, it saves tiemstamp to given file
    oneway void log(1:string fileName),

    //multiply method - return result of multiplication of two integer; it returns integer as well
    int multiply(1:int number1, 2:int number2),

    //get log size method - returns size of log file; throws exeption when problems occur
    int get_log_size(1:string fileName) throws (1:MyError error),

}

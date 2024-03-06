/*要在C++中实现HTTP协议栈，需要使用一个现有的网络编程库。一些常用的库包括libevent、libev、Boost.Asio和Poco等。
以下是一个简单的示例，使用Boost.Asio库实现一个基本的HTTP服务器：*/

// #include <iostream>
// #include <boost/asio.hpp>
// #include <boost/bind.hpp>
// #include <boost/function.hpp>
// #include <boost/shared_ptr.hpp>
// #include <boost/enable_shared_from_this.hpp>

// using namespace std;
// using namespace boost::asio;

// class session : public enable_shared_from_this<session> {
// public:
//     typedef function<void(const string &)> callback_t;

//     session(io_service &io, const string &host, const string &port, const callback_t &callback)
//         : socket_(io), host_(host), port_(port), callback_(callback) {
//     }

//     void start() {
//         async_connect(socket_, host_, port_, boost::bind(&session::handle_connect, shared_from_this(),
//                                                          boost::asio::placeholders::error));
//     }

// private:
//     void handle_connect(const error_code &error) {
//         if (!error) {
//             async_read(socket_, buffer(data_, max_length), boost::bind(&session::handle_read, shared_from_this(),
//                                                                       boost::asio::placeholders::error,
//                                                                       boost::asio::placeholders::bytes_transferred));
//         } else {
//             callback_(error.message());
//         }
//     }

//     void handle_read(const error_code &error, size_t bytes_transferred) {
//         if (!error) {
//             callback_(data_.substr(0, bytes_transferred));
//             data_.erase(0, bytes_transferred);
//             async_read(socket_, buffer(data_, max_length), boost::bind(&session::handle_read, shared_from_this(),
//                                                                      boost::asio::placeholders::error,
//                                                                      boost::asio::placeholders::bytes_transferred));
//         } else {
//             callback_(error.message());
//         }
//     }

//     socket socket_;
//     string host_;
//     string port_;
//     callback_t callback_;
//     enum { max_length = 1024 };
//     char data_[max_length];
// };

// class http_server {
// public:
//     http_server(io_service &io) : acceptor_(io, tcp::endpoint(tcp::v4(), 80)), socket_(io) {
//         start();
//     }

// private:
//     void start() {
//         acceptor_.async_accept(socket_, boost::bind(&http_server::handle_accept, this, boost::asio::placeholders::error));
//     }

//     void handle_accept(const error_code &error) {
//         if (!error) {
//             session session(io_, socket_.remote_endpoint().address().to_string(), socket_.remote_endpoint().port(), boost::bind(&http_server::on_message, this, _1));
//             session.start();
//         } else {
//             start();
//         }
//     }

//     void on_message(const string &message) {
//         cout << message << endl;
//     }

//     tcp::acceptor acceptor_;
//     tcp::socket socket_;
// };

#include <iostream>
#include <list>
#include <boost/any.hpp>

typedef std::list<boost::any> list_any;

//关键部分：可以存放任意类型的对象
void fill_list(list_any& la)
{
    la.push_back(10);//存放常数
    la.push_back( std::string("dyunze") );//存放字符串对象；注意la.push_back(“dyunze”)错误，因为会被当错字符串数组
}

//根据类型进行显示
void show_list(list_any& la)
{
    list_any::iterator it;
    boost::any anyone;

    for( it = la.begin(); it != la.end(); it++ )
    {
        anyone = *it;

        if( anyone.type() == typeid(int) )
            std::cout<<boost::any_cast<int>(*it)<<std::endl;
        else if( anyone.type() == typeid(std::string) )
            std::cout<<boost::any_cast<std::string>(*it).c_str()<<std::endl;
    }
}

int main()
{
    list_any la;
    fill_list(la);
    show_list(la);

    return 0;
}
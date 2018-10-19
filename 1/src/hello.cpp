#include <bits/stdc++.h>
#include <cppcms/application.h>
#include <cppcms/applications_pool.h>
#include <cppcms/http_response.h>
#include <cppcms/service.h>

using namespace std;

class hello_world : public cppcms::application {

public:

    hello_world(cppcms::service& test_service) : cppcms::application(test_service) {}

    virtual void main(string url);    
};

void hello_world::main(string url) {
    string text = "<html><body><h4>Hello World</h4></body></html>";
    response().out() << text << endl;
}


int main(int argc, char* argv[]) {
    try {
        cppcms::service test_service(argc, argv);
        test_service.applications_pool().mount(cppcms::applications_factory<hello_world>());
        test_service.run();
    } 
    catch(exception const& e) {
        cerr << e.what() << endl; 
    }
    return 0;
}

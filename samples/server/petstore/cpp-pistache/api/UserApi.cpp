/**
* OpenAPI Petstore
* This is a sample server Petstore server. For this sample, you can use the api key `special-key` to test the authorization filters.
*
* OpenAPI spec version: 1.0.0
* 
*
* NOTE: This class is auto generated by OpenAPI Generator (https://openapi-generator.tech).
* https://openapi-generator.tech
* Do not edit the class manually.
*/

#include "UserApi.h"
#include "Helpers.h"

namespace org {
namespace openapitools {
namespace server {
namespace api {

using namespace org::openapitools::server::helpers;
using namespace org::openapitools::server::model;

UserApi::UserApi(Pistache::Address addr)
    : httpEndpoint(addr)
{ };

void UserApi::init(size_t thr = 2) {
    auto opts = Pistache::Http::Endpoint::options()
        .threads(thr)
        .flags(Pistache::Tcp::Options::InstallSignalHandler);
    httpEndpoint.init(opts);
    setupRoutes();
}

void UserApi::start() {
    httpEndpoint.setHandler(router.handler());
    httpEndpoint.serve();
}

void UserApi::shutdown() {
    httpEndpoint.shutdown();
}

void UserApi::setupRoutes() {
    using namespace Pistache::Rest;

    Routes::Post(router, base + "/user", Routes::bind(&UserApi::create_user_handler, this));
    Routes::Post(router, base + "/user/createWithArray", Routes::bind(&UserApi::create_users_with_array_input_handler, this));
    Routes::Post(router, base + "/user/createWithList", Routes::bind(&UserApi::create_users_with_list_input_handler, this));
    Routes::Delete(router, base + "/user/:username", Routes::bind(&UserApi::delete_user_handler, this));
    Routes::Get(router, base + "/user/:username", Routes::bind(&UserApi::get_user_by_name_handler, this));
    Routes::Get(router, base + "/user/login", Routes::bind(&UserApi::login_user_handler, this));
    Routes::Get(router, base + "/user/logout", Routes::bind(&UserApi::logout_user_handler, this));
    Routes::Put(router, base + "/user/:username", Routes::bind(&UserApi::update_user_handler, this));

    // Default handler, called when a route is not found
    router.addCustomHandler(Routes::bind(&UserApi::user_api_default_handler, this));
}

void UserApi::create_user_handler(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response) {

    // Getting the body param
    
    User user;
    
    try {
      nlohmann::json request_body = nlohmann::json::parse(request.body());
    
      user.fromJson(request_body);
    
      this->create_user(user, response);
    } catch (std::runtime_error & e) {
      //send a 400 error
      response.send(Pistache::Http::Code::Bad_Request, e.what());
      return;
    }

}
void UserApi::create_users_with_array_input_handler(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response) {

    // Getting the body param
    std::vector<User> user;
    
    try {
      nlohmann::json request_body = nlohmann::json::parse(request.body());
      user =   ModelArrayHelper::fromJson<User>(request_body);
      this->create_users_with_array_input(user, response);
    } catch (std::runtime_error & e) {
      //send a 400 error
      response.send(Pistache::Http::Code::Bad_Request, e.what());
      return;
    }

}
void UserApi::create_users_with_list_input_handler(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response) {

    // Getting the body param
    std::vector<User> user;
    
    try {
      nlohmann::json request_body = nlohmann::json::parse(request.body());
      user =   ModelArrayHelper::fromJson<User>(request_body);
      this->create_users_with_list_input(user, response);
    } catch (std::runtime_error & e) {
      //send a 400 error
      response.send(Pistache::Http::Code::Bad_Request, e.what());
      return;
    }

}
void UserApi::delete_user_handler(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response) {
    // Getting the path params
    auto username = request.param(":username").as<std::string>();
    
    try {
      this->delete_user(username, response);
    } catch (std::runtime_error & e) {
      //send a 400 error
      response.send(Pistache::Http::Code::Bad_Request, e.what());
      return;
    }

}
void UserApi::get_user_by_name_handler(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response) {
    // Getting the path params
    auto username = request.param(":username").as<std::string>();
    
    try {
      this->get_user_by_name(username, response);
    } catch (std::runtime_error & e) {
      //send a 400 error
      response.send(Pistache::Http::Code::Bad_Request, e.what());
      return;
    }

}
void UserApi::login_user_handler(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response) {

    // Getting the query params
    auto usernameQuery = request.query().get("username");
    Pistache::Optional<std::string> username;
    if(!usernameQuery.isEmpty()){
        std::string value;
        if(fromStringValue(usernameQuery.get(), value)){
            username = Pistache::Some(value);
        }
    }
    auto passwordQuery = request.query().get("password");
    Pistache::Optional<std::string> password;
    if(!passwordQuery.isEmpty()){
        std::string value;
        if(fromStringValue(passwordQuery.get(), value)){
            password = Pistache::Some(value);
        }
    }
    
    try {
      this->login_user(username, password, response);
    } catch (std::runtime_error & e) {
      //send a 400 error
      response.send(Pistache::Http::Code::Bad_Request, e.what());
      return;
    }

}
void UserApi::logout_user_handler(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response) {

    try {
      this->logout_user(response);
    } catch (std::runtime_error & e) {
      //send a 400 error
      response.send(Pistache::Http::Code::Bad_Request, e.what());
      return;
    }

}
void UserApi::update_user_handler(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response) {
    // Getting the path params
    auto username = request.param(":username").as<std::string>();
    
    // Getting the body param
    
    User user;
    
    try {
      nlohmann::json request_body = nlohmann::json::parse(request.body());
    
      user.fromJson(request_body);
    
      this->update_user(username, user, response);
    } catch (std::runtime_error & e) {
      //send a 400 error
      response.send(Pistache::Http::Code::Bad_Request, e.what());
      return;
    }

}

void UserApi::user_api_default_handler(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response) {
    response.send(Pistache::Http::Code::Not_Found, "The requested method does not exist");
}

}
}
}
}


#pragma once

#include <drogon/HttpSimpleController.h>

using namespace drogon;

class test_controller : public drogon::HttpSimpleController<test_controller>
{
public:
  void asyncHandleHttpRequest(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback) override;
  PATH_LIST_BEGIN
  // list path definitions here;
  // PATH_ADD("/path", "filter1", "filter2", HttpMethod1, HttpMethod2...);
  // PATH_ADD("/", Get, Post);
  PATH_ADD("/test", Post);
  PATH_LIST_END
};

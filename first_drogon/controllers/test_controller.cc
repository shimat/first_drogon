#include "test_controller.h"
#include <opencv2/opencv.hpp>

void test_controller::asyncHandleHttpRequest(
    const HttpRequestPtr &req,
    std::function<void(const HttpResponsePtr &)> &&callback)
{
    // write your application logic here
    LOG_DEBUG << "bodyData: " << req->bodyData();
    LOG_DEBUG << "contentType: " << req->contentType();

    for (const auto &pair : req->getParameters())
    {
        LOG_DEBUG << "param[" << pair.first << "] = " << req->contentType();
    }

    Json::Reader jsonReader;
    Json::Value requestJson;
    jsonReader.parse(req->bodyData(), requestJson);

    // auto resp = HttpResponse::newHttpResponse();
    //  resp->setBody("<h1>Hello World!</h1>");

    Json::Value ret;
    ret["message"] = requestJson["message"];
    ret["tick_count"] = cv::getTickCount();

    auto response = HttpResponse::newHttpJsonResponse(ret);
    response->setStatusCode(k200OK);
    response->setContentTypeCode(CT_APPLICATION_JSON);

    callback(response);
}

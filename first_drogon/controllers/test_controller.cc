#include "test_controller.h"

void test_controller::asyncHandleHttpRequest(
    const HttpRequestPtr &req,
    std::function<void(const HttpResponsePtr &)> &&callback)
{
    // write your application logic here
    auto resp = HttpResponse::newHttpResponse(); // 新しいレスポンスインスタンスを生成
    resp->setStatusCode(k200OK);                 // HTTPステータスコード 200に設定
    resp->setContentTypeCode(CT_TEXT_HTML);      // Header: Content typeをHTMLにする
    resp->setBody("<h1>Hello World!</h1>");      // Body:
    callback(resp);
}

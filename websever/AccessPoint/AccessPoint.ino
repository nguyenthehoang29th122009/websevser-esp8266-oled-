#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
 
ESP8266WebServer server(80);
 
String webPage =
{
  "<!DOCTYPE html>"
"<!DOCTYPE html>"// Lưu ý: Ở đầu và cuối mỗi dòng chúng ta nhé thêm 1 dấu nháy đôi “ và tất cả các dấu nháy đôi phía trong phải sửa thành dấu nháy đơn ‘
"<html lang='vi'>"
"<head>"
"    <meta charset='UTF-8'>"
"    <meta name='viewport' content='width=device-width, initial-scale=1.0'>"
"    <title>web sếch</title>"
"    <style>"
"        body {"
"            font-family: Arial, sans-serif;"
"            line-height: 1.6;"
"            margin: 0;"
"            padding: 0;"
"            background-color: #f4f4f4;"
"       }"
"        .container {"
"            width: 80%;"
"            margin: auto;"
"            overflow: hidden;"
"        }"
"        header {"
"            background: #333;"
"            color: #EB41A4;"
"            padding-top: 30px;"
"            min-height: 70px;"
"            border-bottom: #E378FF 3px solid;"
"        }"
"        header a {"
"            color: #fff;"
"            text-decoration: none;"
"            text-transform: uppercase;"
"            font-size: 16px;"
"        }"
"        header ul {"
"            padding: 0;"
"            list-style: none;"
"        }"
"        header li {"
"            display: inline;"
"            padding: 0 20px 0 20px;"
"        }"
"        header .highlight, header .current a {"
"            color: #77aaff;"
"        }"
"        header .branding {"
"            float: left;"
"        }"
"        header .branding h1 {"
"            margin: 0;"
"        }"
"        header nav {"
"            float: right;"
"            margin-top: 10px;"
"        }"
"        .bio {"
"            padding: 20px;"
"            background: #fff;"
"            margin-top: 20px;"
"        }"
"        .bio h2 {"
"            text-align: center;"
"            color: #333;"
"        }"
"        .bio p {"
"            text-align: justify;"
"            color: #666;"
"        }"
"        .buttons {"
"            text-align: center;"
"            margin-top: 20px;"
"        }"
"        .buttons a {"
"            display: inline-block;"
"            margin: 10px;"
"            padding: 10px 20px;"
"            background: #333;"
"            color: #fff;"
"            text-decoration: none;"
"            border-radius: 5px;"
"            transition: background 0.3s ease;"
"        }"
"        .buttons a:hover {"
"            background: #5F53CE;"
"        }"
"    </style>"
"</head>"
"<body>"
"    <header>"
"        <div class='container'>"
"            <div class='branding'>"
"                <h1>Thông tin cá nhân</h1>"
"            </div>"
"            <nav>"
"                <ul>"
"                    <li><a href='#' class='current'>Trang chủ</a></li>"
"                    <li><a href='#'>Giới thiệu</a></li>"
"                    <li><a href='#'>Liên hệ</a></li>"
"                </ul>"
"            </nav>"
"        </div>"
"    </header>"
"    <div class='container'>"
"        <section class='bio'>"
"            <h2>Về tôi</h2>"
"            <p>Xin chào! Tôi là Nguyễn Thế Hoàng, một lập trình viên đam mê công nghệ và lập trình web. Tôi có kinh nghiệm làm việc với nhiều ngôn ngữ lập trình khác nhau như HTML, CSS, JavaScript và Python. Tôi luôn tìm kiếm cơ hội học hỏi và phát triển bản thân trong lĩnh vực công nghệ thông tin.</p>"
"            <p>Tôi thích tham gia vào các dự án mã nguồn mở ví dụ như web sếch hentai và chia sẻ kiến thức với cộng đồng. Ngoài ra, tôi cũng quan tâm đến việc phát triển các ứng dụng di động và Internet of Things (IoT). Khi không làm việc, tôi thích sục cặc và bốn lù trẻ em.</p>"
"            <div class='buttons'>"
"                <a href='https://www.facebook.com/BomaytenHoang' target='_blank'>Facebook</a>"
"                <a href='https://github.com/nguyenthehoang29th122009' target='_blank'>GitHub</a>"
"                <a href='https://www.tiktok.com/@ngunhucho29th1209' target='_blank'>TikTok</a>"
"            </div>"
"        </section>"
"    </div>"
"</body>"
"</html>"
};
void Home()
{
  server.send(200, "text/html", webPage);
}
void setup()
{
  Serial.begin(9600);
  while (WiFi.softAP("ESP8266 WiFI", "12345678") == false) 
   {
     Serial.print(".");
     delay(300);
   }
  IPAddress myIP = WiFi.softAPIP();
  server.on("/", Home);
  server.begin();
}
void loop()
{
  server.handleClient();
}
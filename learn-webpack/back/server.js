const http = require("http");

http.createServer(function(req, res){
    // console.log(req);
    console.log("请求头: " + req.headers);
    console.log("http版本: " + req.httpVersion);
    res.write("here is a http response");
    res.writeHead(200, ok ,{
        'Content-Type': "text/plain"
    })
    res.end('ok');
}).listen(3000);
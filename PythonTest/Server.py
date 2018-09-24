from http.server import BaseHTTPRequestHandler
import json
# reference: https://blog.anvileight.com/posts/simple-python-http-server/


class Server(BaseHTTPRequestHandler):

    def do_GET(self):
        self.send_response(200)
        self.send_header('Content-type', 'text/html'.encode())
        self.end_headers()
        self.wfile.write("Hello, world!".encode())
        return


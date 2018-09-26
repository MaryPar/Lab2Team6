from http.server import BaseHTTPRequestHandler
# reference: https://blog.anvileight.com/posts/simple-python-http-server/


class Server(BaseHTTPRequestHandler):

    state = '2'

    def do_GET(self):
        self.send_response(200)
        self.send_header('Content-type', 'text/plain'.encode())
        self.end_headers()
        self.wfile.write(self.state.encode())

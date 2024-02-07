#!/usr/bin/env python3

from http.server import BaseHTTPRequestHandler, HTTPServer
import binascii

class RequestHandler(BaseHTTPRequestHandler):
    def do_GET(self):
        self.send_response(200)
        self.send_header("Content-type", "text/plain")
        self.end_headers()
        print(f"get_data: {self.path.encode().decode('utf-8')}")
        self.wfile.write(self.path.encode())

    def do_POST(self):
        content_length = int(self.headers['Content-Length'])
        post_data = self.rfile.read(content_length)
        print(f"post_data: {post_data}")
        print(f"post_data: {post_data.decode('utf-8')}")
        self.send_response(200)
        self.send_header("Content-type", "text/plain")
        self.end_headers()
        self.wfile.write(post_data)

def main():
    try:
        server = HTTPServer(('', 8000), RequestHandler)
        print('Echo server is running...')
        server.serve_forever()
    except KeyboardInterrupt:
        print('^C received, shutting down the server')
        server.socket.close()

if __name__ == '__main__':
    main()
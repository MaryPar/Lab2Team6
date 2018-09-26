from http.server import HTTPServer
from PythonTest.Server import Server as S
import time


def main():
    print("Beginning main function")
    httpd = HTTPServer(('', 8000), S)
    httpd.serve_forever()


if __name__ == '__main__':
    main()











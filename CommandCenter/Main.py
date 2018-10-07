from http.server import HTTPServer
from PythonTest.Server import Server as S
import time
import logging
import asyncio
import os
from hbmqtt.broker import Broker
import yaml

with open('test.yaml', 'r') as f:
    doc = yaml.load(f)

@asyncio.coroutine
def broker_coro():
    broker = Broker(doc)
    yield from broker.start()


if __name__ == '__main__':
    formatter = "[%(asctime)s] :: %(levelname)s :: %(name)s :: %(message)s"
    logging.basicConfig(level=logging.INFO, format=formatter)
    asyncio.get_event_loop().run_until_complete(broker_coro())
    asyncio.get_event_loop().run_forever()





# def main():
#     print("Beginning main function")
#     httpd = HTTPServer(('', 8000), S)
#     httpd.serve_forever()
#
#
# if __name__ == '__main__':
#     main()











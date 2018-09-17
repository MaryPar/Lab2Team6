import requests
import json
from pprint import pprint

# url = "http://172.16.0.1:8001/FieldData/GetData"
# r = requests.get(url)
# data = r.json()
# print(data)
# ball = data['Ball']
# print(ball)

with open('FieldData.json') as f:
    data = json.load(f)

pprint(data)
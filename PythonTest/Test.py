import requests
import json

url = "http://172.16.0.1:8001/FieldData/GetData"
r = requests.get(url)
data = r.json()
print(data)
ball = data['Ball']
print(ball)
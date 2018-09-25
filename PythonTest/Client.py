import requests

url = "http://192.168.137.33:80/"
data = requests.get(url)
text = str(data.text)
print(text)

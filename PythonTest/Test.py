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

print(data['Corners'])

xcoords = []
ycoords = []

for d in data['Corners']:
    xcoords.append(d['X'])
    ycoords.append(d['Y'])

xcoords.sort()
ycoords.sort()
xmax = xcoords[3]
xmin = xcoords[0]
ymax = ycoords[3]
ymin = ycoords[0]
xrange = xmax - xmin
yrange = ymax - ymin

print("coords: " + str(xcoords) + " "+ str(ycoords))
print("max: " + str(xmax) + " " + str(ymax))
print("min: " + str(xmin) + " " + str(ymin))
print("range: " + str(xrange) + " " + str(yrange))

# pixmapx maps a pixel value px to a real value in the range [0,10]
def pixmapx(px):
    return 10 - 10 * (xmax - px) / xrange

# pixmapy maps a pixel value py to a real value in the range [0,10]
def pixmapy(py):
    return 10 - 10 * (ymax - py) / yrange


print("ball: " + str(data['Ball']))
print("ballX: " + str(pixmapx(data['Ball']['Object Center']['X'])))
print("ballY: " + str(pixmapy(data['Ball']['Object Center']['Y'])))

for x in (0, xmin, xrange/2, xmax):
    print(pixmapx(x))

for y in (0, ymin, yrange/2, ymax):
    print(pixmapy(y))
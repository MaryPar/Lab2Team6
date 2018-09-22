import requests
import json
from http.server import HTTPServer
from PythonTest.Server import Server as S
from pprint import pprint

# url = "http://172.16.0.1:8001/FieldData/GetData"
# f = requests.get(url)

f = open('FieldData.json', 'r')
data = json.load(f)

print("Original Object: " + str(data))

# easier object names and access
ball = (data['Ball']['Object Center']['X'], data['Ball']['Object Center']['Y'])
corners = data['Corners']
redteam = {
    'circle': (data['Red Team Data']['Circle']['Object Center']['X'],
               data['Red Team Data']['Circle']['Object Center']['Y']),
    'square': (data['Red Team Data']['Square']['Object Center']['X'],
               data['Red Team Data']['Square']['Object Center']['Y']),
    'triangle': (data['Red Team Data']['Triangle']['Object Center']['X'],
                 data['Red Team Data']['Triangle']['Object Center']['Y'])}
blueteam = {
    'circle': (data['Blue Team Data']['Circle']['Object Center']['X'],
               data['Blue Team Data']['Circle']['Object Center']['Y']),
    'square': (data['Blue Team Data']['Square']['Object Center']['X'],
               data['Blue Team Data']['Square']['Object Center']['Y']),
    'triangle': (data['Blue Team Data']['Triangle']['Object Center']['X'],
                 data['Blue Team Data']['Triangle']['Object Center']['Y'])}

xcoords = []
ycoords = []

# grabbing the x and y coordinates of the pairs in corners
for d in corners:
    xcoords.append(d['X'])
    ycoords.append(d['Y'])

# sort the coordinates ascending so we can find max, min, and range for x and y
xcoords.sort()
ycoords.sort()
xmax = xcoords[3]
xmin = xcoords[0]
ymax = ycoords[3]
ymin = ycoords[0]
xrange = xmax - xmin
yrange = ymax - ymin

print("Original Ball: " + str(ball))
print("Coords: " + str(xcoords) + " "+ str(ycoords))
print("Max (x,y): " + str(xmax) + " " + str(ymax))
print("Min (x,y): " + str(xmin) + " " + str(ymin))
print("Range (x,y): " + str(xrange) + " " + str(yrange))


# pixelmap maps a pixel pair (px, py) to a real coordinate pair (rx, ry) on a new map with ranges 0<=x<=8 and 0<=y<=4
def pixelmap(px, py):
    return 8 * (px - xmin) / xrange, 4 * (1 - (py - ymin) / yrange)


ballpos = pixelmap(ball[0], ball[1])
rtrianglepos = pixelmap(redteam['triangle'][0], redteam['triangle'][1])
print("Real Ball Position: " + str(ballpos))
print("Red Triangle Position: " + str(rtrianglepos))

httpd = HTTPServer(('', 8000), S)
httpd.serve_forever()
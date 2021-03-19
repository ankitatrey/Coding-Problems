import math, random
import matplotlib.pyplot as plt

class Location():
	def __init__(self, x, y):
		self.x = x
		self.y = y
	def move(self, xc, yc):
		return Location(self.x+float(xc), self.y+float(yc))
	def getCoords(self):
		return self.x,self.y
	def getDist(self, other):
		ox, oy = other.getCoords()
		xDist = self.x - ox
		yDist = self.y - oy
		return math.sqrt(xDist**2 + yDist**2)

class CompassPt():
	possibles = ['E', 'W', 'N', 'S']
	def __init__(self, pt):
		if pt in self.possibles: self.pt = pt
		else: raise ValueError('in Compass.__init__')
	def move(self, dist):
		if self.pt == 'N': return (0, dist)
		if self.pt == 'S': return (0, -dist)
		if self.pt == 'E': return (dist, 0)
		if self.pt == 'W': return (-dist, 0)
		else: raise ValueError('in Compass.move')

class Field():
	def __init__(self, drunk, loc):
		self.drunk = drunk
		self.loc = loc
	def move(self, cp, dist):
		oldLoc = self.loc
		xc, yc = cp.move(dist)
		self.loc = oldLoc.move(xc, yc)
	def getLoc(self):
		return self.loc
	def getDrunk(self):
		return self.drunk


class Drunk():
	def __init__(self, name):
		self.name = name
	def move(self, field, time = 1):
		if field.getDrunk() != self:
			raise ValueError('Drunk.move is called with Drunk not in field.')
		for i in range(time):
			pt = CompassPt(random.choice(CompassPt.possibles))
			field.move(pt, i)


def performTrial(time, f):
	start = f.getLoc()
	distances = [0.0]
	for t in range(1, time+1):
		f.getDrunk().move(f)
		newLoc = f.getLoc()
		distance = newLoc.getDist(start)
		distances.append(distance)
	return distances

#assert False

drunk = Drunk('Ankit Atrey')
for i in range(3):
	f = Field(drunk, Location(0,0))
	distances = performTrial(500, f)
	plt.plot(distances)

plt.title("Ankit's random walks")
plt.xlabel('Time')
plt.ylabel('Distance from origin')

#plt.show()
#assert False

def performSim(time, numTrials):
   distLists = []
   for trial in range(numTrials):
        d = Drunk('Drunk' + str(trial))
        f = Field(d, Location(0, 0))
        distances = performTrial(time, f)
        distLists.append(distances)
   return distLists


def ansQuest(maxTime, numTrials):
   means = []
   distLists = performSim(maxTime, numTrials)
   for t in range(maxTime + 1):
        tot = 0.0
        for distL in distLists:
            tot += distL[t]
        means.append(tot/len(distL))
   plt.figure()
   plt.plot(means)
   plt.ylabel('distance')
   plt.xlabel('time')
   plt.title('Average Distance vs. Time (' + str(len(distLists)) + ' trials)')

ansQuest(500, 300)
plt.show()

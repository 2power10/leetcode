import sys
import operator

# Definition for a point.
class Point(object):
    def __init__(self, a=0, b=0):
        self.x = a
        self.y = b

class iPoint(object):

    def __init__(self, a=0, b=0):
        self.x = a
        self.y = b
    def equals(self, point2):
        return self.x == point2.x and self.y == point2.y

    def __hash__(self):
        return int(self.x) ^ int(self.y)

    def __eq__(self, other):
        return self.x == other.x and self.y == other.y

    def get_line(self, point2):
        if self.equals(point2):
            return None

        if self.x == point2.x:
            ang = sys.float_info.max
            cross = self.x
        elif self.y == point2.y:
            ang = 0
            cross = self.y
        else:
            ang = float(self.y - point2.y) / float(self.x - point2.x)
            cross = self.x - self.y / ang
        return Line(ang, cross)

    def __str__(self):
        return "x: " + str(self.x) + " y: " + str(self.y)

class Line(object):
    def __init__(self, ang, cross):
        self.ang = ang
        self.cross = cross

    def __eq__(self, other):
        return self.ang == other.ang and self.cross == other.cross

    def __hash__(self):
        return int(-1 * self.ang * self.cross) ^ int(self.cross)

    def __str__(self):
        return "angle: " + str(self.ang) + " cross: " + str(self.cross)

class Solution(object):
    def maxPoints(self, points):
        lineMap = {}
        maxCLine = None
        dupPointMap = {}

        ipoints = []
        for point in points:
            ipoints.append(iPoint(point.x, point.y))

        for i in range(0, len(ipoints) - 1):
            startPoint = ipoints[i]
            for j in range(i + 1, len(ipoints)):
                toPoint = ipoints[j]
                line = startPoint.get_line(toPoint)
                if line is not None:
                    if line not in lineMap:
                        lineMap[line] = set()

                    lineMap[line].add(startPoint)
                    lineMap[line].add(toPoint)

                    if maxCLine is None:
                        maxCLine = line
                    if len(lineMap[line]) > len(lineMap[maxCLine]):
                        maxCLine = line

                else:
                    if startPoint not in dupPointMap:
                        dupPointMap[startPoint] = 1
                    else:
                        dupPointMap[startPoint] += 1

        if maxCLine is None:
            return 0
        pointCount = len(lineMap[maxCLine])

        print dupPointMap
        print lineMap[maxCLine]

        for p in lineMap[maxCLine]:
            if p in dupPointMap:
                pointCount += dupPointMap[p]

        return pointCount

def tc1():
    s = Solution()
    coll = []
    coll.append(Point(0 , 0))
    coll.append(Point(10, 10))
    coll.append(Point(20, 20))
    coll.append(Point(10 , 10))
    coll.append(Point(25, 3))
    coll.append(Point(3 , 1))
    coll.append(Point(2 , 324))

    c = s.maxPoints(coll)
    print c

def tc2():
    s = Solution()
    coll = []
    coll.append(Point(0 , 0))
    coll.append(Point(10, 10))
    coll.append(Point(20, 20))
    coll.append(Point(10 , 0))
    coll.append(Point(25, 0))
    coll.append(Point(3 , 0))
    coll.append(Point(2 , 0))

    c = s.maxPoints(coll)
    print c

if __name__ == "__main__":
    p = iPoint(0, 10)
    p2 = iPoint(20, 20)
    p3 = iPoint(40, 30)
    l1 = p.get_line(p2)
    l2 = p.get_line(p3)
    print l1
    print l2
    print l1.__hash__()
    print l2.__hash__()

    s = set()
    p11 = Point(10,10)
    p22 = Point(10,10)
    s.add(p11)
    s.add(p22)
    print(s)
    tc1()

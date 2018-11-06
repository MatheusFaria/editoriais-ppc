import sys

for line in sys.stdin:
    x1, y1, x2, y2 = map(int, line.split(' '))

    print(max(abs(x1 - x2), abs(y1 - y2)))

import sys
import os

def docat(file=sys.stdin):
    while True:
        line = file.readline()
        if not line:
            break

        sys.stdout.write(line)

if sys.stdin.isatty():
    # keyboard
    if len(sys.argv) > 1:
        file = open(sys.argv[1])
        docat(file)
        file.close()
    else:
        docat()
else:
    # pipe
    docat()
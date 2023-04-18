#!/usr/bin/python

from optparse import OptionParser
import random

def main(size):
    size = size
    max_number = size * 2
    for i in range(size):
        print random.randint(1, max_number)


if __name__ == "__main__":
    usage = "usage: %prog SIZE"
    parser = OptionParser(usage=usage)
    options, args = parser.parse_args()
    if len(args) != 1:
        parser.error("Provise size as an argument")

    main(int(args[0]))

#!/usr/bin/env python3

import keylogging
import threading

def keyboard_listener():
 for event in keylogging.iter_keypresses():
     print(event)

def main():
 listener = threading.Thread(target=keyboard_listener)
 listener.start()

if __name__ == '__main__':
 main()

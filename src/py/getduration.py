#!/usr/bin/env python3
from glob import glob
from mutagen.mp3 import MP3

print(f"Total Duration: {(duration := sum(int(MP3(i).info.length) for i in glob('/home/mitchf/Music/*.mp3'))) // 3600:02}:{(duration := duration % 3600) // 60:02}:{duration % 60:02}")

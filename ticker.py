from time import time
from time import sleep

count = 30 * 60
start = time()
while time() - start < count:
    print('     \r', end = '')
    print(int((count - (time() - start)) / 60), end = '')
    sleep(1)
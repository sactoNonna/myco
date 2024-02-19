import time
from timeCheck import timeCheck

if __name__ == '__main__':
    tc = timeCheck()
    tc.stampStartTime("TimeStamp 1:")
    time.sleep(2)
    tc.showTimeTaken("TimeStamp 1:")

    time.sleep(3)
    
    tc.stampStartTime("TimeStamp 2:")
    time.sleep(5)
    tc.showTimeTaken("TimeStamp 2:")
    print('Done')
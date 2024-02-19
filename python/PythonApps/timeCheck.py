import time

class timeCheck:
    def __init__(self):
        self.timeStamp = {}
        
    def stampStartTime(self, checkpoint):
        curTime = time.time()    
        self.timeStamp[checkpoint] = curTime
        FD = time.localtime(int(round(curTime)))
        FDStr = time.strftime("%H:%M:%S", FD) 
        print(f"{checkpoint} at: {FDStr}")

    def showTimeTaken(self, checkpoint):        
        curTime = time.time()            
        FD = time.localtime(int(round(curTime)))
        FDStr = time.strftime("%H:%M:%S", FD) 
        print(f'{checkpoint} finished at: {FDStr}')  
        
        FD = time.gmtime(int(round(curTime - self.timeStamp[checkpoint])))
        FDStr = time.strftime("%H:%M:%S", FD) 
        print(f'\tTime spent by {checkpoint}: {FDStr}') 
        
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
import numpy as np 


class Robot: 

    x = np.zeros((3,1)) # State is pos (x,y) and orientation (th)
    Q = np.eye(3)
    R = np.eye(2)
    rMax = 10 # maximum visible range

    def __init__(self, x0 : np.array, Q : np.array, R: np.array) -> None:
        self.x = x0
        self.Q = Q
        self.R = R

    def update(self, u : np.array, dt : float, addNoise : bool = False):
        v = u.item(0)
        w = u.item(1)
        th = self.x.item(2)

        tmp = np.array([[-v/w*np.sin(th) + v/w*np.sin(th + w * dt)],
                  [v/w*np.cos(th) - v/w*np.cos(th +w*dt)],
                  [w * dt]])

        self.x = self.x + tmp

    def getF(self, u : np.array, dt : float):
        v = u.item(0)
        w = u.item(1)
        th = self.x.item(2)

        F = np.array([[1, 0, -v/w*np.cos(th)+v/w*np.cos(th+w*dt)],
                       [0, 1, -v/w*np.sin(th)+v/w*np.sin(th+w*dt)],
                       [0,0,1]])
        return F

    def getMeasurements(self, landmarks : np.array, addNoise : bool = False):

        dims = landmarks.shape
        numLandmarks = dims[1]

        z = np.zeros((2,numLandmarks))
        observedLandmark = [False]*numLandmarks


        for ii in range(numLandmarks):
            delta = landmarks[:,[ii]] - self.x[0:2]
            q = delta.transpose() @ delta 
            z[0,ii] = np.sqrt(q)
            z[1,ii] = np.arctan2(delta[1],delta[0]) - self.x.item(2)
            if np.sqrt(q) < self.rMax:
                observedLandmark[ii] = True 

        return z, observedLandmark

    def getH(self, landmark: np.array):
        delta = landmark-self.x[0:2]
        dx = delta.item(0)
        dy = delta.item(1)
        q = delta.transpose() @ delta 
        H = np.array([[-np.sqrt(q)*dx, -np.sqrt(q)*dy, 0, np.sqrt(q)*dx, np.sqrt(q)*dy],
                      [dy, -dx, -q, -dy, dx]])/q

import numpy as np
import matplotlib.pyplot as plt
from robot import Robot


def drawSim(x_history : np.array, z_history : np.array, u_history : np.array, landmarks : np.array):
    fig = plt.figure(0)

    plt.plot(x_history[0,:], x_history[1,:], 'b')

    for ii in range(landmarks.shape[1]):
        l = landmarks[:,ii]
        plt.plot(l[0],l[1],'r*')

    plt.xlim(-10,10)
    plt.ylim(-10,10)
    plt.show()


if __name__ == '__main__':

    Q = np.diag([1e-3,1e-3,1e-3])
    R = np.diag([1e-3,1e-3])

    t_start = 0
    t_end = 20
    dt = 0.5
    time = np.arange(t_start, t_end, dt)

    x0 = np.array([[5],[0],[np.pi/2]])
    landmark = np.array([[0],[0]])

    u = np.array([[1],[1.0/5.0]])

    x_history = np.zeros((3,len(time)))
    z_history = np.zeros((2,len(time)))
    u_history = np.zeros((2,len(time)))

    rob = Robot(x0,Q,R)

    for index, tt in enumerate(time):
        rob.update(u,dt)
        z,found = rob.getMeasurements(landmark)

        x_history[:,[index]] = rob.x
        z_history[:,[index]] = z
        u_history[:,[index]] = u

    drawSim(x_history, z_history, u_history, landmark)

    





    
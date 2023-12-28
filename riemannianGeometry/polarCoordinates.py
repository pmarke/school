import numpy as np

def toPolar(x_1,x_2):
    r = np.sqrt(x_1**2 + x_2**2)
    th = np.arctan2(x_2,x_1)
    return r,th 

def toPolarJacobian(x_1,x_2):
    r,th = toPolar(x_1,x_2)

    j11 = x_1 / r
    j12 = x_2 /r 
    j21 = -x_2/(r*r)
    j22 = x_1/(r*r)

    J = np.array([[j11,j12],[j21,j22]])
    return J 

def toPolarHessian(x_1,x_2):
    r = (x_1**2 + x_2**2)
    d1 = r**(3.0/2.0)
    d2 = r**2

    J_u11_d1 = (x_2**2)/d1 
    J_u12_d1 = -x_1*x_2/d1 
    J_u21_d1 = -x_1*x_2/d1 
    J_u22_d1 = (x_1**2)/d1

    J_u11_d2 = 2*x_1*x_2/d2
    J_u12_d2 = (x_2**2-x_1**2)/d2
    J_u21_d2 = (x_2**2-x_1**2)/d2
    J_u22_d2 = -2*x_1*x_2/d2
    

    H1 = np.array([[J_u11_d1,J_u12_d1],[J_u21_d1,J_u22_d1]])
    H2 = np.array([[J_u11_d2,J_u12_d2],[J_u21_d2,J_u22_d2]])
    return H1,H2


if __name__ == "__main__":


    x_1 = 3.0
    x_2 = 4.0
    dt = 1e-6

    r,th = toPolar(x_1,x_2)
    rdx1, thdx1 = toPolar(x_1 + dt, x_2)
    rdx2, thdx2 = toPolar(x_1 , x_2+dt)

    Jest = -np.array([[r-rdx1,r-rdx2],[th-thdx1,th-thdx2]])/dt

    J = toPolarJacobian(x_1,x_2)

    J_inv = np.linalg.inv(J)
    print(np.linalg.inv(J))
    print(x_1/r)

    # print(Jest)
    # print(J)

    Jdx1 = toPolarJacobian(x_1+dt,x_2)
    Jdx2 = toPolarJacobian(x_1,x_2+dt)
    Jdx1_est = (Jdx1-J)/dt
    Jdx2_est = (Jdx2-J)/dt
    H1_est = np.array([[Jdx1_est.item(0,0),Jdx1_est.item(0,1)],[Jdx2_est.item(0,0),Jdx2_est.item(0,1)]])
    H2_est = np.array([[Jdx1_est.item(1,0),Jdx1_est.item(1,1)],[Jdx2_est.item(1,0),Jdx2_est.item(1,1)]])

    print(Jdx1_est)
    print(Jdx2_est)

    H1,H2 = toPolarHessian(x_1,x_2) 
    print("H1\n", H1)
    print("H2\n", H2)

    print("H1_est\n",H1_est)
    print("H2_est\n",H2_est)

    print(J_inv[0:2,0].transpose()@H2@J[1,0:2].transpose())
    print(-1/r**(3.0))

    print(1/4**(1/2)*1/4**(3/2))
    print(1/4**(4/2))
    
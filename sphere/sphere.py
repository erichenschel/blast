#r_thermal = Y^0.41 * constant_th
#r_blast = Y^0.33 * constant_bl
#r_radiation = Y^0.19 * constant_rad

# 3 stages of spherical waves?
# setting should be constant (town below?) as to
# emphasize velocity

# under ideal hydrodynamic conditions -- 
# U = c_o(1+6p/7P_o)^(1/2)
# R = S(gamma) * t^(2/5) * rho_o^(-1/5) * E^(1/5)

# the fluid (density, pressure, temperature, flow velocity, Mach number) change almost instantaneously

#############################################
#Euler Equations / Cauchy Momentum Equations
#Describes the non-relativistic momentum transport
#in any continuum

# treat fluid as continuum -- assign a 
# local bulk flow velocity --> v(x, t) @ pt. x
# Volume (V) bounded by a surface (S)
# mass is given by \int_V rho*dV
# rate of mass flux out of V = \int_S (rho)(v)*dS
# = \int_V \grad (rho*v)dV -- (Green's Formula)




# 1. wave eq (polar coordinates): 
# (1/r) * (d/dr)(r * dv/dr) + (1/r^2) (d^2v/d\theta^2)# = (1/c^2) * (d^2v/dt^2)

# 2. Continuity Equation:
# d(rho)/dt + /grad (rho*v) = 0

# 3. 
# 



import pygame


# creating a Pygame window (screen)
def window():
    (width, height) = (300, 200)
    screen = pygame.display.set_mode((width, height))
    pygame.display.flip()


def main():
    return 0


if __name__ == '__main__':
    main()

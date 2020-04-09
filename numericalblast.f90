Program BlastWave
	Implicit None
	Real :: E, density, t, tmax, dt, S, R, Radius
	Real :: v, velocity, B
	Real :: pressure, p

	Open(unit = 7, file="radius.dat")
	Open(unit=77, file="velocity.dat")
	Open(unit=777, file="pressure.dat")
	Open(unit=4, file="plot.dat")

	S = 1.031
	B = 0.926*5.0/2.0
	density = 1.225
	
	t = 0.0
	tmax = 1
	dt = 0.001

	print*, "Enter the amount of energy produced by the explosion (in Joules)"
	Read(*,*) E

	Do While(t < tmax)
		Radius = R(t, density, E, S)
		velocity = v(Radius, E, t, B, density)
		pressure = p(Radius,E)
		write(7,*) Radius
		write(77,*) Radius, velocity
		write(777,*) Radius, pressure
		write(4,*) t, Radius
		t = t+dt
	End Do

Close(4)
Close(7)
Close(77)
Close(777)
End Program

Function R(t,density,E,S)
	Implicit None
	Real :: R, t, density, E, S
	
	R = S*t**(2.0/5.0)*E**(1/5.0)*density**(-1/5.0)

Return
End Function

Function v(R, E, t, B, density)
	Implicit None
	Real :: R, t, E, B, density, v

	v = R**(-3.0/2.0)*E**(1.0/2.0)*(B*density)**(-1.0/2.0)
	print*, "Time","", "Energy","", "Radius","", "Velocity" 
	print*, t, E, R, v
Return
End Function

Function p(R,E)
	Implicit None
	Real :: p, R, E

	p = 0.155*R**(-3.0)*E
Return
End Function

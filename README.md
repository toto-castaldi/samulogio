# samulogio

This configuration files will help whe building your own led based clock.
--------------------------
INSERT HERE HOW TO BUILD
--------------------------

This configuration file assumes you have 3 different rings, and that you know the number of leds in each of the ring.

This are three integer constants called R1, R2 & R3. 
The order is important: 
	*R1 is "the first physical ring", 	so that its starting led is 0, 		and it will be used for the hours
	*R2 is "the second physical ring", 	so that its starting led is R1, 	and it will be used for the minutes
	*R3 is "the third physical ring", 	so that its starting led is R1+R2,	and it will be used for the seconds
These three constants must be defined in the .hpp file.

If you plan to use a 12, 24 and 60 led ring like we did in our project, here is a little helper.
12 led is SMALL (S)
24 led is MEDIUM (M)
60 led is LARGE (L)

You can define a constant 	SML if you plan to use S(mall) for R1, M(edium) for R2 and L(arge) for R3.
Or you can define 			MLS if you plan to use M(edium) for R1, L(arge) for R2 and S(mall) for R3.
All six behaviours are covered

For each of the ring a constant is defined: OFFSET_R1, OFFSET_R2, OFFSET_R3
They should be adjusted so that the 00:00:00 is on top
If at 00:00:00 you read that led 5 clockwise is on, your offset should be set to +5
If at 00:00:00 you read that led 2 counter-clockwise is on, your offset should be set to -2

You can use the "test" to set a customizable time and see how it will display on the clock.

#define SML


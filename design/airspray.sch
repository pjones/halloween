v 20110115 2
C 40000 40000 0 0 0 title-B.sym
C 42000 44900 1 0 0 arduino-pro-mini.sym
{
T 43800 44800 5 10 1 1 0 6 1
refdes=U1
T 42400 50500 5 10 0 0 0 0 1
device=Arduino Pro Mini
T 42400 50700 5 10 0 0 0 0 1
footprint=DIP24
}
C 40900 45300 1 0 0 vdc-1.sym
{
T 41600 45950 5 10 1 1 0 0 1
refdes=V1
T 41600 46150 5 10 0 0 0 0 1
device=VOLTAGE_SOURCE
T 41600 46350 5 10 0 0 0 0 1
footprint=none
T 41600 45750 5 10 1 1 0 0 1
value=DC 12V
}
N 41200 46500 41200 48200 4
N 40600 48200 42100 48200 4
C 41100 45000 1 0 0 gnd-1.sym
C 42300 43900 1 180 1 npn-3.sym
{
T 43200 43400 5 10 0 0 180 6 1
device=NPN_TRANSISTOR
T 43200 43400 5 10 1 1 180 6 1
refdes=Q1
T 43800 43000 5 10 1 1 0 6 1
comment=TIP120
}
C 41400 43300 1 0 0 resistor-1.sym
{
T 41700 43700 5 10 0 0 0 0 1
device=RESISTOR
T 41600 43600 5 10 1 1 0 0 1
refdes=R4
T 41700 43100 5 10 1 1 0 0 1
value=1k
}
N 44500 50700 40200 50700 4
N 40200 50700 40200 43400 4
N 40200 43400 41400 43400 4
C 43000 44400 1 180 0 gnd-1.sym
N 42900 44100 42900 43900 4
C 55900 44300 1 180 0 valve-solenoid.sym
{
T 55005 44300 5 10 1 1 180 3 1
refdes=I1
T 54400 42300 5 10 1 1 0 0 1
comment=AIR SOLENOID
}
N 42900 41900 42900 42900 4
N 40600 40400 40600 48200 4
C 47500 47200 1 0 0 led-1.sym
{
T 48300 47800 5 10 0 0 0 0 1
device=LED
T 47700 47000 5 10 1 1 0 0 1
refdes=LED3
T 48300 48000 5 10 0 0 0 0 1
symversion=0.1
T 47700 46800 5 10 1 1 0 0 1
comment=BLUE
}
C 47500 48400 1 0 0 led-1.sym
{
T 48300 49000 5 10 0 0 0 0 1
device=LED
T 47700 48200 5 10 1 1 0 0 1
refdes=LED2
T 48300 49200 5 10 0 0 0 0 1
symversion=0.1
T 47700 48000 5 10 1 1 0 0 1
comment=GREEN
}
C 47500 49800 1 0 0 led-1.sym
{
T 48300 50400 5 10 0 0 0 0 1
device=LED
T 47700 49600 5 10 1 1 0 0 1
refdes=LED1
T 48300 50600 5 10 0 0 0 0 1
symversion=0.1
T 47700 49400 5 10 1 1 0 0 1
comment=RED
}
C 49100 50800 1 180 0 gnd-1.sym
N 49000 47400 49000 50500 4
C 46600 49900 1 0 0 resistor-1.sym
{
T 46900 50300 5 10 0 0 0 0 1
device=RESISTOR
T 46800 50200 5 10 1 1 0 0 1
refdes=R1
T 46900 49700 5 10 1 1 0 0 1
value=320
}
C 46600 48500 1 0 0 resistor-1.sym
{
T 46900 48900 5 10 0 0 0 0 1
device=RESISTOR
T 46800 48800 5 10 1 1 0 0 1
refdes=R2
T 46900 48300 5 10 1 1 0 0 1
value=320
}
C 46600 47300 1 0 0 resistor-1.sym
{
T 46900 47700 5 10 0 0 0 0 1
device=RESISTOR
T 46800 47600 5 10 1 1 0 0 1
refdes=R3
T 46900 47100 5 10 1 1 0 0 1
value=320
}
N 46600 47400 46100 47400 4
N 46100 47400 46100 48200 4
N 46100 48200 44100 48200 4
N 44100 48600 46600 48600 4
N 46600 50000 46100 50000 4
N 46100 50000 46100 49400 4
N 46100 49400 44100 49400 4
N 48400 50000 49000 50000 4
N 48400 48600 49000 48600 4
N 48400 47400 49000 47400 4
B 50300 45900 1000 900 3 0 0 0 -1 -1 0 -1 -1 -1 -1 -1
N 44100 46600 50300 46600 4
T 50800 46400 9 10 1 0 0 4 3
FROM 
IR RECV 
MODULE
C 49000 44500 1 180 0 rj45-1.sym
{
T 49000 41600 5 10 0 0 180 0 1
device=RJ45
T 49000 41800 5 10 0 0 180 0 1
footprint=RJ45
T 49000 42600 5 10 1 1 180 0 1
refdes=CONN1
}
C 50600 44500 1 180 1 rj45-1.sym
{
T 50600 41600 5 10 0 0 180 6 1
device=RJ45
T 50600 41800 5 10 0 0 180 6 1
footprint=RJ45
T 50600 42600 5 10 1 1 180 6 1
refdes=CONN2
}
B 54400 44800 1300 600 3 0 0 0 -1 -1 0 -1 -1 -1 -1 -1
T 54500 44900 9 10 1 0 0 0 2
REMOTE 
ACCESSORY
T 51500 44100 9 10 1 0 0 0 1
OW
T 51500 42700 9 10 1 0 0 0 1
O
T 51500 43700 9 10 1 0 0 0 1
BlW
T 51500 42900 9 10 1 0 0 0 1
Bl
T 51500 43900 9 10 1 0 0 0 1
GW
T 51500 43100 9 10 1 0 0 0 1
G
T 51500 43500 9 10 1 0 0 0 1
BrW
T 51500 43300 9 10 1 0 0 0 1
Br
N 51500 44300 54100 44300 4
N 54100 43800 54100 44300 4
N 51500 42900 54100 42900 4
N 54100 42000 54100 43100 4
N 54100 42000 56100 42000 4
N 56100 42000 56100 43800 4
N 56100 43800 55900 43800 4
N 48100 42900 47600 42900 4
N 47600 40400 47600 43100 4
N 47600 40400 40600 40400 4
{
T 46100 40400 5 10 1 1 0 0 1
comment=RJ45 P1 and P2
}
N 46800 44300 48100 44300 4
N 46800 44300 46800 41900 4
N 42600 41900 46800 41900 4
{
T 45300 41900 5 10 1 1 0 0 1
comment=RJ45 P8 and P6
}
N 51500 43100 54100 43100 4
N 48100 43100 47600 43100 4
N 48100 43900 46800 43900 4
N 51500 43900 54100 43900 4
N 51500 44100 53000 44100 4
N 53000 44100 53000 45300 4
N 53000 45300 54400 45300 4
N 48100 44100 47600 44100 4
C 47300 44200 1 270 0 gnd-1.sym
N 48100 43300 46200 43300 4
N 46200 43300 46200 45400 4
N 46200 45400 45000 45400 4
{
T 45400 45400 5 10 1 1 0 0 1
comment=RJ45 P3
}
N 51500 43300 53300 43300 4
N 53300 43300 53300 45000 4
N 53300 45000 54400 45000 4
N 46400 43500 46400 45800 4
N 46400 45800 45000 45800 4
{
T 45400 45800 5 10 1 1 0 0 1
comment=RJ45 P4
}
N 46600 43700 48100 43700 4
N 46600 43700 46600 46200 4
N 46600 46200 45000 46200 4
{
T 45400 46200 5 10 1 1 0 0 1
comment=RJ45 P5
}
N 46400 43500 48100 43500 4
C 41600 41900 1 0 0 switch-pushbutton-no-1.sym
{
T 42000 42200 5 10 1 1 0 0 1
refdes=S1
T 42000 42500 5 10 0 0 0 0 1
device=SWITCH_PUSHBUTTON_NO
}
C 41300 42000 1 270 0 gnd-1.sym
B 50300 41700 6100 3900 3 0 0 0 -1 -1 0 -1 -1 -1 -1 -1
T 50400 45300 9 10 1 0 0 0 1
OUTER MODULE
T 49700 41000 9 14 1 0 0 0 1
AIR SPRAY CONTROLLER
T 50900 40400 9 10 1 0 0 0 1
airspray.sch
T 50500 40100 9 10 1 0 0 0 1
1
T 52100 40100 9 10 1 0 0 0 1
1
T 54200 40400 9 10 1 0 0 0 1
001
T 54200 40100 9 10 1 0 0 0 1
PETER J JONES
C 44300 41600 1 270 0 diode-1.sym
{
T 44900 41200 5 10 0 0 270 0 1
device=DIODE
T 44800 41100 5 10 1 1 0 0 1
refdes=D1
}
N 44500 41600 44500 41900 4
N 44500 40700 44500 40400 4
C 44100 46100 1 0 0 resistor-1.sym
{
T 44400 46500 5 10 0 0 0 0 1
device=RESISTOR
T 44300 46300 5 10 1 1 0 0 1
refdes=R5
T 44600 46300 5 10 1 1 0 0 1
value=320
}
C 44100 45700 1 0 0 resistor-1.sym
{
T 44400 46100 5 10 0 0 0 0 1
device=RESISTOR
T 44300 45900 5 10 1 1 0 0 1
refdes=R6
T 44600 45900 5 10 1 1 0 0 1
value=320
}
C 44100 45300 1 0 0 resistor-1.sym
{
T 44400 45700 5 10 0 0 0 0 1
device=RESISTOR
T 44300 45500 5 10 1 1 0 0 1
refdes=R7
T 44600 45500 5 10 1 1 0 0 1
value=320
}
N 44500 50700 44500 49800 4
N 44100 49800 44500 49800 4
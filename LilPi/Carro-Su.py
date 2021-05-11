# Importamos las librerias
import RPi.GPIO as GPIO
import time

# |========================================| #
# |==========|   Configuración  |==========| #
# |========================================| #

# Configuramos la tarjeta (BOARD / BCM)
GPIO.setmode(GPIO.BCM)

# Configuramos pines de salida
# !=====! Motores !====!
Mo = [[4, 3, 2], [17, 27, 22]]
# !==! Ultrasonicos !==!
Su = [[18,14], [15,23]]

# |===| Configuración de pines |===|
for Motor in Mo:
    for pin in Motor:
        GPIO.setup(pin, GPIO.OUT)
        print("Se configuró el pin: ", pin)
for Ultrasonico in Su:
    # |==| Trigger |==|
    GPIO.setup(Ultrasonico[0], GPIO.OUT)
    # |==|  Echo   |==|
    GPIO.setup(Ultrasonico[1], GPIO.IN)

# |========================================| #
# |==========|      Métodos     |==========| #
# |========================================| #

def Distancia(Sn):
    # Encendemos el Trigger
    GPIO.output(Su[Sn][0], True)
    # El encendido es durande 1us
    time.sleep(0.00001)
    GPIO.output(Su[Sn][0], False)

    StartTime = time.time()
    StopTime = time.time()

    # Iniciamos el conteo
    while GPIO.input(Su[Sn][1]) == 0:
        StartTime = time.time()
    # Obtenemos el tiempo total
    while GPIO.input(Su[Sn][1]) == 1:
        StopTime = time.time()

    # Calculamos la diferencia de tiempo
    TimeElapsed = StopTime - StartTime
    # Retornamos el valor de la distancia
    distance = (TimeElapsed * 34300) / 2
    return  distance

# |========================================| #
# |==========|     Ejecución    |==========| #
# |========================================| #

# Configuramos la potencia de los motores
MoP = [GPIO.PWM(Mo[0][2], 255), GPIO.PWM(Mo[1][2], 255)]
while True:
    print("Distancia Su[1] = "+ str(Distancia(0)))
    print("Distancia Su[2] = "+ str(Distancia(1)))






    time.sleep(1)

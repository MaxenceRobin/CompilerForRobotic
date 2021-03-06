import pycom
import time
import uos

from DRV8833 import *

DRV8833_Sleep_pin = 'P5'
DRV8833_AIN1 = 'P11'
DRV8833_AIN2 = 'P12'
DRV8833_BIN1 = 'P21'
DRV8833_BIN2 = 'P22'

V_MAX = 0.6
V_MOYEN = 0.4
V_MIN = 0.2

C_g = 0
C_d = 0

Moteur_Gauche = DRV8833 (DRV8833_AIN1, DRV8833_AIN2, DRV8833_Sleep_pin, 1, 500, 0, 1)
Moteur_Droit = DRV8833 (DRV8833_BIN1, DRV8833_BIN2, DRV8833_Sleep_pin, 1, 500, 2, 3)

def Avancer_droit (vitesse) :
    global C_g
    global C_d
    Moteur_Droit.Cmde_moteur(SENS_HORAIRE, vitesse)
    Moteur_Gauche.Cmde_moteur(SENS_ANTI_HORAIRE, vitesse)
    C_g = 1
    C_d = 1
def Reculer_droit (vitesse) :
    global C_g
    global C_d
    Moteur_Droit.Cmde_moteur(SENS_ANTI_HORAIRE, vitesse)
    Moteur_Gauche.Cmde_moteur(SENS_HORAIRE, vitesse)
    C_g = -1
    C_d = -1
def Pivoter_droite (vitesse) :
    global C_g
    global C_d
    Moteur_Droit.Cmde_moteur(SENS_ANTI_HORAIRE, vitesse)
    Moteur_Gauche.Cmde_moteur(SENS_ANTI_HORAIRE, vitesse)
    C_g = 1
    C_d = -1
def Pivoter_gauche (vitesse) :
    global C_g
    global C_d
    Moteur_Droit.Cmde_moteur(SENS_HORAIRE, vitesse)
    Moteur_Gauche.Cmde_moteur(SENS_HORAIRE, vitesse)
    C_g = -1
    C_d = 1
def Arret () :
    Moteur_Droit.Arret_moteur()
    Moteur_Gauche.Arret_moteur()

def random_color():
    n = uos.urandom(3)
    color = n[0] + n[1] * 256 + n[2] * 256 * 256
    return color

pycom.heartbeat(False)

print('test')

pycom.rgbled(0x330000)
Avancer_droit(V_MAX)
time.sleep(1)
Reculer_droit(V_MAX)
time.sleep(1)
pycom.rgbled(0x000066)
Pivoter_gauche(V_MAX)
time.sleep(1)
Pivoter_droite(V_MAX)
time.sleep(1)
Arret()
pycom.rgbled(0x000000)


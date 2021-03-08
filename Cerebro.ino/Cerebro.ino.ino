/**=========================== | Ajolo-bot | ===========================**/
/*                        Robot seguidor de personas                     */
/* Desarrollador: González Martínez Álvaro Gabriel                       */
/* Integrantes del equipo:                                               */
/*       González Martínez Álvaro Gabriel                                */
/*       Gutiérrez Carrales José Luis                                    */
/*       Gutiérrez Mora Aranza                                           */
/*                                                                       */
/* Descripción:                                                          */
/* Se  trata  de un  robot  que  tendrá  como funciones prinipales poder */
/* seguir a  personas, esto lo realizará mediante  sensores ultrasonicos */
/* que  le  permitiran analizar si alguna persona se encuentra dentro de */
/* su rango de visibilidad.                                              */
/* Para espesificar los pins a usar utilizaremos arreglos mxn, esto  nos */
/* permitira identificar a los elementos  de la  manera:                 */
/* Identificador[<N. Elemento>][<Adelante/Atras, Trigg/Ecco>];           */
/**=========================== | ========= | ===========================**/

/**======================= | Variables globales | ======================**/
/* |==|   Motores  |==| */
const int Mo[2][2] = {{6, 7}, {8, 9}};
/* |==|  Sensores  |==| */
const int Su[3][2] = {{2, 3}, {0, 0}, {0, 0}};
/* |==| Contadores |==| */
int i = 0, j = 0;
/**========================= | Fin Variables | =========================**/

/**===================== | Área de configuracion | =====================**/
void setup()
{
    /*  Configuracion  de  pins  de  motores como  salida */
    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
            pinMode(Mo[i][j], OUTPUT); /* Pulso de salida */

    /* Configuracion de  pins  de  sensores  ultrasonicos */
    for (i = 0; i < 3; i++)
    {
        pinMode(Su[i][0], OUTPUT); /* Trigger como salida */
        pinMode(Su[i][1], INPUT);  /*  Echo como  entrada */
    }
}
/**=================== | Fin área de configuracion | ===================**/

/**====================== | Funciones y metodos | ======================**/

/* Metodo de ocio para utilizar con leds indicadores */
void Fantastico(int Time)
{
    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
        {
            digitalWrite(Mo[i][j], 1);
            delay(Time);
        }
    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
        {
            digitalWrite(Mo[i][j], 0);
            delay(Time);
        }
}
/**=========== | Fin  metodo Fantasito | ===========**/

/* Funcion que regresa la distancia medida por el Su */
float Distancia(int SuN)
{
    /* Variable local para calculos */
    long Duration;
    /* Limpieza de Trigger */
    digitalWrite(Su[SuN][0], 0);
    delayMicroseconds(2);
    /* Encendido de Trigger 10 segundos */
    digitalWrite(Su[SuN][0], 1);
    delayMicroseconds(10);
    digitalWrite(Su[SuN][0], 0);
    /* Lectura del Echo del sesor */
    Duration = pulseIn(Su[SuN][1], HIGH);
    /* Calculos para la distancia */
    return (Duration * 0.034 / 2.0);
}
/**=========== | Fin  metodo Fantasito | ===========**/

/**==================== | Fin funciones y metodos | ====================**/

/**======================= | Área de ejecucion | =======================**/
void loop()
{
    Fantastico(Distancia(0));
}
/**===================== | Fin área de ejecucion | =====================**/

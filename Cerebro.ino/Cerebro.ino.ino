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

/**=========================== | Variables | ===========================**/
/* |==|   Motores  |==| */
const int Mo[2][2] = {{6, 7}, {8, 9}};
/* |==|  Sensores  |==| */
const int Su[3][2] = {{2, 3}, {0, 0}, {0, 0}}; /*   Sensor  Ultrasonico  */
/* |==| Contadores |==| */
int i = 0, j = 0;
/**========================= | Fin Variables | =========================**/

// Iniciamos con la configuracion de los motores y sensores
void setup()
{
    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
            pinMode(Mo[i][j], OUTPUT);
}
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
void loop()
{
    Fantastico(50);
}
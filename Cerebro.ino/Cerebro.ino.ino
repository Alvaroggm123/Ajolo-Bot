/**=========================== | Ajolo-bot | ===========================**/
/*                        Robot seguidor de personas                     */
/* Desarrollador: González Martínez Alvaro Gabriel                       */
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
const int Mo[2][3] = {{4, 3, 5}, {2, 13, 6}};
/* |==|  Sensores  |==| */
const int Su[3][2] = {{7, 8}, {9, 10}, {11, 12}};
/* |==| Contadores |==| */
int i = 0, j = 0;
/**========================= | Fin Variables | =========================**/

/**===================== | Área de configuracion | =====================**/
void setup()
{
  /*  Configuracion  de  pins  de  motores como  salida */
  for (i = 0; i < 2; i++)
    for (j = 0; j < 3; j++)
      pinMode(Mo[i][j], OUTPUT);

  /* Configuracion de  pins  de  sensores  ultrasonicos */
  for (i = 0; i < 3; i++)
  {
    pinMode(Su[i][0], OUTPUT); /* Trigger como salida */
    pinMode(Su[i][1], INPUT);  /*  Echo como  entrada */
  }
  /* Configuracion de  comunicacion serial con la  PC */
  Serial.begin(115200);/*  configuramos a  115200 bps */

  /* Nos aseguramos  de  tener  los  motores apagados */
  for (i = 0; i < 2; i++)
    for (j = 0; j < 2; j++)
      digitalWrite(Mo[i][j], 0);
}
/**=================== | Fin área de configuracion | ===================**/

/**====================== | Funciones y metodos | ======================**/

/* ==================| Distancia |================== */
/* Funcion que regresa la distancia medida por el Su */
/* espesificado por SuN (N. sensor).                 */
float Distancia(int SuN)
{
  /* Variable local para calculos */
  long Duration;
  int Distancia;
  /* Limpieza de Trigger */
  digitalWrite(Su[SuN][0], 0);
  delayMicroseconds(2);
  /* Encendido de Trigger 10 segundos */
  digitalWrite(Su[SuN][0], 1);
  delayMicroseconds(10);
  digitalWrite(Su[SuN][0], 0);
  /* Lectura del Echo del sesor */
  Duration = pulseIn(Su[SuN][1], 1);
  /* Calculos para la distancia */
  Distancia = Duration * 0.034 / 2;
  return (Distancia);
}
/**=========== | Fin  metodo Fantasito | ===========**/

/* ============ | Imprime Ultrasonico | ============ */

/* Metodo  que  imprimira  mediante  la comunicacion */
/* serial los valores que a el se le envien  por  su */
/* parametro.                                        */
void ImprimeUltra()
{
  String Salida = String(Distancia(0)) + "    " + String(Distancia(1)) + "    " + String(Distancia(2));
  Serial.println(Salida);
}
/**========= | Fin  metodo Imprime ultra| ==========**/

/**==================== | Fin funciones y metodos | ====================**/

/**======================= | Área de ejecucion | =======================**/GIT
void loop()
{
  digitalWrite(Mo[0][1], 0);
  digitalWrite(Mo[1][1], 1);
  analogWrite(Mo[0][2], map(Distancia(0), 0, 20, 100, 255));
  analogWrite(Mo[1][2], map(Distancia(1), 0, 20, 100, 255));
}
/**===================== | Fin área de ejecucion | =====================**/

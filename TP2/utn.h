#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED



#endif // UTN_H_INCLUDED



/** \brief Funcion que sirve para pedir un numero entero
 *
 * \param pResultado puntero a donde va a ser guardado el entero
 * \param mensaje mensaje que vera el usuario
 * \param mensajeError mensaje que vera el usuario si es invalido
 * \param  minimo valor mas chico capaz de recibir la funcion
 * \param  maximo valor mas grande capaz de recibir la funcion
 * \param reintentos la cantidad de veces que se pide el dato al ser invalido
 * \param
 * \param
 * \return
 *
 */

int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);

/** \brief Funcion que sirve para pedir un numero entero
 *
 * \param pResultado puntero a donde va a ser guardado el entero
 * \param mensaje mensaje que vera el usuario
 * \param mensajeError mensaje que vera el usuario si es invalido
 * \param  minimo valor mas chico capaz de recibir la funcion
 * \param  maximo valor mas grande capaz de recibir la funcion
 * \param reintentos la cantidad de veces que se pide el dato al ser invalido
 * \param
 * \param
 * \return
 *
 */

int utn_getNumeroFloat(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos);

/** \brief Funcion que sirve para pedir un numero entero
 *
 * \param pResultado puntero a donde va a ser guardado el entero
 * \param mensaje mensaje que vera el usuario
 * \param mensajeError mensaje que vera el usuario si es invalido
 * \param  minimo valor mas chico capaz de recibir la funcion
 * \param  maximo valor mas grande capaz de recibir la funcion
 * \param reintentos la cantidad de veces que se pide el dato al ser invalido
 * \param
 * \param
 * \return
 *
 */

int utn_getCaracter(char* pResultado,char* mensaje,char* mensajeError,char minimo,char maximo,int reintentos);

int esNumerico(char str[]);
int esTelefono(char str[]);
int esAlfaNumerico(char str[]);
int esSoloLetras(char str[]);

int utn_getCadena(char *pAux, int len, int retry, char* mensaje, char* mensajeError);
int getCadena(char* pAux, int len);
